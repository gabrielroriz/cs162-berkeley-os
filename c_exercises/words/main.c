#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "word.c"

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
    char *addr_first_c_nword = NULL;
    int word_position = 0;

    for (size_t i = 0; i <= content_len; i++)
    {
        char current_char = content[i];

        // is space?
        if (IS_SEPARATOR(current_char))
        {
            if (addr_first_c_nword != NULL)
            {
                // calculate the length of the new word
                char *addr_last_c_nword = &content[i] - 1;
                ptrdiff_t len = (addr_last_c_nword - addr_first_c_nword) + 1;

                struct Word *new_word = malloc(sizeof(struct Word));

                if(new_word == NULL)
                {
                    fprintf(stderr, "Memory allocation failed\n");
                    return 1;
                }

                // link the new word to the list
                if (last_word != NULL)
                {
                    last_word->next = new_word;
                }
                else
                {
                    // first word
                    words = new_word;
                }

                // set the new word values
                new_word->value = addr_first_c_nword;
                new_word->position = word_position++;
                new_word->length = len;
                new_word->next = NULL;

                // new last word
                last_word = new_word;

                addr_first_c_nword = NULL;
            }
        }
        else
        {
            if (addr_first_c_nword == NULL)
            {
                addr_first_c_nword = &content[i];
            }
        }
    }

    print_words(words);
    return 0;
}