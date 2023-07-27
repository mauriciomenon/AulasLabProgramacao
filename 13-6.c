#include <stdio.h>
#include <string.h>

struct Filme {
    char titulo[100];
    char genero[50];
    int ano;
};

void lerFilmes(struct Filme filmes[]) {
    int i;

    printf("Digite as informações dos filmes:\n");

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

void imprimirFilmesAventura(struct Filme filmes[]) {
    int i;
    int encontrados = 0;

    printf("\nFilmes de aventura lancados entre 2001 e 2005:\n");

    for (i = 0; i < 5; i++) {
        if (strcmp(filmes[i].genero, "aventura") == 0 && filmes[i].ano >= 2001 && filmes[i].ano <= 2005) {
            printf("%s\n", filmes[i].titulo);
            encontrados = 1;
        }
    }

    if (!encontrados) {
        printf("Nenhum filme de aventura lancado entre 2001 e 2005 encontrado.\n");
    }
}

int main() {
    struct Filme filmes[5];

    lerFilmes(filmes);
    imprimirFilmesAventura(filmes);

    return 0;
}
