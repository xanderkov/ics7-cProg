#include "defines.h"


int create_array(int **pb_dst, int **pe_dst, int n)
{
    int rc = OK;
    *pb_dst = malloc(n * sizeof(int));
    *pe_dst = *pb_dst + n;
    if (*pb_dst == NULL || *pe_dst == NULL || pb_dst == NULL || pe_dst == NULL)
        rc = NULL_ARR;
    return rc;
}

void add_in_array(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst)
{
    int sum = *(pe_src - 1);
    for (const int *i = pe_src - 2; i >= pb_src; i--)
    {
        if (*i > sum)
        {
            *(pe_dst-- - 1) = *i;
        }
        sum += *i;
    }
}

ARR_DLL int ARR_DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int rc = OK;
    if (pe_src == NULL || pb_src == NULL || pe_src <= pb_src || pb_dst == NULL || pe_dst == NULL)
        rc = NULL_ARR;
    int n = 0;
    if (!rc)
    {
        int sum = *(pe_src - 1);
        for (const int *i = pe_src - 2; i >= pb_src; i--)
        {
            if (*i > sum)
            {
                n++;
            }
            sum += *i;
        }
        if (n == 0)
            rc = NULL_ARR;
    }
    if (!rc)
    {
        rc = create_array(&(*pb_dst), &(*pe_dst), n);
        if (!rc)
        {
            add_in_array(pb_src, pe_src, *pb_dst, *pe_dst);
            rc = OK;
        }
    }
    return rc;
}

ARR_DLL int ARR_DECL compare_ints(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}


void swap(char *a, char *b, size_t size)
{
    char c;
    for (int i = 0; i < size; i++)
    {
        c = *a;
        *a++ = *b;
        *b++ = c;
    }
}


ARR_DLL int ARR_DECL mysort(void *base, size_t n, size_t size, int (*compare)(const void*, const void*))
{
    char *end = (char*)base + n * size, *j;
    for (char *i = (char*)base + size; i < end; i += size)
    {
        j = i;
        while (j > (char*)base && compare(j - size, j) > 0)
        {
            swap(j - size, j, size);
            j -= size;
        }
    }
    return OK;
}