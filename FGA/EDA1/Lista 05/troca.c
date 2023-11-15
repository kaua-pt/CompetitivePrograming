#include <stdio.h>

void troca(char *input)
{

    if (*input == '\0')
    {
        return;
    }
    if (*input == 'x')
    {
        printf("y");
        return troca(input + 1);
    }
    else
    {
        printf("%c", *input);
        return troca(input + 1);
    }
}

int main()
{
    char input[80];
    scanf("%s", input);
    troca(input);

    return 0;
}