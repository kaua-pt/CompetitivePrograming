#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ht[109][20];
int tamanho = 0;

int hash(char *entrada)
{
  int h = 0, retorno = 0;
  for (int i = 0; entrada[i] != '\0'; i++)
    h += entrada[i] * (i + 1LL);

  retorno = (h * 19) % 101;
  return retorno;
}

int busca(char *buscado)
{
  int h = hash(buscado);

  for (int j = 0; j < 20; j++)
  {
    int i = (h + j * j + 23LL * j) % 101;
    if (strcmp(ht[i], buscado) == 0)
      return 1;
  }

  return 0;
}

void inserir(char *entrada)
{
  if (busca(entrada))
    return;

  int h = hash(entrada);
  for (int j = 0; j < 20; j++)
  {
    int i = (h + j * j + 23LL * j) % 101;

    if (*ht[i] == '\0')
    {
      strcpy(ht[i], entrada);
      tamanho++;
      break;
    }
  }
}

void remover(char *entrada)
{
  int h = hash(entrada);
  for (int j = 0; j < 20; j++)
  {
    int i = (h + j * j + 23LL * j) % 101;

    if (strcmp(ht[i], entrada) == 0)
    {
      *ht[i] = '\0';
      tamanho--;
    }
  }
}

int main()
{
  int t;
  scanf(" %d", &t);

  while (t--)
  {
    for (int i = 0; i < 101; i++)
      *ht[i] = '\0';
    tamanho = 0;

    int n;
    scanf(" %d", &n);

    char operacao[4], entrada[16];

    while (n--)
    {
      scanf(" %s:%s", operacao, entrada);
      if (operacao[0] == 'A')
        inserir(entrada);
      else
        remover(entrada);
    }
    printf("%d\n", tamanho);
    for (int i = 0; i < 101; i++)
      if (*ht[i] != '\0')
        printf("%d:%s\n", i, ht[i]);
  }
  return 0;
}