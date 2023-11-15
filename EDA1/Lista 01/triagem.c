#include <stdio.h>
#include <string.h>

int main()
{
    int flag = 0, triagem = 0, i = 0;
    char x[4];

    while (scanf("%s", x) != EOF)
    {
        i++;

        if (strcmp(x, "sim") == 0)
        {
            flag++;
        }
        if (i == 10)
        {
            i = 0;
            if (flag >= 2)
            {
                triagem++;
            }
            flag = 0;
        }
    }

    printf("%d\n", triagem);

    return 0;
}