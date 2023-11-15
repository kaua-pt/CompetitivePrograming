#include <stdio.h>
#include <string.h>

int main()
{
    int inputedNum = 0, flag = 0;
    char x[30];

    while (scanf("%s", x) != EOF)
    {
        if (strcmp(x, "marte") == 0)
        {
            flag = 1;
        }
    }

    flag == 1 ? printf("Leonardo Cicero Marciano") : printf("none");

    return 0;
}