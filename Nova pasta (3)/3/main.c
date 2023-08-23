#include <stdio.h>
#include <math.h>

struct Ponto {
    float x;
    float y;
};

float calcularDistancia(const struct Ponto *p1, const struct Ponto *p2) {
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx * dx + dy * dy);
}

float calcularInclinacao(const struct Ponto *p1, const struct Ponto *p2) {
    if (p2->x - p1->x == 0) {
        return INFINITY; 
    }
    return (p2->y - p1->y) / (p2->x - p1->x);
}

int main() {
    struct Ponto ponto1 = {1.0, 2.0};
    struct Ponto ponto2 = {4.0, 6.0};

    float distancia = calcularDistancia(&ponto1, &ponto2);
    printf("Distância entre os pontos: %.2f\n", distancia);

    float inclinacao = calcularInclinacao(&ponto1, &ponto2);
    printf("Inclinação da reta: %.2f\n", inclinacao);

    return 0;
}

