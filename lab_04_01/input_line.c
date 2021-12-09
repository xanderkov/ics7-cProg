#include "input_line.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#define STR_LEN 80
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define OK 0


int read_line(char *s)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < STR_LEN)
            s[i++] = ch;
        else
            return INPUT_SIZE;

    s[i] = '\0';

    return i;
}