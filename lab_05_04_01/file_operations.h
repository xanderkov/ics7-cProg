#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int delete_students(FILE *f, char *name);
int print_students(FILE *f, FILE *out, char substr[]);
int sort_students(FILE *f);
void copy_str(char s[], char s2[]);
