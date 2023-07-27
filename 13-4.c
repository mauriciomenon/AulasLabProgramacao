#include <stdio.h>
#include <string.h>

struct Carro {
    char fabricante[50];
    char modelo[50];
    int ano;
    char cor[20];
    float preco;
};

struct Carro lerCarro() {
    struct Carro carro;

    printf("Digite o fabricante do carro: ");
    scanf("%s", carro.fabricante);

    printf("Digite o modelo do carro: ");
    scanf("%s", carro.modelo);

    printf("Digite o ano do carro (4 digitos): ");
    scanf("%d", &carro.ano);

    printf("Digite a cor do carro: ");
    scanf("%s", carro.cor);

    printf("Digite o preco do carro: ");
    scanf("%f", &carro.preco);

    return carro;
}

void imprimirCarro(struct Carro carro) {
    printf("\nInformacoes do carro:\n");
    printf("Fabricante: %s\n", carro.fabricante);
    printf("Modelo: %s\n", carro.modelo);
    printf("Ano: %02d\n", carro.ano % 100);
    printf("Cor: %s\n", carro.cor);
    printf("Preco: R$ %.2f\n", carro.preco);
}

void atualizarCarro(struct Carro *carro) {
    if (carro->ano < 2000) {
        carro->ano = 2000;
    }

    if (strcmp(carro->fabricante, "Chevrolet") == 0) {
        strcpy(carro->fabricante, "GM");
    }
}

int main() {
    struct Carro meuCarro = lerCarro();
    imprimirCarro(meuCarro);

    atualizarCarro(&meuCarro);
    imprimirCarro(meuCarro);

    return 0;
}
