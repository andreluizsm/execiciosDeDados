#include <stdio.h>
#include <stdbool.h>

struct Estudante {
    char nome[100];
    int matricula;
    float nota1, nota2, nota3;
};

float calcularMedia(const struct Estudante *e) {
    return (e->nota1 + e->nota2 + e->nota3) / 3.0;
}

bool estaAprovado(const struct Estudante *e) {
    float media = calcularMedia(e);
    return media >= 7.0;
}

int main() {
    struct Estudante estudante1;

    printf("Digite o nome do estudante: ");
    scanf(" %[^\n]", estudante1.nome);

    printf("Digite a matricula do estudante: ");
    scanf("%d", &estudante1.matricula);

    printf("Digite as notas nas tres disciplinas:\n");
    scanf("%f %f %f", &estudante1.nota1, &estudante1.nota2, &estudante1.nota3);

    float media = calcularMedia(&estudante1);
    printf("Media das notas: %.2f\n", media);

    if (estaAprovado(&estudante1)) {
        printf("O estudante %s esta aprovado!\n", estudante1.nome);
    } else {
        printf("O estudante %s nao esta aprovado.\n", estudante1.nome);
    }

    return 0;
}

