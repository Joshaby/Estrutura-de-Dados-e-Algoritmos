#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main()
{
    printf("Editor de Listas\n");
    for (int i = 0; i < 25; i ++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 1; i <= 6; i ++)
    {
        if (i == 1)
        {
            printf("1 - Exibir Lista\n");
        }
        else if (i == 2)
        {
            printf("2 - Inserir\n");
        }
        else if (i == 3)
        {
            printf("3 - Remover\n");
        }
        else if (i == 4)
        {
            printf("4 - Exibir Elemento\n");
        }
        else if (i == 5)
        {
            printf("5 - Exibir Posicao\n");
        }
        else if (i == 6)
        {
            printf("6 - Esvvaziar Lista\n");
        }
    }
    printf("ESC - Sair\n\n");
    printf("Digite sua opcao [ ]\n");
    return 0;
}

