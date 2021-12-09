#include <stdio.h>
#include <math.h>
#define N 10
#define M 10
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define OK 0


int input(int (*arr)[M], int *n, int *m)
{
    int rc = scanf("%d%d", n, m);
    if (rc != 2)
        return INPUT_NUMBER;
    if ((*n > 10 || *n < 1) || (*m > 10 || *m < 1))
        return INPUT_SIZE;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            rc = scanf("%d", &arr[i][j]);
            if (rc != 1)
                return INPUT_NUMBER;
        }
    }
    return OK;
}


int calc_mult_numbers(int (*matrix)[M], int n, int m, int *arr)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = 1;
        for (int j = 0; j < m; j++)
        {
            arr[i] *= matrix[i][j];
        }
    }
    return OK;
}


void repose(int arr1[], int arr2[], int n)
{
    int m[M] = { 0 };
    for (int i = 0; i < n; i++)
        m[i] = arr1[i];
    for (int i = 0; i < n; i++)
        arr1[i] = arr2[i];
    for (int i = 0; i < n; i++)
        arr2[i] = m[i];
}


void sort(int (*matrix)[M], int a[], int n, int m)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                repose(matrix[j], matrix[j + 1], m);
            }
        }
    }
}


int output(int (*matrix)[M], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return OK;
}



int main()
{
    int matrix[N][M] = { { 0 } }, n, m, rc, arr[N] = { 0 };
    rc = input(matrix, &n, &m);
    if (rc == OK)
    {
        calc_mult_numbers(matrix, n, m, arr);
        sort(matrix, arr, n, m);
        output(matrix, n, m);
    }
    return rc;
}
