#include <stdio.h>
#include <math.h>

int main(void)
{
    setbuf(stdout, NULL);
    float v1, v2, t1, t2, v, t;
    scanf("%f%f%f%f", &v1, &t1, &v2, &t2);
    v = v1 + v2;
    t = (v1 * t1 + v2 * t2) / v;
    printf("%f %f", v, t);
    return 0;
}
