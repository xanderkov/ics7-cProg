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


int main()
{
    char s[STR_LEN + 3] = { ' ' }, splited_str[N][STR_LEN] = { { ' ' } }, words[N][STR_LEN] = { { ' ' } };
    int arr[N] = { 0 }, n = 0, k = 0, rc = OK;
    fgets(s, sizeof(s), stdin);
    if (input_str(s) != OK)
        return INPUT_SIZE;
    rc = split_line(s, splited_str, &n);
    if (rc == OK)
    {
        k = search_repeat(splited_str, words, arr, n);
        output_results(words, arr, k);
    }
    return rc;
}
