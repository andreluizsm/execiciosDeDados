#include <stdio.h>

struct Moeda {
    float dolares;
    float euros;
};

float dolaresParaEuros(float valorDolares, float taxaCambio) {
    return valorDolares * taxaCambio;
}

float eurosParaDolares(float valorEuros, float taxaCambio) {
    return valorEuros / taxaCambio;
}

int main() {
    struct Moeda moeda;
    float taxaCambio;

    printf("Digite a taxa de cambio (valor em euros para 1 dolar): ");
    scanf("%f", &taxaCambio);

    printf("Digite o valor em dolares: ");
    scanf("%f", &moeda.dolares);

    moeda.euros = dolaresParaEuros(moeda.dolares, taxaCambio);

    printf("%.2f dolares equivalem a %.2f euros.\n", moeda.dolares, moeda.euros);

    printf("Digite o valor em euros: ");
    scanf("%f", &moeda.euros);

    moeda.dolares = eurosParaDolares(moeda.euros, taxaCambio);

    printf("%.2f euros equivalem a %.2f dolares.\n", moeda.euros, moeda.dolares);

    return 0;
}

