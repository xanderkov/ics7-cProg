#include <stdio.h>
#include <math.h>
#define N 10
#define M 10
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define OK 0


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


void form_matrix(int (*matrix)[M], int n, int m)
{
    int k = 1;
    for (int i = 0; i < m - 1; i += 2)
    {
        for (int j = 0; j < n; j++)
            matrix[j][i] = k++;
        for (int j = n - 1; j > -1; j--)
        {
            matrix[j][i + 1] = k++;
        }
    }
    if (m % 2 != 0)
        for (int j = 0; j < n; j++)
            matrix[j][m - 1] = k++;
}


int input(int *n, int *m)
{
    int rc = scanf("%d%d", n, m);
    if (rc != 2)
        return INPUT_NUMBER;
    if ((*n > 10 || *n < 1) || (*m > 10 || *m < 1))
        return INPUT_SIZE;
    return OK;
}


int main()
{
    int matrix[N][M] = { { 0 } }, n, m, rc;
    rc = input(&n, &m);
    if (rc == OK)
    {
        form_matrix(matrix, n, m);
        output(matrix, n, m);
    }
    return rc;
}
