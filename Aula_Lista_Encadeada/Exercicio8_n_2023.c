#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

/* Definição das estruturas */
struct Item {
    char dado;
};

typedef struct Item TItem;

struct Celula {
    TItem item;
    struct Celula* pProximo;
};

typedef struct Celula TCelula;

struct Lista {
    TCelula* pPrimeiro;
    TCelula* pUltimo;
    int tamanho;
};

typedef struct Lista TLista;


/* Rotinas da lista encadeada */

void iniciacao(TLista** p) {
    *p = (TLista*)malloc(sizeof(TLista));
    (**p).pPrimeiro = NULL;
    (**p).pUltimo = NULL;
    (**p).tamanho = 0;
}

int vazia(TLista* p) {
    if ((*p).tamanho == 0)
        return TRUE;
    else
        return FALSE;
}

void imprimirTItem(TItem x) {
    printf("%c\n", x.dado);
}

void insercaoFinal(TLista* p, TItem x) {
    TCelula* aux = (*p).pUltimo;
    (*p).pUltimo = (TCelula*)malloc(sizeof(TCelula));

    if (vazia(p) == TRUE)
        (*p).pPrimeiro = (*p).pUltimo;
    else
        (*aux).pProximo = (*p).pUltimo;

    (*(*p).pUltimo).item = x;
    (*(*p).pUltimo).pProximo = NULL;

    (*p).tamanho++;
}

int remocaoInicio(TLista* p, TItem* removido) {
    if (vazia(p) == FALSE) {
        TCelula* aux = (*p).pPrimeiro;
        (*p).pPrimeiro = (*aux).pProximo;
        *removido = (*aux).item;
        free(aux);
        (*p).tamanho--;

        if (vazia(p) == TRUE)
            (*p).pUltimo = NULL;

        return TRUE;
    } else
        return FALSE;
}

void impressaoLista(TLista* p) {
    TCelula* t;
    TItem x;

    if (vazia(p) == TRUE) {
        printf("\nLista vazia. Nao ha celulas para imprimir\n");
    } else {
        printf("\nImprimindo conteudo da lista:\n");
        t = (*p).pPrimeiro;

        while (t != NULL) {
            x = (*t).item;
            imprimirTItem(x);
            t = (*t).pProximo;
        }
    }
}

void limpezaLista(TLista* p) {
    while (vazia(p) == FALSE) {
        TItem t;
        remocaoInicio(p, &t);
        printf("Desalocada celula com item %c\n", t.dado);
    }

    free(p);
}

int consultaPosicao(TLista* p, int posicao, TItem* item) {
    if (posicao < 1 || posicao > (*p).tamanho) {
        return FALSE;
    } else {
        int j = 1;
        TCelula* aux = (*p).pPrimeiro;

        while (j < posicao) {
            j++;
            aux = (*aux).pProximo;
        }

        *item = (*aux).item;
        return TRUE;
    }
}

int main() {
    TLista* pCabeca;
    TItem x;

    iniciacao(&pCabeca);

    printf("Digite uma sequencia de caracteres (pressione Enter para encerrar a leitura):\n");

    char linha[100];
    fgets(linha, sizeof(linha), stdin);

    for (int i = 0; linha[i] != '\n'; i++) {
        x.dado = linha[i];
        insercaoFinal(pCabeca, x);
    }

    printf("\nCaracteres inseridos:\n");
    impressaoLista(pCabeca);

    int posicao;
    printf("\nDigite a posicao para consulta: ");
    scanf("%d", &posicao);

    TItem item;
    if (consultaPosicao(pCabeca, posicao, &item)) {
        printf("O item na posicao %d e: %c\n", posicao, item.dado);
    } else {
        printf("Posicao invalida.\n");
    }

    limpezaLista(pCabeca);

    return 0;
}
