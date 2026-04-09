#include <stdio.h>

#define PI 3.14159
#define SQUARE(x) ((x) * (x))
#define SUM_1(x) (x + 1)
#define COMPLEX_FUNC(a, b) ((a) * (b) + (a) / (b))

// Macros allows you to define constants and functions that are expanded
// by the preprocessor before compilation. 
// They can be used to improve:
// - code readability
// - reduce redundancy
// - create more flexible code

// However, they should be used with caution as they can lead to unexpected behavior if not defined properly.
// For example, the SQUARE macro can cause issues if used with expressions, as it may not evaluate as expected due to operator precedence. 
// Always use parentheses around macro parameters and the entire macro definition to avoid such issues.

int main() {
    printf("Hello, World!\n");
    printf("PI: %f\n", PI);
    printf("Square of 5: %d\n", SQUARE(5));
    printf("Sum 1: %d\n", SUM_1(5));
    printf("Complex Function: %d\n", COMPLEX_FUNC(10, 5));
    return 0;
}