#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int len;
    char carac;
    int pos;
} Drink;

void merge(Drink *drinks, int i, int f, int m)
{
    Drink vetorAux[f - i + 1];
    int Ai = i, Bi = m + 1, AUXi = 0, p;

    while (Ai <= m && Bi <= f)
    {
        if (drinks[Ai].len >= drinks[Bi].len)
        {
            vetorAux[AUXi++] = drinks[Ai++];
        }
        else
        {
            vetorAux[AUXi++] = drinks[Bi++];
        }
    }

    while (Ai <= m)
    {
        vetorAux[AUXi++] = drinks[Ai++];
    }
    while (Bi <= f)
    {
        vetorAux[AUXi++] = drinks[Bi++];
    }

    int v = 0;
    for (p = i; p <= f; ++p)
    {
        drinks[p] = vetorAux[v++];
    }
}

void mergeSort(Drink *drinks, int i, int j)
{
    if (i >= j)
        return;

    int meio = i + (j - i) / 2;
    mergeSort(drinks, i, meio);
    mergeSort(drinks, meio + 1, j);
    merge(drinks, i, j, meio);
}

int main()
{
    Drink drinks[100000];
    int i = 0, sent = 0, j;
    char input[100001];
    scanf("%s", input);

    int z = strlen(input);
    for (i = 0; i < z; i++)
    {

        drinks[sent].carac = input[i];
        drinks[sent].pos = i;

        while (input[i] == drinks[sent].carac)
        {
            drinks[sent].len++;
            i++;
        }
        i--;
        sent++;
    }

    mergeSort(&drinks[0], 0, sent);

    for (j = 0; j < sent; j++)
    {
        printf("%d %c %d\n", drinks[j].len, drinks[j].carac, drinks[j].pos);
    }

    return 0;
}