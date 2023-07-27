#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

/* Definição das estruturas */
struct Aluno {
    int matricula;
    char nome[100];
    float nota;
};
typedef struct Aluno TAluno;

struct Celula {
    TAluno aluno;
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

void imprimirAluno(TAluno aluno) {
    printf("Matricula: %d, Nome: %s, Nota: %.2f\n", aluno.matricula, aluno.nome, aluno.nota);
}

void insercaoFinal(TLista* p, TAluno aluno) {
    TCelula* aux = (*p).pUltimo;
    (*p).pUltimo = (TCelula*)malloc(sizeof(TCelula));
    if (vazia(p) == TRUE)
        (*p).pPrimeiro = (*p).pUltimo;
    else
        (*aux).pProximo = (*p).pUltimo;

    (*(*p).pUltimo).aluno = aluno;
    (*(*p).pUltimo).pProximo = NULL;
    (*p).tamanho++;
}

int remocaoInicio(TLista* p, TAluno* removido) {
    if (vazia(p) == FALSE) {
        TCelula* aux = (*p).pPrimeiro;
        (*p).pPrimeiro = (*aux).pProximo;
        *removido = (*aux).aluno;
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
    TAluno aluno;

    if (vazia(p) == TRUE) {
        printf("\nLista vazia. Nao ha celulas para imprimir\n");
    } else {
        printf("\nImprimindo conteudo da lista:\n");
        t = (*p).pPrimeiro;

        while (t != NULL) {
            aluno = (*t).aluno;
            imprimirAluno(aluno);
            t = (*t).pProximo;
        }
    }
}

void limpezaLista(TLista* p) {
    while (vazia(p) == FALSE) {
        TAluno aluno;
        remocaoInicio(p, &aluno);
    }
    free(p);
}

int main() {
    TLista* pCabeca;
    TAluno aluno;
    int status;

    iniciacao(&pCabeca);

    printf("Digite a matricula, o nome e a nota de cada aluno (separados por virgula, dois Enter para encerrar a leitura):\n");

    char linha[100];
    char* nome;
    int matricula;
    float nota;
    int linhas_vazias = 0;

    while (linhas_vazias < 2) {
        fgets(linha, sizeof(linha), stdin);
        if (linha[0] == '\n') {
            linhas_vazias++;
        } else {
            linhas_vazias = 0;
            sscanf(linha, "%d,%[^,],%f", &matricula, nome, &nota);
            aluno.matricula = matricula;
            strncpy(aluno.nome, nome, sizeof(aluno.nome));
            aluno.nota = nota;
            insercaoFinal(pCabeca, aluno);
        }
    }

    printf("\nAlunos cadastrados:\n");
    impressaoLista(pCabeca);

    limpezaLista(pCabeca);

    return 0;
}
