#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char Item;

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

int desempilha(Pilha *pilha)
{
    if (estaVazia(pilha))
    {
        return 1;
    }
    pilha->elem--;
    return 0;
}

void desalocaPilha(Pilha *pilha)
{
    free(pilha->v);
    return;
}

// Estratifica a string em caracteres e aloca na pilha
void breakString(char *input, Pilha *pilha)
{
    int i;
    // obter tamanho da string
    int size = strlen(input);
    for (i = 0; i < size; i++)
    {

        // se for um desses caracteres, ele verifica se o anterior
        // da pilha é igual, se for ele desempilha, senao, empilha
        if (input[i] == '*' || input[i] == '/' || input[i] == '_')
        {
            if (input[i] == '*' && espia(pilha) == '*')
            {
                desempilha(pilha);
                continue;
            }
            if (input[i] == '/' && espia(pilha) == '/')
            {
                desempilha(pilha);
                continue;
            }
            if (input[i] == '_' && espia(pilha) == '_')
            {
                desempilha(pilha);
                continue;
            }
            empilha(pilha, input[i]);
        }
    }
    return;
}

int main()
{
    // Exercicio de pilha
    Pilha pilha;
    criaPilha(&pilha, 100000);
    char input[(int)1e6];
    int i, j;

    // Escaneia informações
    scanf("%d", &i);
    for (j = 0; j <= i; j++)
    {
        fgets(input, 1e6, stdin);
        // para cada frase, chama a funcao
        breakString(input, &pilha);
    }

    // se a pilha estiver vazia, printa C, senao printa E
    estaVazia(&pilha) ? printf("C\n") : printf("E\n");

    desalocaPilha(&pilha);
    return 0;
}