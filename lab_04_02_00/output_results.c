#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string.h>
#include <stddef.h>
#include "split_line.h"
#include "search_repeat.h"
#include "output_results.h"
#define STR_LEN 256
#define N 256
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define OK 0


int input_str(char *s)
{
    int i = 0;
    if (s[i] == '\n')
        return INPUT_NUMBER;
    while (s[i] != '\0')
        i++;
    if (i > STR_LEN + 1)
       return INPUT_SIZE;
   return OK;
}

int output_results(char (*words)[STR_LEN], int *arr, int k)
{
    printf("%s", "Result: ");
    for (int i = 0; i < k; i++)
        printf("%s %d\n", words[i], arr[i]);
    return 0;
}
