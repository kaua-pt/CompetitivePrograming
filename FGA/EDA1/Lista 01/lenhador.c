#include <stdio.h>
#include <string.h>
#include <stdio.h>

char lado;
char matrix[1005][14];
int ladosPos[501];
char lados[501];
int rodadas, galhos;
int coef = 0;

int criarTronco();
int verificarGalhos();
int posicionarLenhador();
int bater();
int verificarMorte();
int trocarLado();
void printTronco();

int main()
{
    int i, j, help;
    char aux;
    char comando[2001];

    scanf("%d", &rodadas);
    scanf("%d", &galhos);

    for (i = 0; i < galhos; i++)
    {
        scanf(" %c", &aux);
        scanf("%d", &ladosPos[i]);
        lados[i] = aux;
    }

    scanf(" %c", &lado);
    scanf("%s", comando);
    // criando tronco;
    criarTronco();
    verificarGalhos();
    posicionarLenhador();
    printTronco();
    // jogar
    for (j = 0; j < strlen(comando); j++)
    {
        if (comando[j] == 'T')
        {
            if (trocarLado())
            {
                continue;
            }
            else
            {
                printTronco();
            }
        }
        if (comando[j] == 'B')
        {
            help = bater();
            if (help == 1)
            {
                break;
            }
            printTronco();
        }
    }

    return 0;
}

verificarMorte()
{
    if (lado == 'E' && matrix[coef + 2][2] == '-' && matrix[coef][4] == '>')
    {
        return 1;
    }
    if (lado == 'D' && matrix[coef + 2][8] == '-' && matrix[coef][6] == '<')
    {
        return 1;
    }
    return 0;
}

trocarLado()
{
    if (lado == 'D')
    {
        if (matrix[coef][2] == '-' || matrix[coef + 1][2] == '-')
        {
            printf("**beep**\n");
            return 1;
        }
        matrix[coef][2] = 'L';
        matrix[coef + 1][2] = 'L';
        matrix[coef][8] = ' ';
        matrix[coef + 1][8] = ' ';
        lado = 'E';
        return 0;
    }
    if (lado == 'E')
    {
        if (matrix[coef][8] == '-' || matrix[coef + 1][8] == '-')
        {
            printf("**beep**\n");
            return 1;
        }

        matrix[coef][2] = ' ';
        matrix[coef + 1][2] = ' ';
        matrix[coef][8] = 'L';
        matrix[coef + 1][8] = 'L';
        lado = 'D';
        return 0;
    }
}

posicionarLenhador()
{

    if (lado == 'D')
    {
        matrix[coef][8] = 'L';
        matrix[coef + 1][8] = 'L';
    }
    if (lado == 'E')
    {
        matrix[coef][2] = 'L';
        matrix[coef + 1][2] = 'L';
    }
}

verificarGalhos()
{
    int i, j;
    for (i = 0; i < galhos; i++)
    {
        j = ladosPos[i] - 1;
        if (lados[i] == 'D')
        {
            matrix[j][8] = '-';
            matrix[j][9] = '-';
            matrix[j][10] = '-';
        }
        if (lados[i] == 'E')
        {
            matrix[j][1] = '-';
            matrix[j][2] = '-';
            matrix[j][3] = '-';
        }
    }
}

criarTronco()
{
    int i, j, numLoop;

    for (i = 0; i < rodadas + 5; i++)
    {
        for (j = 0; j < 11; j++)
        {
            if (i < rodadas)
            {
                if (j == 4 || j == 5 || j == 6)
                {
                    matrix[i][j] = '|';
                }
                else
                {
                    matrix[i][j] = ' ';
                }
            }
            else
            {
                matrix[i][j] = ' ';
            }
        }
    }
}

bater()
{
    if (verificarMorte())
    {
        printf("**morreu**\n");
        return 1;
    }

    if ((matrix[coef][4] == '>' && lado == 'E') || (matrix[coef][6] == '<' && lado == 'D'))
    {
        coef++;
        posicionarLenhador();
        return 0;
    }

    if (matrix[coef][4] == '|' && lado == 'E')
    {
        matrix[coef][4] = '>';
        return 0;
    }

    if (matrix[coef][6] == '|' && lado == 'D')
    {
        matrix[coef][6] = '<';
        return 0;
    }
}

void printTronco()
{
    int i, j;

    printf("~~~~~~~~~~~\n");

    for (i = 4 + coef; i >= coef; i--)
    {
        for (j = 0; j < 11; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    printf("~~~~~~~~~~~\n");
}