#include <stdio.h>
#include <math.h>
#define N 10
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define OK 0


int is_palindrom(int n)
{
    int res = 0; int tmp = n;
    do
    {
        res = res * 10 + tmp % 10;
        tmp /= 10;
    } while (tmp != 0);
    return res == n;
}


int output(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    return OK;
}


int input(int *arr, int *n)
{
    int rc = scanf("%d", n);
    if (rc != 1)
        return INPUT_NUMBER;
    if (*n > 10 || *n < 1)
        return INPUT_SIZE;
    for (int i = 0; i < *n; i++)
    {
        rc = scanf("%d", &arr[i]);
        if (rc != 1)
            return INPUT_NUMBER;
    }
    return OK;
}


int delete_element(int *arr, int *n, int i)
{
    for (int k = i; k < *n; k++)
        arr[k] = arr[k + 1];
    *n -= 1;
    return OK;
}


int delete_palindrom(int *arr, int *n)
{
    int i = *n - 1;
    while (i >= 0)
    {
        if (is_palindrom(arr[i]))
            delete_element(arr, n, i);
        i--;
    }
    if (*n > 0)
        return OK;
    return INPUT_NUMBER;
}


int main()
{
    int arr[N] = { 0 }, n, error;
    error = input(arr, &n);
    if (error == OK)
    {
        error = delete_palindrom(arr, &n);
        if (error == INPUT_NUMBER)
            return INPUT_NUMBER;
        output(arr, n);
    }
    return error;
}
