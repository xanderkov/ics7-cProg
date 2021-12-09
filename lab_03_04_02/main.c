#include <stdio.h>
#include <math.h>
#define N 10
#define M 10
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define SEARCH_ERR -3
#define NUMBER 5
#define OK 0


int input(int (*arr)[M], int *n, int *m)
{
    int rc = scanf("%d%d", n, m);
    if (rc != 2)
        return INPUT_NUMBER;
    if (*n > 10 || *n <= 0 || *m > 10 || *m <= 0 || *n != *m)
        return INPUT_SIZE;
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            rc = scanf("%d", &arr[i][j]);
            if (rc != 1)
                return INPUT_NUMBER;
        }
    }
    return OK;
}


int module(int x)
{
    if (x < 0)
        x *= -1;
    return x;
}


int search_maximum_number(int (*matrix)[M], int n)
{
    int maximum = -1;
    for (int i = 0; i < n; i++)
        for (int j = n - i;  j < n; j++)
            if (module(matrix[i][j]) % 10 == 5)
                if (matrix[i][j] > maximum || maximum == -1)
                    maximum = matrix[i][j];
    if (maximum == -1)
        return SEARCH_ERR;
    return maximum;
}


int output(int maximum)
{
    printf("%d", maximum);
    return OK;
}



int main()
{
    int matrix[N][M] = { { 0 } }, n, rc, m, maximum = 0;
    rc = input(matrix, &n, &m);
    if (rc == OK)
    {
        maximum = search_maximum_number(matrix, n);
        if (maximum == SEARCH_ERR)
            return maximum;
        output(maximum);
    }
    return rc;
}
