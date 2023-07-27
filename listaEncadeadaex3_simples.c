#include <stdio.h>
#include <stdlib.h>

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
};
typedef struct Lista TLista;

void iniciacao(TLista ** p){
	*p=(TLista*)malloc(sizeof(TLista));
	(**p).pPrimeiro = NULL;
	(**p).pUltimo = NULL;
}

void insercaoFinal(TLista *p, TItem x){
	TCelula* aux =(*p).pUltimo;
	(*p).pUltimo = (TCelula*)malloc(sizeof(TCelula));	
	if ((*p).pPrimeiro == NULL)
		(*p).pPrimeiro = (*p).pUltimo;
	else
		aux->pProximo = (*p).pUltimo;
	
	(*(*p).pUltimo).item = x;
	(*(*p).pUltimo).pProximo = NULL;	
}

void impressaoLista(TLista * p){
	TCelula * t = (*p).pPrimeiro; 
	while (t != NULL){
		printf("%d ", t->item.dado);
		t = t->pProximo;
	}
	printf("\n");
}

void limpezaLista(TLista * p){
	TCelula * t = (*p).pPrimeiro;
	while (t != NULL){
		TCelula * aux = t;
		t = t->pProximo;
		free(aux);
	}
	free(p);
}

int main(){
	TLista * pCabeca;
	TItem xg;
	char choice;

	iniciacao(&pCabeca);

	do {
		printf("Digite um número inteiro: ");
		scanf("%d", &(xg.dado));
		insercaoFinal(pCabeca, xg);
		printf("Deseja inserir outro número? (S/N): ");
		scanf(" %c", &choice);
	} while (choice == 'S' || choice == 's');
	
	printf("\nConteúdo da lista:\n");
	impressaoLista(pCabeca);
	
	limpezaLista(pCabeca);

	return 0;
}
