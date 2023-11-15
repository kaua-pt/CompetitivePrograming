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
    struct Node *begin;
    struct Node *end;
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
        return pushFrist(&head, e);
    }
    return pushToBack(&head, e);
}

int popFrist(Head *head)
{
    Node *newBegin = head->begin->next;
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

int search(Head *head, Item e)
{
    Node *begin = head->begin;
    while (begin->c != e)
    {
        if (begin->c == NULL)
            return -1;
        begin = begin->next;
    }
    return begin->c;
}

int contains(Head *head, Item e)
{
    if (search(head, e) != -1)
        return 0;
    return 1;
}