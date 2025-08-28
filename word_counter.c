#include "word_counter.h"

int is_word(char character)
{
    int is_word = 0;
    if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z'))
    {
        is_word = 1;
    }
    return is_word;
}

void introduction(Counter *c)
{
    printf(" ======//This is a Word Counter//====== \n");
    printf("Do you want to count a specific word? (y/n) \n");
    fgets(c->answer, sizeof(c->answer), stdin);
    c->answer[strcspn(c->answer, "\n")] = '\0';
    printf("\n");
}

void original_phrase(Counter *c)
{
    FILE *file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf("Error!\n");
        exit(1);
    }

    c->phrase[0] = '\0';
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file))
    {
        strcat(c->phrase, buffer);
    }

    fclose(file);
}

void selected_word(Counter *c)
{
    printf("Which word you want to count? (plese, write one word) \n");
    fgets(c->buffer, sizeof(c->buffer), stdin);
    printf("\n");

    c->buffer[strcspn(c->buffer, "\n")] = '\0';

    int size = strlen(c->buffer) + 1;
    c->word = (char *)malloc(size * sizeof(char));

    if (c->word == NULL)
    {
        printf("Error!");
    }

    strcpy(c->word, c->buffer);
}

void selected_word_counter(Counter *c)
{
    int i, j;
    c->total_words_specific = 0;
    int len_phrase = strlen(c->phrase);
    int len_word = strlen(c->word);

    for (i = 0; i <= len_phrase - len_word; i++)
    {
        int find_word = 1;

        for (j = 0; j < len_word; j++)
        {
            if (c->phrase[i + j] != c->word[j])
            {
                find_word = 0;
                break;
            }
        }

        if (find_word)
        {
            int before;
            int after;
            if (i == 0)
            {
                before = 0;
            }
            else
            {
                before = is_word(c->phrase[i - 1]);
            }

            if (i + len_word >= len_phrase)
            {
                after = 0;
            }
            else
            {
                after = is_word(c->phrase[i + len_word]);
            }

            if (!(before && after))
                c->total_words_specific++;
        }
    }
}

void total_words(Counter *c)
{
    int i;
    int in_word = 0;
    c->total_words = 0;

    for (i = 0; c->phrase[i] != '\0'; i++)
    {
        if (is_word(c->phrase[i]))
        {
            if (!in_word)
            {
                c->total_words++;
                in_word = 1;
            }
        }
        else
        {
            in_word = 0;
        }
    }
}

void print(Counter *c)
{
    if (c->answer[0] == 'y')
    {
        printf("This phrase have %d words, and %d are %s.", c->total_words, c->total_words_specific, c->word);
    }
    else
    {
        printf("This phrase have %d words.", c->total_words);
    }
}