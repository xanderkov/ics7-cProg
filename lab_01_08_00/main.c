#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>


int output(uint32_t a)
{
    printf("Result: ");
    for (int i = 31; i >= 0; i--)
    {
        if (a & (1 << i))
            printf("%c", '1');
        else
            printf("%c", '0');
    }

    return 0;
}


int main()
{
    uint32_t a;
    int n, rc;
    rc = scanf("%" SCNu32, &a);
    rc += scanf("%d", &n);
    if (rc != 2 || n < 0)
    {
        printf("Error: you input more or less than two numbets");
        return -1;
    }
    n %= 32;
    a = a >> n | (a << (32 - n));
    output(a);
    return 0;
}
