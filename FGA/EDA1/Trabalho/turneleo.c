#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Cidade
{
    char nome[27];
    char ultimaStr;
    char primeiraStr;

} Cidade;

typedef struct queue
{
    int l;
    int r;
    int maxsize;
    Cidade *q;

    char (*full)(struct queue *);

} queue;

char full(queue *q);

queue initialize(int maxs)
{
    queue new;

    new.q = malloc(sizeof(Cidade) * maxs);

    new.l = 0;
    new.r = 0;

    new.maxsize = maxs;
    new.full = full;

    return new;
}

char full(queue *q)
{
    return q->r == q->maxsize;
}

int empty(queue *q)
{
    if (q->l == q->r)
    {
        return 0;
    }
    return 1;
}

Cidade back(queue *q)
{
    return q->q[q->r - 1];
}

Cidade front(queue *q)
{
    return q->q[q->l];
}

void dequeue(queue *q)
{
    ++q->l;
}

void enqueue(queue *q, Cidade i)
{
    if (q->full(q))
        return;

    q->q[q->r++] = i;
}

int size(queue *q)
{
    return q->r - q->l;
}

void destroy(queue *q)
{
    free(q->q);
}

int main()
{
    char input[27];
    int size = 0, count = 0;

    // filaTemporaria
    queue fila;
    fila = initialize(1e6);

    // Pegando quais serao as cidade
    while (scanf("%s", &input) != EOF)
    {
        Cidade cidade;
        int qtd_letras = strlen(input);
        cidade.ultimaStr = input[qtd_letras - 1];
        cidade.primeiraStr = input[0];
        strcpy(cidade.nome, input);

        enqueue(&fila, cidade);
        count++;
    }

    // fila final
    queue filaFinal;
    filaFinal = initialize(count);

    // inserindo a primeira cidade
    Cidade city = front(&fila);
    enqueue(&filaFinal, city);

    while (empty(&fila) != 0)
    {

        dequeue(&fila);
        Cidade cityProx = front(&fila);
        Cidade cityAtual = back(&filaFinal);
        // colocando o ultimo char da cidade atual em maisculo para a comparacao
        char ultimastrUpper = toupper(cityAtual.ultimaStr);
        char primeiraToUpper = toupper(cityProx.primeiraStr);

        /*
        Se a próxima cidade começar com a mesma letra que termina o nome da cidade do
        show atual, essa cidade vai para o final da fila e a próxima cidade é onde será
        realizado o show
        */
        if (primeiraToUpper == ultimastrUpper)
        {
            enqueue(&fila, cityProx);
            dequeue(&fila);

            Cidade cityProx = front(&fila);
            enqueue(&filaFinal, cityProx);
        }
        else
        {
            enqueue(&filaFinal, cityProx);
        }
    }
    int k;
    for (k = 0; k < count; k++)
    {
        Cidade cityFront = front(&filaFinal);
        printf("%s\n", cityFront.nome);
        dequeue(&filaFinal);
    }

    destroy(&filaFinal);

    return 0;
}
