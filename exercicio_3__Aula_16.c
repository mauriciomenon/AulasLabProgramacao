#include <stdio.h>
#include <string.h>
#define TAM 255

void p1()
{
    FILE *arq;
    char frase[TAM];

    arq = fopen("frases.txt", "a");
    if (arq == NULL)
        printf("\nErro abrindo arquivo.\n");
    else
    {
        printf("Digite uma frase para ser gravada no arquivo\n");
        fgets(frase, TAM, stdin);
        strtok(frase, "\n"); // remove enter

        fprintf(arq, "%s\n", frase);

        fclose(arq);
    }
}

void p2()
{
    FILE *arq;
    char frase[TAM];

    arq = fopen("frases.txt", "r");
    if (arq == NULL)
        printf("\nErro abrindo arquivo.\n");
    else
    {
        while (fgets(frase, TAM, arq) != NULL)
        {
            strtok(frase, "\n"); // remove enter

            printf("Frase lida do arquivo: \n");
            printf("%s\n", frase);
        }

        fclose(arq);
    }
}

void limpaStdin()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void p3()
{
    int resposta;

    do
    {
        printf("Voce quer continuar adicionando frases? Digite 1 para sim, 0 para nao: ");
        scanf("%d", &resposta);
        limpaStdin();

        if (resposta == 1)
        {
            p1();
        }
    } while (resposta == 1);
}

int main()
{
    p3();
    p2();

    return 0;
}
