#include <stdio.h>
#define N 10
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define OK 0


int output(double mean)
{
    printf("%lf", mean);
    return 0;
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


double calcarifmeticmean(int *arr, int n)
{
    double mean = 0;
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            mean += arr[i];
            size ++;
        }
    }
    if (size > 0)
        return mean / size;
    return INPUT_NUMBER;
}


int main()
{
    int arr[N] = { 0 }, n, error;
    double mean;
    error = input(arr, &n);
    if (error == OK)
    {
        mean = calcarifmeticmean(arr, n);
        if (mean == INPUT_NUMBER)
        {   
            printf("Input Error");
            return INPUT_NUMBER;
        }
        output(mean);
    }  
    return error;
}
