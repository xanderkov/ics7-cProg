#include "../inc/defines.h"
#include "../inc/io_file.h"
#include "../inc/sort_array.h"


int main(int argc, char **argv)
{
    int rc = WRONG_ARG, *arr, n = 0, *new_arr, *new_end;
    
    if (argc > 2 && argc < 5)
    {
        rc = read_file(argv[1], &arr, &n);
        if (rc == OK)
        {
            if (argc == 4)
            {
                rc = key(arr, arr + n, &new_arr, &new_end);
                if (rc == OK)
                {
                    mysort(new_arr, new_end - new_arr, sizeof(int), compare_ints);
                    print_array(argv[2], new_arr, new_end);
                    free(new_arr);
                    new_arr = NULL;
                    new_end = NULL;
                    rc = OK;
                }
            }
            else
            {
                mysort(arr, n, sizeof(int), compare_ints);
                print_array(argv[2], arr, arr + n);
                rc = OK;
            }
            free(arr);
            arr = NULL;
        }
    }
    return rc;
}