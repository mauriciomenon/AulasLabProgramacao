#include <stdio.h>
#include <string.h>

struct Filme {
    char titulo[100];
    char genero[50];
    int ano;
};

int buscarFilmes(struct Filme filmes[]) {
    char campo[10];
    char valor[100];
    int i, count = 0;

    printf("Digite o campo que deseja usar para buscar filmes (titulo, genero ou ano): ");
    scanf("%s", campo);

    if (strcmp(campo, "titulo") == 0 || strcmp(campo, "genero") == 0 || strcmp(campo, "ano") == 0) {
        printf("Digite o valor que deseja buscar: ");
        scanf("%s", valor);

        printf("\nFilmes encontrados:\n");

        for (i = 0; i < 5; i++) {
            if (strcmp(campo, "titulo") == 0 && strcmp(filmes[i].titulo, valor) == 0) {
                printf("Titulo: %s\nGenero: %s\nAno: %d\n\n", filmes[i].titulo, filmes[i].genero, filmes[i].ano);
                count++;
            } else if (strcmp(campo, "genero") == 0 && strcmp(filmes[i].genero, valor) == 0) {
                printf("Titulo: %s\nGenero: %s\nAno: %d\n\n", filmes[i].titulo, filmes[i].genero, filmes[i].ano);
                count++;
            } else if (strcmp(campo, "ano") == 0 && atoi(valor) == filmes[i].ano) {
                printf("Titulo: %s\nGenero: %s\nAno: %d\n\n", filmes[i].titulo, filmes[i].genero, filmes[i].ano);
                count++;
            }
        }

        return count;
    } else {
        return -1;
    }
}

int main() {
    struct Filme filmes[5];
    int filmesEncontrados;

    printf("Digite as informações dos filmes:\n");

    for (int i = 0; i < 5; i++) {
        printf("\nFilme %d:\n", i + 1);
        printf("Digite o titulo: ");
        scanf("%s", filmes[i].titulo);

        printf("Digite o genero: ");
        scanf("%s", filmes[i].genero);

        printf("Digite o ano: ");
        scanf("%d", &filmes[i].ano);
    }

    filmesEncontrados = buscarFilmes(filmes);

    if (filmesEncontrados == -1) {
        printf("Campo fornecido pelo usuario e inexistente.\n");
    } else if (filmesEncontrados == 0) {
        printf("Nenhum filme possui o valor de campo fornecido.\n");
    }

    return 0;
}
