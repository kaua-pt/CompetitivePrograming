#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le)
{
    celula *elem;

    for (elem = le->prox; elem != NULL; elem = elem->prox)
    {
        printf("%d -> ", elem->dado);
    }

    printf("NULL\n");
}

void imprime_rec(celula *le)
{
    le = le->prox;

    if (le == NULL)
    {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", le->dado);
    imprime_rec(le);
}
