#include <stdio.h>
typedef int Item;

typedef struct Fila
{
    Item *v;
    int i;
    int f;
    int size;
    int elem
} Fila;

int iniciarFila(Fila *fila, int s)
{
    fila->v = malloc(sizeof(Fila) * s);
    fila->i = 0;
    fila->f = 0;
    fila->size = s;
    fila->elem = 0;
    return 0;
}

int enfila(Fila *fila, Item e)
{
    if (fila->elem >= fila->size)
        return 1;

    fila->v[fila->f++] = e;
    fila->elem++;
    return 0;
}

int estaVazia(Fila *fila)
{
    return fila->elem == 0;
}

int desenfila(Fila *fila)
{
    if (estaVazia(fila))
        return 1;

    fila->i++;
    fila->elem--;
    return 0;
}

Item espia(Fila *fila)
{
    return fila->v[fila->i];
}

int main()
{
    int p, r;

    return 0;
}