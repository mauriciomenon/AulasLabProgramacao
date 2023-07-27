#include <stdio.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

int main() {
    struct Data data1;

    printf("Digite o dia: ");
    scanf("%d", &data1.dia);

    printf("Digite o mes: ");
    scanf("%d", &data1.mes);

    printf("Digite o ano: ");
    scanf("%d", &data1.ano);

    printf("Data lida: %d/%d/%d\n", data1.dia, data1.mes, data1.ano);

    return 0;
}
