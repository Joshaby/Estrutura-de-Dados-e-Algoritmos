#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct
{
    int *Codigo;
    char Nome[MAX];
    int *Idade;
    int *Salario;
    char Rua[MAX];
    char Bairro[MAX];
    int *Cep;
    char *PNome, *PRua, *PBairro;
}TCliente;

void CadastrarCliente(TCliente *P)
{
    P->Codigo = (int *)malloc(sizeof(int));
    P->Idade = (int *)malloc(sizeof(int));
    P->Salario = (int *)malloc(sizeof(int));
    P->Cep = (int *)malloc(sizeof(int));
    printf("Digite o codigo do cliente: ");
    scanf("%i", &P->Codigo);
    printf("\nDigite o nome do cliente: ");
    scanf("%s", &P->Nome);
    printf("\nDigite a idade do cliente: ");
    scanf("%i", &P->Idade);
    printf("\nDigite o salario do cliente: ");
    scanf("%i", &P->Salario);
    printf("\nDigite o nome da rua que o clinte mora: ");
    scanf("%s", &P->Rua);
    printf("\nDigite o nome do bairro que o cliente mora: ");
    scanf("%s", &P->Bairro);
    printf("\nDigite o CEP do cliente: ");
    scanf("%s", &P->Cep);
}

void ImprimirCliente(TCliente *P)
{
    int i;
    for (i = 0; i < 100; i ++)
    {
        printf("\n");
    }
    printf("Codigo do cliente: %i\n", P->Codigo);
    printf("Nome do cliente: %s\n", P->PNome);
    printf("Idade do cliente: %i\n", P->Idade);
    printf("Salario do cliente: %i\n", P->Salario);
    printf("\n");
    printf("Enderoço do Cliente\n");
    printf("\n");
    printf("Rua: %s\n", P->PRua);
    printf("Bairro: %s\n", P->PBairro);
    printf("CEP: %i\n", P->Cep);
}

int main()
{
    TCliente P;
    int i;
    CadastrarCliente(&P);
    P.PNome = (char *)malloc(strlen(P.Nome) * sizeof(char));
    P.PRua = (char *)malloc(strlen(P.Rua) * sizeof(char));
    P.PBairro = (char *)malloc(strlen(P.Bairro) * sizeof(char));
    for (i = 0; i < strlen(P.Nome); i ++)
    {
        P.PNome[i] = P.Nome[i];
    }
    for (i = 0; i < strlen(P.Rua); i ++)
    {
        P.PRua[i] = P.Rua[i];
    }
    for (i = 0; i < strlen(P.Nome); i ++)
    {
        P.PBairro[i] = P.Bairro[i];
    }
    ImprimirCliente(&P);
    return 0;
}

