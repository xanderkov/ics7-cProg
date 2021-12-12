#include "defines.h"


int read_array(char *str, int *arr, int n)
{
    if (!str && n > 0) 
        return ERR_READ;
    char *p = str;
    int i = 0;
    
    while (*p && i < n)
    {
        if (isdigit(*p) || ((*p == '-' || *p == '+') && isdigit(*(p+1))))
            arr[i++] = strtol(p, &p, 10);
        else
            p++;
    }
    return OK;
}

int get_count(char *str)
{
    char *p = str;
    int n = 0;
    while (*p)
    {
        if (isdigit(*p) || ((*p == '-' || *p == '+') && isdigit(*(p+1))))
        {
            strtol(p, &p, 10);
            n++;
        }
        else
            p++;
    }
    return n;
}


int read_line(char *str, int *arr, int *n)
{
    int rc = OK;
    if (!str)
        rc = NULL_FILE;
    if (!rc)
        *n = get_count(str);
    if (!rc)
        read_array(str, arr, *n);
    return rc;
}


void print_array(char *file_name, int *arr, int *end)
{
    FILE *f = NULL;
    f = fopen(file_name, "w");
    for (int *i = arr; i < end; i++)
        fprintf(f, "%d ", *i);
    fprintf(f, "\n");
    fclose(f);
}