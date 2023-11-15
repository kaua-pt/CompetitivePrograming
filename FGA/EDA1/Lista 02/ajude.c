#include <stdio.h>

int main(void)
{
    int a[3], r, exp;

    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    scanf("%d", &r);
    exp = *a + *(a + 1) + *(a + 2);

    if (r == exp)
    {
        printf("Acertou\n");
    }
    else
    {
        printf("Errou\n");
    }

    return 0;
}