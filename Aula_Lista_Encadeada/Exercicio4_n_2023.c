#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

/* Definição das estruturas */
struct Item {
    char nome[100];  // nome do livro
    float preco;     // preço do livro
};
typedef struct Item TItem;

struct Celula {
    TItem item;                // informações do elemento
    struct Celula* pProximo;   // ponteiro próximo
};
typedef struct Celula TCelula;

struct Lista {
    TCelula* pPrimeiro;   // ponteiro primeiro
    TCelula* pUltimo;     // ponteiro último
    int tamanho;          // número atual de elementos
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

/* Rotina que deve ser modificada se alterar os campos de TItem
   OBS.: deve mudar se alterar o conteúdo de TItem */
void imprimirTItem(TItem x) {
    printf("Nome: %s, Preco: %.2f\n", x.nome, x.preco);
}

// inserção sempre pode ser realizada, ou seja, sempre é verdadeiro
void insercaoFinal(TLista* p, TItem x) {
    // Passo 1: aux aponta para o mesmo lugar que último, servindo de backup de último
    TCelula* aux = (*p).pUltimo;
    // Passo 2: último aponta para nova célula
    (*p).pUltimo = (TCelula*)malloc(sizeof(TCelula));
    if (vazia(p) == TRUE)
        // Passo 3a: se a lista é vazia, o último inserido também é o primeiro
        (*p).pPrimeiro = (*p).pUltimo;
    else
        // Passo 3b: senão, próximo do aux recebe o último; a ideia é que o penúltimo aponte para o último
        (*aux).pProximo = (*p).pUltimo;

    // Passo 4: colocar TItem na célula
    (*(*p).pUltimo).item = x;
    // Passo 5: anular o próximo do último
    (*(*p).pUltimo).pProximo = NULL;
    // Passo 6: atualizar tamanho
    (*p).tamanho++;
}

/* remoção é realizada e retorna verdadeiro se a lista não estiver vazia;
   caso contrário retorna falso.
   O ponteiro removido indica um TItem passado por referência,
   o qual recebe o TItem a ser removido quando essa função retorna verdadeiro */
int remocaoInicio(TLista* p, TItem* removido) {
    if (vazia(p) == FALSE) {
        // Passo 1: se lista não está vazia, aux aponta para primeira célula, a qual será removida
        TCelula* aux = (*p).pPrimeiro;
        // Passo 2: primeiro passa a apontar para o sucessor da célula que será removida
        (*p).pPrimeiro = (*aux).pProximo;
        // Passo 3: copiar o item para o TItem passado por referência
        *removido = (*aux).item;
        // Passo 4: remover a célula apontada por aux
        free(aux);
        // Passo 5: atualizar tamanho
        (*p).tamanho--;
        // Passo 6: se removeu a última célula, último deve ser anulado, pois primeiro já foi anulado nesse caso
        if (vazia(p) == TRUE)
            (*p).pUltimo = NULL;

        return TRUE;  // indica sucesso (remoção retorna verdadeiro)
    } else
        return FALSE;  // indica erro (remoção retorna falso)
}

// imprimir o conteúdo da lista sem remover elementos
void impressaoLista(TLista* p) {
    TCelula* t;
    TItem x;

    if (vazia(p) == TRUE) {
        printf("\nLista vazia. Nao ha celulas para imprimir\n");
    } else {
        printf("\nImprimindo conteudo da lista:\n");
        t = (*p).pPrimeiro;

        while (t != NULL) {  // ainda há células na lista encadeada
            x = (*t).item;
            imprimirTItem(x);
            t = (*t).pProximo;
        }
    }
}

/* objetivo: remover todos elementos da lista encadeada,
   liberando a área dinâmica de memória que a lista ocupava */
void limpezaLista(TLista* p) {
    while (vazia(p) == FALSE) {  // ainda há células na lista encadeada
        TItem t;
        remocaoInicio(p, &t);  // limpa célula no início, se lista não é vazia
    }
    free(p);  // limpa cabeça da lista
}

int main() {
    TLista* pCabeca;
    TItem xg;
    int status;

    // iniciar a lista encadeada (alocar a TLista)
    iniciacao(&pCabeca);

    printf("Digite o nome e o preco de cada livro (separados por virgula, Enter para nova linha, 2 Enter para encerrar a leitura):\n");

    // leitura dos livros
    char linha[100];
    char* nome;
    float preco;
    int linhas_vazias = 0;

    while (linhas_vazias < 2) {
        fgets(linha, sizeof(linha), stdin);
        if (linha[0] == '\n') {
            linhas_vazias++;
        } else {
            linhas_vazias = 0;
            nome = strtok(linha, ",");
            sscanf(strtok(NULL, ","), "%f", &preco);
            strncpy(xg.nome, nome, sizeof(xg.nome));
            xg.preco = preco;
            insercaoFinal(pCabeca, xg);
        }
    }

    // impressão da lista de livros
    printf("\nLivros cadastrados:\n");
    impressaoLista(pCabeca);

    // desalocação da lista (incluindo cabeça)
    limpezaLista(pCabeca);

    return 0;
}
 