#include "defines.h"


void my_memcpy(char *line, char *new_line)
{
    int len = 0;
    while (line[len] != '\0')
        len++;
    for (int i = 0; i <= len; i++)
        new_line[i] = line[i];
}


void input_in_mounths(char (*mounths)[WORD_LEN])
{
    my_memcpy("january", mounths[0]);
    my_memcpy("february", mounths[1]);
    my_memcpy("march", mounths[2]);
    my_memcpy("april", mounths[3]);
    my_memcpy("may", mounths[4]);
    my_memcpy("june", mounths[5]);
    my_memcpy("july", mounths[6]);
    my_memcpy("august", mounths[7]);
    my_memcpy("september", mounths[8]);
    my_memcpy("october", mounths[9]);
    my_memcpy("november", mounths[10]);
    my_memcpy("december", mounths[11]);
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


void is_slower(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        s[i] = tolower(s[i]);
        i++;
    }
}


int check_mounth(char *s)
{
    char mounths[N + 3][WORD_LEN];

    input_in_mounths(mounths);
    for (int i = 0; i < 12; i++)
        if (compare_str(mounths[i], s) == TRUE)
            return TRUE;
    return FALSE;
}

int is_number(char *s)
{
    char nums[11] = "0123456789";

    int i = 0, j = 0;
    while (s[j] != '\0')
    {
        int flag = FALSE;
        i = 0;
        while (i < 10 && flag == FALSE)
        {
            if (s[j] == nums[i])
                flag = TRUE;
            i++;
        }
        if (flag == FALSE)
            return FALSE;
        j++;
    }
    return TRUE;
}


int check_all(char (*words)[WORD_LEN + 1])
{
    char mounths[N + 3][WORD_LEN], *ptr;
    input_in_mounths(mounths);
    is_slower(words[1]);
    if (is_number(words[0]) == TRUE && check_mounth(words[1]) == TRUE && is_number(words[2]) == TRUE)
    {
        long day, year;
        day = strtol(words[0], &ptr, 0);
        year = strtol(words[2], &ptr, 0);
        if (year > 9999 && year < 0 && day < 0)
            return NOT_DATE;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 == 0))
        {
            if (compare_str(words[1], mounths[1]) == TRUE && day <= 29)
                return OK;
        }
        else
        {
            if (compare_str(words[1], mounths[1]) == TRUE && day <= 28)
                return OK;
        }
        for (int i = 0; i < 7; i += 2)
            if (compare_str(words[1], mounths[i]) == TRUE && day <= 31)
                return OK;
        for (int i = 7; i < 12; i += 2)
            if (compare_str(words[1], mounths[i]) == TRUE && day <= 31)
                return OK;
        for (int i = 3; i < 7; i += 2)
            if (compare_str(words[1], mounths[i]) == TRUE && day <= 30)
                return OK;
        for (int i = 8; i < 11; i += 2)
            if (compare_str(words[1], mounths[i]) == TRUE && day <= 30)
                return OK;
    }
    return NOT_DATE;
}
