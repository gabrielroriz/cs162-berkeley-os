#include <stdio.h>

// "#define" defines a macro, which is a piece of code that gets replaced by the preprocessor before compilation
// sizeof(arr[0]|*arr) = size of each element (int, which is 4 bytes on most systems)
// sizeof(arr) = size of the entire array (which is n of elements * size of each element))
#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))

// ========== Notes ==========
// In C, arrays decay to pointers when passed to functions, 
// so you cannot get the length of an array inside a function.
// You have to pass the length as a separate argument or use 
// a sentinel value to indicate the end of the array (like null terminator in strings).


int main(int argc, char *argv[]) {
    // Array declartion with int {name}[{size}]
    int nums[3] = {1, 2, 5};

    for(int i = 0; i < ARRAY_LEN(nums); i++){
        printf("Num at index %d is %d\n", i, nums[i]);
    }

    char *str = "abcd";
    printf("My string is %s\n", str);
    return 0;
}
