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
    Node *begin;
    int count;
} LinkedList;

void initList(LinkedList *list)
{
    list->begin = NULL;
    list->count = 0;
}

void listInsertFirst(LinkedList *list, int e)
{
    Node *n = malloc(sizeof(Node));
    n->element = e;
    n->next = NULL;
    list->begin = n;
    list->count++;
}

void listInsertLast(LinkedList *list, int e)
{
    Node *n = malloc(sizeof(Node));
    n->element = e;
    n->next = NULL;
    list->count++;

    Node *h = list->begin;
    while (h->next != NULL)
        h = h->next;

    h->next = n;
    return;
}
void pushList(LinkedList *list, int e)
{
    if (list->begin == NULL)
    {
        listInsertFirst(list, e);
        return;
    }
    listInsertLast(list, e);
    return;
}

int search(LinkedList *list, int e)
{
    Node *n = list->begin;
    while (n != NULL)
    {
        if (n->element == e)
            return 1;
        n = n->next;
    }
    return 0;
}

typedef struct HashT
{
    int size;
    LinkedList *lists;
} HashT;

void initHashT(HashT *HT)
{
    int i;
    HT->size = 0;
    HT->lists = malloc(sizeof(LinkedList) * HT_SIZE);

    for (i = 0; i < HT_SIZE; i++)
        initList(&HT->lists[i]);
}

void HashInsert(HashT *HT, int elem)
{
    pushList(&HT->lists[HASH(elem)], elem);
    HT->size++;
}

int HashSearch(HashT *HT, int elem)
{
    return search(&HT->lists[HASH(elem)], elem);
}

int main()
{
    int rep, i, elem;
    HashT table;
    initHashT(&table);

    scanf("%d", &rep);
    for (i = 0; i < rep; i++)
    {
        scanf("%d", &elem);
        HashInsert(&table, elem);
    }

    while (scanf("%d", &elem) != EOF)
    {
        if (HashSearch(&table, elem))
        {
            printf("sim\n");
            continue;
        }
        printf("nao\n");
    }

    return 0;
}