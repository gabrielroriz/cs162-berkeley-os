#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include<ctype.h>

#include "word.c"


void add_word(
    // list information
    struct Word **last_word, 
    struct Word **words,
    // word information
    char *word_value, 
    unsigned int word_position, 
    ptrdiff_t word_length)
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
    if (*last_word != NULL)
    {
        (*last_word)->next = new_word;
    }
    else
    // first word
    {
        *words = new_word;
    }

    // set the new word values
    new_word->value = word_value;
    new_word->position = word_position++;
    new_word->length = word_length;
    new_word->next = NULL;

    // add as the last word
    *last_word = new_word;
}

int main(int argc, char *argv[])
{
    // check if the user provided an argument
    if (argc < 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *content = argv[1];
    size_t content_len = strlen(content);

    struct Word *words = NULL;

    // auxiliar variables
    struct Word *last_word = NULL;
    char *word_value = NULL;
    int word_position = 0;

    for (size_t i = 0; i <= content_len; i++)
    {
        char current_char = content[i];

        // is space?
        if (IS_SEPARATOR(current_char))
        {
            if (word_value != NULL)
            {
                // calculate the length of the new word
                char *last_word_character = &content[i] - 1;
                ptrdiff_t word_length = (last_word_character - word_value) + 1;

                // add the new word to the list
                add_word(&last_word, &words, word_value, word_position, word_length);
                word_position++;

                // reset the first character of the next word
                word_value = NULL;
            }
        }
        else
        // is not space, start of a new word
        {
            if (word_value == NULL)
            {
                word_value = &content[i];
            }
        }
    }

    printf("Words found:\n");
    print_words(words);
    return 0;
}