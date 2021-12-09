#include <stdio.h>
#include <math.h>
#define N 10
#define M 10
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define OK 0


int output(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    return OK;
}


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


int operate(int (*matrix)[M], int n, int m, int *arr)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 1;
        for (int j = 0; j < m / 2; j++)
        {
            if (matrix[i][j] != matrix[i][m - j - 1])
                flag = 0;
        }
        arr[i] = flag;
    }
    return OK;
}


int main()
{
    int matrix[N][M] = { { 0 } }, n, m, rc, arr[N] = { 0 };
    rc = input(matrix, &n, &m);
    if (rc == OK)
    {
        operate(matrix, n, m, arr);
        output(arr, n);
    }
    return rc;
}
