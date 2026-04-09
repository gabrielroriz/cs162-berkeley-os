#include <stdio.h>
#include <stdlib.h>


// structs organize and group variables in a container so that they're easily accessible by a single pointer.
struct coord {
    int x;
    int y;
};

// when we pass struct values into functions they are copied
void modify1(struct coord c) {
    c.x = 5;
    c.y = 6;
}

// when we pass a pointer to a struct into a function, 
//we can modify the original struct because we are passing the address of the struct, not a copy of it.
void modify2(struct coord *c) {
    c->x = 5;
    c->y = 6;
}


int main(){
    struct coord c1; // This is a variable of type struct coord, which is stored on the STACK.
    c1.x = 10; // We can access the members of the struct using the dot operator.
    c1.y = 20;


    struct coord *c2 = malloc(sizeof(struct coord)); // This is a pointer to a struct coord, which is allocated on the HEAP.

    if (c2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit with an error code if malloc fails
    }

    c2->x = 30; // We can access the members of the struct using the arrow operator.
    c2->y = 40;

    // c2-> = (*c2). because the arrow operator is just a shorthand for dereferencing the pointer and then accessing the member.

    // Arrow operator (->) is used to access members of a struct through a pointer, 
    // while the dot operator (.) is used to access members of a struct directly.

    (*c2).x = 50; // We can also access the members of the struct using the dereference operator and the dot operator.
    (*c2).y = 60;


    // No change because a copy of the struct is passed
    modify1(c1);
    modify1(*c2);
    printf("modify1\n");
    printf("x: %d, y: %d\n", c1.x, c1.y);
    printf("x: %d, y: %d\n", c2->x, c2->y);

    // Change because we passed a pointer to the struct
    modify2(&c1);
    modify2(c2);
    printf("modify2\n");
    printf("x: %d, y: %d\n", c1.x, c1.y);
    printf("x: %d, y: %d\n", c2->x, c2->y);


    free(c2); // Don't forget to free the allocated memory to avoid memory leaks.

    return 0;
}