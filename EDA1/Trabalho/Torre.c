#include <stdio.h>
#include <stdlib.h>

void reveal(char **map)
{
}

int main()
{
    int alt, larg, torres, i, j, num;
    scanf("%d %d", &alt, &larg);
    char camp[alt][larg];

    for (i = 0; i < alt; i++)
    {
        scanf("%s", camp[i]);
        int j;
        for (j = 0; j < larg; j++)
        {
            if (camp[i][j] == 't')
                torres++;
        }
    }

    for (j = 0; j < torres; j++)
    {
        scanf("%d", &num);
        revel(camp);
    }

    return 0;
}