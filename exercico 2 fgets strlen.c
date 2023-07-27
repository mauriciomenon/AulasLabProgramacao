#include <stdio.h>
#include <string.h>

int contar_palavras(char string[]) {
    int i, contador = 0;
    int tamanho = strlen(string);

    for (i = 0; i < tamanho; i++) {
        if (string[i] == ' ' && i > 0 && string[i-1] != ' ') {
            contador++;
        }
    }

    if (string[tamanho-1] != ' ') {
        contador++;
    }

    return contador;
}

int main() {
    char string[50];

    printf("Digite a string: ");
    fgets(string, 50, stdin);

    int num_palavras = contar_palavras(string);

    printf("Numero de palavras na string: %d\n", num_palavras);

    return 0;
}
