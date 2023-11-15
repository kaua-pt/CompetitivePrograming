#include <stdio.h>
#include <stdlib.h>
#define M 128

typedef struct Item
{
    char name;
} Item;

typedef struct Pilha
{
    Item *v;
    int size;
    int elem;
} Pilha;

int voltarRecursao(Pilha *pilha){};

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
typedef struct Cell
{
    int cima, tras, dir, esq, visited;
} Cell;

Cell matrix[M][M];
int estaVoltando = 0, primeiroPassoVolta = 0, xInit = M / 2, yInit = M / 2, direction = 0;

int rodarRato(char d)
{
    if (d == 'd')
    {
        direction++;
        if (direction == 4)
            direction = 0;
    }
    if (d == 'e')
    {
        direction--;
        if (direction == -1)
            direction = 3;
    }
}

int frente(int retorno)
{
    return (retorno << 0) & 1;
}
int direita(int retorno)
{
    return (retorno << 1) & 1;
}
int tras(int retorno)
{
    return (retorno << 2) & 1;
}
int esqueda(int retorno)
{
    return (retorno << 3) & 1;
}

void rEmpilhar(Pilha *pilha, char op)
{
    Item e;
    e.name = op;
    empilha(pilha, e);
}

void reWalk()
{
    if (direction == 0)
        direction == 2;
    if (direction == 1)
        direction = 3;
    if (direction == 2)
        direction = 0;
    if (direction == 3)
        direction = 1;
}

void walk()
{
    if (direction == 0)
        yInit++;
    if (direction == 1)
        xInit++;
    if (direction == 2)
        yInit--;
    if (direction == 3)
        xInit--;
}

int isMatch()
{
    return matrix[xInit][yInit].visited;
}

int andarFrente(Pilha *pilha)
{
    walk();
    if (isMatch())
    {
        if (direction == 0)
            yInit--;
        if (direction == 1)
            xInit--;
        if (direction == 2)
            yInit++;
        if (direction == 3)
            xInit++;
        primeiroPassoVolta = 1;
        voltarRecursao(pilha);
    }
    if (estaVoltando == 0)
    {
        rEmpilhar(pilha, 'F');
    }
    printf("m");
    return 1;
}
void andarDir(Pilha *pilha)
{
    if (estaVoltando == 0)
        rEmpilhar(pilha, 'D');

    printf("r");
    rodarRato('d');
}

void andarEsq(Pilha *pilha)
{
    if (estaVoltando == 0)
        rEmpilhar(pilha, 'E');
    printf("l");
    rodarRato('e');
}

void andarTras(Pilha *pilha)
{
    if (estaVoltando == 0)
    {
        rEmpilhar(pilha, 'T');
    }
    printf("l");
    printf("l");
}

int checagem()
{
    int data;
    printf("s");
    scanf("%d", &data);
    if (direita(data))
    {
        if (!matrix[xInit][yInit + 1].visited)
            return 1;
    }
    if (esqueda(data))
    {
        if (!matrix[xInit][yInit - 1].visited)
            return 2;
    }
    if (frente(data))
    {
        if (!matrix[xInit + 1][yInit].visited)
            return 3;
    }
    return 0;
}

void voltarRecursao(Pilha *pilha)
{
    reWalk();
    while (!estaVazia(pilha))
    {
        Item e = espia(pilha);
        desempilha(pilha);

        if (e.name == 'F' && primeiroPassoVolta)
        {
            walk();
            printf("l");
            printf("l");
            printf("m");
            primeiroPassoVolta = 0;
        }
        if (e.name == 'F' && !primeiroPassoVolta)
        {
            walk();
            printf("m");
        }
        if (e.name == 'D')
        {
            printf("l");
        }
        if (e.name == 'E')
        {
            printf("r");
        }

        int retorno = checagem();
        if (retorno != 0)
        {
            if (retorno == 1)
            {
                andarDir(pilha);
                andarFrente(pilha);
                return;
            }
            if (retorno == 2)
            {
                andarEsq(pilha);
                andarFrente(pilha);
                return;
            }
            if (retorno == 3)
                andarFrente(pilha);
            return;
        }
    }
}

int main()
{
    int data, prox;
    Pilha *pilha;
    criaPilha(pilha, 10000);

    while (1)
    {
        printf("s");
        scanf("%d", &data);
        printf("d");
        scanf("%d", &prox);

        matrix[xInit][yInit].visited = 1;

        if (prox == 0)
            break;

        if (frente(data))
        {
            andarFrente(pilha);
            continue;
        }
        if (direita(data))
        {
            andarDir(pilha);
            continue;
        }
        if (esqueda(data))
        {
            andarEsq(pilha);
            continue;
        }
        if (tras(data))
        {
            andarTras(pilha);
            continue;
        }
    }

    return 0;
}