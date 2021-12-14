#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40

typedef struct
{
    char Nome[MAX + 1];
    char *NOME;
}Struct;

char EscreverChar(Struct *P)
{
    int i;
    scanf("%s", &P->Nome);
    P->NOME = (char*)malloc(MAX * sizeof(char));
    for (i = 0; i < MAX; i ++)
    {
        P->NOME[i] = P->Nome[i];
    }
    printf("%s", P->NOME);
}

int main()
{
    Struct P;
    EscreverChar(&P);
    free(P.NOME);
    return 0;
}
