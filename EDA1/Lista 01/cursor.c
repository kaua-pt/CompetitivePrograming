#include <stdio.h>

int encontrarUltimoChar(char *matrix)
{
    int i, contador = 0;

    for (i = 0; i < 1004; i++)
    {
        if (matrix[i] != '\0')
        {
            contador++;
        }
        else
        {
            return contador;
        }
    }
}

int main()
{
    int linhas, colunaI, linhaI, k, resultL, resultC, helperF;
    char x;
    char matrix[1004][1004];
    scanf("%d", &linhas);

    for (k = 1; k <= linhas; k++)
    {
        scanf(" %1000[^\n]s", matrix[k]);
    }

    scanf("%d %d", &linhaI, &colunaI);
    resultL = linhaI;
    resultC = colunaI;

    while (scanf("\n%c", &x) != EOF)
    {

        if (x == 'j')
        {
            if ((resultL + 1) <= linhas)
            {
                resultL = resultL + 1;

                helperF = encontrarUltimoChar(matrix[resultL]);

                //  5      >    8

                if ((resultC > helperF) || (resultC < helperF && helperF < colunaI))
                {
                    resultC = helperF;
                }
                else
                {
                    resultC = colunaI;
                }
            }
        }

        if (x == 'k')
        {

            if (resultL > 1)
            {
                resultL = resultL - 1;

                helperF = encontrarUltimoChar(matrix[resultL]);

                if (resultC > helperF || (resultC < helperF && helperF < colunaI))
                {
                    resultC = helperF;
                }
                else
                {
                    resultC = colunaI;
                }
            }
        }
        printf("%d %d %c\n", resultL, resultC, matrix[resultL][resultC - 1]);
    }

    return 0;
}
