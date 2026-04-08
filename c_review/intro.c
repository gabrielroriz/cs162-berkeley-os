// https://cs162.org/ladder/
// a library that contains functions like printf
#include <stdio.h>

// argc = number of elements in argv. "c" stands for "count"
// argv = list of string arguments inputted into the program. "v" stands for "vector"
int main(int argc, char *argv[]){

    printf("%s\n", "Hello world!");

    printf("Filename: %s\n", argv[0]); // the name of the program

    if (argc > 1) {
        printf("First argument: %s\n", argv[1]); // the first argument
    }

    // 0 means successful termination of the program
    // 1 means unsuccessful termination of the program
    // you can also return other numbers to indicate different types of errors
    return 0;
}

// Compile a single file
// gcc intro.c -o intro

// # Run it
// ./intro