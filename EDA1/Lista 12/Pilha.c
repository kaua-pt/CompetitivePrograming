typedef struct Item
{
    int i;
} Item;

typedef struct Pilha
{
    Item *v;
    int size;
    int elem;
} Pilha;

void criaPilha(Pilha *pilha, int s)
{
    pilha->v = malloc(sizeof(Pilha) * s);
    pilha->size = s;
    pilha->elem = 0;
}

int estaVazia(Pilha *pilha)
{
    return pilha->elem == 0;
}

int estaCheia(Pilha *pilha)
{
    return pilha->elem == pilha->size;
}

Item espia(Pilha *pilha)
{
    return pilha->v[pilha->elem];
}

int empilha(Pilha *pilha, Item e)
{
    if (estaCheia(pilha))
        return 1;

    pilha->v[pilha->elem++] = e;
    return 0;
}

int desempilha(Pilha *pilha)
{
    if (estaVazia(pilha))
        return 1;

    pilha->elem--;
    return 0;
}

void desalocaPilha(Pilha *pilha)
{
    free(pilha);
}
