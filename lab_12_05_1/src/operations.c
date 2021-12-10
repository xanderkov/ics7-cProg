#include "operations.h"

char *my_strncat(char *str1, const char *str2, const size_t len)
{
    if (!str1 || !str2) 
        return NULL;
    size_t i = my_strlen(str1);
    for (size_t j = 0; j < my_strlen(str2) && j < len; i++, j++)
        str1[i] = str2[j];
    str1[i] = '\0';
    return str1;
}

size_t my_strlen(const char *str)
{
    if (!str)
        return NULL_POINTER;
    size_t len = 0;
    for (; *str; str++, len++);
    return len;
}

int number_size(long long number, char *const filter, int base)
{
    int len = 0;
    if (my_strncmp(filter, "all", 3) == 0 && number < 0)
        len++;
    if (number < 0)
        number *= -1;
    for (unsigned long i = number; i > base - 1; i /= base, len++);
    return ++len;
}

char *inttostr(long long number, int *const buf_size, int base)
{
    int j = 0, i = 0, minus = 0;
    int size = number_size(number, "abs", base);

    char *str = (char *) malloc((size + 2) * sizeof(char));

    if (!str)
        return NULL;

    if (number < 0)
    {
        number *= -1;
        (*buf_size)--;
        str[j++] = '-';
        minus++;
        size++;
    }
    do
    {
        int r = (int)(number % (unsigned long long)(base));
        str[j++] = (char)r + (r < 10 ? '0' : 'a' - 10);
        number /= (unsigned long long)(base);
        (*buf_size)--;
    } while (number != 0 && j < size && *buf_size > 0);
    if (*buf_size > 0)
        str[j] = '\0'; 
    else
        str[--j] = '\0';
    for (j--, i = minus; i < j; j--, i++) 
    {
        char tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
    }
    return str;
}

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    if (str1 == NULL || str2 == NULL)
        return NULL_POINTER;
    int rc = OK;
    for (int i = 0; i < n && !rc; i++)
    {
        if (str1[i] > str2[i])
            rc = GREATER;
        else if (str1[i] < str2[i])
            rc = LESS;
    }
    return rc;
}
