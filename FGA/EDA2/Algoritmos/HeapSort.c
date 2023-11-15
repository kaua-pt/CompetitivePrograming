/*
Ordenar uma heap - O(NlogN), space(N), extraSpace(1)

Assim como o Quicksort, ele precisa de duas funções: HeapSort e Cria Heap
A princípio, ele pega elementos do meio até o inicio do vetor para criar a heap,
assim, o elemento do topo da heap, vai para o final do vetor v e assim cria
novamente uma outra heap.

O importante é, para cada iteração do for debaixo, você vai colocar o elemento do topo
da heap na posição N-i do vetor normal, sendo N seu tamanho e I o indice do for;
*/

void criaHeap(int *v, int i, int f) 
{
    int aux = v[i];
    int j = i * 2 + 1; // calcula um dos filhos
    while (j <= f) // estou dentro do vetor ?
    {
        if (j < f)
            if (v[j] < v[j + 1]) // verifica qual dos filhos de i é maior
                j++;
        if (aux < v[j]) // filho é maior que o pai ?
        {
            // se sim, passa o filho maior para o pai
            v[i] = v[j];
            i = j;
            j = 2 * i + 1;
        }
        else
        {
            // se nao, apenas soma
            j = f + 1;
        }
    }
    v[i] = aux;
}

void heapSort(int *v, int n)
{
    int i, aux;
    for (i = (n - 1) / 2; i >= 0; i--) // cria heap de metade do vetor
        criaHeap(v, i, n);

    for (i = n - 1; i >= 1; i--) // passa pelo vetor trocando elementos
    {
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        criaHeap(v, 0, i - 1); // cria heap quando a troca termina
    }
}