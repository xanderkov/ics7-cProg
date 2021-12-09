#include <stdio.h>


int power(long long int base, int n)
{
    long long int res = 1;

    while (n > 0)
    {
        res *= base;
        n = n - 1;
    }

    return res;
}


int main()
{
    long long int a;
    int n, rc;
    rc = scanf("%lld %d", &a, &n);
    if (rc != 2 || n < 0 || n == 0)
    {
        return -1;
    }
    a = power(a, n);
    printf("%lld", a);
    return 0;
}
