#include <stdlib.h>
#include <stdio.h>
#include "word.h"

void print_words(struct Word *word)
{
    while (word != NULL)
    {
        // %.*s is used to print a string with a specified length,
        // where the length is provided as an argument before the string itself.
        printf("(%d) %.*s\n", word->position + 1, (int)word->length, word->value);
        word = word->next;
    }
}