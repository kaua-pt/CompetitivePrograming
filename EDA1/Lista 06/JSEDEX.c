#include <stdio.h>

int main()
{
    int d, x, y, z;
    scanf("%d", &d);
    scanf("%d %d %d", &x, &y, &z);

    if ((d <= x) && (d <= y) && (d <= z))
    {
        printf("S");
    }
    else
    {
        printf("N");
    }

    return 0;
}