#include <stdlib.h>
#include <stdio.h>
#include "word.h"

void print_words(struct Word *word)
{
    while (word != NULL)
    {
        // %.*s is used to print a string with a specified length,
        // where the length is provided as an argument before the string itself.
        char *value = malloc(word->length + 1);
        snprintf(value, word->length + 1, "%.*s", (int)word->length, word->value);

        // convert the word to lowercase (char by char)
        for (int i = 0; i < word->length; i++) {
            value[i] = tolower(value[i]);
        }

        // print the word position and value
        printf("(%d) %s\n", word->position + 1, value);

        // free the allocated memory for the word value
        free(value);
        
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