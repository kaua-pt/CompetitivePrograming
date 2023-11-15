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

int buscaBin(int *vetor, int i, int f, int busca)
{
    while (i + 1 < f)
    {
        int meio = (f + i) / 2;
        if (busca >= vetor[meio])
            i = meio;
        if (busca < vetor[meio])
            f = meio;
    }
    return vetor[i] == busca ? i : -1;
}

int main()
{
    int *vetor, nums, input, i;
    scanf("%d", &nums);
    vetor = malloc(nums * sizeof(int));

    for (i = 0; i < nums; i++)
        scanf("%d", &vetor[i]);

    mergeSort(vetor, 0, nums - 1);

    while (scanf("%d", &input) != EOF)
        buscaBin(vetor, 0, nums - 1, input) == -1 ? printf("nao\n") : printf("sim\n");

    return 0;
}