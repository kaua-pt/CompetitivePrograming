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

int createHead(Head *x)
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

int pushFrist(Head *x, Item i)
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

int popFrist(Head *x)
{
    // se a lista estiver vazia,ele não faz nada
    if (x->size == 0)
    {
        printf("No job for Ada?\n");
        return 0;
    }

    Node *t = x->first;

    printf("%d\n", x->first->item);
    x->first = x->first->next;
    if (x->first == NULL)
        x->last = NULL;

    x->size--;
    free(t);
    return 1;
}

int pushToBack(Head *x, Item i)
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

int popLast(Head *x)
{
    // se a lista estiver vazia,ele não faz nada
    if (x->size == 0)
    {
        printf("No job for Ada?\n");
        return 1;
    }
    Node *t = x->last;

    printf("%d\n", x->last->item);

    x->last = x->last->previous;
    if (x->last != NULL)
        x->last->next = NULL;
    else
        x->first = NULL;

    x->size--;
    free(t);
}

int main()
{
    // Utiliza-se de uma flag para definir
    // se queremos ordem reversa ou não
    int q, i, n, reverse = 0;
    char com[1001];
    Head head;
    createHead(&head);

    // extrai informação
    scanf("%d", &q);

    // para com[0]
    // se for b, ele printa o ultimo e o exclui
    // se for f, ele printa o primeiro e o exclui
    // se for p, ele puxa para trás da lista
    // se for t ele puxa para frente da lista
    // se for r ele troca o sinal da flag na qual inverte ou não
    // as operações
    for (i = 0; i < q; i++)
    {
        scanf("%s", com);
        if (com[0] == 'b')
            if (reverse == 0)
                popLast(&head);
            else
                popFrist(&head);
        if (com[0] == 'f')
            if (reverse == 0)
                popFrist(&head);
            else
                popLast(&head);
        if (com[0] == 'p')
        {
            scanf("%d", &n);
            if (reverse == 0)
                pushToBack(&head, n);
            else
                pushFrist(&head, n);
        }
        if (com[0] == 't')
        {
            scanf("%d", &n);
            if (reverse == 0)
                pushFrist(&head, n);
            else
                pushToBack(&head, n);
        }
        if (com[0] == 'r')
        {
            if (reverse == 0)
            {
                reverse = 1;
                continue;
            }
            if (reverse == 1)
            {
                reverse = 0;
                continue;
            }
        }
    }

    return 0;
}