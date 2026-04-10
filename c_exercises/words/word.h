// Header guard: prevents this file from being included more than once
// in the same translation unit, avoiding redefinition errors.
#ifndef WORD_H
#define WORD_H

#include <stddef.h>

struct InitialCharBucket
{
    char initial;
    struct WordCounter *head;
    struct WordCounter *tail;
    struct InitialCharBucket *next;
    size_t n_distinct;
};
struct WordCounter
{
    char *value;
    ptrdiff_t length;
    struct WordCounter *next;
    unsigned int frequency;
};

struct Word
{
    char *value;
    unsigned int position;
    ptrdiff_t length;
    struct Word *next;
};

void print_words(struct Word *word);
void print_frequency(struct InitialCharBucket *bucket);
void add_word_frequency(struct InitialCharBucket **buckets, char *value, ptrdiff_t length);

void add_word(
    struct Word **tail,
    struct Word **head,
    char *value,
    unsigned int position,
    ptrdiff_t length);

#define IS_SEPARATOR(c) ((c) == ' ' || (c) == '\n' || (c) == '\t' || (c) == '\r' || (c) == '\0')

#endif /* WORD_H */