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

void selectionSort(Item *vetor, int i)
{
    int j, min, k;

    for (j = 0; j < i; j++)
    {
        min = j;
        for (k = j + 1; k < i; k++)
        {
            if (vetor[k].elem < vetor[min].elem)
            {
                min = k;
            }
        }
        EXC(vetor[j], vetor[min]);
    }
}

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

    return vetor[inicio].elem == busca ? inicio : -1;
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

    selectionSort(&vetor, m);

    // vetor ordenado - busca binaria

    for (l = 0; l < n; l++)
    {
        int result = buscaBin(vetor, 0, m, vetorP[l]);
        result == -1 ? printf("-1\n") : printf("%d\n", vetor[result].pos);
    }

    return 0;
}