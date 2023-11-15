#include <stdio.h>
#include <stdlib.h>

// deve ser declarado como unsigned long long
// como dito no inicio da questão
#define ull unsigned long long
#define key(x) (x.curr)
#define less(a, b) (key(a) < key(b))
#define swap(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }
#define cmpswap(a, b) \
    if (less(b, a))   \
    swap(a, b)

typedef struct Item
{
    ull curr;
    ull prev;
    ull next;
} Item;

int partition(Item *v, int size)
{
    int l = -1, r = size - 1;
    Item pivot = v[r];

    while (1)
    {
        while (less(v[++l], pivot))
            ;
        while (less(pivot, v[--r]) && r > l)
            ;

        if (l >= r)
            break;
        swap(v[l], v[r]);
    }
    swap(v[l], v[size - 1]);
    return l;
}

// quicksort utilizado para ordenar o vetor
// de char com base na sua current char
void quicksort(Item *v, int size)
{
    if (size < 2)
        return;

    cmpswap(v[(size - 1) / 2], v[size - 1]);
    cmpswap(v[0], v[(size - 1) / 2]);
    cmpswap(v[size - 1], v[(size - 1) / 2]);

    int m = partition(v, size);
    quicksort(v, m);
    quicksort(v + m + 1, size - m - 1);
}

// função reponsável por procurar o próximo elemento
// se não achar retorna -1
int search(Item *v, int n, ull x)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (key(v[m]) == x)
            return m;
        else if (key(v[m]) < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

// funcao recursiva que monta a sequencia
// de elementos
int is_sane(Item *v, int n, Item prev, Item target)
{
    // verifica se o de trás de target aponta pra ele
    // e se o da frente do de target também aponta pra ele
    if (prev.next == target.curr && target.prev == prev.curr)
        return 1;

    // procura o elemento pra colocar e verifica se é coerente
    int idx = search(v, n, prev.next);
    if (idx == -1 || v[idx].prev != prev.curr)
        return 0;

    return is_sane(v, n, v[idx], target);
}

Item v[500000];

int main()
{
    int n;
    for (n = 0; scanf(" %llx %llx %llx", &v[n].curr, &v[n].prev, &v[n].next) == 3; n++)
        ;

    Item ptr1 = v[0], ptr2 = v[1];
    quicksort(v, n);

    printf("%s\n", (is_sane(v, n, ptr1, ptr2) ? "sana" : "insana"));

    return 0;
}
