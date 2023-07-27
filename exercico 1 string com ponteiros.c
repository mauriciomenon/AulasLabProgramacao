#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *remover_caractere(char *string, char caractere)
{
    int i, j = 0;
    int tamanho = strlen(string);
    char *nova_string = (char *)malloc(sizeof(char) * tamanho + 1);

    for (i = 0; i < tamanho; i++)
    {
        if (string[i] != caractere)
        {
            nova_string[j] = string[i];
            j++;
        }
    }
    nova_string[j] = '\0';
    printf("String modificada: %s\n", nova_string); // adicionado
    return nova_string;
}

int main()
{
    char string_original[50];
    char caractere_a_ser_removido;

    printf("Digite a string original: ");
    scanf("%s", string_original);

    printf("Digite o caractere a ser removido: ");
    scanf(" %c", &caractere_a_ser_removido);

    char *string_modificada = remover_caractere(string_original, caractere_a_ser_removido);

    free(string_modificada);
    return 0;
}
