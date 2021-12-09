#include "split_line.h"
#include <stddef.h>
#define TRUE 1
#define FALSE -1
#define WORD 16
#define STR_LEN 256
#define N 256
#define OUT_OF_WORD -2
#define NO_WORD -3
#define OK 0


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


int split_line(char *s, char (*words)[STR_LEN], int *n)
{
    int i = 0, point = 0;
    char word[STR_LEN] = { ' ' };
    char delim[] = { ' ', ',', ';', ':', '-', '.', '!', '?', '\n', '\0' };
    while (s[i] != '\0')
    {
        if (is_delim(s[i], delim) == FALSE)
        {
            word[point++] = s[i];
            if (point > WORD)
                return OUT_OF_WORD;
        }
        else
        {
            if (word[0] != ' ' && word[0] != '\n' && word[0] != '\0')
            {
                equate_words(words[(*n)++], word, &point);
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
