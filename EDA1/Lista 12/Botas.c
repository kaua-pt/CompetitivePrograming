#include <stdio.h>
#include <stdlib.h>

typedef struct botinha
{
    int e;
    int d;
} botinha;

void solve(int n)
{
    int num, comb = 0, i;
    botinha *botas = calloc(sizeof(botinha), 66);

    while (n-- != 0)
    {
        char side;
        scanf("%d", &num);
        scanf("%c", &side);
        scanf("%c", &side);
        side == 'D' ? botas[num].d++ : botas[num].e++;
    }

    for (i = 0; i < 66; i++)
    {
        if (botas[i].d < botas[i].e)
            comb += botas[i].d;
        if (botas[i].d >= botas[i].e)
            comb += botas[i].e;
    }

    printf("%d\n", comb);
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
        solve(n);
    return 0;
}