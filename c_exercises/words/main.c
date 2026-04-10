#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>

#include "word.h"

int main(int argc, char *argv[])
{
    // check if the user provided an argument
    if (argc < 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    // get the content from the command line argument
    char *content = argv[1];
    size_t content_len = strlen(content);

    // list of words
    struct Word *head = NULL;

    // auxiliar variables
    struct Word *tail = NULL;

    // word data
    char *word_value = NULL;
    unsigned int word_position = 0;

    for (size_t i = 0; i <= content_len; i++)
    {
        // get the current character
        char current_char = content[i];

        if (IS_SEPARATOR(current_char))
        // is space or end of string
        {
            if (word_value != NULL)
            {
                // calculate the length of the new word
                char *last_word_character = &content[i] - 1;
                ptrdiff_t word_length = (last_word_character - word_value) + 1;

                // add the new word to the list
                add_word(&tail, &head, word_value, word_position, word_length);
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
    print_words(head);
    return 0;
}