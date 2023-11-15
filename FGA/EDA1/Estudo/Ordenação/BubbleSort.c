#include <stdio.h>
#define EXC(A, B) \
    int tt = A;   \
    A = B;        \
    B = tt

void bubbleSort(int *v, int l, int r)
{
    int i, j;
    for (i = l; i < r; i++)
    {
        for (j = r; j > l; j--)
        {
            if (LESS(v[j], v[j - 1]))
            {
                EXC(v[j], v[j - 1]);
            }
        }
    }
}

int main()
{

    int vetor = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    bubbleSort(vetor, 0, 10);
    return 0;
}