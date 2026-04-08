// A string is an array of characters ending with a null terminator \0.
// So, we can represent string as a char * or as a char array.
// For example, char str[] = "Hello"; and char *str = "Hello";
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void print_chars(char *str){
    size_t len = strlen(str); // It returns the length of the string excluding the null terminator.
    // strlen return a size_t type, which is an unsigned integer type. We can use %zu format specifier to print it.
    printf("(%zu): ", len);
    size_t i = 0;
    while(i < len){
        printf("%c", *(str + i));
        i++;
    }
    printf("%d", str[len]); // This will print the null terminator (\0), which is not visible, but it is there.
    printf("\n");
}

char *str_copier(char *str){
    // size_t is specifically for memory sizes and array indices - it's the return type of sizeof, strlen, malloc, .size() methods etc.
    size_t len = strlen(str);

    char *copied = malloc(sizeof(char) * (len + 1));

    strcpy(copied, str);

    return copied;
}

int main(){

    char *str = "Help me!"; // This is a pointer to a string literal, which is stored in read-only memory. WE CANNOT MODIFY THIS STRING.
    char str2[] = "Help me!"; // This is an array of characters, which is stored in writable memory. WE CAN MODIFY THIS STRING.
    printf("str: %s\n", str);
    printf("str2: %s\n", str2);

    print_chars(str);
    print_chars(str2);

    print_chars(str_copier(str)); // This will print the copied string, which is stored in writable memory, so we can modify it if we want.

}

