#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct Node
{
    Item c;
    struct Node *next;
} Node;

typedef struct Head
{
    int size;
    struct Node *begin;
    struct Node *end;
} Head;

int iniciarLista(Head *head)
{
    head->size = 0;
    head->begin = NULL;
    head->end = NULL;
}

int inserePrimeiro(Head *head, Item e)
{
    Node *aux = malloc(sizeof(Node));
    if (aux == NULL)
        return 1;

    aux->c = e;
    aux->next = head->begin;

    head->size++;
    head->begin = aux;
    if (head->end == NULL)
        head->end = aux;
    return 0;
}

int insereDepois(Head *head, Item e)
{
    Node *aux = malloc(sizeof(Node));
    if (aux == NULL)
        return 1;
    aux->c = e;
    aux->next = NULL;

    head->end->next = aux;
    head->end = aux;
    return 0;
}

int push(Head *head, Item e)
{
    if (head->size == 0)
        inserePrimeiro(head, e);
    else
        insereDepois(head, e);
}

int removePrimeiro(Head *head)
{
}

int removeDepois()
{
}

int buscaLista()
{
}