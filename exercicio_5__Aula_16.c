#include <stdio.h>
#include <string.h>

#define MAX 255

void copiaArquivo(char nomeOrigem[MAX], char nomeDestino[MAX])
{
    FILE *origem;
    FILE *destino;
    char linha[MAX];

    origem = fopen(nomeOrigem, "r");
    destino = fopen(nomeDestino, "w");

    if (origem == NULL)
    {
        printf("\nErro abrindo arquivo origem.\n");
    }
    else if (destino == NULL)
    {
        printf("\nErro abrindo arquivo destino.\n");
    }
    else
    { // dois arquivos abertos com sucesso
        while (fgets(linha, MAX, origem) != NULL)
        { // lê da origem
            // strtok(linha, "\n");
            // fprintf(destino,"%s\n", linha); //salva no destino
            fprintf(destino, "%s", linha); // salva no destino
        }
        printf("Copia realizada com sucesso\n");

        fclose(origem);
        fclose(destino);
    }
}

int main()
{
    char nomeOrigemg[MAX], nomeDestinog[MAX];

    printf("Digite o nome do arquivo de origem (nao esqueca do .txt): ");
    fgets(nomeOrigemg, MAX, stdin);
    strtok(nomeOrigemg, "\n");

    printf("Arquivo de destino (nao esqueca do .txt): ");
    fgets(nomeDestinog, MAX, stdin);
    strtok(nomeDestinog, "\n");

    copiaArquivo(nomeOrigemg, nomeDestinog);

    return 0;
}