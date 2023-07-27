#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

struct Item{
	char dado;
};
typedef struct Item TItem;

struct Celula{
	TItem item;
	struct Celula * pProximo;
};
typedef struct Celula TCelula;

struct Lista{
	TCelula * pPrimeiro;
	TCelula * pUltimo;
	int tamanho;
};
typedef struct Lista TLista;

void iniciacao(TLista ** p){
	*p=(TLista*)malloc(sizeof(TLista));
	(**p).pPrimeiro = NULL;
	(**p).pUltimo = NULL;
	(**p).tamanho = 0;
}

int vazia(TLista * p){
	if ((*p).tamanho == 0)
		return TRUE;
	else return FALSE;
}

void imprimirTItem(TItem x){
	printf("%c",x.dado);  // Removido o \n daqui
}

void insercaoFinal(TLista *p,TItem x){
	TCelula* aux =(*p).pUltimo;
	(*p).pUltimo = (TCelula*)malloc(sizeof(TCelula));	
	if (vazia(p)==TRUE)
		(*p).pPrimeiro=(*p).pUltimo;
	else
		(*aux).pProximo = (*p).pUltimo;
	
	(*(*p).pUltimo).item = x;
	(*(*p).pUltimo).pProximo = NULL;	
	(*p).tamanho++;	
}

int remocaoInicio(TLista *p, TItem *removido){
	if (vazia(p)==FALSE){		
		TCelula *aux = (*p).pPrimeiro;		
		(*p).pPrimeiro=(*aux).pProximo;		
		*removido = (*aux).item;
		free(aux);		
		(*p).tamanho--;		
		if (vazia(p)==TRUE)
			(*p).pUltimo = NULL;					
		return TRUE;
	}
	else
		return FALSE;
}

void impressaoLista(TLista * p){
	TCelula * t;
	TItem x;
	if (vazia(p) == TRUE){
		printf("\nLista vazia. Nao ha celulas para imprimir\n");
	}
	else{
		printf("\nImprimindo conteudo da lista\n");
		t=(*p).pPrimeiro; 
		while (t!=NULL){
			x = (*t).item;
			imprimirTItem(x);
			t=(*t).pProximo;
		}
		printf("\n");  // Colocado um \n aqui para quebrar linha depois de imprimir a lista
	}
}

void limpezaLista(TLista * p){
	while (vazia(p)==FALSE){
		TItem t;
		remocaoInicio(p,&t);
		printf("Desalocada celula com item %c\n",t.dado); 
	}
	free(p);
}

int main(){
	TLista * pCabeca;
	TItem xg;
	char ch;

	iniciacao(&pCabeca);
	
	printf("Digite uma string, caractere por caractere (aperte Enter para terminar):\n");
	while((ch = getchar()) != '\n'){
		xg.dado = ch;
		insercaoFinal(pCabeca,xg);
	}
	xg.dado = '\0';
	insercaoFinal(pCabeca,xg);
	
	impressaoLista(pCabeca);
	
	limpezaLista(pCabeca);
	
	return 0;
}
