#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000


typedef struct
{
    char strOrigem[MAX], strFim[MAX], *p1, *p2;
}Struct;

void EscreverChar(Struct *P)
{
    scanf("%s", &P->strOrigem);
    scanf("%s", &P->strFim);
}

void ColocarNoVetor(Struct *P)
{
    int i;
    P->p1 = (char *)malloc(strlen(P->strOrigem) * sizeof(char));
    P->p2 = (char *)malloc(strlen(P->strFim) * sizeof(char));
    for (i = 0; i < strlen(P->p1); i ++)
    {
        P->p1[i] = P->strOrigem[i];
    }
    for (i = 0; i < strlen(P->p2); i ++)
    {
        P->p2[i] = P->strFim[i];
    }
}

int Verificar(Struct *P)
{
    int i, cont = 0;
    char v[strlen(P->p2)];
    if (strlen(P->p1) < strlen(P->p2))
    {
        return 0;
    }
    else
    {
        for (i = strlen(P->p2); i < strlen(P->p1); i ++)
        {
            v[i] = P->p1[i];
        }
        printf("%c", v[0]);
    }
}

int main()
{
    int Verifica;
    Struct P;
    EscreverChar(&P);
    ColocarNoVetor(&P);
    Verifica = Verificar(&P);
    printf("%i", Verifica);
}

