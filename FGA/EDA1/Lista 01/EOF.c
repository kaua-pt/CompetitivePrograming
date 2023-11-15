#include <stdio.h>

int main()
{
    int x, inputedNum = 0;

    while (scanf("%d", &x) != EOF)
    {
        inputedNum++;
    }

    printf("%d", inputedNum);

    return 0;
}