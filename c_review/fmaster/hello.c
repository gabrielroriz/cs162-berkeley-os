#include <unistd.h> // import write function
#include <stdio.h> // import printf function

// main() is a function that returns nothing ("void")
void main(){
    write(1, "Hello World!\n", 13);
    // 1 means write to stdout; 2 means write to stderr
    // 13 is the length of the string "Hello World!\n"
    printf("Hello World!\n");

    int num = 42;
    printf("The number is %d\n", num);

}