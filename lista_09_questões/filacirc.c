#include <stdio.h>
#include <stdlib.h>
# define MAX 6

typedef struct 
{
    int Vetor[MAX];
    int Frente;
    int Atras;
    int Tamanho;
}FilaCirc;

void Interface()
{
    int i = 0;
    printf("\tEditor de listas V4\n\n");
    for(i = 0; i < 33; i ++)
    {
        printf("=");
    }
    printf("\n\n");
    for (i = 1; i <= 7; i ++)
    {
        if(i == 1) printf("1 - Criar Fila\n");
        else if (i == 2) printf("2 - Enfileirar\n");
        else if (i == 3) printf("3 - Desenfileirar\n");
        else if (i == 4) printf("4 - Exibir Fila\n");
        else if (i == 5) printf("5 - Esvaziar Fila\n");
        else if (i == 6) printf("6 - Tamanho Fila\n");
        else if (i == 7) printf("7 - Concatenar Filas\n");
    }
    printf("\n");
}

FilaCirc CriarFila()
{
    FilaCirc *P = (FilaCirc *)malloc(sizeof(FilaCirc));
    P -> Atras = -1;
    P -> Frente = 0;
    P -> Tamanho = 0;
    return *P;
}

int FilaVazia(FilaCirc *P) { return P -> Tamanho == 0; }

int EnfileirarFila(FilaCirc *P, int Dado)
{
    int A = (P -> Atras + 1) % MAX;
    if (P -> Tamanho == MAX) return 0;
    else
    {
        P -> Atras = A;
        P -> Vetor[A] = Dado;
        P -> Tamanho ++;
        return 1;
    }
}

int DesinfileirarFila(FilaCirc *P, int Dado)
{
    if (FilaVazia(P) || (P -> Vetor[P -> Frente] != Dado)) return 0;
    else
    {
        P -> Frente = (P -> Frente + 1) % MAX;
        P -> Tamanho --;
        return 1;
    }
}

int TamanhoFila(FilaCirc *P)
{
    if(FilaVazia(P)) return 0;
    else
    {
        int cont = 0;
        for (int i = 1, AUX = P -> Frente; i <= P -> Tamanho; i ++, AUX = (AUX + 1) % MAX) cont ++;
        return cont;
    }
}

void ExibirFila(FilaCirc *P)
{
    if(FilaVazia(P)) printf("Fila vazia!\n\n");
    else
    {
        for (int i = 1, AUX = P -> Frente; i <= P -> Tamanho; i ++, AUX = (AUX + 1) % MAX)
        {
            printf("%i ", P -> Vetor[AUX]);
        }
        printf("\n\n");
    }
}

int main ()
{
    int Entrada = 0, Entrada1 = 0, Dado = 0, Dado1 = 0;
    FilaCirc P;
    while (1)
    {
        Interface();
        printf("Digite uma opcao: ");scanf("%i", &Entrada);
        printf("\n");
        if (Entrada == 1)
        {
            P = CriarFila();
            printf("Fila criada!\n\n");
        }
        else if (Entrada == 2)
        {
            printf("Digite o dado: ");scanf("%i", &Dado);
            printf("\n");
            if (EnfileirarFila(&P, Dado)) printf("Dado adicionado!\n\n");
            else printf("Dado nao adicionado!\n\n");
        }
        else if (Entrada == 3)
        {
            printf("Digite o dado: ");scanf("%i", &Dado);
            printf("\n");
            if (DesinfileirarFila(&P, Dado)) printf("Dado removido!\n\n");
            else printf("Dado nao removido!\n\n");
        }
        else if (Entrada == 4) ExibirFila(&P);
        else if (Entrada == 5)
        {
            P = CriarFila();
            printf("Fila esvaziada!\n\n");
        }
        else if (Entrada == 6) 
        {
            if (TamanhoFila(&P)) printf("Tamanho: %i\n\n", (TamanhoFila(&P)));
            else printf("Fila vazia!\n\n");
        }
        else if (Entrada == 7)
        {
            printf("Digite a quantidade de listas para concatenar: ");scanf("%i", &Entrada1);
            printf("\n");
            if (Entrada1 == 2)
            {
                int i = 0, j = 0;
                FilaCirc P1 = CriarFila();
                for (i = 0; i < TamanhoFila(&P); i ++)
                {
                    printf("Digite o dado: ");scanf("%i", &Dado);
                    printf("\n");
                    if (EnfileirarFila(&P1, Dado)) printf("Dado adicionado!\n\n");
                    else printf("Dado nao adicionado!\n\n");
                }
                int *P2 = (int*)malloc((TamanhoFila(&P) + TamanhoFila(&P1)) * sizeof(int));
                for (i = 0; i < ((TamanhoFila(&P) + TamanhoFila(&P1))); i ++, j ++)
                {
                    P2[i] = P.Vetor[j];
                    P2[i + 1] = P1.Vetor[j];
                    i += 1;
                }
                for (i = 0; i < ((TamanhoFila(&P) + TamanhoFila(&P1))); i ++, j ++)
                {
                    printf("%i ", P2[i]);
                }
                printf("\n\n");
            }
            else if (Entrada1 == 3)
            {
                int i = 0, j = 0;
                FilaCirc P1 = CriarFila();
                FilaCirc P2 = CriarFila();
                for (i = 0; i < TamanhoFila(&P); i ++)
                {
                    printf("Digite o dado: ");scanf("%i", &Dado);
                    printf("\n");
                    if (EnfileirarFila(&P1, Dado)) printf("Dado adicionado!\n\n");
                    else printf("Dado nao adicionado!\n\n");
                }
                for (i = 0; i < TamanhoFila(&P); i ++)
                {
                    printf("Digite o dado: ");scanf("%i", &Dado);
                    printf("\n");
                    if (EnfileirarFila(&P2, Dado)) printf("Dado adicionado!\n\n");
                    else printf("Dado nao adicionado!\n\n");
                }
                int *P3 = (int*)malloc((TamanhoFila(&P) + TamanhoFila(&P1) + TamanhoFila(&P2)) * sizeof(int));
                for (i = 0; i < ((TamanhoFila(&P) + TamanhoFila(&P1) + TamanhoFila(&P2))); i ++, j ++)
                {
                    P3[i] = P.Vetor[j];
                    P3[i + 1] = P1.Vetor[j];
                    P3[i + 2] = P2.Vetor[j];
                    i += 2;
                }
                for (i = 0; i < ((TamanhoFila(&P) + TamanhoFila(&P1) + TamanhoFila(&P2))); i ++, j ++)
                {
                    printf("%i ", P3[i]);
                }
                printf("\n\n");
            }
        }
    }
    return 0;
}
