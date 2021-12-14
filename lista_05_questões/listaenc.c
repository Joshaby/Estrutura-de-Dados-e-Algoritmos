#include <stdio.h>
#include <stdlib.h>

typedef struct ListaEnc
{
    int Dado;
    struct ListaEnc *Proximo;
}No;

typedef No *TListaEnc;

void Interface()
{
    printf("\tEditor de Listas\n");
    for (int i = 0; i < 33; i ++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 1; i <= 16; i ++)
    {
        if (i == 1) printf("1 - Criar Lista\n");
        else if (i == 2) printf("2 - Verificar Lista\n");
        else if (i == 3) printf("3 - Tamanho da Lista\n");
        else if (i == 4) printf("4 - Exibir Elemento\n");
        else if (i == 5) printf("5 - Exibir Posicao\n");
        else if (i == 6) printf("6 - Inserir Elemento com Posicao\n");
        else if (i == 7) printf("7 - Remover Elemento com Posicao\n");
        else if (i == 8) printf("8 - Inserir Elemento na Primeira Posicao\n");
        else if (i == 9) printf("9 - Inserir Elemento na Ultima Posicao\n");
        else if (i == 10) printf("10 - Modificar Elemento\n");
        else if (i == 11) printf("11 - Remover Primeiro Elemento\n");
        else if (i == 12) printf("12 - Remover Ultimo Elemento\n");
        else if (i == 13) printf("13 - Remover Elemento com seu Valor\n");
        else if (i == 14) printf("14 - Imprimir Lista\n");
        else if (i == 15) printf("15 - Esvaziar Lista\n");
        else if (i == 16) printf("16 - Sair\n");
    }
    for (int i = 0; i < 33; i ++)
    {
        printf("-");
    }
    printf("\n");
    printf("Digite uma opção:\n");
}

TListaEnc Aloc() { return (No *)malloc(sizeof(No)); }

void *CriarLista(TListaEnc *Lista){ *Lista = NULL; }

int VerificaLista(TListaEnc Lista){ return Lista == NULL; }

int TamanhoLista(TListaEnc Lista)
{
    int cont = 0;
    if (VerificaLista(Lista)) return cont;
    for ( ;!VerificaLista(Lista); Lista = Lista -> Proximo) cont ++;
    return cont;
}

int VerificaElemento(TListaEnc Lista, int Dado)
{
    int i = 0;
    for ( ;!VerificaLista(Lista); Lista = Lista -> Proximo)
    {
        if (Dado == Lista -> Dado)
        {
            i ++;
        }
    }
    return i;
}

int ExibirElemento(TListaEnc Lista, int Posicao, int *Dado1)
{
    int Posicao1 = 1, i;
    if (VerificaLista(Lista)) return 0;
    else
    {
        for (i = 1; i <= Posicao; i++, Posicao1 ++, Lista = Lista -> Proximo)
        {
            if (Posicao == Posicao1) 
            {
                *Dado1 = Lista -> Dado;
                return 1;
            }
        }
    }
}

int ExibirPosicao(TListaEnc Lista, int Dado, int *Dado1)
{
    int Posicao1 = 1;
    if (VerificaLista(Lista) || VerificaElemento(Lista, Dado) < 1) return 0;
    else
    {
        for ( ;!VerificaLista(Lista); Lista = Lista -> Proximo, Posicao1 ++)
        {
            if (Dado == Lista -> Dado)
            {
                break;
            }
        }
        *Dado1 = Posicao1;
    }
}

void ImprimirLista(TListaEnc Lista)
{
    if (VerificaLista(Lista)) printf("Lista Vazia!\n\n");
    else
    {
        printf("( ");
        for ( ;!VerificaLista(Lista); Lista = Lista -> Proximo) printf("%i ", Lista -> Dado);
        printf(")\n\n");
    }
}

int EsvaziarLista(TListaEnc *Lista)
{
    free(*Lista);
    CriarLista(*Lista);
    return 1;
}

int InserirPrimeiraPosicao(TListaEnc *Lista, int Dado)
{
    TListaEnc NovoDado = NULL;
    if (VerificaLista(*Lista))
    {
        if((NovoDado = Aloc()) == NULL) return 0;
        else
        {
            NovoDado -> Dado = Dado;
            NovoDado -> Proximo = NULL;
            *Lista = NovoDado;
            return 1;
        }
    }
    else if (!VerificaLista(*Lista))
    {
        if((NovoDado = Aloc()) == NULL) return 0;
        else
        {
            NovoDado -> Dado = Dado;
            NovoDado -> Proximo = *Lista;
            *Lista = NovoDado;
            return 1;
        }
    }
}

int InserirUltimaPosicao(TListaEnc *Lista, int Dado)
{
    int cont = 1;
    TListaEnc Help = NULL, NovoDado = NULL;
    Help = *Lista;
    if (VerificaLista(*Lista)) return 0;
    else
    {
        while (cont < TamanhoLista(*Lista))
        {
            Help = Help -> Proximo;
            cont ++;
        }
        if ((NovoDado = Aloc()) == NULL) return 0;
        {
            NovoDado -> Dado = Dado;
            NovoDado -> Proximo = Help -> Proximo;
            Help -> Proximo = NovoDado;
            return 1;
        }
    }
}

int RemoverPrimeiraPosicao(TListaEnc *Lista)
{
    TListaEnc Help = NULL;
    Help = *Lista;
    if (VerificaLista(*Lista)) return 0;
    else
    {   
        *Lista = Help -> Proximo;
        free(Help);
        return 1;
    }
}

int InserirPosicao(TListaEnc *Lista, int Dado, int Posicao)
{
    TListaEnc Help = NULL, NovoDado = NULL;
    int cont = 1;
    if (Posicao > 1)
    {
        if (VerificaLista(*Lista)) return 0;
        else
        {
            Help = *Lista;
            while (cont < Posicao - 1 && Help != NULL)
            {
                Help = Help -> Proximo;
                cont ++;
            }
            if (Help == NULL) return 0;
            if((NovoDado = Aloc()) == NULL) return 0;
            NovoDado -> Dado = Dado;
            NovoDado -> Proximo = Help -> Proximo;
            Help -> Proximo = NovoDado;
            return 1;
        }
    }
}

int RemoverPosicao(TListaEnc *Lista, int *Dado, int Posicao)
{
    int cont = 1;
    TListaEnc Help = NULL, Help1 = NULL;
    Help = *Lista;
    if (VerificaLista(*Lista) || VerificaElemento(*Lista, Dado) < 1) return 0;
    else
    {
        if (TamanhoLista(*Lista) == 1)
        {
            free(*Lista);
            *Lista = NULL;
        }
        else if (TamanhoLista(*Lista) > 1)
        {
            while (cont <= Posicao - 1 && Help != NULL)
            {
                Help1 = Help;
                Help = Help -> Proximo;
                cont ++;
            }
            if (Help == NULL) return 0;
            else
            {
                Help1 -> Proximo = Help -> Proximo;
                free(Help);
                return 1;
            }
        }
    }
}

int RemoverUltimaPosicao(TListaEnc *Lista)
{
    TListaEnc Help = NULL, Help1 = NULL;
    Help = *Lista;
    if (VerificaLista(*Lista)) return 0;
    else
    {
        if (TamanhoLista(*Lista) > 1)
        {
            while (Help -> Proximo != NULL)
            {
                Help1 = Help;
                Help = Help -> Proximo;
            }
            Help1 -> Proximo = NULL;
            Help -> Proximo = NULL;
            free(Help);
            return 1;
        }
        else if (TamanhoLista(*Lista) == 1)
        {
            *Lista = Help -> Proximo;
            free(Help);
            return 1;
        }
    }
}

int ModificarDado(TListaEnc *Lista, int Dado, int Posicao)
{
    int cont = 1;
    TListaEnc Help = NULL;
    Help = *Lista;
    if (VerificaLista(*Lista) || Posicao < 1 || Posicao > TamanhoLista(*Lista) + 1) return 0;
    else
    {
        while (cont <= TamanhoLista(*Lista) && Help != NULL)
        {
            if (Posicao == cont)
            {
                Help -> Dado = Dado;
                return 1;
            }
            Help = Help -> Proximo;
            cont ++;
        }
    }
}

int RemoverComDado(TListaEnc *Lista, int Dado)
{
    TListaEnc Help = NULL, Help1 = NULL;
    Help = *Lista;
    int cont = 1;
    if (VerificaLista(*Lista) || VerificaElemento(*Lista, Dado) < 1) return 0;
    else if (Dado == Help -> Dado)
    {
        *Lista = Help -> Proximo;
        free(Help);
        return 1;
    }
    else
    {
        while (cont <= TamanhoLista(*Lista) && Help != NULL)
        {
            Help1 = Help;
            Help = Help -> Proximo;
            cont ++;
            if (Dado == Help -> Dado)
            {
                Help1 -> Proximo = Help -> Proximo;
                free(Help);
                return 1;
            }
        }
    }
}

int main()
{
    TListaEnc Lista;
    int Entrada, Dado, Posicao, Dado1 = 0, Dado2 = 0;
    while (Entrada != 16)
    {
        Interface();
        scanf("%i", &Entrada);
        if (Entrada == 1)
        {
            if (CriarLista(&Lista)) printf("Lista criada!\n\n");
            else printf("Lista não criada!\n\n");
        }
        else if (Entrada == 2)
        {
            if (VerificaLista(Lista)) printf("Lista vazia!\n\n");
            else printf("A lista possui elementos!\n\n");
        }
        else if (Entrada == 3) printf("Tamanho da lista %i!\n\n", TamanhoLista(Lista));
        else if (Entrada == 4)
        {
            printf("Digite a Posicao: ");scanf("%i", &Posicao);
            if (ExibirElemento(Lista, Posicao, &Dado1)) printf("Dado: %i\n\n", Dado1);
            else printf("Posicao nao existe ou a lista esta vazia!\n\n");
        }
        else if (Entrada == 5)
        {
            printf("Digite a Dado: ");scanf("%i", &Dado);
            if (ExibirPosicao(Lista, Dado, &Dado1)) printf("Posicao: %i\n\n", Dado1);
            else printf("A lista esta vazia ou dado digitado nao existe!\n\n");
        }
        else if (Entrada == 6)
        {
            printf("Digite a Dado: ");scanf("%i", &Dado);
            printf("Digite a Posicao: ");scanf("%i", &Posicao);
            if (Posicao > 1)
            {
                if (InserirPosicao(&Lista, Dado, Posicao)) printf("Dado adicionado com sucesso!\n\n");
                else printf("Dado não adicionado!\n\n");
            }
            else if (Posicao == 1)
            {
                if (InserirPrimeiraPosicao(&Lista, Dado)) printf("Dado adicionado com sucesso!\n\n");
                else printf("Dado não adicionado!\n\n");
            }
            else if (Posicao > TamanhoLista(Lista) + 1 && Posicao < 1) printf("A posicao nao existe!\n\n");
        }
        else if (Entrada == 7)
        {
            printf("Digite a Dado: ");scanf("%i", &Dado);
            printf("Digite a Posicao: ");scanf("%i", &Posicao);
            if (Posicao > 1)
            {
                if (RemoverPosicao(&Lista, Dado, Posicao)) printf("Dado removido com sucesso!\n\n");
                else printf("Dado nao removido!\n\n");
            }
            if (Posicao == 1)
            {
                if (RemoverPrimeiraPosicao(&Lista)) printf("Dado removido com sucesso!\n\n");
                else printf("Dado nao removido!\n\n");
            }
            else if (Posicao > TamanhoLista(Lista) + 1 && Posicao < 1) printf("A posicao nao existe!\n\n");
        }
        else if (Entrada == 8)
        {   
            printf("Digite o dado: ");scanf("%i", &Dado);
            if (InserirPrimeiraPosicao(&Lista, Dado)) printf("Dado adicionado com sucesso!\n\n");
            else printf("Dado não adicionado!\n\n");
        }
        else if (Entrada == 9)
        {
            printf("Digite o dado: ");scanf("%i", &Dado);
            if (InserirUltimaPosicao(&Lista, Dado)) printf("Dado adicionado com sucesso!\n\n");
            else printf("Dado não adicionado!\n\n");
        }
        else if (Entrada == 10)
        {
            printf("Digite o dado: ");scanf("%i", &Dado);
            printf("Digite a Posicao: ");scanf("%i", &Posicao);
            if (ModificarDado(&Lista, Dado, Posicao)) printf("Dado modificado!\n\n");
            else printf("Dado não modificado!\n\n");
        }
        else if (Entrada == 11)
        {
            printf("Digite o dado: ");scanf("%i", &Dado);
            if (RemoverPrimeiraPosicao(&Lista)) printf("Dado removido com sucesso!\n\n");
            else printf("Dado nao removido!\n\n");
        }
        else if (Entrada == 12)
        {
            if (RemoverUltimaPosicao(&Lista)) printf("Dado removido com sucesso!\n\n");
            else printf("Dado nao removido!\n\n");
        }
        else if (Entrada == 13)
        {
            printf("Digite o dado: ");scanf("%i", &Dado);
            if (RemoverComDado(&Lista, Dado)) printf("Dado removido com sucesso!\n\n");
            else printf("Dado nao removido!\n\n");
        }
        else if (Entrada == 14) ImprimirLista(Lista);
        else if (Entrada == 15) if (EsvaziarLista(&Lista)) printf("Lista esvaziada!\n\n");
    }
    return 0;
}