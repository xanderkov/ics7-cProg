#include <stdio.h>
#include <math.h>

#define PI 4.0 * atan(1.0)


int is_equal(double x, double y)
{
    if (fabs(x - y) < 1e-8)
        return 3;
    return 1;
}


double calc_ang(double a, double c, double b)
{
    double ang;
    ang = acos((a * a + c * c - b * b) / (2 * a * c));
    return ang;
}


int main()
{
    double xa, ya, xb, yb, xc, yc, ab, bc, ac, anga, angb, angc;
    int rc;

    rc = scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc);
    if (rc != 6)
        return -1;
    if (((xa < xb || xb < xa) && (ya < yb || yb < ya)) || ((xc < xb || xb < xc) && (yc < yb || yb < yc)) || ((xa < xc || xc < xa) && (ya < yc || yc < ya)))
    {
        ab = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
        bc = sqrt((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb));
        ac = sqrt((xc - xa) * (xc - xa) + (yc - ya) * (yc - ya));
    }
    else
        return -1;

    if ((ab + bc < ac) || (ab + ac < bc) || (ac + bc < ab))
        return -1;
    if (is_equal(ab + bc, ac) != 1 || is_equal(ab + ac, bc) != 1 || is_equal(ac + bc, ab) != 1)
        return -1;

    anga = calc_ang(ab, ac, bc);
    angb = calc_ang(ab, bc, ac);
    angc = calc_ang(bc, ac, ab);
    if (anga < PI / 2 && angb < PI / 2 && angc < PI / 2)
        printf("%d", 0);
    else if (anga > PI / 2 || angb > PI / 2 || angc > PI / 2)
        printf("%d", 2);
    else
        printf("%d", 1);

    return 0;
}
