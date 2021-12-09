#include "defines.h"


int input_str(char *s)
{
    int i = 0;
    if (s[i] == '\n')
        return INPUT_NUMBER;
    while (s[i] != '\0')
        i++;
    if (i > N + 1)
       return INPUT_SIZE;
   return OK;
}


void my_memcpy(char *line, char *new_line)
{
    int len = 0;
    while (line[len] != '\0')
        len++;
    for (int i = 0; i <= len; i++)
        new_line[i] = line[i];
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


void delete(char *s, int pos)
{
    int i = pos;
    while (s[i] != '\0')
    {
        s[i] = s[i + 1];
        i++;
    }
}


int compare_str(char a[], char b[])
{
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] != b[i])
            return FALSE;
        i++;
    }
    if (b[i] == '\0')
        return TRUE;
    return FALSE;
}


void delete_repeats(char *s)
{
    int i = 0, num = 1;
    char arr[N] = { ' ' };
    arr[0] = s[i++];
    while (s[i] != '\0')
    {
        int flag = 1;
        for (int j = 0; j < num; j++)
            if (arr[j] == s[i])
            {
                delete(s, i);
                flag = 0;
            }
        if (flag == 1)
        {
            arr[num++] = s[i];
            i++;
        }
    }
}


void reverse(char (*a)[WORD_LEN + 1], int n, char *s)
{
    char str[2] = { ' ', '\0' };
    for (int i = n - 2; i >= 0; i--)
        if (compare_str(a[n - 1], a[i]) == FALSE)
        {
            delete_repeats(a[i]);
            strcat(s, str);
            strcat(s, a[i]);
        }
}
