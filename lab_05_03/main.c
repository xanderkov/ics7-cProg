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


int main(int argc, char **argv)
{
    FILE *f = NULL;
    int rc = OK;
    char *str = "";
    int number = 0;
    if (argc > 2)
    {
        if (argv[1][0] == 'c' && argc == 4)
        {
            number = strtol(argv[2], &str, 0);
            f = fopen(argv[3], "wb");
            fill_file_by_rand(f, number);
            fclose(f);
        }
        else if (argv[1][0] == 'c' && argc != 4)
            return NO_FILE;
        else if (argv[1][0] == 'p' && argc == 3)
        {
            f = fopen(argv[2], "rb");
            if (file_size(f) == NO_FILE)
            {
                return NO_FILE;
            }
            rewind(f);
            print_file(f);
            fclose(f);
        }
        else if (argv[1][0] == 'p' && argc != 3)
            return NO_FILE;
        else if (argv[1][0] == 's' && argc == 3)
        {
            f = fopen(argv[2], "rb+");
            if (file_size(f) == NO_FILE)
            {
                return NO_FILE;
            }
            rewind(f);
            sort_file(f);
            fclose(f);
        }
        else if (argv[1][0] == 's' && argc != 3)
            return NO_FILE;
        else
            return NO_FILE;
    }
    else
        rc = NO_INFO;

    return rc;
}
