#include <stdio.h> // For printf() and perror() etc
#include <string.h> // For memcpy() and strlen() etc
#include <stdlib.h> // For malloc() and free()
#include <sys/socket.h> // socket() is declared in sys/socket.h
#include <unistd.h> // close() is declared in unistd.h
#include <netinet/in.h> // For sockaddr_in and htons() etc
#include <errno.h> // For errno

#define MAX_REQUEST_BYTES 1024 // 1 KB should be enough for our purposes, 
// but in a real web server you would want to be able to handle much larger requests
// (e.g. with large headers or a large body) and so you would want to use a larger buffer 
// size and/or read the request in multiple chunks instead of all at once.

int main() {
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1) {
        perror("socket");
        return 1;
    }

    printf("socket_fd: %d\n", socket_fd); // 3 is the first file descriptor that is not stdin, stdout, or stderr

    // Configuration for SO_REUSEADDR: https://man7.org
    int opt = 1;
    setsockopt(
        socket_fd, 
        SOL_SOCKET, 
        SO_REUSEADDR, 
        &opt, 
        sizeof(opt)
    );
    printf("SO_REUSEADDR set\n");

    // Bind the socket to an address and port so that the 
    // OS knows to send incoming requests to this socket.
    struct sockaddr_in address;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all network interfaces
    address.sin_family = AF_INET; // Use IPv4
    address.sin_port = htons(8081); // Listen on port 8081

    int bind_result = bind(
        socket_fd, 
        (struct sockaddr*) &address, 
        sizeof(address)
    );

    if(bind_result == -1) {
        printf("errno = %d\n", errno);
        perror("bind");
        close(socket_fd);
        return 1;
    }

    // Start listening for incoming requests on the socket.
    int listen_result = listen(socket_fd, 10); // 10 is the maximum number of pending connections that can be queued up before the OS starts rejecting new ones

    if (listen_result == -1) {
        perror("listen");
        close(socket_fd);
        return 1;
    } 

    char req[MAX_REQUEST_BYTES + 1]; // +1 for null terminator
    while (1) {
        printf("Waiting for incoming requests...\n");
        int client_socket_fd = accept(socket_fd, NULL, NULL);
        if (client_socket_fd == -1) {
            perror("accept");
            close(socket_fd);
            continue; // If accept() fails, skip to the next iteration of the loop to try accepting the next incoming request
        }

        char content[] = "HTTP/1.1 200 OK\r\nContent-Type: text/plain; charset=utf-8\r\nCache-Control: no-store\r\n\r\nHello, world!";
        write(client_socket_fd, content, strlen(content));
        
        // We don't actually do anything with the request in this example, so we can just close 
        // the client socket immediately after accepting the connection. In a real web server, 
        // you would want to read the request from the client socket and send back a response before closing it.
        close(client_socket_fd);
    }

    close(socket_fd);
    return 0;
}