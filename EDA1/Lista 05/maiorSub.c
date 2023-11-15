#include <stdio.h>
#include <string.h>

// Não está correto

char input[101], sub[101];

int checkFinal(int place, int len, int leninp)
{
    if (len == 0)
    {
        return place;
    }
    if (input[leninp - 1] == sub[len - 1])
    {
        return checkFinal(place, len - 1, leninp - 1);
    }
    if (input[leninp - 1] != sub[len - 1])
    {
        place--;
        return checkFinal(place, strlen(sub), leninp - 1);
    }
}

int checkIni(char *input, char *s, int place, int len)
{
    if (len == 0)
    {
        return place;
    }
    if (*input == *s)
    {
        place++;
        return checkIni(input + 1, s + 1, place, len - 1);
    }
    if (*input != *s)
    {
        place++;
        return checkIni(input + 1, sub, place, strlen(sub));
    }
}

int main()
{
    int init, final;
    scanf("%s", input);
    scanf("%s", sub);
    init = checkIni(input, sub, 0, strlen(sub)) - strlen(sub);
    final = checkFinal(strlen(input), strlen(sub), strlen(input));
    if (final == (init + strlen(sub) + 1))
    {
        printf("%d\n", strlen(sub));
    }
    else
    {
        printf("%d\n", final - init);
    }
    return 0;
}