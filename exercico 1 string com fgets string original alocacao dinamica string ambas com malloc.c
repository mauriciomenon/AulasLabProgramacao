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
    char *string_original = NULL;
    size_t tamanho = 0;
    char caractere_a_ser_removido;
    char *string_modificada;

    printf("Digite a string original: ");
    getline(&string_original, &tamanho, stdin);
    string_original[strcspn(string_original, "\n")] = 0; // remove a quebra de linha da string lida

    // aloca dinamicamente a memória necessária para armazenar a string lida
    string_original = (char*) malloc(tamanho * sizeof(char));
    if (string_original == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }
    // lê a string original usando fgets
    fgets(string_original, tamanho, stdin);
    // remove a quebra de linha da string lida
    string_original[strcspn(string_original, "\n")] = 0;

    printf("Digite o caractere a ser removido: ");
    scanf("%c", &caractere_a_ser_removido);
    getchar(); // consome a quebra de linha deixada pelo scanf

    string_modificada = remover_caractere(string_original, caractere_a_ser_removido);

    printf("String original: %s\n", string_original);
    printf("String modificada: %s\n", string_modificada);

    free(string_original);
    free(string_modificada);
    return 0;
}
