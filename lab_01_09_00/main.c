#include <stdio.h>
#include <math.h>
#define EPS 1e-8


double output()
{
    double g = 0;
    float x;
    int n = 1, rc = -1;
    rc = scanf("%f", &x);
    if (rc != 1 || fabs(x) < EPS)
        return -1;
    while (x > 0)
    {
        g += x / n;
        n++;
        rc = scanf("%f", &x);
        if (rc != 1 || fabs(x) < EPS)
            return -1;
    }
    return sqrt(g);
}


int main()
{
    double g = output();
    if (fabs(g + 1) < EPS)
        return -1;
    printf("%lf", g);
    return 0;
}
