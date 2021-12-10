#include "functions.h"
#include "file_operations.h"

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


int is_space(char *str)
{
    while (*str != '\0')
    {
        if (!isspace(*str))
            return OK;
        str++;
    }
    return SPACE_NAME;
}

void print_struct_field(films *film, int n)
{
    for (int i = 0; i < n; i++)
        printf("%s\n%s\n%s\n", film[i].title, film[i].name, film[i].year);
}

void print_struct(films *film, int i)
{
    if (i != NOT_FOUND)
        printf("%s\n%s\n%s\n", film[i].title, film[i].name, film[i].year);
    else
        printf("%s", "Not found");
}

void free_str(char **s)
{
    free(*s);
    *s = NULL;
}

int add_symbol(char **str, int *len, char c, int *n)
{
    int rc = OK;
    if (*n <= *len + 1 && !rc)
    {
        *n *= 2;
        char *tmp = NULL;
        tmp = realloc(*str, *n * sizeof(char));
        if (!tmp)
            rc = ERR_MEM;
        *str = tmp;
    }
    (*str)[*len] = c;
    *len += 1;
    return rc;
}

int get_line(FILE *f, char **str, int *len)
{
    char c;
    *len = 0;
    int rc = OK, n = 1;
    while (fscanf(f, "%c", &c) == 1 && c != '\n' && c != EOF && !rc)
        rc = add_symbol(str, len, c, &n);
    if (*len > 0 && !rc)
        rc = add_symbol(str, len, '\0', &n);
    else if (*len > 0)
        free_str(str);
    else
        rc = NULL_FILE;
    return rc;
}

int get_number_of_records(FILE *f, int *n)
{
    int num = 0, rc = OK;
    char line[STR_LEN];
    while (fgets(line, STR_LEN, f) != NULL)
        num++;
    if (num % 3 == 0 && num > 0)
        *n = num / 3;
    else
        rc = NOT_MULTIPLE;
    rewind(f);
    return rc;
}


int copy_in_struct(FILE *f, films *film)
{
    char *title = NULL, *name = NULL, *year = NULL;
    int len = 0;
    int rc = OK;
    if (!get_line(f, &title, &len))
    {
        if (!get_line(f, &name, &len))
        {
            if (!get_line(f, &year, &len))
            {
                film->title = strdup(title);
                film->name = strdup(name);
                film->year = strdup(year);
                free_str(&year);
                char *ptr;
                if (is_space(film->title) || is_space(film->name) || is_space(film->year))
                    rc = SPACE_NAME;
                if (strtol(film->year, &ptr, 0) <= 0 || is_number(film->year) == FALSE)
                    rc = NOT_YEAR;
            }
            else
                rc = NULL_FILE;
            free_str(&name);
        }
        else
            rc = NULL_FILE;
        free_str(&title);
    }
    return rc;
}

void init_struct(films *film, int n)
{
    for (int i = 0; i < n; i++)
    {
        film->title = 0;
        film->name = 0;
        film->year = 0;
        film++;
    }
}

void free_struct(films **film, int n)
{
    for (int i = 0; i < n && (*film)[i].title != 0; i++)
    {
        free((*film)[i].title);
        (*film)[i].title = NULL;
        free((*film)[i].name);
        (*film)[i].name = NULL;
        free((*film)[i].year);
        (*film)[i].year = NULL;
    }
    free(*film);
}


int read_file_from_struct(FILE *f, films **film, int *n, char *field)
{
    int rc = OK, i = 0;
    rc = get_number_of_records(f, n);
    if (!rc)
    {
        *film = malloc(*n * sizeof(films));
        if (*film)
        {
            init_struct(*film, *n);
            for (i = 0; i < *n && !rc; i++)
            {
                rc = copy_in_struct(f, *film + i);
                if (!rc)
                    put_in_true_place(*film, field, i);
            }
            if (rc)
                free_struct(film, i + 1);
        }
        else
        {
            *n = 0;
            rc = ERR_MEM;
        }
    }
    fclose(f);
    return rc;
}
