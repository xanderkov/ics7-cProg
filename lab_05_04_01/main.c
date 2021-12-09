#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "file_operations.h"
#include "file_existence.h"
#define N 259
#define OK 0
#define NO_FILE -1
#define NO_INFO -2
#define NO_SEQUENCE -3
#define TOO_MANY_FILES -4
#define PARAM_ERROR 53


int main(int argc, char **argv)
{
    FILE *f = NULL, *out = NULL;
    int rc = OK;
    char substr[N] = { ' ' };
    if (argc > 2 && strlen(argv[1]) > 1)
    {
        if (argv[1][0] == 's' && argv[1][1] == 't' && argc == 3)
        {
            f = fopen(argv[2], "r");
            if (file_size(f) == NO_FILE)
                return NO_FILE;
            rewind(f);
            rc = sort_students(f);
            fclose(f);
        }
        else if (argv[1][0] == 's' && argv[1][1] == 't' && argc != 3)
            return PARAM_ERROR;
        else if (argv[1][0] == 'f' && argv[1][1] == 't' && argc == 5)
        {
            f = fopen(argv[2], "r");
            out = fopen(argv[3], "w");
            if (file_size(f) == NO_FILE)
                return NO_FILE;
            copy_str(argv[4], substr);
            rewind(f);
            rc = print_students(f, out, substr);
            fclose(f);
            fclose(out);
        }
        else if (argv[1][0] == 'f' && argv[1][1] == 't' && argc != 5)
            return PARAM_ERROR;
        else if (argv[1][0] == 'd' && argv[1][1] == 't' && argc == 3)
        {
            f = fopen(argv[2], "r");
            if (file_size(f) == NO_FILE)
                return NO_FILE;
            rewind(f);
            rc = delete_students(f, argv[2]);
            fclose(f);
        }
        else if (argv[1][0] == 'd' && argv[1][1] == 't' && argc != 3)
            return PARAM_ERROR;
        else
            return PARAM_ERROR;
    }
    else
        return PARAM_ERROR;
    return rc;
}
