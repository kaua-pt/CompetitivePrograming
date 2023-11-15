#include <stdio.h>

int main()
{
    char times[11];
    int t, n, *results, i, max, somaPontos;

    while (scanf("%d %d", &t, &n))
    {
        if (t == 0)
            break;

        somaPontos = 0;
        results = malloc(t * sizeof(int));
        for (i = 0; i < t; i++)
        {
            scanf("%s %d", times, &results[i]);
            somaPontos = somaPontos + results[i];
        }

        printf("%d\n", (n * 3) - somaPontos);
    }

    return 0;
}