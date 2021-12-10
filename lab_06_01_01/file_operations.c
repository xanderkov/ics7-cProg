#include "struct.h"
#include "functions.h"


void swap_struct(films *f1, films *f2)
{
    films c = *f1;
    *f1 = *f2;
    *f2 = c;
}


int give_index(char *field, films film, char *key)
{
    int rc = OK;
    if (strcmp(field, "title\0") == 0)
        strcpy(key, film.title);
    else if (strcmp(field, "name\0") == 0)
        strcpy(key, film.name);
    else if (strcmp(field, "year\0") == 0)
        strcpy(key, film.year);
    return rc;
}


int check_equality(char *f1, char *f2, char *field)
{
    int eq = 0;
    if (strcmp(field, "year\0") == 0)
    {
        char *ptr;
        eq = strtol(f1, &ptr, 0) - strtol(f2, &ptr, 0);
    }
    else
        eq = strcmp(f1, f2);
    return eq;
}

int compare_fields(films *film, char *field, int j)
{
    char films_field_1[STR_LEN] = { ' ' }, films_field_2[STR_LEN] = { ' ' };
    give_index(field, film[j], films_field_1);
    give_index(field, film[j + 1], films_field_2);
    return check_equality(films_field_1, films_field_2, field);
}


int binary_search(films *film, char *field, char *key, int l, int r)
{
    int rc = NOT_FOUND;
    if (r >= l && rc == NOT_FOUND)
    {
        int mid = l + (r - l) / 2;
        char film_field[STR_LEN] = { ' ' };
        give_index(field, film[mid], film_field);
        int eq = check_equality(film_field, key, field);
        if (eq == 0)
            rc = mid;
        if (eq > 0)
            return binary_search(film, field, key, l, mid - 1);
        if (rc == NOT_FOUND)
            return binary_search(film, field, key, mid + 1, r);
    }
    return rc;
}


int search_film(films *film, int n, char *field, char *key)
{
    char *ptr;
    int rc = OK;
    if (strtol(key, &ptr, 0) <= 0 && strcmp(field, "year\0") == 0)
        rc = NOT_YEAR;
    if (!rc)
        rc = binary_search(film, field, key, 0, n - 1);
    return rc;
}


int is_space(char *str)
{
    int rc = SPACE_NAME;
    while (*str != '\0' && rc == SPACE_NAME)
    {
        if (!isspace(*str))
            rc = OK;
        str++;
    }
    return rc;
}

void print_struct_field(films *film, int n)
{
    for (int i = 0; i < n; i++)
        printf("%s\n%s\n%s\n", film[i].title, film[i].name, film[i].year);
}

void put_in_true_place(films *film, char *field, int n)
{
    for (int j = n; j > 0; j--)
    {
        if (compare_fields(film, field, j - 1) > 0)
        {
            swap_struct(film + j - 1, film + j);
        }
    }
}

int is_number(char *s)
{
    char nums[11] = "0123456789";

    int i = 0, j = 0;
    int flag = FALSE;
    int rc = TRUE;
    while (s[j] != '\0' && rc == TRUE)
    {
        i = 0;
        while (i < 10 && flag == FALSE)
        {
            if (s[j] == nums[i])
                flag = TRUE;
            i++;
        }
        if (flag == FALSE)
            rc = FALSE;
        j++;
    }
    return rc;
}


int read_file_from_struct(FILE *f, films *film, int *n, char *field)
{
    int rc = OK, num = 0;
    films *f_double = film;
    while ((num = fscanf(f, "%[^\n]%*c%[^\n]%*c%[^\n]%*c", f_double->title, f_double->name, f_double->year)) == 3)
    {
        if (strlen(f_double->title) > STR_LEN - 2 || strlen(f_double->name) > STR_LEN - 2 || strlen(f_double->year) > STR_LEN - 2)
            rc = LONG_STR;
        if (is_space(f_double->title) != OK || is_space(f_double->name) != OK || is_space(f_double->year) != OK)
            rc = SPACE_NAME;
        char *ptr;
        if (strtol(f_double->year, &ptr, 0) <= 0 || is_number(f_double->year) == FALSE)
            rc = NOT_YEAR;
        put_in_true_place(film, field, *n);
        (*n)++;
        f_double++;
        if (*n > 15)
            rc = TOO_MANY;
    }
    if (num > 0 && num < 3)
        rc = NOT_MULTIPLE;
    if (*n == 0)
        rc = NULL_FILE;
    return rc;
}


void print_struct(films *film, int i)
{
    if (i != NOT_FOUND)
        printf("%s\n%s\n%s\n", film[i].title, film[i].name, film[i].year);
    else
        printf("%s", "Not found");
}
