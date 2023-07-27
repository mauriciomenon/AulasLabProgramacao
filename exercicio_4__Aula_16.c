#include <stdio.h>
#include <string.h>
#define TAM 255

void p1()
{
    FILE *arq;
    char frase[TAM];

    arq = fopen("frases.txt", "a"); // mudança
    if (arq == NULL)
        printf("\nErro abrindo arquivo.\n");
    else
    {
        printf("Digite uma frase para ser gravada no arquivo\n");
        fgets(frase, TAM, stdin); // lê frase do teclado (arquivo stdin)
        strtok(frase, "\n");      // remove enter

        fprintf(arq, "%s\n", frase); // imprime no arquivo texto

        fclose(arq);
    }
}

int f()
{
    FILE *arq;
    char frase[TAM];
    char palavra[TAM];
    int encontrado = 0;

    arq = fopen("frases.txt", "r");
    if (arq == NULL)
        printf("\nErro abrindo arquivo.\n");
    else
    {
        printf("Digite a palavra a ser buscada\n");
        fgets(palavra, TAM, stdin);
        strtok(palavra, "\n"); // remove enter

        while ((fgets(frase, TAM, arq) != NULL) && (encontrado == 0))
        {                        // lê frases do arquivo texto
            strtok(frase, "\n"); // remove enter

            if (strcmp(frase, palavra) == 0)
                encontrado = 1;
        }

        fclose(arq);
    }
    return encontrado;
}

void limpaStdin()
{
    char c; // discard all characters up to and including newline
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void p3()
{
    int n, i;

    printf("Digite o numero de frases que deseja inserir\n");
    scanf("%d", &n);

    limpaStdin();

    for (i = 0; i < n; i++)
    {
        p1();
    }
}

int main()
{
    int encontradoG;

    p3();
    encontradoG = f();

    if (encontradoG == 0)
        printf("\n\nPalavra nao encontrada.\n");
    else
        printf("\n\nPalavra encontrada!\n");

    return 0;
}