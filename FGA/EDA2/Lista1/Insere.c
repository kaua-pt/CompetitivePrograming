#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x)
{
    celula *ini = malloc(sizeof(celula));
    ini->dado = x;
    ini->prox = le->prox;
    le->prox = ini;
    return;
}

void insere_antes(celula *le, int x, int y)
{
    celula *init = malloc(sizeof(celula));
    init->dado = x;
    while (le->prox != NULL && le->prox->dado != y)
    {
        le = le->prox;
    }
    init->prox = le->prox;
    le->prox = init;
}
