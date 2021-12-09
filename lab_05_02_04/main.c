#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "procces.h"
#define OK 0
#define NO_FILE -1
#define NO_INFO -2
#define NO_SEQUENCE -3
#define TOO_MANY_FILES -4


int main(int argc, char **argv)
{
    if (argc != 2)
        return TOO_MANY_FILES;
    FILE *f;
    double value = 0;
    int place_min = 0, place_max = 0;
    f = fopen(argv[1], "r");
    int rc = find_places_min_max(f, &place_min, &place_max);
    if (rc == OK)
    {
        rewind(f);
        rc = get_value_between(f, place_min, place_max, &value);
        fprintf(stdout, "%lf", value);
    }
    fclose(f);
    return rc;
}
