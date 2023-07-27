#include <stdio.h>
#include <string.h>

#define MAX 255
#define NF 5

struct Filme
{
	char titulo[MAX];
	char genero[MAX];
	int ano;
};

typedef struct Filme filme;

void limpaStdin()
{
	char c;
	/* descartar todos os caracteres ate \n (incluindo o proprio \n) */
	while (((c = getchar()) != '\n') && (c != EOF))
		;
}

void p1(filme vetor[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("Digite titulo, genero e ano para filme %d\n", i + 1);
		fgets(vetor[i].titulo, MAX, stdin);
		strtok(vetor[i].titulo, "\n");
		fgets(vetor[i].genero, MAX, stdin);
		strtok(vetor[i].genero, "\n");
		scanf("%d", &(vetor[i].ano)); // scanf("%d",&vetor[i].ano);
		limpaStdin();
	}
}

void p3(filme vetor[], int size)
{
	int i;

	printf("\nImprimindo os dados dos %d filmes\n", size);
	for (i = 0; i < size; i++)
	{
		printf("%s; ", vetor[i].titulo);
		printf("%s; ", vetor[i].genero);
		printf("%d\n", vetor[i].ano);
	}
}

int main()
{
	filme vg[NF]; // struct Filme vg[NF];

	p1(vg, NF);
	p3(vg, NF);

	return 0;
}
