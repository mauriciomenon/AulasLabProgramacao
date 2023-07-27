#include <stdio.h>

// Função para carregar matriz de entrada
void carregarMatriz(float matriz[3][4])
{
    printf("Entre com os valores da matriz:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%f", &matriz[i][j]);
        }
    }
}

// Função para imprimir a matriz
void imprimirMatriz(float matriz[4][3])
{
    printf("Matriz transposta:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para preencher a matriz transposta 4x3 com os dados da matriz carregada 3x4
void preencherTransposta(float matriz3x4[3][4], float transposta4x3[4][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            transposta4x3[j][i] = matriz3x4[i][j];
        }
    }
}

int main()
{
    float matriz[3][4], transposta[4][3];

    // Carrega matriz de entrada a partir do teclado
    carregarMatriz(matriz);

    // Preenche a matriz transposta 4x3 com os dados da matriz carregada 3x4
    preencherTransposta(matriz, transposta);

    // Imprime a matriz transposta
    imprimirMatriz(transposta);

    return 0;
}
