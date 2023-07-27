#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

/*Definição das estruturas*/
struct Item{ //estrutura básica
	char dado; //informação do elemento
	/* outros campos podem ser incluídos*/
};
typedef struct Item TItem;

struct Celula{ //elemento da lista
	TItem item; //informações do elemento
	struct Celula * pProximo; //ponteiro próximo
};
typedef struct Celula TCelula;

struct Lista{ //"cabeça" da lista
	TCelula * pPrimeiro; //ponteiro primeiro
	TCelula * pUltimo; //ponteiro último
	int tamanho; //número atual de elementos
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
OBS.: deve mudar se alterar o conteúdo de TItem*/
void imprimirTItem(TItem x){
	printf("%c\n",x.dado);
}

//inserção sempre pode ser realizada, i.e., sempre é verdadeiro
void insercaoFinal(TLista *p,TItem x){
	//Passo 1: aux aponta para o mesmo lugar que último, servindo de backup de último
	TCelula* aux =(*p).pUltimo;
	//Passo 2: último aponta para nova célula
	(*p).pUltimo = (TCelula*)malloc(sizeof(TCelula));	
	if (vazia(p)==TRUE)
		//Passo 3a: se a lista é vazia, o último inserido também é o primeiro
		(*p).pPrimeiro=(*p).pUltimo;
	else
		//Passo 3b: senão, próximo do aux recebe o último; a ideia é que o penúltimo aponte para o último	
		(*aux).pProximo = (*p).pUltimo;
	
	//Passo 4: colocar TItem na célula
	(*(*p).pUltimo).item = x;
	//Passo 5: anular o próximo do último
	(*(*p).pUltimo).pProximo = NULL;	
	//Passo 6: atualizar tamanho
	(*p).tamanho++;	
}

/*remoção é realizada e retorna verdadeiro se a lista não estiver vazia; 
caso contrário retorna falso.
O ponteiro removido indica um TItem passado por referência, o qual recebe o TItem
a ser removido quando essa função retorna verdadeiro*/
int remocaoInicio(TLista *p, TItem *removido){
	if (vazia(p)==FALSE){		
		//Passo 1: se lista não está vazia, aux aponta para primeira célula, a qual será removida
		TCelula *aux = (*p).pPrimeiro;		
		//Passo 2: primeiro passa a apontar para o sucessor da célula que será removida
		(*p).pPrimeiro=(*aux).pProximo;		
		//Passo 3: copiar o item para o TItem passado por referência
		*removido = (*aux).item;
		//Passo 4: remover a célula apontada por aux
		free(aux);		
		//Passo 5: atualizar tamanho
		(*p).tamanho--;		
		//Passo 6: se removeu a última célula, último deve ser anulado, pois primeiro já foi anulado nesse caso
		if (vazia(p)==TRUE)
			(*p).pUltimo = NULL;					
		
		return TRUE; //indica sucesso (remoção retorna verdadeiro)
	}
	else
		return FALSE; //indica erro (remoção retorna falso)
}


//imprimir o conteúdo da lista sem remover elementos
void impressaoLista(TLista * p){
	TCelula * t;
	TItem x;
	
	if (vazia(p) == TRUE){
		printf("\nLista vazia. Nao ha celulas para imprimir\n");
	}
	else{
		printf("\nImprimindo conteudo da lista\n");
		t=(*p).pPrimeiro; 
		
		while (t!=NULL){ //ainda há células na lista encadeada
			x = (*t).item;
			imprimirTItem(x);
			t=(*t).pProximo;
		}
	}
}

/*objetivo: remover todos elementos da lista encadeada, 
liberando a área dinâmica de memória que a lista ocupava*/
void limpezaLista(TLista * p){
	while (vazia(p)==FALSE){ //ainda há células na lista encadeada
		TItem t;
		remocaoInicio(p,&t);//limpa célula no início, se lista não é vazia
		//Obs.: substituir por imprimirTItem(x) para ter código mais flexível
		printf("Desalocada celula com item %c\n",t.dado); 
	}
	free(p);//limpa cabeça da lista
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
	
	//dizer se a lista é vazia ou não
	if (vazia(pCabeca) == TRUE)
		printf("A lista esta vazia\n");

	//inserção de uma célula por vez, no final da lista, até que valor específico seja digitado
	printf("\nDeseja inserir celula na lista? (digite 1 para sim e outro numero para nao)\n");
	scanf("%d",&val);
	printf("\n");

	while (val==1){	//enquanto val é 1, insere uma célula
		limpaStdin(); //ideia: possibilitar leitura de char a ser digitado na sequência (ao invés de \n)	
	
		//inserção da célula i
		printf("Digite os campos da estrutura TItem\n");
		scanf("%c",&(xg.dado)); //no momento, o único campo é um caractere
	
		insercaoFinal(pCabeca,xg);
		
		printf("\nDeseja inserir celula na lista? (digite 1 para sim e outro numero para nao)\n");
		scanf("%d",&val);
		printf("\n");
	}
	
	//remoção de uma célula no início da lista
	status=remocaoInicio(pCabeca, &xg);
	if (status==TRUE) {
		printf("\nA celula removida que estava no inicio da lista e: ");
		printf("%c\n",xg.dado);
	}
	else
		printf("\nNao e possivel remover\n");
	
	//desalocação da lista (incluindo cabeça)
	limpezaLista(pCabeca);
	
	return 0;
}
