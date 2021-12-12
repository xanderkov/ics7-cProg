#include "defines.h"
#include "io.h"


void move_array(int *arr, int n, int k)
{
    k %= n;
    int *new_arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (i < k) 
            new_arr[i] = arr[n + i - k];
        else
            new_arr[i] = arr[i - k];
    }
    for (int i = 0; i < n; i++)
        arr[i] = new_arr[i];
    free(new_arr);
}

int check_on_square(int x)
{
    if (x < 0) 
        return NOT_SQUARE;
    int square = 0;
    while (square * square < x)
        square += 1;
    if (square * square != x)
        square = NOT_SQUARE;
    return square;    
}

int get_count_of_squares(int *arr, int n)
{
    int new_n = 0;
    for (int i = 0; i < n; i++)
        if (check_on_square(arr[i]) >= 0)
            new_n += 1;
    return new_n;
}

void place_in_array_squares(int *arr, int n, int *sqr, int new_n)
{
    int number = 0;
    for (int i = 0; i < n; i++)
        if (check_on_square(arr[i]) >= 0)
            sqr[number++] = arr[i];
}