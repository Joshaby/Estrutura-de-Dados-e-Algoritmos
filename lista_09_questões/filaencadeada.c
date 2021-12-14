#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int Dado;
    struct No *Proximo;
}No;

typedef struct 
{
    No *Inicio;
    No *Final;
    int Tamanho;
}FilaEnc;

void Interface()
{
    printf("Editor de fila v2.0\n");
    for (int i = 0; i < 33; i ++) printf("=");
    printf("\n");
    for (int i = 1; i <= 8; i ++)
    {
        if (i == 1) printf("1 - Criar fila\n");
        else if (i == 2) printf("2 - Verificar fila\n");
        else if (i == 3) printf("3 - Tamanho da fila\n");
        else if (i == 4) printf("4 - Elemento frente\n");
        else if (i == 5) printf("5 - Enfileirar\n");
        else if (i == 6) printf("6 - Desenfileirar\n");
        else if (i == 7) printf("7 - Imprimir fila\n");
        else if (i == 8) printf("8 - Sair\n\n");
    }
}

No* Novo(){ return (No*)malloc(sizeof(No)); }

FilaEnc CriarFila(FilaEnc *P)
{
    P -> Inicio = P -> Final = NULL;
    P -> Tamanho = 0;
}

int VerificarFila(FilaEnc P)
{
    return P.Inicio == NULL || P.Final == NULL;
}

int TamanhoFila(FilaEnc P)
{
    int cont = 0;
    while(P.Inicio != NULL)
    {
        cont ++;
        P.Inicio = P.Inicio -> Proximo;
    }
    return cont;
}

int ElementoFrente(FilaEnc P, int *Dado)
{
    if (VerificarFila(P)) return 0;
    else
    {
        *Dado = P.Inicio -> Dado;
        return 1;
    }
}

int Enfileirar(FilaEnc *P, int Dado)
{
    No *AUX = NULL;
    if ((AUX = Novo()) == NULL) return 0;
    else
    {
        AUX -> Dado = Dado;
        AUX -> Proximo = NULL;
    }
    if (VerificarFila(*P)) P -> Inicio = AUX;
    else (P -> Final -> Proximo) = AUX;
    P -> Final = AUX;
    P -> Tamanho ++;
    return 1;
}

int Desenfileirar(FilaEnc *P)
{
    if (VerificarFila(*P)) return 0;
    if (P -> Inicio == P ->Final)
    {
        P -> Final = NULL;
        P -> Inicio = NULL;
        return 1;
    }
    No *AUX = P -> Inicio;
    P -> Inicio = P ->Inicio -> Proximo;
    free(AUX);
    P ->Tamanho --;
    return 1;
}

void ImprimirFila(FilaEnc P)
{
    if (VerificarFila(P)) printf("Fila vazia!\n\n");
    else
    {
        printf("Fila\n");
        for ( ;P.Inicio != NULL; P.Inicio = P.Inicio -> Proximo) printf("%i\n", P.Inicio -> Dado);
        printf("\n");
    }
}

int main()
{
    FilaEnc P;
    int Entrada = 0, Dado = 0;
    while (Entrada != 8)
    {
        Interface();
        printf("Digite a opcao: ");scanf("%i", &Entrada);
        printf("\n");
        if (Entrada == 1)
        {
            CriarFila(&P);
            printf("Fila criada!\n\n");
        }
        else if (Entrada == 2)
        {
            if (VerificarFila(P)) printf("Fila Vazia!\n\n");
            else printf("A fila possui elementos!\n\n");
        }
        else if (Entrada == 3) printf("Tamanho da fila: %i\n\n", TamanhoFila(P));
        else if (Entrada == 4)
        {
            if(ElementoFrente(P, &Dado)) printf("Elemento frente: %i\n\n", Dado);
            else printf("Fila vazia!\n\n");
        }
        else if (Entrada == 5)
        {
            printf("Digite o dado: ");scanf("%i", &Dado);
            if (Enfileirar(&P, Dado)) printf("Dado enfileirado com sucesso!\n\n");
            else printf("Dado nao enfileirado!\n\n");
        }
        else if (Entrada == 6)
        {
            if (Desenfileirar(&P)) printf("Elemento desinfileirado!\n\n");
            else printf("Elemento nao desinfileirado!\n\n");
        }
        else if (Entrada == 7) ImprimirFila(P);
    }
    return 0;
}
