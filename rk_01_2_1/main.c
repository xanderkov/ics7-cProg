#include <stdio.h>
#include <math.h>


int input(int *x)
{
    if (scanf("%d", x) == 1)
        if (*x > 0)
            return 0;
    return -1;
}


int search_min(int x, int *min)
{
    int minimum = x % 10;
    while (x > 9)
    {
        x /= 10;
        if (x % 10 < minimum)
            minimum = x % 10;
    }
    *min = minimum;
    return 0;
}

int search_max(int x, int *max)
{
    int maximum = x % 10;
    while (x > 9)
    {
        x /= 10;
        if (x % 10 > maximum)
            maximum = x % 10;
    }
    *max = maximum;
    return 0;
}

int output(int x)
{
    printf("%d", x);
    return 0;
}

int main()
{
    int x, min, max;
    input(&x);
    search_min(x, &min);
    search_max(x, &max);
    output(max - min);
    return 0;
}
