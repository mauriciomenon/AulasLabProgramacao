#include <stdio.h>
#include <string.h>

int contar_palavras(char string[]) {
    int num_palavras = 1; // começa com 1 para contar a última palavra
    int tamanho = strlen(string);
    int i;

    for (i = 0; i < tamanho; i++) {
        if (string[i] == ' ') {
            num_palavras++;
        }
    }

    return num_palavras;
}

int main() {
    char string[100];

    printf("Digite a string: ");
    fgets(string, 100, stdin);

    int num_palavras = contar_palavras(string);

    printf("Numero de palavras: %d\n", num_palavras);

    return 0;
}
