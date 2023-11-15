#include <stdio.h>
#include <stdlib.h>
typedef int Item;
typedef struct Node
{
    Item c;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Head
{
    int size;
    Node *begin;
    Node *end;
} Head;

int createHead(Head *head)
{
    head->begin = NULL;
    head->end = NULL;
    head->size = 0;
    return 0;
}

int pushFrist(Head *head, Item e)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
        return 1;

    node->c = e;
    node->next = NULL;
    node->prev = NULL;

    head->size++;
    head->begin = node;
    head->end = node;

    return 0;
}

int pushToBack(Head *head, Item e)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
        return -1;

    node->c = e;
    node->prev = head->end;
    node->next = NULL;

    head->end->next = node;

    head->size++;
    head->end = node;
    return 0;
}

int pushLink(Head *head, Item e)
{
    if (head->size == 0)
    {
        return pushFrist(head, e);
    }
    return pushToBack(head, e);
}

int popFristp(Head *head)
{
    Node *newBegin = head->begin->next;
    printf(" %d,", head->begin->c);
    free(head->begin);
    newBegin->prev = NULL;
    head->begin = newBegin;
    head->size--;
    return 0;
}

int popFrist(Head *head)
{
    Node *newBegin = head->begin->next;
    printf(" %d,", head->begin->c);
    free(head->begin);
    newBegin->prev = NULL;
    head->begin = newBegin;
    head->size--;
    return 0;
}

int popLast(Head *head)
{
    Node *newLast = head->end->prev;
    free(head->end->prev);
    head->end = newLast;
    head->size--;
    return 0;
}

int popLink(Head *head)
{
    if (head->size == 1)
    {
        popFrist(head);
        return 0;
    }
    popLast(head);
    return 0;
}

void criaCartas(Head *head, int c)
{
    int i = 1;
    while (i++ <= c)
        pushLink(head, i);

    return;
}

void resolver(int c)
{
    Head *head;
    createHead(&head);
    criaCartas(&head, c);

    // tira a primeira
    printf("Cartas Descartadas:");
    while (head->size > 1)
    {
        printf("salve");
        // tira primeira
        popFristp(&head);
        // de cima vai pra tras
        Node *no = head->begin;
        popFrist(&head);
        pushToBack(&head, no);
    }
    printf("\n");
    printf("Carta restante: %d\n", head->begin->c);
    return;
}

int main()
{
    int cartas;
    scanf("%d", &cartas);
    resolver(cartas);
    return 0;
}