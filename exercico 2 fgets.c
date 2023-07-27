#include <stdio.h>
#include <string.h>

int contar_palavras(char* string) {
    int tamanho = strlen(string);
    int contador = 0;
    int i;

    // Verifica se há um espaço em branco após cada palavra
    for (i = 0; i < tamanho; i++) {
        if (string[i] == ' ') {
            contador++;
        }
    }

    // Adiciona 1 para contar a última palavra, já que não há espaço após ela
    contador++;

    return contador;
}

int main() {
    char string[100];

    printf("Digite a string: ");
    fgets(string, 100, stdin);

    int numero_de_palavras = contar_palavras(string);

    printf("O numero de palavras na string e: %d\n", numero_de_palavras);

    return 0;
}
