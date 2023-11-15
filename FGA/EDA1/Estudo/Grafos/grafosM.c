#include <stdio.h>
#include <stdlib.h>

/*
    Grafos são um conjunto de vertices e arestas que conectam um par de vertices.Definimos
    um grafo como G = (Vertices,arestas). Temos os V = {1,2,3,4},e as A = {"ligacoes entre V"}
    Dois vertices são adjacentes de houver uma aresta ligando-os.

    Arco = Aresta, que está sempre conectando dois vertices

    Em um grafo, também temos a questão da direção(digrafos), se tivermos A->B, A está ligado
    a B, mas B não está ligado a A. Assim, um grau de um vertice é o numero de arestas ligadas
    a ele. Quando temos um digrafo, temos o conceito de grau de entrada e grau de saida.

    Um laço é um (V,V), ele está ligado a si mesmo

    Caminho é literalmente o caminho percorrido em um grafo de uma informação a outra, temos o
    seu comprimento(arestas) e o conceito de caminho simples que é o caminho sem repetir vertices
    e temos o de caminho ciclico e aciclico. Temos o conceito de multigrafo que é mais de uma aresta
    realizando a mesma ligação


    Representação de grafos
    Temos a matriz de adjacencia ou listas de adjacencias. Se tivermos muitas ligações, usa matriz
    senão usa aresta, se ele for esparso(poucas ligações) usa lista, ela usa o conceito de Nodes.

    - Matriz de adjacencia -> Matriz NxN no qual N é o número de vertices.Possui um alto custo (O(N^2))
    utiliza 0 para falar que não há ligação e 1 para indicar que há ligação, se não temos um digrafo,
    teremos uma matriz simetrica

    Problema das pontes de Konigsberg, fundou a teoria dos grafos, aqui temos o conceito de multigrafos
    normalmente usa lista de adjacencia

    Tempos:
                Matriz          Listas
    Inserir        1               1
    Remover        1              d(v)
    Existe ?       1              d(v)
    Vizinhos       V              d(v)

    Um grafo contém várias "partes", subdivisões que podemos chamar de componentes conexos,Então
    temos o problema de busca. Temos a busca em profundidade,na qual avançamos o máximo o possível
    se não encontrarmos o alvo, recuamos o minimo o possivel e pegamos um caminho não visitado

*/
typedef struct
{
    int **adj;
    int n;
} Grafo;

typedef Grafo *p_grafo;

p_grafo criar_grafo(int n)
{
    int i, j;
    // aloca grafo
    p_grafo g = malloc(sizeof(Grafo));
    // define tamanho
    g->n = n;

    // aloca altura
    g->adj = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        // aloca largura
        g->adj[i] = malloc(n * sizeof(int));

    // define tudo como 0, poderia usar calloc ?
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g->adj[i][j] = 0;
    return g;
}

void insere_aresta(p_grafo g, int u, int v)
{
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void remove_aresta(p_grafo g, int u, int v)
{
    g->adj[u][v] = 0;
    g->adj[v][u] = 0;
}

int tem_aresta(p_grafo g, int u, int v)
{
    return g->adj[u][v];
}

p_grafo le_grafo()
{
    int n, m, i, u, v;
    p_grafo g;
    scanf("%d %d", &n, &m);
    g = criar_grafo(n);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        insere_aresta(g, u, v);
    }
    return g;
}

int grau(p_grafo g, int u)
{
    int v, grau = 0;
    for (v = 0; v < g->n; v++)
        if (g->adj[u][v])
            grau++;
    return grau;
}

void imprime_arestas(p_grafo g)
{
    int u, v;
    for (u = 0; u < g->n; u++)
        for (v = u + 1; v < g->n; v++)
            if (g->adj[u][v])
                printf("{%d,%d}\n", u, v);
}

// desaloca tudo
void destroi_grafo(p_grafo g)
{
    int i;
    for (i = 0; i < g->n; i++)
        free(g->adj[i]);
    free(g->adj);
    free(g);
}

int main()
{
    return 0;
}