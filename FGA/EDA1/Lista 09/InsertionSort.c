#include "stdio.h"
#define EXC(A, B) \
    int tt = A;   \
    A = B;        \
    B = tt

void insertionSort(int *vetor, int l, int r)
{
    int minor, k, aux, i;

    for (i = r - 1; i > l; i--)
    {
        if (vetor[i] < vetor[i - 1])
        {
            EXC(vetor[i - 1], vetor[i]);
        }
    }

    for (k = 2; k < r; k++)
    {
        int u = k;
        aux = vetor[u];

        while (aux < vetor[u - 1])
        {
            vetor[u] = vetor[u - 1];
            u--;
        }
        vetor[u] = aux;
    }
}

int main()
{
    int vetor[50000], i = 0, l;

    while (scanf("%d", &vetor[i]) != EOF)
        i++;

    insertionSort(vetor, 0, i);

    for (l = 0; l < i; l++)
    {
        printf("%d%s", vetor[l], l == i - 1 ? "\n" : " ");
    }
    return 0;
}