#include <stdio.h>

int contar_palavras(char *string) {
    int contador = 0;
    char *ptr = string;

    // loop até o final da string
    while (*ptr != '\0') {
        // se encontrar um espaço em branco seguido de uma letra, incrementa o contador de palavras
        if (*ptr == ' ' && *(ptr + 1) != ' ') {
            contador++;
        }
        ptr++;
    }
    // se a última letra não for um espaço em branco, a última palavra não foi contada, então incrementa o contador
    if (*(ptr - 1) != ' ') {
        contador++;
    }
    return contador;
}

int main() {
    char string[50];

    printf("Digite a string: ");
    fgets(string, 50, stdin);

    int num_palavras = contar_palavras(string);

    printf("A string tem %d palavras.\n", num_palavras);

    return 0;
}
