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
    long sz = 0;
    if (f == NULL)
        return NO_FILE;
    if (fseek(f, 0, SEEK_END))
        return NO_FILE;
    sz = ftell(f);
    if (sz <= 0)
        return NO_FILE;
    rewind(f);
    return OK;
}
