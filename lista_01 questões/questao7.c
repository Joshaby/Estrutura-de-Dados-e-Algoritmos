#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct
{
    int *v;
}Vetor;

void escreveVetor(Vetor *a)
{
    int i;
    for (i = 0; i < MAX; i ++)
    {
        scanf("%i", &a->v[i]);
    }
}

void imprimeVetor(Vetor *a)
{
    int i;
    for (i = 0; i < MAX; i ++)
    {
        printf("%i ", a->v[i]);
    }
}

int main()
{
    Vetor a;
    a.v = (int *)malloc(MAX * sizeof(int));
    escreveVetor(&a);
    imprimeVetor(&a);
    return 0;                   
}

