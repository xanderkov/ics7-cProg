#include <stdio.h>
#define N 10
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define NUMBER_ERROR 100
#define OK 0


int insertion_sort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return OK;
}


int output(int *arr, int *n)
{
    for (int i = 0; i < *n; i++)
        printf("%d\n", arr[i]);
    return OK;
}


int input(int *arr)
{
    int rc = 0, i = 0;
    while (i < N)
    {
        rc = scanf("%d", &arr[i++]);
        if (rc != 1)
            return i - 1;
    }
    if (scanf("%d", &rc) == 1)
        return NUMBER_ERROR;
    else
        return i;
}


int main()
{
    int arr[N] = { 0 }, n, error;
    error = input(arr);
    n = error;
    if (error == 0)
        return INPUT_NUMBER;
    if (error == NUMBER_ERROR)
    {
        n = N;
        insertion_sort(arr, n);
        output(arr, &n);
        return NUMBER_ERROR;
    }
    insertion_sort(arr, n);
    output(arr, &n);
    return 0;
}
