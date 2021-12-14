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
    char *PNome;
}TCliente;

typedef struct
{
    char Rua[MAX];
    char Bairro[MAX];
    unsigned int *Cep;
    char *PRua, *PBairro;
}TEndereco;

void CadastrarCliente(TCliente *P, TEndereco *Q)
{
    P->Codigo = (int *)malloc(sizeof(int));
    P->Idade = (int *)malloc(sizeof(int));
    P->Salario = (int *)malloc(sizeof(int));
    Q->Cep = (int *)malloc(sizeof(int));
    printf("Digite o codigo do cliente: ");
    scanf("%i", &P->Codigo);
    printf("\nDigite o nome do cliente: ");
    scanf("%s", &P->Nome);
    printf("\nDigite a idade do cliente: ");
    scanf("%i", &P->Idade);
    printf("\nDigite o salario do cliente: ");
    scanf("%i", &P->Salario);
    printf("\nDigite o nome da rua que o clinte mora: ");
    scanf("%s", &Q->Rua);
    printf("\nDigite o nome do bairro que o cliente mora: ");
    scanf("%s", &Q->Bairro);
    printf("\nDigite o CEP do cliente: ");
    scanf("%i", &Q->Cep);
}

void ImprimirCliente(TCliente *P, TEndereco *Q)
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
    printf("Rua: %s\n", Q->PRua);
    printf("Bairro: %s\n", Q->PBairro);
    printf("CEP: %i\n", Q->Cep);
}

void AlterarEndereco(TEndereco *Q)
{
    char NRua[MAX], NBairro[MAX];
    int i, NCEP;
    free(Q->PBairro);
    free(Q->PRua);
    Q->Cep = (int *)malloc(sizeof(int));
    printf("\nDigite o novo nome da rua que o clinte mora: ");
    scanf("%s", &NRua);
    printf("\nDigite o novo nome do bairro que o cliente mora: ");
    scanf("%s", &NBairro);
    printf("\nDigite o novo CEP do cliente: ");
    scanf("%i", &NCEP);
    Q->PRua = (char *)malloc(strlen(NRua) * sizeof(char));
    Q->PBairro = (char *)malloc(strlen(NBairro) * sizeof(char));
    Q->Cep = &NCEP;
    for (i = 0; i < strlen(Q->Rua); i ++)
    {
        Q->PRua[i] = NRua[i];
    }
    for (i = 0; i < strlen(Q->Bairro); i ++)
    {
        Q->PBairro[i] = NBairro[i];
    }
    for (i = 0; i < 100; i ++)
    {
        printf("\n");
    }
    printf("Nova Rua: %s\n", Q->PRua);
    printf("Novo Bairro: %s\n", Q->PBairro);
    printf("Novo CEP: %i\n", Q->Cep);
}

int main()
{
    TCliente P;
    TEndereco Q;
    int i;
    char sn[4];
    CadastrarCliente(&P, &Q);
    P.PNome = (char *)malloc(strlen(P.Nome) * sizeof(char));
    Q.PRua = (char *)malloc(strlen(Q.Rua) * sizeof(char));
    Q.PBairro = (char *)malloc(strlen(Q.Bairro) * sizeof(char));
    for (i = 0; i < strlen(P.Nome); i ++)
    {
        P.PNome[i] = P.Nome[i];
    }
    for (i = 0; i < strlen(Q.Rua); i ++)
    {
        Q.PRua[i] = Q.Rua[i];
    }
    for (i = 0; i < strlen(Q.Bairro); i ++)
    {
        Q.PBairro[i] = Q.Bairro[i];
    }
    ImprimirCliente(&P, &Q);
    for (i = 0; i < 100; i ++)
    {
        printf("\n");
    }
    printf("Dejesa alterar o endereço do cliente?\n");
    scanf("%s", &sn);
    if (strcmp(sn, "sim") == 0)
    {
        AlterarEndereco(&Q);
        printf("\n");
    }
    return 0;
}

