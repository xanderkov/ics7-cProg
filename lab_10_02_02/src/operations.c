#include "defines.h"
#include "io.h"

void solve_equation(equation *eq, int n, int a, int *sol)
{
    for (int i = 0; i < n - 1; i++)
    {
        *sol += eq->coef;
        *sol *= a;
        eq = eq->next;
    }
    *sol += eq->coef;
}

void find_derivative(equation *eq, int n, equation **deq)
{
    for (int i = 0; i < n - 1; i++)
    {
        equation *node = NULL;
        node = create(eq->coef * (n - i - 1));
        *deq = append(*deq, node);
        eq = eq->next;
    }
}


void add_equations(equation *eq, equation *eq2, equation **sol, int n1, int n2)
{
    int n = 0;
    equation *node = NULL;
    if (n1 < n2)
    {
        n = n1;
        for (;n1 < n2; n1++)
        {
            node = create(eq2->coef);
            *sol = append(*sol, node);
            eq2 = eq2->next;
        }
    }
    else if (n2 < n1)
    {
        n = n2;
        for (;n2 < n1; n2++)
        {
            node = create(eq->coef);
            *sol = append(*sol, node);
            eq = eq->next;
        }
    }
    else
        n = n2;
    for (int i = 0; i < n; i++)
    {
        node = create(eq->coef + eq2->coef);
        *sol = append(*sol, node);
        eq = eq->next;
        eq2 = eq2->next;
    }
}

void split_eqution(equation *eq, equation **even, equation **odd, int n)
{
    int n_even = n / 2;
    equation *node = NULL;
    for (int i = 0; i < n_even; i++)
    {
        node = create(eq->coef);
        *odd = append(*odd, node);
        eq = eq->next;
        node = create(eq->coef);
        *even = append(*even, node);
        eq = eq->next;
    }
    if (eq)
    {
        node = create(eq->coef);
        *even = append(*even, node);
    }
}