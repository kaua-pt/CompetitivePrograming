#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p)
{
    if (p->prox != NULL)
    {
        celula *p2 = p->prox;
        int i = p2->dado;
        p->prox = p2->prox;
        free(p2);
        return i;
    }
}

void remove_elemento(celula *le, int x)
{
    while (le->prox != NULL && le->prox->dado != x)
        le = le->prox;
    if (le->prox != NULL)
    {
        celula *p1 = le->prox;
        le->prox = p1->prox;
        free(p1);
    }
}

void remove_todos_elementos(celula *le, int x)
{
    while (le->prox != NULL)
    {
        if (le->prox->dado == x)
        {
            celula *p1 = le->prox;
            le->prox = p1->prox;
            free(p1);
        }
        else
        {
            le = le->prox;
        }
    }
}