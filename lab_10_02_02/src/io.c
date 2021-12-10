#include "defines.h"


void free_list(equation **eq)
{
    equation *next;
    for (; *eq; *eq = next)
    {
        next = (*eq)->next;
        free(*eq);
    }
}


equation *create(int x)
{
    equation *node = malloc(sizeof(equation));
    if (node)
    {
        node->coef = x;
        node->next = NULL;
    }
    return node;
}

equation *append(equation *head, equation *node)
{
    if (!head)
        return node;
    equation *cur = head;
    for (; cur->next; cur = cur->next);
    cur->next = node;
    return head;
}

int input_equation(int *n, equation **eq)
{
    int rc = OK, x = 0, i = 0;
    if (scanf("%d", n) != 1 || *n <= 0)
        rc = WRONG_ARG;
    if (!rc)
    {
        for (i = 0; i < *n && !rc; i++)
        {
            if (scanf("%d", &x) == 1)
            {
                equation *node = NULL;
                node = create(x);
                *eq = append(*eq, node);
            }
            else
                rc = ERR_READ;
        }
        if (rc)
            free_list(eq);
    }
    return rc;
}


void print_equation(equation *eq)
{
    equation *p = eq;
    for (; p->next; p = p->next)
        printf("%d ", p->coef);
    printf("%d ", p->coef);
    printf("L\n");
}


int input_type(int *type)
{
    int rc = OK;
    char name[STR_LEN];
    if (scanf("%s", name) == 1)
    {
        if (!strcmp(name, "val"))
            *type = VAL;
        else if (!strcmp(name, "ddx"))
            *type = DDX;
        else if (!strcmp(name, "sum"))
            *type = SUM;
        else if (!strcmp(name, "dvd"))
            *type = DVD;
        else
            rc = WRONG_ARG;
    }
    return rc;
}


