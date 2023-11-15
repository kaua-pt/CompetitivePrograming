#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int computarDigitos(char input[1001], int soma)
{
    if (*input == '\0')
    {
        return soma;
    }
    else
    {
        soma = soma + (input[0] - '0');
        return computarDigitos(input + 1, soma);
    }
}

int somar_int(int num, int soma)
{
    if (num < 1)
    {
        return soma;
    }
    int resto = num % 10;
    soma = soma + resto;
    return somar_int(num / 10, soma);
}

int saberDegree(int soma, int degree)
{
    if (soma < 9)
    {
        return degree;
    }
    else if (soma == 9)
    {
        degree++;
        return degree;
    }
    else
    {
        degree++;
        soma = somar_int(soma, 0);
        return saberDegree(soma, degree);
    }
}

int main()
{
    char input[1001];
    int result, len;

    while (scanf("%s", input))
    {
        if (*input == '0')
            break;

        result = computarDigitos(input, 0);
        len = saberDegree(result, 0);

        if (result % 9 == 0)
        {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", input, len);
        }
        else
        {
            printf("%s is not a multiple of 9.\n", input);
        }
    }

    return 0;
}