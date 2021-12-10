#include "defines.h"

void solve_equation(equation *eq, int n, int a, int *sol);
void find_derivative(equation *eq, int n, equation **deq);
void add_equations(equation *eq, equation *eq2, equation **sol, int n, int n2);
void split_eqution(equation *eq, equation **even, equation **odd, int n); 
