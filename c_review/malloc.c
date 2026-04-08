// malloc returns a pointer to the start of a region of memory on the heap.

// malloc data on the HEAP !== declaring data on the STACK (like we do with arrays and variables).
// When we declare a variable or an array, it is stored on the STACK, which is a region of memory that is automatically managed by the compiler.
// When we use malloc, we are allocating memory on the HEAP, which is a region of memory that is manually managed by the programmer. 
// We need to free the allocated memory when we are done.

// The HEAP is a region of memory that is used for dynamic memory allocation, which means that we can allocate and deallocate memory at runtime.
// The STACK is a region of memory that is used for static memory allocation, which means that the size of the memory is determined at compile time and cannot be changed at runtime.

// Everything we declare on STACK is automatically deallocated when it goes out of scope, 
// but everything we allocate on the HEAP using malloc must be manually deallocated using free to avoid memory leaks.

// We cannot return a STACK variable from a function because it will go out of scope and be deallocated when the function returns,
// but we can return a HEAP variable from a function because it will remain allocated until we explicitly free it.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr = malloc(sizeof(int)); // This allocates memory for a single integer on the HEAP and returns a pointer to it.

    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit with an error code if malloc fails
    }

    *ptr = 42; // We can assign a value to the allocated memory using the dereference operator.

    printf("Value at ptr: %d\n", *ptr); // This will print the value we assigned to the allocated memory.

    free(ptr); // Don't forget to free the allocated memory to avoid memory leaks.

    return 0;
}