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


void put_in_true_place(films *film, char *field, int n)
{
    for (int j = n; j > 0; j--)
        if (compare_fields(film, field, j - 1) > 0)
            swap_struct(film + j - 1, film + j);
}


