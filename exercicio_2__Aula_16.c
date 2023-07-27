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

void p2()
{
    FILE *arq;
    char frase[TAM];

    arq = fopen("frases.txt", "r"); // mudança
    if (arq == NULL)
        printf("\nErro abrindo arquivo.\n");
    else
    {
        while (fgets(frase, TAM, arq) != NULL)
        {                        // lê frases do arquivo texto
            strtok(frase, "\n"); // remove enter

            printf("Frase lida do arquivo: \n");
            printf("%s\n", frase); // imprime na tela (arquivo stdout)
        }

        fclose(arq);
    }
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
    p3(); // mudança
    p2();

    return 0;
}