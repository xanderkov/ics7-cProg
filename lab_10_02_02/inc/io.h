#include "defines.h"

int input_equation(int *n, equation **eq);
void print_equation(equation *eq);
int input_type(int *type);
void free_list(equation **eq);
equation *append(equation *head, equation *node);
equation *create(int x);