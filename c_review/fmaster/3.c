#include <stdio.h>
#include <string.h>

// const means that this variable cannot be modified after it's initialized, 
// and the string literal is stored in read-only memory, 
// so we don't have to worry about accidentally modifying it later in the program
const char *DEFAULT_FILE = "/index.html\0";

char *to_path(char *req){

    // for loop alternative:
    char *start, *end;

    for(
        start = req;
        start[0] != ' ';
        start++
    ){
        if(!start[0]){ // if we reach the end of the string without finding a space, then we return NULL
            return NULL; 
        }
    }

    start++; // skip past the space separator

    for(
        end = start;
        end[0] != ' ';
        end++
    ){
        if(!end[0]){ // if we reach the end of the string without finding a space, then we return NULL
            return NULL;
        }
    }

    if(end[-1] == '/'){ // if the character before end is a slash ("blog/"), then we want to move end back by one character
        end--;
    } else if(start[0] == '/'){ // if the character at start is a slash ("/blog"), then we want to move start forward by one character
        start++;
    }
    
    // end[0] = '\0'; // replace the space at the end of the path with a null terminator, so that we can return a string that ends at the end of the path

    memcpy(end, DEFAULT_FILE, strlen(DEFAULT_FILE) + 1); // copy "index.html" to the end of the path, so that we can return a string that ends with "index.html"
    return start;
}


int main (){
    char req[] = "GET /blog HTTP/1.1";
    char *path = to_path(req);
    printf("The path is: %s\n", path);
    return 0;
}