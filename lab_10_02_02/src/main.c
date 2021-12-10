#include "defines.h"
#include "io.h"
#include "operations.h"


int main()
{
    int rc = OK, type = -1, n = 0, a = 0, solution = 0, n2 = 0;
    equation *eq = NULL, *deq = NULL, *eq2 = NULL, *sol = NULL, *even = NULL, *odd = NULL;
    rc = input_type(&type);
    switch (type)
    {
        case VAL:
            rc = input_equation(&n, &eq);
            if (!rc && scanf("%d", &a) == 1)
            {
                solve_equation(eq, n, a, &solution);
                printf("%d", solution);
                free_list(&eq);
            }
            break;
        case DDX:
            rc = input_equation(&n, &eq);
            if (!rc)
            {
                find_derivative(eq, n, &deq);
                print_equation(deq);
                free_list(&deq);
                free_list(&eq);
            }
            break;
        case SUM:
            rc = input_equation(&n, &eq);
            if (!rc)
            {
                rc = input_equation(&n2, &eq2);
                if (!rc)
                {
                    add_equations(eq, eq2, &sol, n, n2);
                    print_equation(sol);
                    free_list(&sol);
                    free_list(&eq2);
                }
                free_list(&eq);
            }
            break;
        case DVD:
            rc = input_equation(&n, &eq);
            if (!rc)
            {
                split_eqution(eq, &even, &odd, n);
                free_list(&eq);
                print_equation(even);
                print_equation(odd);
                free_list(&even);
                free_list(&odd);
            }
            break;
        default:
            rc = WRONG_ARG;
            break;
    }
    return rc;
}
