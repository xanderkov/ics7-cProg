#include "my_snprintf.h"

int get_end_size(const char *format, va_list arg)
{
    int size = 0;
    char c;
    char *str;
    int digit;
    long long x_number = 0;
    while (*format)
    {
        if (!my_strncmp(format, "%d", SPEC_SIZE))
        {
            digit = va_arg(arg, int);
            size += number_size(digit, "all", 10);
            format += SPEC_SIZE;
        }
        else if (!my_strncmp(format, "%c", SPEC_SIZE))
        {
            c = va_arg(arg, int);
            c = c;
            size += CHAR_SIZE;
            format += SPEC_SIZE;
        }
        else if (!my_strncmp(format, "%s", SPEC_SIZE))
        {
            str = va_arg(arg, char*);
            size += my_strlen(str);
            format += SPEC_SIZE;
        }
        else if (!my_strncmp(format, "%x", SPEC_SIZE))
        {
            x_number = va_arg(arg, unsigned int);
            size += number_size(x_number, "all", 16);
            format += SPEC_SIZE;
        }
        else
        {
            size += CHAR_SIZE;
            format += CHAR_SIZE;
        }
    }
    return size;
}

int my_snprintf(char *buffer, int buf_size, const char *format, ...)
{   
    char *str;
    int rval = 0;
    int format_end_size;
    va_list arg;

    if (buffer != NULL)
        buffer[0] = '\0';

    va_start(arg, format);
    char c;
    int digit;
    long long x_number = 0;
    int size = 0;
    while (*format && buf_size - CHAR_SIZE > 0 && buffer != NULL)
    {
        if (!my_strncmp(format, "%d", SPEC_SIZE))
        {
            digit = va_arg(arg, int);
            rval += number_size(digit, "all", 10);
            str = inttostr(digit, &buf_size, 10);
            my_strncat(buffer, str, my_strlen(str));
            free(str);
            format += SPEC_SIZE;
        }
        else if (!my_strncmp(format, "%c", SPEC_SIZE))
        {
            c = va_arg(arg, int);
            rval += CHAR_SIZE;
            size = my_strlen(buffer);
            buffer[size] = c;
            buffer[size + CHAR_SIZE] = '\0';
            format += SPEC_SIZE;
            buf_size -= CHAR_SIZE;
        }
        else if (!my_strncmp(format, "%s", SPEC_SIZE))
        {
            str = va_arg(arg, char*);
            size = my_strlen(buffer);
            int len = my_strlen(str);
            if (buf_size - len < 0)
                len = buf_size - 1;
            my_strncat(buffer, str, len);
            rval += my_strlen(str);
            format += SPEC_SIZE;
            buf_size -= len;
        }
        else if (!my_strncmp(format, "%x", SPEC_SIZE))
        {
            x_number = va_arg(arg, unsigned int);
            str = inttostr(x_number, &buf_size, 16);
            rval += number_size(x_number, "all", 16);
            my_strncat(buffer, str, my_strlen(str));
            
            free(str);
            format += SPEC_SIZE;
        }
        else
        {
            rval += CHAR_SIZE;
            my_strncat(buffer, format, CHAR_SIZE);
            format += CHAR_SIZE;
            buf_size -= CHAR_SIZE;
        }
    }

    format_end_size = get_end_size(format, arg);

    va_end(arg);
    rval += format_end_size;
    return rval;
}
