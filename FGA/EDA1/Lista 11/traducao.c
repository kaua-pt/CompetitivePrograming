#include <stdio.h>
#include <string.h>

typedef struct
{
    char jap[81];
    char br[81];
} Traducao;

typedef struct
{
    char jap[81];
    char br[81];
} Letra;

void traducao(Traducao *trad, Letra *letra, int lenL, int lenT)
{
    char aux[81];
    char linha[81];
    int i, j;
    for (i = 0; i < lenL; i++)
    {
        char *token = strtok(letra[i].jap, ' ');
        while (token != NULL)
        {
            for (j = 0; j < lenT; j++)
            {
                if (strcmp(token, trad[j].jap) == 0)
                {
                    char v = strcat(trad[j].br, " ");
                    strcat(aux, v);
                }
                else
                {
                    char v = strcat(trad[j].jap, " ");
                    strcat(aux, v);
                }
            }
            token = strtok(NULL, " ");
        }
        strcpy(letra[i].br, aux);
    }
}

int main()
{
    Traducao *trad;
    Letra *letra;
    int inst, dic, musc, k;
    char aux[81];

    scanf("%d", &inst);

    while (inst != 0)
    {
        int i = 0, j = 0;
        scanf("%d %d", &dic, &musc);
        trad = malloc(sizeof(Traducao) * dic);
        letra = malloc(sizeof(Letra) * musc);

        do
        {
            scanf("[^( |\n)]%s", trad[i].jap);
            scanf("[^( |\n)]%s", trad[i].br);
            i++;
        } while (i < dic);

        while (j < musc)
        {
            scanf("[^( |\n)]%s", letra[j].jap);
            j++;
        }
        traducao(&trad, &letra, musc, dic);

        for (k = 0; k < musc; k++)
        {
            printf("%s\n", letra[k].br);
        }
        inst--;
    }
    return 0;
}