#include <stdio.h>

struct Filme {
    char titulo[100];
    char genero[50];
    int ano;
};

void lerFilmes(struct Filme filmes[]) {
    int i;

    for (i = 0; i < 5; i++) {
        printf("\nFilme %d:\n", i + 1);
        printf("Digite o titulo: ");
        scanf("%s", filmes[i].titulo);

        printf("Digite o genero: ");
        scanf("%s", filmes[i].genero);

        printf("Digite o ano: ");
        scanf("%d", &filmes[i].ano);
    }
}

void imprimirFilmes(struct Filme filmes[]) {
    int i;

    printf("\nLista de filmes:\n");

    for (i = 0; i < 5; i++) {
        printf("Filme %d:\n", i + 1);
        printf("Titulo: %s\n", filmes[i].titulo);
        printf("Genero: %s\n", filmes[i].genero);
        printf("Ano: %d\n", filmes[i].ano);
        printf("\n");
    }
}

int main() {
    struct Filme filmes[5];

    lerFilmes(filmes);
    imprimirFilmes(filmes);

    return 0;
}