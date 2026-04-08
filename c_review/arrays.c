#include <stdio.h>
#include <stdlib.h>

// We can represent arrays using [] syntax or as pointer using * syntax.
// For example, int arr[5] and int *arr are both valid.
// However, when we declare an array with [], we are actually declaring a pointer to the first element of the array.

// malloc returns a pointer to a block of memory of the specified size, which can be used to store an array of a certain type.

int main(){
    int NUM_ELEMENTS = 5;
    int arr[NUM_ELEMENTS]; // This is an array of 5 integers.

    for(int i = 0; i < NUM_ELEMENTS; i++){
        arr[i] = i; // Assign values to the array
    }

    // This is a pointer to an array of 5 integers allocated on the heap.
    // malloc = memory allocation, which allocates a block of memory and returns a pointer to it.
    int *arr2 = malloc(sizeof(int) * NUM_ELEMENTS);

    printf("arr2: %p\n", arr2);

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        // We can assign values to the array using POINTER ARITHMETIC.
        // It means: address of arr2 + i (which gives us the address of the i-th element) and then dereference it to assign a value.
        *(arr2 + i) = i;
        
        // We can also print the address of each element in arr2 using pointer arithmetic.
        // First argument: value of i, second argument: address of the i-th element in arr2 (which is arr2 + i).
        printf("(arr2 + %d): %p\n", i, arr2 + i);
    }

    free(arr2); // Don't forget to free the allocated memory to avoid memory leaks.

    return 0;
}