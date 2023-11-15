#include <stdio.h>

int main()
{
    int n, i;
    char input[20000];
    scanf("%d", &n);

    while (n != 0)
    {
        int alice = 0, beto = 0;
        scanf(" %[^\n]s", input);
        n = n * 2;
        for (i = 0; i < n; i++)
        {
            if (n % 2 == 0)
            {
                if (input[i] == '1')
                {
                    beto++;
                }
                if (input[i] == '0')
                {
                    alice++;
                }
            }
        }
        printf("Alice ganhou %d e Beto ganhou %d\n", alice, beto);
        scanf("%d", &n);
    }

    return 0;
}