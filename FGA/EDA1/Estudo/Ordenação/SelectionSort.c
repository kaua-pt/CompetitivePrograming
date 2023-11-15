#include <stdio.h>

// comparar todos os elementos do vetor e encontrar o menor elemento
// movemos ele pro primeiro elemento

void troca(int *v, int *v2)
{
    int aux;
    aux = *v;
    *v = *v2;
    *v2 = aux;
}

void selectionSort(int *v, int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n - 1; j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
            troca(&v[i], &v[min]);
        }
    }
}

int main()
{
    int k;
    int vetor = {5, 9, 7, 6, 1, 4, 8, 3, 2, 0};
    selectionSort(vetor, 10);
    return 0;
}