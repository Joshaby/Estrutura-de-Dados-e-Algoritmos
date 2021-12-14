#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
}EstCvl;

char *imprimeEstadoCivil(EstCvl *a)
{
    if (a -> codigo == 1) printf("Solteiro(a)\n");
    else if (a -> codigo == 2) printf("Casado(a)");
    else if (a -> codigo == 3) printf("Divorciado(a)\n");
    else if (a -> codigo == 4) printf("Viuvo(a)\n");
}

int main()
{
    EstCvl a;
    scanf("%i", &a.codigo);
    imprimeEstadoCivil(&a);
    return 0;
}
