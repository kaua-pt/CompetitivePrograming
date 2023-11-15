#include <stdio.h>

int check(char *input, int soma)
{
    if (input[2] == '\0')
    {
        return soma;
    }
    if (*input == input[2])
    {
        soma++;
        return check(input + 1, soma);
    }
    return check(input + 1, soma);
}

int main()
{
    char input[201];
    scanf("%s", input);
    printf("%d\n", check(input, 0));

    return 0;
}