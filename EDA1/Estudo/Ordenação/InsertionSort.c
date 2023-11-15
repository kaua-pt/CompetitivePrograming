#include <stdio.h>
#define EXC(A, B) \
    int tt = A;   \
    A = B;        \
    B = tt

// consideramos que já há uma ordenação e inserir um novo elemento em ordem
// mais rapido que o selection

void troca(int *v, int *v2)
{
    int aux;
    aux = *v;
    *v = *v2;
    *v2 = aux;
}

void insertionSort(int *v, int l, int r)
{
    int i;
    for (i = r - 1; i > l; i--)
        if (v[i] < v[i - 1])
        {
            EXC(v[i], v[i - 1]);
        }

    for (i = l + 2; i < r; i++)
    {
        int j = i;
        int aux = v[i];
        while (aux < v[j - 1])
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = aux;
    }
}

int main()
{

    int vetor = {0, 1, 2, 3, 5, 6, 7, 8, 9}; // inserir 4

    return 0;
}