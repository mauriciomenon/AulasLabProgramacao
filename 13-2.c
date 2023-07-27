#include <stdio.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Aluno {
    char nome[50];
    struct Data d_nasc;
};

int main() {
    struct Aluno aluno;

    printf("Digite o nome do aluno: ");
    scanf("%s", aluno.nome);

    printf("Digite o dia de nascimento: ");
    scanf("%d", &aluno.d_nasc.dia);

    printf("Digite o mes de nascimento: ");
    scanf("%d", &aluno.d_nasc.mes);

    printf("Digite o ano de nascimento: ");
    scanf("%d", &aluno.d_nasc.ano);

    printf("\nDados do aluno:\n");
    printf("Nome: %s\n", aluno.nome);
    printf("Data de nascimento: %d/%d/%d\n", aluno.d_nasc.dia, aluno.d_nasc.mes, aluno.d_nasc.ano);

    return 0;
}
