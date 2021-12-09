#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "file_operations.h"
#define OK 0
#define NO_FILE -1
#define NO_INFO -2
#define NO_SEQUENCE -3
#define BAD_POS -4


int fill_file_by_rand(FILE *f, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = rand();
        fwrite(&x, 1, sizeof(x), f);
    }
    return OK;
}


int print_file(FILE *f)
{
    int x = 0;
    while (fread(&x, sizeof(x), 1, f) == 1)
        printf("%d ", x);
    return NO_INFO;
}


int get_number_by_pos(FILE *f, int pos)
{
    int x = 0;
    rewind(f);
    fseek(f, (pos - 1) * sizeof (int), SEEK_SET);
    fread(&x, 1, sizeof(x), f);
    rewind(f);
    return x;
}


int put_number_by_pos(FILE *f, int pos, int number)
{
    fseek(f, (pos - 1) * sizeof (int), SEEK_SET);
    fwrite(&number, 1, sizeof(number), f);
    rewind(f);
    return pos;
}


int sort_file(FILE *f)
{
    int x = 0, pos = 1, minimum = -1, iter = 1, min_pos = -1, number = 0, n = 0;
    while (fread(&x, sizeof(x), 1, f) == 1)
        n++;
    rewind(f);
    while (fread(&x, sizeof(x), 1, f) == 1 && iter < n)
    {
        minimum = get_number_by_pos(f, n);
        min_pos = n;
        while (fread(&x, sizeof(x), 1, f) == 1)
        {
            if (minimum > x && pos >= iter)
            {
                minimum = x;
                min_pos = pos;
            }
            pos++;
        }
        number = get_number_by_pos(f, iter);
        put_number_by_pos(f, iter, minimum);
        put_number_by_pos(f, min_pos, number);
        iter++;
        pos = 1;
        rewind(f);
    }

    return OK;
}


