#include <stdio.h>
#include <stdbool.h>
#include <string.h>


struct Produto {
    char nome[100];
    float preco;
    int quantidadeEstoque;
};

void comprarProduto(struct Produto *produto, int quantidadeComprada) {
    if (quantidadeComprada <= produto->quantidadeEstoque) {
        produto->quantidadeEstoque -= quantidadeComprada;
        printf("Compra de %d unidades de %s realizada com sucesso!\n", quantidadeComprada, produto->nome);
    } else {
        printf("Quantidade em estoque insuficiente.\n");
    }
}

int main() {
    struct Produto produto1;

    strcpy(produto1.nome, "Camiseta");
    produto1.preco = 29.99;
    produto1.quantidadeEstoque = 50;

    printf("Bem-vindo a loja!\n");
    printf("Produto disponivel: %s\n", produto1.nome);
    printf("Preco: R$%.2f\n", produto1.preco);
    printf("Quantidade em estoque: %d\n", produto1.quantidadeEstoque);

    int quantidadeComprada;
    printf("Digite a quantidade que deseja comprar: ");
    scanf("%d", &quantidadeComprada);

    comprarProduto(&produto1, quantidadeComprada);

    printf("Estoque atual de %s: %d\n", produto1.nome, produto1.quantidadeEstoque);

    float totalCompra = produto1.preco * quantidadeComprada;
    printf("Total da compra: R$%.2f\n", totalCompra);

    return 0;
}

