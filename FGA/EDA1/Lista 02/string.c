#include <stdio.h>

int main()
{
    int input;

    while (scanf("%x", &input) != EOF)
    {
        int a;
        char *prt = &input;

        for (a = 0; a < 4; a++)
        {
            if (prt[a] == 0)
            {
                printf("\n");
                return 0;
            }
            printf("%c", (char)prt[a]);
        }
    }
}