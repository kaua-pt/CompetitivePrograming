#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Pessoa
{
    char nome[101];
    char cpf[12];
    char rg[9];
} Pessoa;

typedef struct Carro
{
    char renavam[12];
    char chassi[18];
    char modelo[100];
    char placa[7];
    char cor[50];
    int ano;
    char fk_pessoa[12];
} Carro;

FILE *Open_file(char *path, char *mode)
{
    FILE *database;
    database = fopen(path, mode);

    if (database == NULL)
        return fopen(path, "w+b");

    return database;
}

int validarCPF(const char *cpf)
{

    for (int i = 0; i < 11; i++)
        if (!isdigit(cpf[i]))
            return 0;

    int todosIguais = 1;
    for (int i = 1; i < 11; i++)
        if (cpf[i] != cpf[0])
        {
            todosIguais = 0;
            break;
        }

    if (todosIguais)
        return 0;

    int soma = 0;
    for (int i = 0; i < 9; i++)
        soma += (cpf[i] - '0') * (10 - i);

    int digito1 = (soma * 10) % 11;
    if (digito1 == 10)
        digito1 = 0;

    if (cpf[9] - '0' != digito1)
        return 0;

    soma = 0;
    for (int i = 0; i < 10; i++)
        soma += (cpf[i] - '0') * (11 - i);

    int digito2 = (soma * 10) % 11;
    if (digito2 == 10)
        digito2 = 0;

    if (cpf[10] - '0' != digito2)
        return 0;

    return 1;
}

int validarRENAVAM(const char *renavam)
{
    if (strlen(renavam) != 11)
        return 0;

    for (int i = 0; i < 11; i++)
        if (!isdigit(renavam[i]))
            return 0;

    int soma = 0;
    for (int i = 0; i < 10; i++)
        soma += (renavam[i] - '0') * (2 + i % 8);

    int digito = soma % 11;
    if (digito == 10)
        digito = 0;

    if (renavam[10] - '0' != digito)
        return 0;

    return 1;
}

int procuraPessoa(char *pessoa, FILE *f)
{
    Pessoa p;

    while (!feof(f))
    {
        fread(&p, sizeof(Pessoa), 1, f);
        if (strstr(pessoa, p.cpf) != NULL)
            return 1;
    }

    return 0;
}

int procuraRenavam(char *renavam, FILE *f)
{
    Carro c;

    while (!feof(f))
    {
        fread(&c, sizeof(Carro), 1, f);
        if (strstr(renavam, c.renavam) != NULL)
            return 1;
    }

    return 0;
}

int procuraChassi(char *chassi, FILE *f)
{
    Carro c;

    while (!feof(f))
    {
        fread(&c, sizeof(Carro), 1, f);
        if (strstr(chassi, c.chassi) != NULL)
            return 1;
    }

    return 0;
}

int procuraPlaca(char *placa, FILE *f)
{
    Carro c;

    while (!feof(f))
    {
        fread(&c, sizeof(Carro), 1, f);
        if (strstr(placa, c.placa) != NULL)
            return 1;
    }

    return 0;
}

int compare_pessoas(const void *a, const void *b)
{
    Pessoa *pessoa_a = (Pessoa *)a;
    Pessoa *pessoa_b = (Pessoa *)b;
    return strcmp(pessoa_a->cpf, pessoa_b->cpf);
}

void ordenaPessoa()
{
    FILE *f = fopen("pessoas.bin", "rb");

    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);

    Pessoa *pessoas = (Pessoa *)malloc(file_size);

    int i = 0, j;
    while (fread(&pessoas[i], sizeof(Pessoa), 1, f) == 1)
        i++;

    fclose(f);

    qsort(pessoas, i, sizeof(Pessoa), compare_pessoas);

    f = fopen("pessoas.bin", "wb");

    for (j = 0; j < i; j++)
        fwrite(&pessoas[j], sizeof(Pessoa), 1, f);

    fclose(f);
    free(pessoas);
}

int compare_carros(const void *a, const void *b)
{
    Carro *carro_a = (Carro *)a;
    Carro *carro_b = (Carro *)b;
    return strcmp(carro_a->renavam, carro_b->renavam);
}

void ordenaCarro()
{
    FILE *f = fopen("carro.bin", "rb");

    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);

    Carro *carros = (Carro *)malloc(file_size);

    int i = 0, j;
    while (fread(&carros[i], sizeof(Carro), 1, f) == 1)
        i++;

    fclose(f);

    qsort(carros, i, sizeof(Carro), compare_carros);

    f = fopen("carro.bin", "wb");

    for (j = 0; j < i; j++)
        fwrite(&carros[j], sizeof(Carro), 1, f);

    fclose(f);
    free(carros);
}

void menu();

void cadastraPessoa()
{
    FILE *f = Open_file("pessoas.bin", "r+b");
    Pessoa p;

    printf("Digite o nome da pessoa: ");
    scanf("%s", p.nome);

    printf("Digite o CPF da pessoa: ");
    while (1)
    {
        scanf("%s", p.cpf);
        if (validarCPF(p.cpf) && !procuraPessoa(p.cpf, f))
            break;
        printf("CPF invalido ou repetido\n Digite novamente: ");
    }

    printf("Digite o RG da pessoa: ");
    scanf("%s", p.rg);

    fwrite(&p, sizeof(Pessoa), 1, f);
    fclose(f);

    ordenaPessoa();
    return;
}

void cadastraCarro()
{
    FILE *fPessoa = Open_file("pessoas.bin", "r+b");
    FILE *fCarro = Open_file("carro.bin", "r+b");
    Pessoa p;
    Carro c;

    printf("Digite o RENAVAM do carro: ");
    while (1)
    {
        scanf("%s", c.renavam);
        if (!procuraRenavam(c.renavam, fCarro))
            break;
        printf("Renavam invalido ou repetido\n Digite novamente: ");
    }

    printf("Digite o CHASSI do carro: ");
    while (1)
    {
        scanf("%s", c.chassi);
        if (!procuraChassi(c.chassi, fCarro))
            break;
        printf("Chassi invalido ou repetido\n Digite novamente: ");
    }

    printf("Digite o MODELO do carro: ");
    scanf("%s", c.modelo);

    printf("Digite a PLACA do carro: ");
    while (1)
    {
        scanf("%s", c.placa);
        if (!procuraPlaca(c.placa, fCarro))
            break;
        printf("Placa invalida ou repetida\n Digite novamente: ");
    }

    printf("Digite a COR do carro: ");
    scanf("%s", c.cor);

    printf("Digite o ANO do carro: ");
    scanf("%d", &c.ano);

    printf("Digite o cpf do dono do carro: ");
    while (1)
    {
        scanf("%s", c.fk_pessoa);
        if (procuraPessoa(c.fk_pessoa, fPessoa))
            break;
        printf("Pessoa nao cadastrada\n Digite novamente: ");
    }

    fwrite(&c, sizeof(Carro), 1, fCarro);
    fclose(fCarro);
    fclose(fPessoa);
    ordenaCarro();
    return;
};

void finalizar()
{
    FILE *fPessoa = Open_file("pessoas.bin", "r+b");
    FILE *fCarro = Open_file("carro.bin", "r+b");
    Pessoa p;
    Carro c;
    int i = 1;

    fseek(fPessoa, 0, SEEK_SET);
    while (fread(&p, sizeof(Pessoa), 1, fPessoa))
    {
        printf("Pessoa %d \n  Nome: %s \n  CPF: %s \n  RG: %s\n", i, p.nome, p.cpf, p.rg);

        printf("Carros registrados:\n");
        int j = 1;
        fseek(fCarro, 0, SEEK_SET);
        while (fread(&c, sizeof(Carro), 1, fCarro))
        {
            if (strstr(c.fk_pessoa, p.cpf) != NULL)
            {
                printf("Carro %d\n", j);
                printf("    Placa: %s\n", c.placa);
                printf("    Renavam: %s\n", c.renavam);
                printf("    Modelo: %s\n", c.modelo);
                printf("    Chassi: %s\n", c.chassi);
                printf("    Ano: %d\n", c.ano);
                printf("    Cor: %s\n", c.cor);
                printf("\n");
            }
            j++;
        }

        i++;
        printf("\n");
    }
}

void menu()
{
    while (1)
    {
        int escolha;
        printf("1 - Cadastro de Pessoa\n");
        printf("2 - Cadastro de Carro\n");
        printf("3 - Finalizar cadastros\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            cadastraPessoa();
            break;
        case 2:
            cadastraCarro();
            break;
        case 3:
            system("cls || clear");
            finalizar();
            exit(0);
            break;
        default:
            printf("Invalid option %d\n");
            break;
        }
    }
    return;
}

int main()
{
    menu();
    return 0;
}