#include <stdio.h>
#include <stdlib.h>

/*
    Semelhante a uma lista encadeada, nela teremos o elemento posterior
    e o anterior com as estruturas basicas chamadas de nó.Falamos que os
    Nodes que vieram do inicial são filhos, se um Node não for pai, ele é
    uma folha.

    Suponha que x é um nó, um descentedente de x é todo aquele nó que possa ser
    alcançado atraves da iteração de x por x->next, seja dir ou esq;Assim, temos que
    x pode ser um root (raiz) de uma arvore que é o seu endereço, e que se ela tiver
    um pai, ela é uma subarvore de uma arvore maior, teremos sub direita e sub esquerda

    Modelos recursivos são melhores para este tipo de estrutura. Podemos percorrer a arvore
    de diversas maneiras, como D R E, OU E R D (pos ordem), ou R E D (pre ordem)

    Altura de um nó a distância ele e seu descendente mais afastado,já a altura de uma arvore
    é a distancia do root até a folha mais distante, a arvore está balanceada se a sub esquerda
    e a sub direita tiverem a mesma altura

    Para inserção, pode-se realizar o algoritmo de maior que e menor que, inserindo
    no campo de null.Isto pode eventualmente deixar a arvore desbalanceada, isto significa
    que a mesma quantidade de elementos a direita, contém da esquerda, isto ajuda algoritmos
    de busca;

    Tempos:
    Listas duplamente encadeadas e vetor nao ordenado: I/R em O(1) e busca em O(n)
    Vetores ordenados: I/R em O(n) e busca em O(log n)
    Arvores binarias de busca : O(log n)

    Busca em arvore binária, parecida com uma busca binária, mas a eficiencia depende da forma
    da arvore, se ela for uma arvore linear, como uma lista, custa O(n), se for uma arvore de
    verdade, custa O(log n).

    O minimo de uma arvore é o menor valor que ela pode assumir,o sucessor é o proximo elemento
    da arvore ordenada.

    Para remover de uma arvore binaria, pegamos o sucessor dele e colocamos no local do elemento
    então, removemos o sucessor do local.

    Arvores binarias completas: todos os níveis estão cheios, exceto o ultimo e os nós do ultimo
    nivel estão mais a esquerda possiveis, temos aqui a heap

*/

typedef struct Node
{
    int conteudo; // carga util
    Node *esq;
    Node *dir;
    Node *pai;
} Node;

typedef Node *pNo;

pNo inserir(pNo raiz, int valor)
{
    pNo no;
    if (raiz == NULL)
    {
        no = malloc(sizeof(Node));
        no->conteudo = valor;
        no->dir = NULL;
        no->esq = NULL;
        no->pai = no;
        return no;
    }
    if (valor < raiz->conteudo)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

pNo busca(pNo raiz, int valor)
{
    if (raiz == NULL || raiz->conteudo == valor)
        return raiz;
    if (valor < raiz->conteudo)
        return busca(raiz->esq, valor);
    if (valor > raiz->conteudo)
        return busca(raiz->dir, valor);
}

pNo min(pNo raiz)
{
    if (raiz->esq == NULL)
        return raiz;
    return min(raiz->esq);
}

pNo sucessor(pNo x)
{
    if (x->dir != NULL)
        return minimo(x->dir);
    else
        return ancestral_a_direita(x);
}

pNo ancestral_a_direita(pNo x)
{
    if (x == NULL)
        return NULL;
    if (x->pai == NULL || x->pai->esq == x)
        return x->pai;
    else
        return ancestral_a_direita(x->pai);
}

int main()
{
    return 0;
}