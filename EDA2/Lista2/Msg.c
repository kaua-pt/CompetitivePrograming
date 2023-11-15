#include <stdio.h>
#include <stdlib.h>

#define M (1 << 22)

int main()
{
    unsigned int menor = (1 << 20), numero;
    char *v = calloc(M, sizeof(char)), l;

    while (scanf("%u %c", &numero, &l) != EOF)
    {
        v[numero] = l;

        if (numero < menor)
            menor = numero;
    }

    printf("%s\n", &v[menor]);
    return 0;
}