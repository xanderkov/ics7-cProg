#include <stdio.h>
#include <math.h>
#define N 10
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define OK 0


int output(int x)
{
    printf("%d\n", x);
    return OK;
}


int input(int *begin, int *end)
{
    int n;
    int rc = scanf("%d", &n);
    if (rc != 1)
        return INPUT_NUMBER;
    if (n > 10 || n < 1)
        return INPUT_SIZE;
    for (int i = 0; i < n; i++)
    {
        rc = scanf("%d", begin + i);
        if (rc != 1)
            return INPUT_NUMBER;
    }
    *end = n - 1;
    return OK;
}


int find_max(int *end, int *arr)
{
    int maximum = *arr + *end;
    while (arr <= end)
    {
        if (*arr + *end > maximum)
            maximum = *arr + *end;
        arr++;
        end--;
    }
    return maximum;
}


int main()
{
    int arr[N] = { 0 }, end, error, maximum;
    error = input(arr, &end);
    if (error == OK)
    {
        maximum = find_max(arr + end, arr);
        output(maximum);
    }
    return error;
}
