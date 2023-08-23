#include <stdio.h>
#include <string.h>
#include <time.h>

struct Funcionario {
    char nome[100];
    char cargo[100];
    float salario;
    struct tm dataAdmissao;
};

void darAumento(struct Funcionario *funcionario, float percentualAumento) {
    funcionario->salario += (funcionario->salario * percentualAumento / 100.0);
    printf("Aumento de %.2f%% aplicado com sucesso para o funcionario %s.\n", percentualAumento, funcionario->nome);
}

int calcularTempoNaEmpresa(const struct Funcionario *funcionario) {
    time_t currentTime;
    time(&currentTime);
    
    struct tm *dataAtual = localtime(&currentTime);
    
    int anos = dataAtual->tm_year - funcionario->dataAdmissao.tm_year;
    int meses = dataAtual->tm_mon - funcionario->dataAdmissao.tm_mon;

    if (meses < 0) {
        anos--;
        meses += 12;
    }

    return anos;
}

int main() {
    struct Funcionario funcionario1;

    strcpy(funcionario1.nome, "Joao");
    strcpy(funcionario1.cargo, "Desenvolvedor");
    funcionario1.salario = 5000.0;

    time_t currentTime;
    time(&currentTime);
    funcionario1.dataAdmissao = *localtime(&currentTime);
    funcionario1.dataAdmissao.tm_year -= 3; 
    printf("Dados do funcionario:\n");
    printf("Nome: %s\n", funcionario1.nome);
    printf("Cargo: %s\n", funcionario1.cargo);
    printf("Salario: R$%.2f\n", funcionario1.salario);

    int anosNaEmpresa = calcularTempoNaEmpresa(&funcionario1);
    printf("Tempo na empresa: %d anos\n", anosNaEmpresa);

    darAumento(&funcionario1, 10.0); 

    printf("Novo salario: R$%.2f\n", funcionario1.salario);

    return 0;
}

