#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* remover_caractere(char* string, char caractere) {
    int i, j = 0;
    int tamanho = strlen(string);
    char* nova_string = (char*) malloc(sizeof(char) * tamanho + 1);

    for (i = 0; i < tamanho; i++) {
        if (string[i] != caractere) {
            nova_string[j] = string[i];
            j++;
        }
    }
    nova_string[j] = '\0';
    return nova_string;
}

int main() {
    char* string_original = NULL;
    char caractere_a_ser_removido;

    printf("Digite a string original: ");
    scanf("%ms", &string_original); // %ms faz com que o scanf aloque a memória para a string

    getchar(); // Consome o caractere de quebra de linha deixado pelo scanf anterior

    printf("Digite o caractere a ser removido: ");
    scanf("%c", &caractere_a_ser_removido);

    char* string_modificada = remover_caractere(string_original, caractere_a_ser_removido);

    printf("String original: %s\n", string_original);
    printf("String modificada: %s\n", string_modificada);

    free(string_original);
    free(string_modificada);
    return 0;
}
