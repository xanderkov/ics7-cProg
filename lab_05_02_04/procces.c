#include <stdio.h>
#include <stddef.h>
#define OK 0
#define NO_FILE -1
#define NO_INFO -2
#define NO_SEQUENCE -3
#define BAD_POS -4


int find_places_min_max(FILE *f, int *place_min, int *place_max)
{
    double minimum = -1, maximum = 0, x = 0;
    int n = 0;
    if (fscanf(f, "%lf%lf", &minimum, &maximum) == 2)
    {
        *place_min = 1;
        *place_max = 2;
        if (maximum < minimum)
        {
            x = minimum;
            minimum = maximum;
            maximum = x;
        }
        while (fscanf(f, "%lf", &x) == 1)
        {
            n++;
            if (x > maximum)
            {
                *place_max = n + 2;
                maximum = x;
            }
            if (x < minimum)
            {
                *place_min = n + 2;
                minimum = x;
            }
        }
        if (n == 0)
            return NO_SEQUENCE;
    }
    else
        return NO_INFO;   
    if (*place_max < *place_min)
    {
        n = *place_min;
        *place_min = *place_max;
        *place_max = n;
    }
    return OK;
}


int get_value_between(FILE *f, int place_min, int place_max, double *value)
{
    int n = 0;
    double x = 0, summa = 0, num = 0;
    while (fscanf(f, "%lf", &x) == 1)
    {
        n++;
        if (n > place_min && n < place_max)
        {
            summa += x;
            num++;
        }
    }
    *value = summa / num;
    return OK;
}
