#include <stdlib.h>
#include <stdio.h>

typedef struct Pista
{
    int id;
    int value;
    int next;
} Pista;

typedef struct Pilha
{
    Pista *p;
    int size;
    int elem;
} Pilha;


void criaPilha(Pilha *pilha, int s){
    pilha->p = malloc(sizeof(Pilha) * s);
    pilha->size = s;
    pilha->elem = -1;
}

int estaVazia(Pilha *pilha){
    return pilha->elem == -1;
}

int estaCheia(Pilha *pilha){
    return pilha->elem == pilha->size;
}

Pista espia(Pilha *pilha){
    return pilha->p[pilha->elem];
}

int empilha(Pilha *pilha, Pista e){
    if (estaCheia(pilha))
        return 1;

    pilha->elem++;
    pilha->p[pilha->elem] = e;
    return 0;
}

int desempilha(Pilha *pilha){
    if (estaVazia(pilha))
        return 1;

    pilha->elem--;
    return 0;
}

void desalocaPilha(Pilha *pilha){
    free(pilha);
}

int main(){

    int numero_linhas;
    scanf("%d", &numero_linhas);

    struct Pista* pistas = (struct Pista*)malloc(sizeof(struct Pista) * numero_linhas);

    int value,next,id;
    for(int i = 0; i < numero_linhas; i++) {
        scanf("%d %d %d", &id, &value, &next);
        pistas[i].id = id;
        pistas[i].value = value;
        pistas[i].next = next;
    }
    
    Pilha pilha;
    criaPilha(&pilha,numero_linhas);
    int fim_local;

    // obter fim, o primeiro valor a ser empilhado, o que tem next == -1
    for (int n = 0; n < numero_linhas; n++){
        int fim = 0;
        if (pistas[n].next == -1){
            fim = 1;
            fim_local = n;
        }

        if(fim == 1){
            empilha(&pilha, pistas[n]);
        }
    }

    //colocando os outros e passando pela lista varias vezes
    for (int j = 0; j < numero_linhas; j++){
        for (int i = 0; i < numero_linhas; i++){
            //so empilha a pista se o valor next dela for o mesmo do id do topo/ultimo valor empilhado 
            if (pistas[i].next == pistas[fim_local].id){
                empilha(&pilha, pistas[i]);
                fim_local = i;
            }       
        }
    }
    
    //print
    int k;
    for (k = pilha.elem; k >= 0; k--)
        printf("%d\n", pilha.p[k].value);
/*
3
10 35 80
20 50 -1
80 57 20
*/
    return 0;
}
