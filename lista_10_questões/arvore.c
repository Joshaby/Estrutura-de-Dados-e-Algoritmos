#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Arvore {
    int Dado;
    struct Arvore *Direita;
    struct Arvore *Esquerda;
}No;

typedef No *Arvore;

void Interface() {
    printf("Editor de Arvore v1.0\n");
    printf("1 - Inicializar arvore\n");
    printf("2 - Criar raiz\n");
    printf("3 - Inserir elementos\n");
    printf("4 - Exibir arvore\n");
    printf("5 - Situação da arvore\n");
    printf("6 - Tamanho\n");
    printf("7 - Esvaziar arvore\n");
    printf("8 - Buscar valor na arvore\n");
    printf("9 - Exibir arvore(Escrita)\n");
    printf("10 - QTDe de nos\n");
}

int Criar(Arvore *P) { return *P = NULL; }

int ArvoreVazia(Arvore P) { return P == NULL; }

No *CriarNo(int Dado) {
    No *New;
    New = (No*)malloc(sizeof(No));
    New->Dado = Dado;
    New->Direita = NULL;
    New->Esquerda = NULL;
    return New;
}


void InsereElementos(Arvore P, int Dado) {
    if (Dado >= P->Dado) {
        if (P->Direita != NULL) return InsereElementos(P->Direita, Dado);
        else {
            No *New = CriarNo(Dado);
            P->Direita = New;
        }
    }
    else {
        if (P->Esquerda != NULL) return InsereElementos(P->Esquerda, Dado);
        else {
            No *New = CriarNo(Dado);
            P->Esquerda = New;
        }
    }
}

int Esquerdo(Arvore P) { return P->Esquerda == NULL; }

int Direito(Arvore P) { return P->Direita == NULL; }

void ExibirArvore(Arvore P) {
    if(!ArvoreVazia(P)) {
        ExibirArvore(P->Esquerda);
        printf("%i ", P->Dado);
        ExibirArvore(P->Direita);
    }
}

int QTDE(Arvore P) {
    if(!ArvoreVazia(P)) {
        int AE = 1 + QTDE(P->Esquerda);
        int AD = QTDE(P->Direita);
        return AE + AD;
    }
    else return 0;
}

int QTDEFilho(Arvore P) {
    if (P == NULL) return 0;
    if (P->Esquerda == NULL && P->Direita == NULL) return 1;
    cont + QTDEFilho(P->Esquerda) + QTDEFilho(P->Direita);
    return cont;
}

//return 1 + (filhodire(arv->d)) == NULL & filhoe(arv
void EsvaziarArvore(Arvore P) {
    if(!ArvoreVazia(P)) {
        ExibirArvore(P->Esquerda);
        ExibirArvore(P->Direita);
        free(P);
    }
}

No* BuscaFast(Arvore P, int V) {
    if (P == NULL || P->Dado == V) return P;
    else {
        if (V >= P->Dado) return BuscaFast(P->Direita, V);
        else if (V < P->Dado) return BuscaFast(P->Esquerda, V);
    } 
}

No *BuscaSlow(Arvore P, int V) {
    if (P == NULL || P->Dado == V) return P;
    else {
        No *R = BuscaSlow(P->Esquerda, V);
        if (R != NULL) return R;
        else return BuscaSlow(P->Direita, V);
    }
}

void ArvoreEscrita(Arvore P) {
    if (ArvoreVazia(P)) printf("<>");
    else {
        printf("<");
        printf("%i", P->Dado);
        ArvoreEscrita(P->Esquerda);
        ArvoreEscrita(P->Direita);
        printf(">");
    }
}

int main() {
    Arvore P;
    while(1) {
        Interface();
        int Entrada = 0, Entrada1 = 0;
        printf("Digite a opcao: ");scanf("%i", &Entrada);
        if (Entrada == 1) Criar(&P);
        else if (Entrada == 2) {
            printf("Digite o valor da raiz: ");scanf("%i", &Entrada1);
            P = CriarNo(Entrada1);
        }
        else if (Entrada == 3) {
            printf("Digite o valor do no: ");scanf("%i", &Entrada1);
            InsereElementos(P, Entrada1);
        }
        else if (Entrada == 5) ExibirArvore(P);
        else if (Entrada == 6) printf("QTDE de nos da arvore: %i\n", QTDE(P));
        else if (Entrada == 7) EsvaziarArvore(P);
        else if (Entrada == 8) {
            printf("Digite o valor a ser buscado: ");scanf("%i", &Entrada1);
            No *P1 = BuscaFast(P, Entrada1);
            if (P1 != NULL) {
                if (P1->Dado == Entrada1) printf("Valor encontrado!\n");
                else printf("Valor nao encontrado!\n");
            }
            else printf("Valor nao encontrado!\n");
        }
        else if (Entrada == 9) ArvoreEscrita(P);
        else if (Entrada == 10) printf("QTDE :%i\n", QTDEFilho(P));
    }
}
