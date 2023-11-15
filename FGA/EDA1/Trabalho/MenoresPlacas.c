#include <stdio.h>
#include <stdlib.h>
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

// insere elementos no vetor, utilizando o
// insertion em cada iteração
int insere(int *v, int n2, int placas)
{
    v[placas] = n2;
    // aplica insertion nos dados
    insertionSort(v, 0, placas + 1);

    // trava o contador das placas em 100
    if (++placas > 100)
        placas = 100;

    // retorna numero de placas
    return placas;
}

// printar elementos na tela
void printa(int *v, int n2, int placas)
{
    int i;
    if (n2 > placas)
        n2 = placas;
    for (i = 0; i < n2; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main()
{
    int v[101];
    int n1, n2, placas = 0;

    // extrair dados
    while (scanf("%d %d", &n1, &n2) != EOF)
    {
        if (n1 == 1)
        {
            placas = insere(v, n2, placas);
        }
        if (n1 == 2)
        {
            printa(v, n2, placas);
        }
    }
    return 0;
}
