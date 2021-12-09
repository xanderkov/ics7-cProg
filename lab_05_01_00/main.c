#include <stdio.h>
#include <stddef.h>
#include "procces.h"
#define OK 0
#define NO_FILE -1
#define NO_INFO -2
#define NO_DEQUENCE -3


int main()
{
    int n = 0;
    int rc = process(stdin, &n);
    if (rc == OK)
        fprintf(stdout, "%d", n);
    return rc;
}
