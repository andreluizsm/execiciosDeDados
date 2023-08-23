#include <stdio.h>
#include <stdbool.h>

struct ContaBancaria {
    char nomeTitular[100];
    int numeroConta;
    float saldo;
};

void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Deposito de %.2f realizado com sucesso!\n", valor);
}

bool sacar(struct ContaBancaria *conta, float valor) {
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de %.2f realizado com sucesso!\n", valor);
        return true;
    } else {
        printf("Saldo insuficiente para o saque.\n");
        return false;
    }
}

float verificarSaldo(const struct ContaBancaria *conta) {
    return conta->saldo;
}

int main() {
    struct ContaBancaria conta1;

    printf("Digite o nome do titular da conta: ");
    scanf(" %[^\n]", conta1.nomeTitular);

    printf("Digite o numero da conta: ");
    scanf("%d", &conta1.numeroConta);

    conta1.saldo = 0; 

    depositar(&conta1, 1000.0); 

    float saldoAtual = verificarSaldo(&conta1);
    printf("Saldo atual: %.2f\n", saldoAtual);

    sacar(&conta1, 500.0); 

    saldoAtual = verificarSaldo(&conta1);
    printf("Saldo atual: %.2f\n", saldoAtual);

    return 0;
}

