#ifndef _OPERATIONS_

#define _OPERATIONS_
#include "defines.h"

void add_matrix(double **mtr_1, double **mtr_2, double **res_mtr, int n, int m);
void multiply_matrix(double **mtr_1, double **mtr_2, double **res_mtr, int n, int m, int mn);
int solve_slae(double **mtr_1, double **res_mtr, int n);

#endif