#include <stdio.h>
#include <stdlib.h>

#define HT_SIZE 140000
#define HASH(PI) (PI % HT_SIZE)

typedef struct Node
{
    int element;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *last;
    Node *begin;
    int count;
} LinkedList;

typedef struct HashT
{
    int size;
    LinkedList *lists;
} HashT;

void initList(LinkedList *list)
{
    list->last = NULL;
    list->begin = NULL;
    list->count = 0;
}

void listInsertFirst(LinkedList *list, int e)
{
    Node *n = malloc(sizeof(Node));
    n->element = e;
    n->next = NULL;
}

void initTable(HashT *table)
{
    table->size = 0;
    table->lists = malloc(sizeof(LinkedList) * HT_SIZE);
}