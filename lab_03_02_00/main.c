#include <stdio.h>
#include <math.h>
#define N 10
#define M 10
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define OK 0


int output(int (*matrix)[M], int n, int m, int *flag)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
        if (flag[i] == 100)
        {
            printf("\n");
            for (int k = 0; k < m; k++)
                printf("%d ", flag[i]);
        }
        printf("\n");
    }
    return OK;
}


int input(int (*arr)[M], int *n, int *m, int *number)
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
    rc = scanf("%d", number);
    if (rc != 1)
        return INPUT_NUMBER;
    if (*number < 0 || *number > 9)
        return INPUT_NUMBER;
    return OK;
}


int search_first_number(int x)
{
    while (x > 9)
        x /= 10;
    return x;
}


int module(int x)
{
    if (x < 0)
        x *= -1;
    return x;
}


int operate(int (*matrix)[M], int n, int m, int number, int *flag)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int f = 0;
        for (int j = 0; j < m; j++)
        {
            if (search_first_number(module(matrix[i][j])) == number)
            {
                sum++;
                f = 1;
            }
            if (module(matrix[i][j]) % 10 == number)
                sum--;
        }
        if (sum == 0 && f == 1)
            flag[i] = 100;
        else
            flag[i] = 0;
    }
    return OK;
}


int main()
{
    int matrix[N][M] = { { 0 } }, n, m, rc, number, flag[N] = { 0 };
    rc = input(matrix, &n, &m, &number);
    if (rc == OK)
    {
        operate(matrix, n, m, number, flag);
        output(matrix, n, m, flag);
    }
    return rc;
}
