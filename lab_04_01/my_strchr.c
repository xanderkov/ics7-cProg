#include "my_strchr.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#define STR_LEN 80
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define OK 0


char *my_strchr(char *s, int c)
{
    do
    if (*s == (char)c)
        return s;
    while (*s++);
    return 0;
}