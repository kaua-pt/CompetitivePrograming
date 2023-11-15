#include <stdio.h>

int main()
{
    int n, i, number, sum = 0;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &number);
        sum = sum + number;
    }

    printf("%d\n", sum);

    return 0;
}