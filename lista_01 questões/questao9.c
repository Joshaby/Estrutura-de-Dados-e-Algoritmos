#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct
{
    char *V, b[MAX];
    int i;
}Vetor;

char DigiteeImprimeVetor(Vetor *P)
{
    scanf("%[^\n]s", &P->b);
    char *c = (char *)malloc(strlen(P->b) * sizeof(char));
    for (P->i = 0; P->i < strlen(P->b); P->i ++)
    {
        c[P->i] = P->b[strlen(P->b) - (P->i + 1)];
    }
    for (P->i = 0; P->i < strlen(P->b); P->i ++)
    {
        printf("%c", c[P->i]);
    }
}

int main()
{
    Vetor P;
    DigiteeImprimeVetor(&P);
    return 0;
}

