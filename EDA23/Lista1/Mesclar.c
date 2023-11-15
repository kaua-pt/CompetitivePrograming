#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3)
{
    celula *cel1 = l1->prox, *cel2 = l2->prox, *root = l3;

    while (cel1 != NULL && cel2 != NULL)
    {
        if (cel1->dado < cel2->dado)
        {
            root->prox = cel1;
            cel1 = cel1->prox;
        }
        else
        {
            root->prox = cel2;
            cel2 = cel2->prox;
        }
        root = root->prox;
    }
    if (cel1 == NULL)
        root->prox = cel2;
    else
        root->prox = cel1;
}
