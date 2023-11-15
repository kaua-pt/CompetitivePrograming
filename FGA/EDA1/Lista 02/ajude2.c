#include <stdio.h>

int main(void)
{
    int rep, i, res, exp = 0, *vet;
    scanf("%d", &rep);
    vet = malloc(rep * sizeof(int));

    for (i = 0; i < rep; i++)
    {
        scanf("%d", &vet[i]);
        exp = exp + vet[i];
    }
    free(vet);
    scanf("%d", &res);

    if (res == exp)
    {
        printf("Acertou\n");
    }
    else
    {
        printf("Errou\n");
    }

    return 0;
}