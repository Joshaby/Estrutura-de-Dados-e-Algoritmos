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
            printf("6 - Esvaziar Lista\n");
        }
    }
    printf("7 - Sair\n\n");
    printf("Digite uma opção:\n");
}

int TamanhoLista(Tlista *lista) { return lista -> TamanhoLista; }

int CriarLista(Tlista *lista) { return lista -> TamanhoLista = 0; }

int ListaCheia(Tlista *lista) { return lista -> TamanhoLista == MAX; }

int ListaVazia(Tlista *lista) { return lista -> TamanhoLista == 0; }

int ExibirLista(Tlista *lista)
{
    int i;
    if (ListaVazia(lista)) return 0;
    printf("[ ");
    for (i = 0; i < TamanhoLista(lista); i ++)
    {
        printf("%i ", lista -> ListaElementos[i]);
    }
    printf("]\n");
    return 1;
}

int VerificaPosicao(Tlista *lista, int Posicao)
{
    return lista -> ListaElementos[Posicao] == NULL ? 1 : 0;
}

int VerificaElemento(Tlista *lista, int Elemento, int *Dado)
{
    int i;
    if (ListaVazia(lista)) return 0;
    for (i = 0; i < lista -> TamanhoLista; i ++)
    {
        if (Elemento == lista -> ListaElementos[i])
        {
            *Dado ++;
        }
    }
    return 1;
}

int InserirElemento(Tlista *lista, int Elemento, int Posicao)
{
    if (ListaCheia(lista) || Posicao < 0 || Posicao > TamanhoLista(lista)) return 0;
    lista -> ListaElementos[Posicao] = Elemento;
    lista -> TamanhoLista ++;
    return 1;
}

int RemoverElemento(Tlista *lista, int Elemento, int Posicao, int *Dado, int *Dado1)
{
    int i;
    VerificaElemento(lista, Elemento, &Dado);
    if (ListaVazia(lista) || Posicao < 0 || Posicao > TamanhoLista(lista) || 
    VerificaPosicao(lista, Posicao) || Dado < 1 || Elemento != lista ->ListaElementos[Posicao]) return 0;
    else if (Posicao < (TamanhoLista(lista) - 1))
    {
        *Dado1 = lista -> ListaElementos[Posicao];
        for (i = Posicao; i < TamanhoLista(lista); i ++)
        {
            lista -> ListaElementos[i] = lista -> ListaElementos[i + 1];
        }
        lista -> TamanhoLista --;
        return 1;
    }
    else if (Posicao == (TamanhoLista(lista) - 1)) 
    {
        *Dado1 = lista -> ListaElementos[Posicao];
        lista -> TamanhoLista --;
        return 1;
    }
}

int ExibirElemento(Tlista *lista, int Posicao, int *Dado)
{   
    int i;
    if (ListaVazia(lista) || Posicao < 0 || Posicao > TamanhoLista(lista)) return 0;
    for (i = 0; i < TamanhoLista(lista); i ++)
    {
        if (Posicao == i)
        {
            *Dado = lista -> ListaElementos[i];
        }
    }
    return 1;
}

int ExibirPosicao(Tlista *lista, int Elemento, int *Dado, int *Dado1)
{
    int i;
    VerificaElemento(lista, Elemento, &Dado);
    if (ListaVazia(lista) || Dado < 1) return 0;
    for (i = 0; i < TamanhoLista(lista); i ++)
    {
        if (Elemento == lista -> ListaElementos[i])
        {
            *Dado1 = i;
        }
    }
    return 1;
}

int EsvaziarLista(Tlista *lista)
{
    if (ListaVazia(lista)) return 0;
    free(lista);
    return 1;
}

int main()
{
    int Elemento, Posicao, Entrada, Dado = 0, Dado1 = 0;
    Tlista *l = (Tlista*)malloc(sizeof(Tlista));
    CriarLista(l);
    while(1)
    {
        Interface();
        scanf("%i", &Entrada);
        if (Entrada == 1)
        {
            if (ExibirLista(l));
            else
            {
                printf("Lista vazia!\n");
            }
        }
        else if (Entrada == 2)
        {
            printf("Digite o elemento: ");scanf("%i", &Elemento);
            printf("Digite o posicao: ");scanf("%i", &Posicao);
            if (InserirElemento(l, Elemento, Posicao - 1))
            {
                printf("Elemento adicionado com sucesso!\n");
            }
            else
            {
                printf("Elemento não adicionado!\n");
            }
        }
        else if (Entrada == 3) 
        {
            printf("Digite o elemento: ");scanf("%i", &Elemento);
            printf("Digite o posicao: ");scanf("%i", &Posicao);
            if (RemoverElemento(l, Elemento, Posicao - 1, &Dado, &Dado1))
            {
                printf("Elemento removido com sucesso\n");
            }
            else
            {
                printf("Elemento não removido!\n");
            }
        }
        else if (Entrada == 4)
        {
            printf("Digite o posicao: ");scanf("%i", &Posicao);
            if(ExibirElemento(l, Posicao - 1, &Dado))
            {
                printf("Elemento %i na posicao %i\n", Dado, Posicao);
            }
            else
            {
                printf("Posicao nao existe ou esta vazia!\n");
            }
        }
        else if (Entrada == 5)
        {
            printf("Digite o elemento: ");scanf("%i", &Elemento);
            if (ExibirPosicao(l, Elemento, Dado, &Dado1))
            {
                printf("Elemento %i na posicao %i\n", Elemento, Dado1 + 1);
            }
            else
            {
                printf("O elemento não existe ou a lista esta vazia\n");
            }
        }
        else if (Entrada == 6)
        {
            EsvaziarLista(l);
            l->TamanhoLista = 0;
        }
        else if(Entrada == 7)
        {
            break;
        }
    }
    return 0;
}


