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
    char maiorCaractere;
};

typedef struct Lista TLista;


/* Rotinas da lista encadeada */

void iniciacao(TLista** p) {
    *p = (TLista*)malloc(sizeof(TLista));
    (**p).pPrimeiro = NULL;
    (**p).pUltimo = NULL;
    (**p).tamanho = 0;
    (**p).maiorCaractere = '\0';  // Inicialmente, o maior caractere é vazio
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

    if (x.dado > (*p).maiorCaractere) {  // Atualiza o maior caractere se necessário
        (*p).maiorCaractere = x.dado;
    }
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

    printf("Maior caractere atual: %c\n", (*p).maiorCaractere);  // Imprime o maior caractere
}

void limpezaLista(TLista* p) {
    while (vazia(p) == FALSE) {
        TItem t;
        remocaoInicio(p, &t);
        printf("Desalocada celula com item %c\n", t.dado);
    }

    free(p);
}

int main() {
    TLista* pCabeca;
    TItem x;

    iniciacao(&pCabeca);

    printf("Digite os caracteres (pressione Enter para encerrar a leitura):\n");

    char linha[100];

    while (fgets(linha, sizeof(linha), stdin) != NULL && linha[0] != '\n') {
        for (int i = 0; linha[i] != '\n'; i++) {
            x.dado = linha[i];
            insercaoFinal(pCabeca, x);
        }
    }

    printf("\nCaracteres inseridos:\n");
    impressaoLista(pCabeca);

    limpezaLista(pCabeca);

    return 0;
}
