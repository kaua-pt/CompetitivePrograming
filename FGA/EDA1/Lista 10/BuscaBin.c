#include <stdio.h>
#define EXC(A, B) \
    Item tt = A;  \
    A = B;        \
    B = tt

typedef struct
{
    int pos;
    int elem;
} Item;

int buscaBin(Item *vetor, int inicio, int fim, int busca)
{

    while (inicio + 1 < fim)
    {
        int meio = (inicio + fim) / 2;
        if (busca < vetor[meio].elem)
            fim = meio;
        if (busca >= vetor[meio].elem)
            inicio = meio;
    }

    if (vetor[inicio].elem == busca)
        return inicio;

    if (vetor[inicio].elem != busca)
    {
        if (vetor[inicio].elem > busca)
        {
            return inicio;
        }
        else
        {
            return inicio + 1;
        }
    }
}

void merge(Item *vetor, int i, int f, int m)
{
    Item vetorAux[f - i + 1];
    int Ai = i, Bi = m + 1, AUXi = 0, p;

    while (Ai <= m && Bi <= f)
    {
        if (vetor[Ai].elem <= vetor[Bi].elem)
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

void mergeSort(Item *vetor, int i, int j)
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
    int m, n, init, init2, l;
    scanf("%d %d", &m, &n);

    Item vetor[m];
    int vetorP[n];

    for (init = 0; init < m; init++)
    {
        scanf(" %d", &vetor[init].elem);
        vetor[init].pos = init;
    }

    for (init2 = 0; init2 < n; init2++)
    {
        scanf(" %d", &vetorP[init2]);
    }

    for (l = 0; l < n; l++)
    {
        int result = buscaBin(vetor, 0, m, vetorP[l]);
        printf("%d\n", result);
    }

    return 0;
}