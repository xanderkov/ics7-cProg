#include "defines.h"


void equate_words(char a[], char b[], int *n)
{
    for (int i = 0; i < *n; i++)
        a[i] = b[i];
    a[*n] = '\0';
    *n = 0;
}


int is_delim(char c, char *delim)
{
    while (*delim != '\0')
    {
        if (c == *delim)
            return TRUE;
        delim++;
    }
    return FALSE;
}


void return_to_original(char *word)
{
    for (int j = 0; j < WORD_LEN; j++)
        word[j] = ' ';
}


int split_line(char *s, char (*words)[WORD_LEN + 1], int *n)
{
    int i = 0, point = 0;
    char word[WORD_LEN] = { ' ' };
    char delim[] = { ' ', '\n', '\t', '\r', '\0' };
    while (s[i] != '\0')
    {
        if (is_delim(s[i], delim) == FALSE)
        {
            word[point++] = s[i];
            if (point > WORD_LEN)
                return WORD_NUM;
        }
        else
        {
            if (word[0] != ' ' && word[0] != '\n' && word[0] != '\0')
            {
                equate_words(words[(*n)++], word, &point);
                return_to_original(word);
            }
        }
        i++;
    }
    if (word[0] != ' ')
        equate_words(words[(*n)++], word, &point);
    if (*n == 0)
        return NO_WORD;
    return OK;
}
