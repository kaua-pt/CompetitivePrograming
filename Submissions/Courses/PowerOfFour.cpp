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

// a ideia é, potencias de 4 estão presentes com um bit unico em posição par
// checa que tem bit ali
// se nao passa
/
; // se for arpar , verifica se tem em mais algum lugar
// se for par, verifica se tem em mais algum lugar