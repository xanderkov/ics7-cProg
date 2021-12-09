#include <stdio.h>
#include <math.h>


double decompose(double x, double eps)
{
    double func = 1, nom = 1, n = 1, fact = 1;
    while (nom > eps)
    {
        nom *= x / fact;
        n += 1;
        fact *= n;
        func += nom;
    }
    return func;
}



int main()
{
    double x, f, s, abs, rel, eps;
    int rc;

    rc = scanf("%lf%lf", &x, &eps);
    if (rc != 2 || eps < 0 || eps > 1)
        return -1;
    f = exp(x);
    s = decompose(x, eps);
    abs = fabs(f - s);
    rel = abs / fabs(f);
    printf("%lf %lf %lf %lf", f, s, abs, rel);
    return 0;
}
