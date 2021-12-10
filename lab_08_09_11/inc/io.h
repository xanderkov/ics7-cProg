#ifndef _READ_

#define _READ_
#include "defines.h"

int init_matrix(FILE *f, double ***mtr, int *n, int *m);
void print_matrix(FILE *f_res, double **res_mtr, int n, int m);
int free_matrix(double **mtr);
double **create_matrix(int n, int m);

#endif