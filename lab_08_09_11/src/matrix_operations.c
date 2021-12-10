#include "defines.h"


void add_matrix(double **mtr_1, double **mtr_2, double **res_mtr, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res_mtr[i][j] = mtr_1[i][j] + mtr_2[i][j];
}


void multiply_matrix(double **mtr_1, double **mtr_2, double **res_mtr, int n, int m, int mn)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            res_mtr[i][j] = 0;
            for (int k = 0; k < mn; k++)
                res_mtr[i][j] += mtr_1[i][k] * mtr_2[k][j];
        }
}


void find_slae_solution(double **mtr_1, double **res_mtr, int n)
{
    double elem = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        res_mtr[i][0] = 0;
        elem = mtr_1[i][n];
        for (int j = n - 1; j > i; j--) 
            elem -= mtr_1[i][j] * res_mtr[j][0];
        res_mtr[i][0] = elem;
    }
}

void swap(double **mtr, int i, int j, int max_index)
{
    double elem = mtr[i][j];
    mtr[i][j] = mtr[max_index][j];
    mtr[max_index][j] = elem;
}

void swap_str_with_max_element(double **mtr, int i, int max_index, int n)
{
    if (i != max_index)
        for (int j = i; j < n + 1; j++)
            swap(mtr, i, j, max_index);
}

int transform_max_str(double **mtr, int i, int n)
{
    double max_elem = mtr[i][i];
    if (fabs(max_elem - 0) < EPS)
        return NULL_SOLUTION;
    mtr[i][i] = 1;   
    for (int j = i + 1; j < n + 1; j++) 
        mtr[i][j] /= max_elem;
    return OK;
}


void transform_all_str(double **mtr, int i, int n)
{
    for (int j = i + 1; j < n; j++)
    {
        double elem = mtr[j][i];
        mtr[j][i] = 0;
        if (elem != 0)
            for (int k = i + 1; k < n + 1; k++)
                mtr[j][k] -= elem * mtr[i][k];
    }
}

int solve_slae(double **mtr, double **res_mtr, int n)
{
    double max_elem = 0;
    int rc = OK;
    for (int i = 0; i < n && rc == OK; i++)
    {
        max_elem = fabs(mtr[i][i]);
        int max_index = i;
        for (int j = 0; j < n && rc == OK; j++)
        {
            if (fabs(mtr[j][i]) > max_elem)
            {
                max_index = j;
                max_elem = fabs(mtr[j][i]);
            }
            if (fabs(max_elem - 0) < EPS)
                rc = NULL_SOLUTION;
            swap_str_with_max_element(mtr, i, max_index, n);
            rc = transform_max_str(mtr, i, n);
            if (rc)
                rc = NULL_SOLUTION;
            transform_all_str(mtr, i, n);
        }
    }
    if (!rc)
        find_slae_solution(mtr, res_mtr, n);
    return rc;
}