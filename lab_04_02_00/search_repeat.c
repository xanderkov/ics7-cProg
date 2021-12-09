#include "split_line.h"
#include <stddef.h>
#define TRUE 1
#define FALSE -1
#define STR_LEN 256
#define N 256


int compare_str(char a[], char b[])
{
    int i = 0;
    do
    {
        if (a[i] != b[i])
            return FALSE;
    } while (a[++i] != '\0');
    if (b[i] == '\0')
        return TRUE;
    return FALSE;
}


int equate(char a[], char b[])
{
    int i = 0;
    while (a[i] != '\0')
    {
        b[i] = a[i];
        i++;
    }
    return i;
}


int search_repeat(char (*splited_str)[STR_LEN], char (*words)[STR_LEN], int *arr, int n)
{
    arr[0] = 1;
    int j = 0;
    j = equate(splited_str[0], words[0]);
    words[0][j] = '\0';
    int point = 1;
    for (int i = 1; i < n; i++)
    {
        int flag = TRUE;
        for (j = 0; j < point; j++)
        {
            if (compare_str(words[j], splited_str[i]) == TRUE)
            {
                arr[j]++;
                flag = FALSE;
                break;
            }
        }
        if (flag == TRUE)
        {
            j = 0;
            j = equate(splited_str[i], words[point]);
            if (j > 0)
            {
                words[point][j] = '\0';
                arr[point++] = 1;
            }
        }
    }
    return point;
}
