#include <stdio.h>

int vetor[16 * (int)1e5 + (int)6.66];

void merge(int *vetor, int i, int f, int m)
{
    int vetorAux[f - i + 1];
    int Ai = i, Bi = m + 1, AUXi = 0, p;

    while (Ai <= m && Bi <= f)
    {
        if (vetor[Ai] <= vetor[Bi])
        {
            vetorAux[AUXi++] = vetor[Ai++];
        }
        else
        {
            vetorAux[AUXi++] = vetor[Bi++];
        }
    }

    while (Ai <= m)
    {
        vetorAux[AUXi++] = vetor[Ai++];
    }
    while (Bi <= f)
    {
        vetorAux[AUXi++] = vetor[Bi++];
    }

    int v = 0;
    for (p = i; p <= f; ++p)
    {
        vetor[p] = vetorAux[v++];
    }
}

int main()
{
    int len, i, j, ocupation = 0;
    for (i = 0; i < 8; ++i)
    {
        scanf("%d", &len);
        if (len == 0)
            continue;
        for (j = 0; j < len; ++j)
            scanf("%d", &vetor[ocupation + j]);
        merge(&vetor[0], 0, ocupation + len - 1, ocupation - 1);
        ocupation += len;
    }

    printf("%d", vetor[0]);
    for (i = 1; i < ocupation; ++i)
        printf(" %d", vetor[i]);
    printf("\n");
    return 0;
}