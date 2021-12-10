#include "defines.h"
#include "io.h"
#include "matrix_operations.h"


int main(int argc, char **argv)
{
    int rc = WRONG_ARG, n = 0, m = 0, n_1 = 0, m_1 = 0;
    FILE *f_mtr_1 = NULL, *f_res = NULL;
    double **mtr_1 = NULL, **res_mtr = NULL, **mtr_2 = NULL;
    if (argc == 5)
    {
        FILE *f_mtr_2 = NULL;
        f_mtr_1 = fopen(argv[2], "r");
        if (f_mtr_1 != NULL)
        {
            f_mtr_2 = fopen(argv[3], "r");
            if (f_mtr_2 != NULL)
            {
                int n_2 = 0, m_2 = 0;
                rc = init_matrix(f_mtr_1, &mtr_1, &n_1, &m_1);
                if (!rc)
                {
                    rc = init_matrix(f_mtr_2, &mtr_2, &n_2, &m_2);
                    if (!rc)
                    {
                        if (strcmp(argv[1], "a") == 0 && n_1 == n_2 && m_1 == m_2)
                        {
                            n = n_1;
                            m = m_1;
                            res_mtr = create_matrix(n, m);
                            if (res_mtr != NULL)
                                add_matrix(mtr_1, mtr_2, res_mtr, n, m);
                            else
                                rc = NULL_POINTER;
                        }
                        else if (strcmp(argv[1], "m") == 0 && m_1 == n_2)
                        {
                            res_mtr = create_matrix(n_1, m_2);
                            if (res_mtr != NULL)
                                multiply_matrix(mtr_1, mtr_2, res_mtr, n_1, m_2, m_1);
                            else
                                rc = NULL_POINTER;
                            n = n_1;
                            m = m_2;
                        }
                        else
                            rc = WRONG_ARG;
                        if (!rc)
                        {
                            f_res = fopen(argv[4], "w");
                            if (f_res != NULL)
                            {
                                print_matrix(f_res, res_mtr, n, m);    
                                fclose(f_res);
                            }
                            else
                                rc = NULL_FILE;
                            free_matrix(res_mtr);
                        }
                        free_matrix(mtr_2);
                    }
                    free_matrix(mtr_1); 
                }
                fclose(f_mtr_2);
            }
            else
                rc = NULL_FILE;
            fclose(f_mtr_1);
        }
        else
            rc = NULL_FILE;
    }
    else if (argc == 4 && strcmp(argv[2], argv[3]) != 0)
    {
        f_mtr_1 = fopen(argv[2], "r");
        if (f_mtr_1)
        {
            rc = init_matrix(f_mtr_1, &mtr_1, &n_1, &m_1);
            if (!rc)
            {
                if (strcmp(argv[1], "o") == 0 && n_1 + 1 == m_1)
                {
                    n = n_1;
                    m = 1;
                    res_mtr = create_matrix(n, m);
                    if (res_mtr != NULL)
                    {
                        rc = solve_slae(mtr_1, res_mtr, n);
                        if (rc)
                            free_matrix(res_mtr);
                    }
                    else 
                        rc = NULL_POINTER;
                }
                else
                    rc = WRONG_ARG;
                if (!rc)
                {
                    f_res = fopen(argv[3], "w");
                    if (f_res != NULL)
                    {
                        print_matrix(f_res, res_mtr, n, m);
                        fclose(f_res);    
                    }
                    else
                        rc = NULL_FILE;
                    free_matrix(res_mtr);
                }
                free_matrix(mtr_1);
            }
            fclose(f_mtr_1);
        }
        else
            rc = NULL_FILE;
    }
    else
        rc = WRONG_ARG;
    return rc;
}
