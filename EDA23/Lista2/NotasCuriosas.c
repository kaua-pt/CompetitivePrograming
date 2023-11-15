#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rep, elem, i, freq = -1, maior = -1;
    int *vetor = calloc(1001, sizeof(int));

    scanf("%d", &rep);
    for (i = 0; i < rep; i++)
    {
        scanf("%d", &elem);
        vetor[elem]++;
    }

    for (i = 0; i < 1001; i++)
    {
        if (freq < vetor[i])
        {
            freq = vetor[i];
            maior = i;
        }
        if (freq == vetor[i] && i > maior)
        {
            freq = vetor[i];
            maior = i;
        }
    }
    printf("%d\n", maior);
    return 0;
}