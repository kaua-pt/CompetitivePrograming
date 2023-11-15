#include <stdio.h>

int main()
{
    long int vetor[10000];
    int notalida, rep, dia = 0;
    long int codigolido;

    while (scanf(" %d", &rep) != EOF)
    {
        int i, j;
        long int menorCodigo = 110000000;
        int maiorAva = -1;
        dia++;

        for (j = 0; j < rep; j++)
        {
            scanf(" %ld %d", &codigolido, &notalida);

            if (maiorAva < notalida)
            {
                maiorAva = notalida;
                menorCodigo = codigolido;
            }
            if ((maiorAva == notalida) && menorCodigo > codigolido)
            {
                menorCodigo = codigolido;
            }
        }

        printf("Dia %d\n", dia);
        printf("%ld\n", menorCodigo);
        printf("\n");
    }

    return 0;
}