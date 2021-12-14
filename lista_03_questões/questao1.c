#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct
{
    char *Nome;
    int Idade;
    float Altura;
}Taluno;

Taluno CriarAluno(Taluno *a, char LNome[], int LIdade, float LAltura)
{
    a->Nome = LNome;
    a->Idade = LIdade;
    a->Altura = LAltura;
}

void ImprimirDados(Taluno *a)
{
    printf("\n\n\n");
    printf("Nome do aluno: %s\n", a->Nome);
    printf("Idade: %i\n", a->Idade);
    printf("Altura: %.2f\n", a->Altura);
}

void ModificarDados(Taluno *a, char NNome[], int NIdade, float NAltura)
{
    a->Nome = NNome;
    a->Idade = NIdade;
    a->Altura = NAltura;
}

int main()
{
    char LNome[MAX], sn[4], NNome[MAX];
    int LIdade, NIdade;
    float LAltura, NAltura;
    Taluno *a;
    a = (Taluno *)malloc(sizeof(Taluno));
    if (a != NULL)
    {
        printf("Digite o nome do aluno: ");scanf("%s", &LNome);
        printf("Digite a idade do aluno: ");scanf("%i", &LIdade);
        printf("Digite a altura do aluno: ");scanf("%f", &LAltura);
        CriarAluno(a, LNome, LIdade, LAltura);
        ImprimirDados(a);
        printf("\n\n\n");
        printf("Deseja modificar os dados do aluno: ");scanf("%s", &sn);
        if (strcmp(sn, "sim") == 0)
        {
            printf("Digite o novo nome do aluno: ");scanf("%s", &NNome);
            printf("Digite a nova idade do aluno: ");scanf("%i", &NIdade);
            printf("Digite a nova altura do aluno: ");scanf("%f", &NAltura);
            ModificarDados(a, NNome, NIdade, NAltura);
            printf("\n\n");
            ImprimirDados(a);
        }
        else
        {
            return 1;
        }
    }
    printf("Deseja liberar o aluno: ");scanf("%s", &sn);
    if (strcmp(sn, "sim") == 0)
    {
        free(a);
        printf("Aluno liberadoa\n");
    }
    return 0;
}

