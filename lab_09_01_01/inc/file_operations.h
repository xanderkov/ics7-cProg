#ifndef _MY_FUNC_
#define _MY_FUNC_
#include "functions.h"
#include "struct.h"
#define STR_LEN 27
#define NOT_OK -42
#define OK 0

int sort_films(films *film, int n, char *field);
int search_film(films *film, int n, char *field, char *key);
void put_in_true_place(films *film, char *field, int n);
#endif

