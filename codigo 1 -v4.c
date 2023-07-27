#include <stdio.h>

void inputMatrix(float matrix[3][3]);
float findSmallestElement(float matrix[3][3]);
void multiplyBySmallestElement(float matrix[3][3], float smallestElement);
void printMatrix(float matrix[3][3]);

int main()
{
    float matrix[3][3];

    inputMatrix(matrix);
    float smallestElement = findSmallestElement(matrix);
    multiplyBySmallestElement(matrix, smallestElement);
    printMatrix(matrix);

    return 0;
}

void inputMatrix(float matrix[3][3])
{
    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }
}

float findSmallestElement(float matrix[3][3])
{
    float smallest = matrix[0][0];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] < smallest)
            {
                smallest = matrix[i][j];
            }
        }
    }

    return smallest;
}

void multiplyBySmallestElement(float matrix[3][3], float smallestElement)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] *= smallestElement;
        }
    }
}

void printMatrix(float matrix[3][3])
{
    printf("Matriz resultante:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}
