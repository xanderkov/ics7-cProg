#ifndef _IO_

#define _IO_
#include "struct.h"
#include "functions.h"

int read_file_from_struct(FILE *f, films **film, int *n, char *field);
int print_struct(films *film, int i);
int print_struct_field(films *film, int n);
void free_struct(films **film, int n);
int is_number(char *s);
int is_space(char *str);
int add_symbol(char **str, int *len, char c, int *n);
void free_str(char **s);

#endif