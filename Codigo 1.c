#include <stdio.h>

// Função para carregar matriz de entrada
void carregarMatriz(float matriz[3][3])
{
    printf("Entre com os valores da matriz:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%f", &matriz[i][j]);
        }
    }
}

// Função para identificar o menor elemento da matriz de entrada
float identificarMenor(float matriz[3][3])
{
    float menor = matriz[0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
            }
        }
    }
    return menor;
}

// Função para multiplicar o menor elemento por cada elemento da matriz de entrada
void multiplicarMatriz(float matriz[3][3], float menor, float resultado[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            resultado[i][j] = matriz[i][j] * menor;
        }
    }
}

// Função para imprimir a matriz resultante da multiplicação
void imprimirMatriz(float matriz[3][3])
{
    printf("Matriz resultante:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    float matriz[3][3], resultado[3][3], menor;

    // Carrega matriz de entrada a partir do teclado
    carregarMatriz(matriz);

    // Identifica o menor elemento da matriz de entrada
    menor = identificarMenor(matriz);

    // Multiplica o menor elemento por cada elemento da matriz de matriz de entrada, resultando em uma nova matriz
    multiplicarMatriz(matriz, menor, resultado);

    // Imprime a matriz resultante da multiplicação
    imprimirMatriz(resultado);

    return 0;
}
