#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string.h>
#include <stddef.h>
#define WORD_LEN 30
#define N 259
#define INPUT_NUMBER -1
#define INPUT_SIZE -2
#define WORD_NUM -3
#define NO_WORD -4
#define EMPTY_STR -5
#define OK 0
#define TRUE 1
#define FALSE -1

int split_line(char *s, char words[][WORD_LEN + 1], int *n);
