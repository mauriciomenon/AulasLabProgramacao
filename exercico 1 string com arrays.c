#include <stdio.h>
#include <string.h>

void remover_caractere(char string[], char caractere) {
    int i, j = 0;
    int tamanho = strlen(string);

    for (i = 0; i < tamanho; i++) {
        if (string[i] != caractere) {
            string[j] = string[i];
            j++;
        }
    }
    string[j] = '\0';
}

int main() {
    char string_original[50];
    char caractere_a_ser_removido;

    printf("Digite a string original: ");
    scanf("%s", string_original);

    printf("Digite o caractere a ser removido: ");
    scanf(" %c", &caractere_a_ser_removido);

    remover_caractere(string_original, caractere_a_ser_removido);

    printf("String modificada: %s\n", string_original);

    return 0;
}
