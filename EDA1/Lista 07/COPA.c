#include <stdio.h>

int main()
{
    char timesQ[8], timesS[4], timesF[2], timeV;
    int t1, t2, i;

    for (i = 0; i < 8; i++)
    {
        scanf("%d %d", &t1, &t2);
        if (t1 > t2)
        {
            timesQ[i] = (char)65 + (2 * i);
        }
        else
        {
            timesQ[i] = (char)65 + (2 * i) + 1;
        }
    }

    for (i = 0; i < 4; i++)
    {
        scanf("%d %d", &t1, &t2);
        if (t1 > t2)
        {
            timesS[i] = timesQ[2 * i];
        }
        else
        {
            timesS[i] = timesQ[2 * i + 1];
        }
    }

    for (i = 0; i < 2; i++)
    {
        scanf("%d %d", &t1, &t2);
        if (t1 > t2)
        {
            timesF[i] = timesS[2 * i];
        }
        else
        {
            timesF[i] = timesS[2 * i + 1];
        }
    }

    scanf("%d %d", &t1, &t2);
    if (t1 > t2)
    {
        timeV = timesF[0];
    }
    else
    {
        timeV = timesF[1];
    }
    printf("%c", timeV);
    return 0;
}
