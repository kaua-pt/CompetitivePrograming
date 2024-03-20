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

void menu();

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

    printf("vrau");

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

void cadastraPessoa()
{
    FILE *f = fopen("pessoas.bin", "r+b");
    Pessoa p;

    printf("Digite o nome da pessoa: ");
    scanf("%s", p.nome);

    printf("Digite o CPF da pessoa: ");
    while (1)
    {
        scanf("%s", p.cpf);
        if (validarCPF(p.cpf) && procuraPessoa(p.cpf, f))
            break;
        printf("CPF invalido ou repetido\n Digite novamente: ");
    }

    printf("Digite o RG da pessoa: ");
    scanf("%s", p.rg);

    fwrite(&p, sizeof(Pessoa), 1, f);
    fclose(f);

    printf("\nRegistrar mais pessoas?\n");
    printf("1-Sim\n2-Nao\n");
    int choose;
    scanf("%d", &choose);

    if (choose == 1)
    {
        system("cls");
        cadastraPessoa();
    }
    else
        printf("Aperte enter\n");
    getchar();
    system("cls || clear");
    menu();
    return;
}
void cadastraCarro()
{
    FILE *fPessoa = fopen("pessoas.bin", "r+b");
    FILE *fCarro = fopen("carro.bin", "r+b");
    Pessoa p;
    Carro c;

    printf("Digite o RENAVAM do carro: ");
    while (1)
    {
        scanf("%s", c.renavam);
        if (validarRENAVAM(c.renavam) && procuraRenavam(c.renavam, fCarro))
            break;
        printf("Renavam invalido ou repetido\n Digite novamente: ");
    }

    printf("Digite o CHASSI do carro: ");
    while (1)
    {
        scanf("%s", c.chassi);
        if (procuraChassi(c.chassi, fCarro))
            break;
        printf("Chassi invalido ou repetido\n Digite novamente: ");
    }

    printf("Digite o MODELO do carro: ");
    scanf("%s", c.modelo);

    printf("Digite a PLACA do carro: ");
    while (1)
    {
        scanf("%s", c.placa);
        if (procuraPlaca(c.placa, fCarro))
            break;
        printf("Placa invalida ou repetida\n Digite novamente: ");
    }
    scanf("%s", c.placa);

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

    printf("\nRegistrar mais carros?\n");
    printf("1-Sim\n2-Nao\n");
    int choose;
    scanf("%d", &choose);

    if (choose == 1)
    {
        system("cls");
        cadastraCarro();
    }
    else
        printf("Aperte enter\n");
    getchar();
    system("cls || clear");
    menu();
    return;
};

void finalizar()
{
    FILE *fPessoa = fopen("pessoas.bin", "r+b");
    FILE *fCarro = fopen("carro.bin", "r+b");
    Pessoa p;
    Carro c;

    while (!feof(fPessoa))
    {
        int i = 1;
        fread(&p, sizeof(Pessoa), 1, fPessoa);
        printf("Pessoa %d \n Nome: %s \n CPF: %s \n RG: %s\n", i, p.nome, p.cpf, p.rg);
        printf("Carros registrados:\n");
        while (!feof(fCarro))
        {
            int j = 1;
            fread(&c, sizeof(Carro), 1, fCarro);
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
    return;
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