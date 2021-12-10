#include "defines.h"
#include "io.h"
#include "matrix_operations.h"

bool compare_matrixes(double **m1, double **m2, int n, int m)
{
    bool rc = true;
    for (int i = 0; i < n && rc; i++)
        for (int j = 0; j < m && rc; j++)
            if (fabs(m1[i][j] - m2[i][j]) > EPS)
                rc = false;
    return rc;
}

int test_1_mult()
{
    int rc = OK;
    double **mtr_1 = create_matrix(2, 2);
    double **mtr_2 = create_matrix(2, 2);
    mtr_1[0][0] = 1;
    mtr_1[0][1] = 1;
    mtr_1[1][0] = 2;
    mtr_1[1][1] = 2;
    mtr_2[0][0] = 1;
    mtr_2[0][1] = 1;
    mtr_2[1][0] = 2;
    mtr_2[1][1] = 2;
    double **res_check = create_matrix(2, 2);
    res_check[0][0] = 3;
    res_check[0][1] = 3;
    res_check[1][0] = 6;
    res_check[1][1] = 6;
    double **res_mtr = create_matrix(2, 2);
    multiply_matrix(mtr_1, mtr_2, res_mtr, 2, 2, 2);
    if (compare_matrixes(res_check, res_mtr, 2, 2))
        rc = OK;
    else
        rc = -1;
    free_matrix(mtr_1);
    free_matrix(mtr_2);
    free_matrix(res_check);
    free_matrix(res_mtr);
    return rc;
}

int test_1_add()
{
    int rc = OK;
    double **mtr_1 = create_matrix(2, 2);
    double **mtr_2 = create_matrix(2, 2);
    mtr_1[0][0] = 1;
    mtr_1[0][1] = 1;
    mtr_1[1][0] = 2;
    mtr_1[1][1] = 2;
    mtr_2[0][0] = 1;
    mtr_2[0][1] = 1;
    mtr_2[1][0] = 2;
    mtr_2[1][1] = 2;
    double **res_check = create_matrix(2, 2);
    res_check[0][0] = 2;
    res_check[0][1] = 2;
    res_check[1][0] = 4;
    res_check[1][1] = 4;
    double **res_mtr = create_matrix(2, 2);
    add_matrix(mtr_1, mtr_2, res_mtr, 2, 2);
    if (compare_matrixes(res_check, res_mtr, 2, 2))
        rc = OK;
    else
        rc = -1;
    free_matrix(mtr_1);
    free_matrix(mtr_2);
    free_matrix(res_check);
    free_matrix(res_mtr);
    return rc;
}


int test_1_slae()
{
    int rc = OK;
    double **mtr_1 = create_matrix(3, 4);
    mtr_1[0][0] = 1;
    mtr_1[0][1] = 2;
    mtr_1[0][2] = 3;
    mtr_1[0][3] = 4;
    mtr_1[1][0] = 5;
    mtr_1[1][1] = 6;
    mtr_1[1][2] = 7;
    mtr_1[1][3] = 8;
    mtr_1[2][0] = 9;
    mtr_1[2][1] = 1;
    mtr_1[2][2] = 2;
    mtr_1[2][3] = 3;
    double **res_mtr = create_matrix(3, 1);
    double **res_check = create_matrix(3, 1);
    res_check[0][0] = 0;
    res_check[1][0] = -1;
    res_check[1][0] = 2;
    solve_slae(mtr_1, res_mtr, 3);
    if (compare_matrixes(res_check, res_mtr, 3, 1))
        rc = OK;
    free_matrix(mtr_1);
    free_matrix(res_check);
    free_matrix(res_mtr);
    return rc;
}

int test_2_slae()
{
    int rc = OK;
    double **mtr_1 = create_matrix(2, 3);
    mtr_1[0][0] = 1;
    mtr_1[0][1] = 0;
    mtr_1[0][2] = 1;
    mtr_1[1][0] = 0;
    mtr_1[1][1] = 1;
    mtr_1[1][2] = 2;
    double **res_mtr = create_matrix(2, 1);
    double **res_check = create_matrix(2, 1);
    res_check[0][0] = 1;
    res_check[1][0] = 2;
    solve_slae(mtr_1, res_mtr, 2);
    if (compare_matrixes(res_check, res_mtr, 2, 1))
        rc = OK;
    free_matrix(mtr_1);
    free_matrix(res_check);
    free_matrix(res_mtr);
    return rc;
}


int main()
{
    test_1_add();
    test_1_slae();
    test_1_mult();
    test_2_slae();
    return OK;
}