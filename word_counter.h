#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10000

typedef struct word_counter
{
    char phrase[N];
    char buffer[100];
    char *word;
    int total_words_specific;
    int total_words;
    char answer[3];
} Counter;

int is_word(char character);
void introduction(Counter *c);
void original_phrase(Counter *c);
void selected_word(Counter *c);
void selected_word_counter(Counter *c);
void total_words(Counter *c);
void print(Counter *c);