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

void insere_inicio(celula *le, int x)
{
    celula *novo = malloc(sizeof(celula));

    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

void insere_antes(celula *le, int x, int y)
{

    while (le->prox != NULL)
    {
        if (le->prox->dado == y)
        {
            celula *novo = malloc(sizeof(celula));

            novo->dado = x;
            novo->prox = le->prox;
            le->prox = novo;
            return;
        }
        le = le->prox;
    }
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;

    return;
}

int remove_primeiro(celula *p)
{
    int x = 0;
    celula *lixo = p->prox;
    if (lixo != NULL)
    {
        int x = lixo->dado;
        p->prox = lixo->prox;
        free(lixo);
    }
    return x;
}

void remove_elemento(celula *le, int x)
{
    while (le->prox != NULL)
    {
        if (le->prox->dado == x)
        {
            celula *temp = le->prox;
            le->prox = le->prox->prox;
            free(temp);
            return;
        }
        le = le->prox;
    }
}

void remove_todos_elementos(celula *le, int x)
{
    while (le->prox != NULL)
    {
        if (le->prox->dado == x)
        {
            celula *temp = le->prox;
            le->prox = le->prox->prox;
            free(temp);
        }
        else
        {
            le = le->prox;
        }
    }
}

celula *busca(celula *le, int x)
{
    if (le == NULL)
    {
        return NULL;
    }

    while (le->prox != NULL)
    {
        if (le->prox->dado == x)
        {
            return le->prox;
        }

        le = le->prox;
    }

    return NULL;
}

celula *busca_rec(celula *le, int x)
{
    if (le == NULL)
    {
        return NULL;
    }

    if (le->dado == x)
    {
        return le;
    }

    return busca_rec(le->prox, x);
}




//  321 256 201 684 661 849 156 840 874 981 985 191 
