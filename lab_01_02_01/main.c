#include <stdio.h>
#include <math.h>


int main()
{
    double a, b, fi, s;
    scanf("%lf %lf %lf", &a, &b, &fi);
    s = 0.5 * fabs(b - a) * tan(4.0 * atan(1.0) * fi / 180) * (b + a) * 0.5;
    printf("%.6lf", s);
    return 0;
}
