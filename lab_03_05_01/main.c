#include <stdio.h>
#include <math.h>
#define N 10
#define M 10
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define ERR_SIZE -3
#define NOT_PRIME -4
#define OK 0


int input(int (*arr)[M], int *n, int *m)
{
    *n = 0;
    *m = 0;
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


int is_sum_up_ten(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum > 10;
}


int module(int x)
{
    if (x < 0)
        x *= -1;
    return x;
}


int search_upper_ten_numbers(int (*matrix)[M], int n, int m, int *arr, int *num)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (is_sum_up_ten(module(matrix[i][j])))
            {
                arr[*num] = matrix[i][j];
                *num += 1;
            }
        }
    }
    if (*num == 0)
        return ERR_SIZE;
    return OK;
}


void shift(int *arr, int n)
{
    for (int i = 0; i < 3; i++)
    {
        int t = arr[0];
        for (int j = 0; j <= n; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = t;
    }
}


void insert_in_matrix(int (*matrix)[M], int *arr, int n, int m)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (is_sum_up_ten(module(matrix[i][j])))
                matrix[i][j] = arr[k++];
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
    int matrix[N][M] = { { 0 } }, n, m, rc, arr[N*M] = { 0 }, num = 0;
    rc = input(matrix, &n, &m);
    if (rc == OK)
    {
        rc = search_upper_ten_numbers(matrix, n, m, arr, &num);
        if (rc == ERR_SIZE)
            return ERR_SIZE;
        shift(arr, num);
        insert_in_matrix(matrix, arr, n, m);
        output(matrix, n, m);
    }
    return rc;
}
