#include <stdio.h>
#include <math.h>
#include <string.h>
#include "input_line.h"
#include "my_strchr.h"
#define STR_LEN 80
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define ERR_FUNC -3
#define OK 0


int main()
{
    int n;
    char s1[STR_LEN + 1], s2[STR_LEN + 1], *k;
    n = read_line(s1);
    if (n > 0)
    {
        k = strchr(s1, ' ');
        k = my_strchr(s2, ' ');
        if (s1 != s2)
            return ERR_FUNC;
        printf(k);
        return OK;
    }
    return n;
}
