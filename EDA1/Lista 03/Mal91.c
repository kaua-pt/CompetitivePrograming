#include <stdio.h>

int f91(int input)
{
    if (input > 100)
    {
        return input - 10;
    }
    else
    {
        return f91(f91(input + 11));
    }
}

int main()
{
    int input, result;
    scanf("%d", &input);

    while (input != 0)
    {
        result = f91(input);
        printf("f91(%d) = %d\n", input, result);
        scanf("%d", &input);
    }

    return 0;
}