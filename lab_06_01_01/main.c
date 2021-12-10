#include "struct.h"
#include "file_operations.h"


int main(int argc, char **argv)
{
    FILE *f = NULL;
    int rc = NOT_OK, n = 0;
    films film[FILE_LEN];
    if (argc > 2 && argc < 5)
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
            rc = NULL_FILE; 
        else if (strcmp(argv[2], "title\0") != 0 && strcmp(argv[2], "name\0") != 0 && strcmp(argv[2], "year\0") != 0)
            rc = WRONG_FIELD;
        else
            rc = read_file_from_struct(f, film, &n, argv[2]);
        if (rc == OK)
        {
            if (argc > 3)
            {
                rc = search_film(film, n, argv[2], argv[3]);
                if (rc != NOT_YEAR)
                {
                    print_struct(film, rc);
                    rc = OK;
                }
            }
            else
            {
                print_struct_field(film, n);
            }
            fclose(f);
        }
    }
    return rc;
}