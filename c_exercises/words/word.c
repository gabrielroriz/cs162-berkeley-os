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

void add_word(
    // list data
    struct Word **tail, 
    struct Word **head,
    // word data
    char *value, 
    unsigned int position, 
    ptrdiff_t length)
{
    // allocate memory for the new word
    struct Word *new_word = malloc(sizeof(struct Word));

    // check if memory allocation was successful
    if(new_word == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // link the new word to the list
    if (*tail != NULL)
    {
        (*tail)->next = new_word;
    }
    else
    // first word
    {
        *head = new_word;
    }

    // set the new word values
    new_word->value = value;
    new_word->position = position;
    new_word->length = length;
    new_word->next = NULL;

    // add as the last word
    *tail = new_word;
}