#include <stdio.h>

void inverte(char *input)
{

    if (*input == '\0')
    {
        return;
    }
    else
    {
        inverte(input + 1);
        printf("%c", *input);
    }
}

int main()
{
    char input[501];
    scanf("%s", input);
    inverte(input);

    return 0;
}