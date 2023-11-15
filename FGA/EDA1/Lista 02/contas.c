#include <stdio.h>

int faz_conta_direito(int parcelas, char op)
{
    int *vet, i;
    vet = malloc(parcelas * sizeof(int));

    for (i = 0; i < parcelas; i++)
    {
        if (op == '+')
        {
            if (i == 0)
            {
                scanf("%d", &vet[i]);
            }
            else
            {
                scanf("%d", &vet[i]);
                vet[0] = vet[0] + vet[i];
            }
        }
        if (op == '-')
        {
            if (i == 0)
            {
                scanf("%d", &vet[i]);
            }
            else
            {
                scanf("%d", &vet[i]);
                vet[0] = vet[0] - vet[i];
            }
        }
    }
    return vet[0];
}
