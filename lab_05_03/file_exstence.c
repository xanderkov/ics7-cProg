#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "file_operations.h"
#include "file_existence.h"
#define OK 0
#define NO_FILE -1
#define NO_INFO -2
#define NO_SEQUENCE -3
#define TOO_MANY_FILES -4


int file_size(FILE *f)
{
    long sz = 0, int_sz = 0;
    if (f == NULL)
        return NO_FILE;
    if (fseek(f, 0L, SEEK_END))
        return NO_FILE;
    sz = ftell(f);
    if (sz <= 0 || sz % sizeof(int) != 0)
    {
        fclose(f);
        return NO_FILE;
    }
    rewind(f);
    int x = 0;
    while (fread(&x, sizeof(x), 1, f) == 1)
        int_sz += sizeof (int);
    if (int_sz != sz)
    {
        fclose(f);
        return NO_INFO;
    }
    return OK;
}
