#include <stdio.h>
#include <stdlib.h>
typedef char Item;

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
    return pilha->v[pilha->elem - 1];
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

char solucao(char *string)
{
    int i = 0;
    Pilha *pilha;

    criaPilha(pilha, 100000);
    // joga na pilha
    while (string[i] != '\n')
    {
        if (string[i] == '(' || string[i] == '[' || string[i] == '{')
        {
            empilha(pilha, string[i]);
        }
        else
        {

            if (string[i] == ')')
            {
                if (!estaVazia(pilha) && espia(pilha) == '(')
                {
                    desempilha(pilha);
                }
                else
                {
                    return 'N';
                }
            }

            if (string[i] == ']')
            {
                if (!estaVazia(pilha) && espia(pilha) == '[')
                {
                    desempilha(pilha);
                }
                else
                {
                    return 'N';
                }
            }

            if (string[i] == '}')
            {
                if (!estaVazia(pilha) && espia(pilha) == '{')
                {
                    desempilha(pilha);
                }
                else
                {
                    return 'N';
                }
            }
        }
        i++;
    }

    char result = estaVazia(pilha) ? 'S' : 'N';
    desalocaPilha(pilha);
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    char buff;
    scanf("%c", &buff);

    while (n--)
    {
        char s[(int)1e6];
        fgets(s, 1e6, stdin);
        printf("%c\n", solucao(s));
    }

    return 0;
}