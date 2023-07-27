#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct Item{
	int dado;  // Alterado de char para int
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
	printf("%d\n",x.dado);  // Alterado de %c para %d
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
	}
}

void limpezaLista(TLista * p){
	while (vazia(p)==FALSE){
		TItem t;
		remocaoInicio(p,&t);
		printf("Desalocada celula com item %d\n",t.dado);  // Alterado de %c para %d
	}
	free(p);
}

int main(){
	TLista * pCabeca;
	TItem xg;
	int val;

	iniciacao(&pCabeca);
	
	if (vazia(pCabeca) == TRUE)
		printf("A lista esta vazia\n");
	
	printf("\nDeseja inserir celula na lista? (digite 1 para sim e outro numero para nao)\n");
	scanf("%d",&val);
	printf("\n");

	while (val==1){	
		printf("Digite um número inteiro\n");
		scanf("%d",&(xg.dado));  // Alterado de %c para %d
	
		insercaoFinal(pCabeca,xg);
		
		printf("\nDeseja inserir celula na lista? (digite 1 para sim e outro numero para nao)\n");
		scanf("%d",&val);
		printf("\n");
	}
	
	int status=remocaoInicio(pCabeca, &xg);
	if (status==TRUE) {
		printf("\nA celula removida que estava no inicio da lista e: ");
		printf("%d\n",xg.dado);  // Alterado de %c para %d
	}
	else
		printf("\nNao e possivel remover\n");
	
	limpezaLista(pCabeca);
	
	return 0;
}
