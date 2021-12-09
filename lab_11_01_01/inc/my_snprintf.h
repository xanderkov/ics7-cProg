#ifndef __MY_SNPRINTF_H__

#define __MY_SNPRINTF_H__

#include <stdio.h>
#include <stdarg.h>

#include "defines.h"
#include "operations.h"


int get_size_end_format(const char *format, va_list arg);

int my_snprintf(char *buffer, int buf_size, const char *format, ...);

#endif
