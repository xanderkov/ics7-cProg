#ifndef _MY_STRUCT_

#define _MY_STRUCT_

typedef struct equation equation;

struct equation
{
    int coef;
    equation *next;
};

#endif
