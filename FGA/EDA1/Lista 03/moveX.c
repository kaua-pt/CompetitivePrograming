#include <stdio.h>

void mover(char *string)
{
    if (*string == '\0')
    {
        return;
    }
    if (*string == 'x')
    {
        mover(string + 1);
        printf("%c", *string);
    }
    else
    {
        printf("%c", *string);
        mover(string + 1);
    }
}

int main()
{
    char string[100];
    scanf("%s", string);
    mover(string);
    return 0;
}