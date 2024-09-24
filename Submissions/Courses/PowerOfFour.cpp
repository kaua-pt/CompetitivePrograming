#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n)
{
    bool IsPowerOfFour = false;
    if (!n)
        return false;
    if (n == 1)
        return true;
    for (int i = 0; i < 32; i++)
    {
        // n shifitado i vezes é impar(potencia de 4) e i é par
        if (((n >> i) & 1) && (i & 1) == 0 && IsPowerOfFour)
            IsPowerOfFour = true;
        else
            IsPowerOfFour = false;
    }
}