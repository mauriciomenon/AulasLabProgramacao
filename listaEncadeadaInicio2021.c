#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

/*Defini��o das estruturas*/
struct Item{ //estrutura b�sica
	char dado; //informa��o do elemento
	/* outros campos podem ser inclu�dos*/
};
typedef struct Item TItem;

struct Celula{ //elemento da lista
	TItem item; //informa��es do elemento
	struct Celula * pProximo; //ponteiro pr�ximo
};
typedef struct Celula TCelula;

struct Lista{ //"cabe�a" da lista
	TCelula * pPrimeiro; //ponteiro primeiro
	TCelula * pUltimo; //ponteiro �ltimo
	int tamanho; //n�mero atual de elementos
};
typedef struct Lista TLista;


/*Rotinas da lista encadeada*/
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

/*Rotina que deve ser modificada se alterar os campos de TItem
OBS.: deve mudar se alterar o conte�do de TItem*/
void imprimirTItem(TItem x){
	printf("%c\n",x.dado);
}

//inser��o sempre pode ser realizada, i.e., sempre � verdadeiro
void insercaoFinal(TLista *p,TItem x){
	//Passo 1: aux aponta para o mesmo lugar que �ltimo, servindo de backup de �ltimo
	TCelula* aux =(*p).pUltimo;
	//Passo 2: �ltimo aponta para nova c�lula
	(*p).pUltimo = (TCelula*)malloc(sizeof(TCelula));	
	if (vazia(p)==TRUE)
		//Passo 3a: se a lista � vazia, o �ltimo inserido tamb�m � o primeiro
		(*p).pPrimeiro=(*p).pUltimo;
	else
		//Passo 3b: sen�o, pr�ximo do aux recebe o �ltimo; a ideia � que o pen�ltimo aponte para o �ltimo	
		(*aux).pProximo = (*p).pUltimo;
	
	//Passo 4: colocar TItem na c�lula
	(*(*p).pUltimo).item = x;
	//Passo 5: anular o pr�ximo do �ltimo
	(*(*p).pUltimo).pProximo = NULL;	
	//Passo 6: atualizar tamanho
	(*p).tamanho++;	
}

/*remo��o � realizada e retorna verdadeiro se a lista n�o estiver vazia; 
caso contr�rio retorna falso.
O ponteiro removido indica um TItem passado por refer�ncia, o qual recebe o TItem
a ser removido quando essa fun��o retorna verdadeiro*/
int remocaoInicio(TLista *p, TItem *removido){
	if (vazia(p)==FALSE){		
		//Passo 1: se lista n�o est� vazia, aux aponta para primeira c�lula, a qual ser� removida
		TCelula *aux = (*p).pPrimeiro;		
		//Passo 2: primeiro passa a apontar para o sucessor da c�lula que ser� removida
		(*p).pPrimeiro=(*aux).pProximo;		
		//Passo 3: copiar o item para o TItem passado por refer�ncia
		*removido = (*aux).item;
		//Passo 4: remover a c�lula apontada por aux
		free(aux);		
		//Passo 5: atualizar tamanho
		(*p).tamanho--;		
		//Passo 6: se removeu a �ltima c�lula, �ltimo deve ser anulado, pois primeiro j� foi anulado nesse caso
		if (vazia(p)==TRUE)
			(*p).pUltimo = NULL;					
		
		return TRUE; //indica sucesso (remo��o retorna verdadeiro)
	}
	else
		return FALSE; //indica erro (remo��o retorna falso)
}


//imprimir o conte�do da lista sem remover elementos
void impressaoLista(TLista * p){
	TCelula * t;
	TItem x;
	
	if (vazia(p) == TRUE){
		printf("\nLista vazia. Nao ha celulas para imprimir\n");
	}
	else{
		printf("\nImprimindo conteudo da lista\n");
		t=(*p).pPrimeiro; 
		
		while (t!=NULL){ //ainda h� c�lulas na lista encadeada
			x = (*t).item;
			imprimirTItem(x);
			t=(*t).pProximo;
		}
	}
}

/*objetivo: remover todos elementos da lista encadeada, 
liberando a �rea din�mica de mem�ria que a lista ocupava*/
void limpezaLista(TLista * p){
	while (vazia(p)==FALSE){ //ainda h� c�lulas na lista encadeada
		TItem t;
		remocaoInicio(p,&t);//limpa c�lula no in�cio, se lista n�o � vazia
		//Obs.: substituir por imprimirTItem(x) para ter c�digo mais flex�vel
		printf("Desalocada celula com item %c\n",t.dado); 
	}
	free(p);//limpa cabe�a da lista
}

void limpaStdin(){ 
	char c; // discard all characters up to and including newline
	while ((c = getchar()) != '\n' && c != EOF); 
}

int main(){
	TLista * pCabeca;
	TItem xg;
	int val,status;
	
	//iniciar a lista encadeada (alocar a TLista)
	iniciacao(&pCabeca);
	
	//dizer se a lista � vazia ou n�o
	if (vazia(pCabeca) == TRUE)
		printf("A lista esta vazia\n");

	//inser��o de uma c�lula por vez, no final da lista, at� que valor espec�fico seja digitado
	printf("\nDeseja inserir celula na lista? (digite 1 para sim e outro numero para nao)\n");
	scanf("%d",&val);
	printf("\n");

	while (val==1){	//enquanto val � 1, insere uma c�lula
		limpaStdin(); //ideia: possibilitar leitura de char a ser digitado na sequ�ncia (ao inv�s de \n)	
	
		//inser��o da c�lula i
		printf("Digite os campos da estrutura TItem\n");
		scanf("%c",&(xg.dado)); //no momento, o �nico campo � um caractere
	
		insercaoFinal(pCabeca,xg);
		
		printf("\nDeseja inserir celula na lista? (digite 1 para sim e outro numero para nao)\n");
		scanf("%d",&val);
		printf("\n");
	}
	
	//remo��o de uma c�lula no in�cio da lista
	status=remocaoInicio(pCabeca, &xg);
	if (status==TRUE) {
		printf("\nA celula removida que estava no inicio da lista e: ");
		printf("%c\n",xg.dado);
	}
	else
		printf("\nNao e possivel remover\n");
	
	//desaloca��o da lista (incluindo cabe�a)
	limpezaLista(pCabeca);
	
	return 0;
}
