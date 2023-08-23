#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

void setPessoa(struct Pessoa *p, const char *nome, int idade, float altura) {
    strcpy(p->nome, nome);
    p->idade = idade;
    p->altura = altura;
}

void imprimirPessoa(const struct Pessoa *p) {
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Altura: %.2f\n", p->altura);
}

int main() {

    struct Pessoa pessoa1;

    setPessoa(&pessoa1, "Joao", 25, 1.75);

    imprimirPessoa(&pessoa1);

    return 0;
}

