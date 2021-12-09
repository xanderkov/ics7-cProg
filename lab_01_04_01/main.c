#include <stdio.h>
#include <math.h>

int main()
{
    int number, entrance, floor;
    scanf("%d", &number);
    entrance = (number - 1) / 36 + 1;
    floor = (number - 1) % 36 / 4 + 1;
    printf("%d \n", entrance);
    printf("%d \n", floor);
    return 0;
}
