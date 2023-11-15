#include <stdio.h>
#include <stdlib.h>

// runtime

int somaDigitos(char *input, int soma)
{
    if (*input == '\0')
    {
        return soma;
    }

    soma = soma + (*input - '0');
    return somaDigitos(input + 1, soma);
}

int main()
{
    char *input = malloc(sizeof(char) * 14);

    scanf("%s", input);

    printf("%d\n", somaDigitos(input, 0));

    free(input);

    return 0;
}