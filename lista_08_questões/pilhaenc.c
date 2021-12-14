#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha
{
    int Dado;
    struct Pilha *Proximo;
}No;

typedef No* PilhaEnc;

void Interface()
{
    printf("Editor de Pilha v2.0\n");
    for (int i = 0; i < 23; i ++) printf("=");
    printf("\n");
    for (int i = 1; i <= 11; i ++)
    {
        if (i == 1) printf("1 - Inicializar\n");
        else if (i == 2) printf("2 - Empilhar\n");
        else if (i == 3) printf("3 - Desempilhar\n");
        else if (i == 4) printf("4 - Elemento do topo\n");
        else if (i == 5) printf("5 - Imprimir pilha\n");
        else if (i == 6) printf("6 - Esvaziar a pilha\n");
        else if (i == 7) printf("7 - Base da pilha\n");
        else if (i == 8) printf("8 - Tamanho da pilha\n");
        else if (i == 9) printf("9 - Desempilha N elementos\n");
        else if (i == 10) printf("10 - Mostrar sub-topo\n\n");
    }
}

void Inicializar(PilhaEnc *P){ *P = NULL; }

int PilhaVazia(PilhaEnc P){ return P == NULL; }

PilhaEnc Novo(){ return (No*)malloc(sizeof(No)); }

int TamanhoPilha(PilhaEnc P) 
{ 
    int cont = 0;
    for ( ;!PilhaVazia(P); P = P -> Proximo) cont ++;
    return cont;
}

int Empilhar(PilhaEnc *P, int Dado)
{
    PilhaEnc AUX = NULL;
    if ((AUX = Novo()) == NULL) return 0;
    else
    {
        AUX -> Dado = Dado;
        AUX -> Proximo = *P;
        *P = AUX;
        return 1;
    }
}

int ElementoTopo(PilhaEnc P, int *Dado)
{
    if (PilhaVazia(P)) return 0;
    else *Dado = P -> Dado; 
    return 1;
}

int Desempilhar(PilhaEnc *P, int *Dado)
{
    if (PilhaVazia(*P)) return 0;
    else
    {
        PilhaEnc AUX = *P;
        *P = AUX -> Proximo;
        *Dado = AUX -> Dado;
        free(AUX);
        return 1;
    }
}

void ImprimirPilha(PilhaEnc P)
{
    if (PilhaVazia(P)) printf("Pilha vazia!\n\n");
    else
    {
        printf("Pilha\n");
        for ( ;!PilhaVazia(P); P = P -> Proximo) printf("%i\n", P -> Dado);
        printf("\n");
    }
}

int EsvaziarPilha(PilhaEnc *P)
{
    if (PilhaVazia(*P)) return 0;
    else
    {
        while (*P != NULL)
        {
            PilhaEnc AUX = NULL;
            AUX = *P;
            *P = AUX -> Proximo;
            free(AUX);
        }
        return 1;
    }
}

void BaseDaPilha(PilhaEnc P)
{
    int cont = 0;
    if (PilhaVazia(P)) printf("Pilha vazia!\n\n");
    else
    {
        while (P -> Proximo != NULL) P = P -> Proximo;
        printf("Base: %i\n\n", P -> Dado);
    }
}

void SubTop(PilhaEnc P)
{ 
    if (PilhaVazia(P)) printf("Pilha vazia!\n\n");
    else printf("Sub-topo: %i\n\n", (P -> Proximo) -> Dado); 
}

int main()
{
    PilhaEnc P;
    int Entrada = 0, Dado = 0;
    while (1)
    {
        Interface();
        printf("Digite sua opcao: ");scanf("%i", &Entrada);
        printf("\n");
        if (Entrada == 1) Inicializar(&P);
        else if (Entrada == 2)
        {
            printf("Digite o dado: ");scanf("%i", &Dado);
            if (Empilhar(&P, Dado)) printf("Dado empilhado com sucesso!\n\n");
            else printf("Dado não empilhado!\n\n");
        }
        else if (Entrada == 3)
        {
            if (Desempilhar(&P, &Dado)) printf("Dado desempilhado %i!\n\n", Dado);
            else printf("Dado não desempilhado!\n\n");
        }
        else if (Entrada == 4)
        {
            if (ElementoTopo(P, &Dado)) printf("Dado do topo %i!\n\n", Dado);
            else printf("Pilha vazia!\n\n");
        }
        else if (Entrada == 5) ImprimirPilha(P);
        else if (Entrada == 6) EsvaziarPilha(&P);
        else if (Entrada == 7) BaseDaPilha(P);
        else if (Entrada == 8)
        {
            if (PilhaVazia(P)) printf("Pilha vazia!\n\n");
            else printf("Tamanho da pilha: %i\n\n", TamanhoPilha(P));
        }
        else if (Entrada == 9)
        {
            printf("Digite a quantidade: ");scanf("%i", &Entrada);
            if (Entrada < 0 || Entrada > TamanhoPilha(P) || PilhaVazia(P)) printf("Nao e possivel desempilhar!\n\n");
            else
            {
                for (int i = 0; i < Entrada; i ++)
                {
                    Desempilhar(&P, &Dado);
                    printf("Dado desempilhado %i!\n\n", Dado);
                }
            }
        }
        else if (Entrada == 10) SubTop(P);
    }
    return 0;

}

