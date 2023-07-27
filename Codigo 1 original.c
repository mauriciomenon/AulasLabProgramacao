#include <stdio.h>
#define NL 3
#define NC 3

void carregaMatriz(double entrada[NL][NC], int s1, int s2)
{
    int i, j;

    printf("Carregando matriz %d x %d do teclado\n", s1, s2);

    for (i = 0; i < s1; i++)
    {
        for (j = 0; j < s2; j++)
        {
            scanf("%lf", &entrada[i][j]);
        }
    }
}

double encontraMenor(double entrada[NL][NC], int s1, int s2)
{
    int i, j;
    double menor;

    menor = entrada[0][0]; // alternativa: DBL_MAX (incluir float.h)
    for (i = 0; i < s1; i++)
    {
        for (j = 0; j < s2; j++)
        {
            if (entrada[i][j] < menor)

                menor = entrada[i][j];

						/*
						caso quisermos encontrar o maior da matriz, deve-se
                        mudar o if atual para o que segue no comentário
                        if (entrada[i][j] > maior) 
                        maior = entrada[i][j];
                        */
        }
    }
    return menor;
}

void multiplicaMenor(double entrada[NL][NC], double resultante[NL][NC], double menor, int s1, int s2)
{
    int i, j;
    for (i = 0; i < s1; i++)
    {
        for (j = 0; j < s2; j++)
        {

            resultante[i][j] = menor * entrada[i][j];
        }
    }
}

void imprimeMatriz(double resultante[NL][NC], int s1, int s2)
{

    int i, j;

    printf("Imprimindo matriz...\n");
    for (i = 0; i < s1; i++)
    { // percorre linhas
        for (j = 0; j < s2; j++)
        { // percorre colunas
            printf("%.2lf ", resultante[i][j]);
        }

        printf("\n");
    }
}

int main()
{

    double mat[NL][NC];
    double res[NL][NC];
    double men;

    carregaMatriz(mat, NL, NC);
    men = encontraMenor(mat, NL, NC);
    multiplicaMenor(mat, res, men, NL, NC);
    imprimeMatriz(res, NL, NC);

    return 0;
}
