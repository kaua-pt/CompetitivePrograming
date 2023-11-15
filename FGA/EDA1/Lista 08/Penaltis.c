#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// oxoxo // time A ganha
// ooxxo

int main()
{

    char *time1, *time2;
    int rodadas, i, equal = 0, rools = 0, time1G = 0, time2G = 0, f1, f2;

    scanf("%d", &rodadas);
    time1 = malloc((rodadas * sizeof(char)) + 1);
    time2 = malloc((rodadas * sizeof(char)) + 1);
    f1 = rodadas;
    f2 = rodadas;
    scanf(" %s", time1);
    scanf(" %s", time2);

    for (i = 0; i < rodadas; i++)
    {
        rools++;
        if (time1[i] == 'o')
        {
            time1G++;
        }
        f1--;
        if (time1G + f1 < time2G || time2G + f2 < time1G)
        {
            break;
        }

        rools++;
        if (time2[i] == 'o')
        {
            time2G++;
        }
        f2--;
        if (time1G + f1 < time2G || time2G + f2 < time1G)
        {
            break;
        }
    }

    if (time1G == time2G)
    {
        printf("Empate\n");
    }
    else
    {
        printf("%d\n", rools);
    }

    return 0;
}