#include <stdio.h>

void ultP(int *input, int soma, int value)
{

    if (*input == 0)
    {
        return;
    }
    if ((soma + *input) > value)
    {
        ultP(input + 1, 0, value);
        printf("%d\n", *input);
    }
    else
    {
        ultP(input + 1, soma + *input, value);
    }
}

int main()
{
    int input[1000], i = 0, value;

    while (scanf(" %d", &input[i]))
    {
        if (input[i] == 0)
            break;

        i++;
    }

    scanf("%d", &value);
    ultP(input, 0, value);

    return 0;
}