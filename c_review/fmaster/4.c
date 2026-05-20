#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

// 👉 First, build and run the program.
//
// To do this, make sure you're in the `exercises` directory, and then run:
//
// gcc -o app4 4.c && ./app4

const char* DEFAULT_FILE = "index.html";

char *to_path(char *req) {
    char *start, *end;

    // Advance `start` to the first space
    for (start = req; start[0] != ' '; start++) {
        if (!start[0]) {
            return NULL;
        }
    }

    start++; // Skip over the space

    // Advance `end` to the second space
    for (end = start; end[0] != ' '; end++) {
        if (!end[0]) {
            return NULL;
        }
    }

    // Ensure there's a '/' right before where we're about to copy in "index.html"
    if (end[-1] != '/') {
        end[0] = '/';
        end++;
    }

    // If there isn't enough room to copy in "index.html" then return NULL.
    // (This only happens if the request has no headers, which should only
    // come up in practice if the request is malformed or something.)
    if (end + strlen(DEFAULT_FILE) > req + strlen(req)) {
        return NULL;
    }

    // Copy in "index.html", overwriting whatever was there in the request string.
    memcpy(end, DEFAULT_FILE, strlen(DEFAULT_FILE) + 1);

    return start + 1; // Skip the leading '/' (e.g. in "/blog/index.html")
}

void print_file(const char *path) {
    int fd = open(path, O_RDONLY);
    if(fd == -1){
        printf("Error occurred while opening file.\n");
        return;
    }

    struct stat metadata;
    if (fstat(fd, &metadata) == -1) {
        printf("Error occurred while fetching file metadata.\n");
        close(fd);
        return;
    }

    // 👉 Change this to `char *` and malloc(). (malloc comes from <stdlib.h>)
    //    Hint 1: Don't forget to handle the case where malloc returns NULL!
    //    Hint 2: Don't forget to `free(buf)` later, to prevent memory leaks.
    // char buf[metadata.st_size + 1];
    char *buf = malloc(metadata.st_size + 1);

    if(!buf){
        printf("Error occurred while allocating memory.\n");
        close(fd);
        return;
    }

    ssize_t bytes_read = read(fd, buf, metadata.st_size);
    if (bytes_read == -1) {
        printf("Error occurred while reading file.\n");
        close(fd);
        free(buf);
        return;
    }
    buf[bytes_read] = '\0';
    printf("\n%s contents:\n\n%s\n", path, buf);

    close(fd);
    free(buf);

    // 👉 Go back and add error handling for all the cases above where errors could happen.
    //    (You can just printf that an error happened.) Some relevant docs:
    //

}

int main() {
    char req1[] = "GET / HTTP/1.1\nHost: example.com";
    print_file(to_path(req1));

    char req2[] = "GET /blog HTTP/1.1\nHost: example.com";
    print_file(to_path(req2));

    return 0;
}