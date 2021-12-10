#include "defines.h"
#include "io.h"
#include "operations.h"


int compare_lists(equation *a, equation *b)
{
    for (; a->next && b->next; a = a->next, b = b->next)
        if (a->coef != b->coef)
            return ERR;
    return OK;
}


int solve_equation_test1()
{
    equation *eq = NULL, *node = NULL;
    int n = 3, sol = 0, a = 2, sol_ch = 7, rc = ERR_READ;
    node = create(1);
    eq = append(eq, node);
    node = create(1);
    eq = append(eq, node);
    node = create(1);
    eq = append(eq, node);
    solve_equation(eq, n, a, &sol);
    if (sol == sol_ch)
        rc = OK;
    free_list(&eq);
    return rc;
}

int find_derivative_test1()
{
    equation *eq = NULL, *node = NULL, *deq_ch = NULL, *deq = NULL;
    int n = 3, rc = ERR_READ;
    node = create(1);
    eq = append(eq, node);
    node = create(1);
    eq = append(eq, node);
    node = create(1);
    eq = append(eq, node);
    node = create(2);
    deq_ch = append(deq_ch, node);
    node = create(1);
    deq_ch = append(deq_ch, node);
    find_derivative(eq, n, &deq);
    if (!compare_lists(deq, deq_ch))
        rc = OK;
    free_list(&deq);
    free_list(&deq_ch);
    free_list(&eq);
    return rc;
}

int add_equations_test_1()
{
    equation *a = NULL, *node = NULL, *eq_ch = NULL, *b = NULL, *eq = NULL;
    int n = 3, rc = ERR_READ;
    node = create(1);
    a = append(a, node);
    node = create(1);
    a = append(a, node);
    node = create(1);
    a = append(a, node);
    node = create(1);
    b = append(b, node);
    node = create(1);
    b = append(b, node);
    node = create(1);
    b = append(b, node);
    node = create(2);
    eq_ch = append(eq_ch, node);
    node = create(2);
    eq_ch = append(eq_ch, node);
    node = create(2);
    eq_ch = append(eq_ch, node);
    add_equations(a, b, &eq, n, n);
    if (!compare_lists(eq, eq_ch))
        rc = OK;
    free_list(&eq);
    free_list(&eq_ch);
    free_list(&a);
    free_list(&b);
    return rc;
}


int split_eqation_test_1()
{
    equation *eq = NULL, *node = NULL, *a_ch = NULL, *a = NULL, *b_ch = NULL, *b = NULL;
    int n = 3, rc = ERR_READ;
    node = create(1);
    eq = append(eq, node);
    node = create(1);
    eq = append(eq, node);
    node = create(1);
    eq = append(eq, node);
    node = create(1);
    a_ch = append(a_ch, node);
    node = create(1);
    b_ch = append(b_ch, node);
    node = create(1);
    b_ch = append(b_ch, node);
    split_eqution(eq, &a, &b, n);
    if (!compare_lists(a, a_ch) && !compare_lists(b, b_ch))
        rc = OK;
    free_list(&eq);
    free_list(&a_ch);
    free_list(&a);
    free_list(&b);
    free_list(&b_ch);
    return rc;
}

int main()
{
    int err = OK;
    err += find_derivative_test1();
    err += solve_equation_test1();
    err += add_equations_test_1();
    err += split_eqation_test_1();
    if (err != OK)
        printf("%d", err);
    return err;
}