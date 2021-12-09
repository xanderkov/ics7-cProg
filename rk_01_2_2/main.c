#include <stdio.h>
#include <math.h>
#define N 100


int input(int *arr, int *n)
{
    if (scanf("%d", n) == 1)
    if (*n < 0 || *n > 100)
        return - 1;
    for (int i = 0; i < *n; i++)
        if (scanf("%d", &arr[i]) != 1)
                return -1;
    return 0;
}


int delete_element(int *arr, int *n, int k)
{
    int i = k;
    while (i < *n - 1)
    {
        arr[i] = arr[i + 1];
        i += 1;
    }
    *n -= 1;
    return 0;
}

int search_posl(int *arr, int *n)
{
    int i = 1;
    while (i < *n)
    {
        if (arr[i - 1] >= arr[i])
            delete_element(arr, n, i);
        i ++;

    }
    return 0;
}


int output(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

int main()
{
    int arr[N] = { 0 }, n;
    input(arr, &n);
    search_posl(arr, &n);
    output(arr, n);
    return 0;
}
