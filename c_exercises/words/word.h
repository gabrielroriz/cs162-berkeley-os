// Header guard: prevents this file from being included more than once
// in the same translation unit, avoiding redefinition errors.
#ifndef WORD_H
#define WORD_H

#include <stddef.h>

struct WordFrequency
{
    char *word;
    unsigned int frequency;
    struct WordFrequency *next;
};

struct Word
{
    char *value;
    unsigned int position;
    ptrdiff_t length;
    struct Word *next;
};

void print_words(struct Word *word);

void add_word(
    struct Word **tail, 
    struct Word **head,
    char *value, 
    unsigned int position,
    ptrdiff_t length);

#define IS_SEPARATOR(c) ((c) == ' ' || (c) == '\n' || (c) == '\t' || (c) == '\r' || (c) == '\0')

#endif /* WORD_H */