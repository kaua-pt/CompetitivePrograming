#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int extrair(int **v)
{
    int n = 0;
    char input[4200000];
    while (scanf(" %s", input) == 1)
    {
        v[n] = malloc((strlen(input) + 1) * sizeof(char));
        strcpy(v[n], input);
        n++;
    }

    return n;
}

int solve(char *grandao, char *substr)
{
    int rep = 0;
    char *strLocal = strstr(grandao, substr);
    while (strLocal != 0)
    {
        strLocal++;
        strLocal = strstr(strLocal, substr);
        rep++;
    }

    return rep;
}

int main()
{
    char **v = malloc(100005 * sizeof(char *));
    int numstr, i;

    numstr = extrair(v);

    for (i = 0; i < numstr - 1; i++)
    {
        printf("%d\n", solve(v[i], v[numstr - 1]));
    }

    return 0;
}