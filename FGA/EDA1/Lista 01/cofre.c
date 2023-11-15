#include <stdio.h>

int main()
{
    int n, valora, valorb = 0, dif, difacumulada = 0, teste = 0, i, j;
    int valores[100];

    scanf("%d", &n);

    while (n != 0)
    {
        teste++;

        for (i = 0; i < n; i++)
        {

            scanf("%d %d", &valora, &valorb);
            dif = valora - valorb;

            if (i == 0)
            {
                valores[i] = dif;
            }
            else
            {
                valores[i] = dif + valores[i - 1];
            }
        }

        for (j = 0; j < n; j++)
        {
            printf("%d\n", valores[j]);
            if (j == (n - 1))
            {
                printf("\n");
            }
        }

        scanf("%d", &n);
    }

    return 0;
}