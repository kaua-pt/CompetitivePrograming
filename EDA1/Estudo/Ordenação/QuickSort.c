#define EXC(A, B) \
    int tt = A;   \
    A = B;        \
    B = tt

int separe(int *V, int l, int r)
{
    int i = l - 1, j = r;
    int v = V[r];
    for (;;)
    {
        while (V[++i] < v)
            ;
        while (v < V[--j])
            if (j == l)
                break;
        if (i >= j)
            break;
        EXC(V[i], V[j]);
    }
    EXC(V[i], V[r]);
    return i;
}

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

    for (k = 2; k <= r; k++)
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

void qs(int *v, int l, int r)
{
    if (r - l <= 32)
        return;

    EXC(v[(l + r) / 2], v[r - 1]);

    if (v[l] < v[r - 1])
    {
        EXC(v[l], v[r - 1]);
    }
    if (v[l] < v[r])
    {
        EXC(v[l], v[r]);
    }
    if (v[r - 1] < v[r])
    {
        EXC(v[r - 1], v[r]);
    }

    int j = separe(v, l + 1, r - 1);
    qs(v, l, j - 1);
    qs(v, j + 1, r);
}

void qsI(int *V, int l, int r)
{
    qs(V, l, r);
    insertionSort(V, l, r);
}