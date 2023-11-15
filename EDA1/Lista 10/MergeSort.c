#include <stdio.h>

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

void mergeSort(int *vetor, int i, int j)
{
    if (i >= j)
        return;

    int meio = i + (j - i) / 2;
    mergeSort(vetor, i, meio);
    mergeSort(vetor, meio + 1, j);
    merge(vetor, i, j, meio);
}

int main()
{
    int i, len, k;
    scanf("%d", &len);
    int vetor[len];

    for (i = 0; i < len; i++)
    {
        scanf("%d", &vetor[i]);
    }

    mergeSort(&vetor[0], 0, len - 1);

    printf("%d", vetor[0]);
    for (k = 1; k < len; k++)
    {
        printf(" %d", vetor[k]);
    }
    printf("\n");

    return 0;
}