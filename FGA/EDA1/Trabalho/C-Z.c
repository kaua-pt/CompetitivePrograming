#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item
{
    char name[101];
} Item;

typedef struct Pilha
{
    Item *v;
    int size;
    int elem;
} Pilha;

int criaPilha(Pilha *pilha, int s)
{
    pilha->v = malloc(sizeof(Item) * s);
    if (pilha->v == NULL)
        return 1;

    pilha->size = s;
    pilha->elem = -1;
    return 0;
}

int estaVazia(Pilha *pilha)
{
    return pilha->elem == -1;
}

Item espia(Pilha *pilha)
{

    return pilha->v[pilha->elem];
}

int estaCheia(Pilha *pilha)
{
    return pilha->elem == pilha->size;
}

int empilha(Pilha *pilha, Item e)
{
    if (estaCheia(pilha))
        return 1;

    pilha->elem++;
    pilha->v[pilha->elem] = e;
    return 0;
}

// se a pilha estiver vazia, imprime null
// se tiver algum elemento, ela apenas printa o ultimo
int desempilha(Pilha *pilha)
{
    if (estaVazia(pilha))
    {
        printf("NULL\n");
        return 1;
    }
    printf("%s\n", pilha->v[pilha->elem].name);
    pilha->elem--;
    return 0;
}

void desalocaPilha(Pilha *pilha)
{
    free(pilha->v);
    return;
}

int main()
{
    // String de input
    char input[101];

    // Cria pilha
    Pilha pilha;
    criaPilha(&pilha, 100);

    // Puxar dado de opção
    while (scanf("%s", input) != EOF)
    {
        // caso for desfazer, ele remove da pilha
        if (strstr(input, "desfazer"))
        {
            desempilha(&pilha);
            continue;
        }
        // empilha se for diferente
        Item e;
        char buf;

        // buffer para ler o nome
        scanf("%c", &buf);
        scanf("%[^\n]", e.name);
        empilha(&pilha, e);
    }

    desalocaPilha(&pilha);
    return 0;
}