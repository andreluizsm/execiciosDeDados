#include <stdio.h>

struct Tipo {
    int valorInteiro;
    float valorFlutuante;
    char letra;
};

void setTipo(struct Tipo *t, int inteiro, float flutuante, char letra) {
    t->valorInteiro = inteiro;
    t->valorFlutuante = flutuante;
    t->letra = letra;
}

void imprimeTipo(const struct Tipo *t) {
    printf("Valor Inteiro: %d\n", t->valorInteiro);
    printf("Valor Quebrado: %.2f\n", t->valorFlutuante);
    printf("Letra: %c\n", t->letra);
}

int main() {
    struct Tipo meuTipo;

    setTipo(&meuTipo, 42, 3.14, 'A');

    imprimeTipo(&meuTipo);

    return 0;
}

