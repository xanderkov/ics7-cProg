#include "defines.h"


void free_matrix(double **mtr)
{
    free(mtr[0]);
    free(mtr);
    mtr = NULL;
}


double **create_matrix(int n, int m)
{
    double **ptrs = NULL, *data = NULL;
    ptrs = malloc(n * sizeof(double*));
    if (!ptrs)
        return NULL;
    data = malloc(n * m * sizeof(double));
    if (!data)
    {
        free(ptrs);
        return NULL;
    }
    for (int i = 0; i < n; i++)
        ptrs[i] = data + i * m;
    return ptrs;
}


int read_matrix(FILE *f, double **mtr, int n, int m)
{
    int rc = OK;
    double tmp = 0;
    for (int i = 0; i < n && rc == OK; i++)
        for (int j = 0; j < m && rc == OK; j++)
        {
            if (fscanf(f, "%lf", &tmp) != 1)
                rc = ERR_ARR;
            else
                mtr[i][j] = tmp;
        }
    if (fscanf(f, "%lf", &tmp) != EOF)
        rc = NULL_FILE;
    if (rc)
        free_matrix(mtr);
    return rc;
}


int init_matrix(FILE *f, double ***mtr, int *n, int *m)
{
    int rc = OK;
    if (fscanf(f, "%d%d", n, m) != 2 || *n <= 0 || *m <= 0)
        rc = ERR_ARR;
    if (!rc)
    {
        *mtr = create_matrix(*n, *m);
        if (*mtr)
            rc = read_matrix(f, *mtr, *n, *m);
        else
            rc = NULL_POINTER;
    }
    return rc;
}


void print_matrix(FILE *f, double **res_mtr, int n, int m)
{
    fprintf(f, "%d %d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            fprintf(f, "%lf ", res_mtr[i][j]);
        fprintf(f, "\n");
    }
}
