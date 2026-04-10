#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "word.h"

void print_frequency(struct InitialCharBucket *bucket)
{
    while (bucket != NULL)
    {
        printf("'%c': %zu word(s)\n", bucket->initial, bucket->n_distinct);
        struct WordCounter *counter = bucket->head;
        while (counter != NULL)
        {
            printf("  - %.*s (freq: %u)\n", (int)counter->length, counter->value, counter->frequency);
            counter = counter->next;
        }
        bucket = bucket->next;
    }
}

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

void add_word_frequency(
    struct InitialCharBucket **buckets,
    char *value,
    ptrdiff_t length)
{
    // lowercase the first character for bucket lookup/creation
    char current_initial = tolower(value[0]);

    // walk the bucket list to find a matching initial, tracking the last node for insertion
    struct InitialCharBucket *bucket = NULL;
    struct InitialCharBucket *last_bucket = NULL;

    if (*buckets != NULL)
    {
        struct InitialCharBucket *it = *buckets;
        while (it != NULL)
        {
            if (it->initial == current_initial)
            {
                bucket = it;
                break;
            }
            last_bucket = it;
            it = it->next;
        }
    }

    // no bucket found: allocate a new one and append it to the list
    if (bucket == NULL)
    {
        bucket = malloc(sizeof(struct InitialCharBucket));
        if (bucket == NULL)
        {
            fprintf(stderr, "Memory allocation failed for bucket\n");
            exit(1);
        }
        bucket->initial = current_initial;
        bucket->head = NULL;
        bucket->tail = NULL;
        bucket->next = NULL;
        bucket->n_distinct = 0;

        // link into the list
        if (last_bucket != NULL)
            last_bucket->next = bucket;
        else
            *buckets = bucket;
    }

    // check if the word already exists in the bucket (case-insensitive)
    struct WordCounter *counter = bucket->head;
    while (counter != NULL)
    {
        if (counter->length == length &&
            strncasecmp(counter->value, value, (size_t)length) == 0)
        {
            // word found: increment its frequency counter
            counter->frequency++;
            return;
        }
        counter = counter->next;
    }

    // word not found: allocate a new entry and append it to the bucket
    counter = malloc(sizeof(struct WordCounter));
    if (counter == NULL)
    {
        fprintf(stderr, "Memory allocation failed for word counter\n");
        exit(1);
    }
    counter->value = value;
    counter->length = length;
    counter->frequency = 1;
    counter->next = NULL;

    // link into the bucket's word list
    if (bucket->tail != NULL)
        bucket->tail->next = counter;
    else
        bucket->head = counter;

    bucket->tail = counter;
    bucket->n_distinct++;
}

void add_word(
    struct Word **tail,
    struct Word **head,
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