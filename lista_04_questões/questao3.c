#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 20

typedef struct
{
    int ListaElementos[MAX];
    int TamanhoLista;
}Tlista;

void Interface()
{
    printf("Editor de Listas\n");
    for (int i = 0; i < 25; i ++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 1; i <= 7; i ++)
    {
        if (i == 1)
        {
            printf("1 - Exibir Lista\n");
        }
        else if (i == 2)
        {
            printf("2 - Inserir na primeira posicao\n");
        }
        else if (i == 3)
        {
            printf("3 - Inserir na ultima posicao\n");
        }
        else if (i == 4)
        {
            printf("4 - Remover da primeira posicao\n");
        }
        else if (i == 5)
        {
            printf("5 - Remover da ultima posicao\n");
        }
        else if (i == 6)
        {
            printf("6 - Remover elementos iguais\n");
        }
        else if (i == 6)
        {
            printf("6 - Modificar elemento\n");
        }
    }
    printf("7 - Sair\n\n");
    printf("Digite uma opção:\n");
}