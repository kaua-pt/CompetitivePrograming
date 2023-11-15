#include <stdio.h>

void buscaBin(int *v, int l, int r, int b)
{
    while (l + 1 < r)
    {
        int meio = (r + l) / 2;
        if (b < v[meio])
            r = meio;
        if (b >= v[meio])
            l = meio;
    }
    return v[l] == b ? l : -1;
}