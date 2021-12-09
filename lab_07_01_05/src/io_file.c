#include "../inc/defines.h"


void read_array(FILE *f, int *arr, int n)
{
    rewind(f);
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", arr);
        arr++;
    }
}

int get_count(FILE *f)
{
    int dummy, n = 0;
    while (fscanf(f, "%d", &dummy) == 1)
        n++;
    return n;
}


int read_file(char *file_name, int **arr, int *n)
{
    FILE *f = NULL;
    int rc = OK, *p = NULL;
    f = fopen(file_name, "r");
    if (f == NULL)
        rc = NULL_FILE;
    if (rc == OK)
    {
        *n = get_count(f);
        if (feof(f) && *n)
            p = malloc(*n * sizeof(int));
        else
            rc = NULL_ARR;
    }
    if (rc == OK)
    {
        read_array(f, p, *n);
        *arr = p;
        fclose(f);
    }
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