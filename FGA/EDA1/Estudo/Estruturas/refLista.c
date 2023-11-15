#include <stdio.h>
#include <stdlib.h>
typedef int Item;

typedef struct Node
{
    Item item;
    struct Node *next;
    struct Node *previous;
} Node;

typedef struct Head
{
    Node *first;
    Node *last;
    int size;
} Head;

int criaLista(Head *x)
{
    x->first = NULL;
    x->last = NULL;
    x->size = 0;
    return 1;
}

int estaVazia(Head *x)
{
    return x->first == NULL;
}

int PuxaFrente(Head *x, Item i)
{
    Node *novoNo = malloc(sizeof(Node));

    if (novoNo == NULL)
        return 0;
    novoNo->previous = NULL;
    novoNo->item = i;

    if (x->size == 0)
    {
        novoNo->next = NULL;
        x->first = novoNo;
        x->last = novoNo;
    }
    else
    {
        x->first->previous = novoNo;
        novoNo->next = x->first;
        x->first = novoNo;
    }

    x->size++;
    return 1;
}

int removeFrente(Head *x)
{
    if (x->size == 0)
    {
        printf("No job for Ada?\n");
        return 0;
    }

    Node *t = x->first;
    printf("valor %d\n", x->first->item);
    x->first = x->first->next;
    x->size--;
    free(t);
    return 1;
}

int puxaTras(Head *x, Item i)
{

    Node *novoNo = malloc(sizeof(Node));
    if (novoNo == NULL)
        return 0;
    novoNo->next = NULL;
    novoNo->item = i;

    if (x->size == 0)
    {
        x->first = novoNo;
        x->last = novoNo;
        novoNo->previous = NULL;
    }
    else
    {
        x->last->next = novoNo;
        novoNo->previous = x->last;
        x->last = novoNo;
    }

    x->size++;
    return 1;
}

int removeFim(Head *x)
{
    if (x->size == 0)
    {
        printf("No job for Ada?\n");
        return 1;
    }
    Node *t = x->last;
    printf("valor %d\n", x->last->item);
    x->last = x->last->previous;
    x->last->next = NULL;
    x->size--;
    free(t);
}