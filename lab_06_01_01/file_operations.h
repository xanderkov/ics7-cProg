#ifndef _MY_FUNC_
#define _MY_FUNC_
#include "functions.h"
#include "struct.h"
#define STR_LEN 27
#define NOT_OK -42
#define OK 0

int sort_films(films *film, int n, char *field);
int search_film(films *film, int n, char *field, char *key);
int read_file_from_struct(FILE *f, films *film, int *n, char *field);
int print_struct(films *film, int i);
int print_struct_field(films *film, int n);
#endif

