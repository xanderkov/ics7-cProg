#include <stdio.h>
#include <math.h>
#define N 10
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define OK 0


int power(long long int base, int n)
{
    long long int res = 1;

    while (n > 0)
    {
        res *= base;
        n = n - 1;
    }

    return res;
}


int calcarmstrong(int x)
{
    int size = 1, arm = 0, p = 0;
    while (size < x)
    {
        size *= 10;
        p++;
    }
    size = x;
    while (x > 0)
    {
        arm += power(x % 10, p);
        x /= 10;
    }
    return arm == size;
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


int create_calc_amstrong_array(int *arr, int n, int *size, int *m)
{
    for (int i = 0; i < n; i++)
        if (calcarmstrong(arr[i]))
            m[(*size)++] = arr[i];
    if (*size > 0)
        return OK;
    return INPUT_NUMBER;
}


int main()
{
    int arr[N] = { 0 }, n, error, m[N] = { 0 }, size = 0;
    error = input(arr, &n);
    if (error == OK)
    {
        error = create_calc_amstrong_array(arr, n, &size, m);
        if (error == INPUT_NUMBER)
            return INPUT_NUMBER;
        output(m, size);
    }
    return error;
}
