#include "stdio.h"
#define EXC(A, B) \
    int tt = A;   \
    A = B;        \
    B = tt

// passa um loop, "confiando" que o j é o menor, então, passa um k verificando
// o k encontra um menor e vapo, só reatribui esse menor na posição j

int main()
{
    int vetor[1000], i = 0, j, k, l, min;

    while (scanf("%d", &vetor[i]) != EOF)
        i++;

    for (j = 0; j < i; j++)
    {
        min = j;
        for (k = j + 1; k < i; k++)
        {
            if (vetor[k] < vetor[min])
            {
                min = k;
            }
        }
        EXC(vetor[j], vetor[min]);
    }

    for (l = 0; l < i; l++)
    {
        printf("%d ", vetor[l]);
    }
}