#include <stdio.h>

// "#define" defines a macro, which is a piece of code that gets replaced by the preprocessor before compilation
// sizeof(arr[0]|*arr) = size of each element (int, which is 4 bytes on most systems)
// sizeof(arr) = size of the entire array (which is n of elements * size of each element))
#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))
// In C arrays decay to pointers when passed to functions, 
// so you cannot get the length of an array inside a function.
// You have to pass the length as a separate argument or use a sentinel 
// value to indicate the end of the array (like null terminator in strings).


int main(int argc, char *argv[]) {
    // Array declartion with int {name}[{size}]
    // Initialize values with {val1, val2, ...}
    int nums[4] = {1, 2, 5, 6};

    for(int i = 0; i < ARRAY_LEN(nums); i++){
        printf("Num at index %d is %d\n", i, nums[i]); // %d stands for decimal integer in printf.
    }

    // We declare strings using char arrays, and we can initialize them with string literals (enclosed in double quotes)
    // char arrays = *strings, which are null-terminated (they end with a special character '\0' to indicate the end of the string)
    char *str = "abcdefg";
    printf("My string is %s\n", str); // %s stands for string in printf
    printf("Size of each char is %lu bytes\n", sizeof(str[0])); // sizeof(char) is 1 byte = 8 bits. Ex:. 0b00000001. 0b means binary literal in C.
    // %lu stands for unsigned long in printf, which is the type returned by sizeof operator.
    return 0;
}
