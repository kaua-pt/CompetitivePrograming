#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int v;
    struct No *prox;
} No;

typedef No *p_no;

typedef struct
{
    p_no *adjacencia;
    int n;
} Grafo;

typedef Grafo *p_grafo;

int main()
{

    return 0;
}
