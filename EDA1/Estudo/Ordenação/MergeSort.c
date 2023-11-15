#include <stdio.h>

// ordena um vetor de L até R inteiros ;
// juntar subvetores; Assim, divide-se o vetor em algumas partes, ordena e dps junta

void merge(int *v, int l, int r, int m)
{
    int *vAux;
    vAux = malloc(sizeof(int) * (r - l + 1));
    int aAux = l, bAux = m + 1, viAux = 0, k;

    while (aAux <= m && bAux <= r)
    {
        if (v[aAux] <= v[bAux])
            vAux[viAux++] = v[aAux++];
        else
            vAux[viAux++] = v[bAux++];
    }

    while (aAux <= m)
    {
        vAux[viAux++] = v[aAux++];
    }
    while (bAux <= r)
    {

        vAux[viAux++] = v[bAux++];
    }

    int vi = 0;
    for (k = 0; k <= r; k++)
    {
        v[k] = vAux[vi++];
    }
}

void mergeSort(int *v, int l, int r)
{
    if (l >= r)
        return;

    int m = (l + r) / 2;
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);
    merge(v, l, r, m);
}

int main()
{

    int vetor = {0, 1, 2, 3, 5, 6, 7, 8, 9}; // inserir 4
    return 0;
}