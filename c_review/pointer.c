// Pointer is an address that points to a location in memory.
// It can be used to store the address of a variable, an array, or a function.

// &x = address of x (reference operator)
// *p = value at address p (dereference operator)

// Pointer type is declared with {type} *{name}, where {type} is the type of the value that the pointer points to.

#include <stdio.h>

int modify1(int z){
    // Here, z is a copy of the value of x, so modifying z does not affect x
    z = 5;
}

int modify2(int *z){
    // Here, we are dealing with pointer to the address of x, 
    // so modifying the value at that address will affect x
    // (We can get the value at the pointer by using the * syntax)
    *z = 5;
}

int main(int argc, char *argv[]) {
    int x = 4;
    int *y = &x;

    modify1(x);
    printf("Value of x after modify1: %d\n", x); // x is still 4

    modify2(y);
    
    printf("The value of x after modify2: %d\n", x); // *y is 5 because we modified the value at the address that y points to (which is x)

    return 0;
}