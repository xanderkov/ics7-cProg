#include <stdio.h>
#include <stddef.h>
#define OK 0
#define NO_FILE -1
#define NO_INFO -2
#define NO_SEQUENCE -3


int process(FILE *f, int *value)
{
    int n = 0, first = -1, second = -1, maximum = 0;
    if (fscanf(f, "%d", &first) == 1)
    {
        while (fscanf(f, "%d", &second) == 1)
        {
            if (first < 0 && second > maximum)
                maximum = second;
            first = second;
            n++;
        }
        if (n == 0)
            return NO_SEQUENCE;
    }
    else
        return NO_INFO;
    if (maximum == 0)
        return NO_SEQUENCE;
    *value = maximum;
    return OK;
}
