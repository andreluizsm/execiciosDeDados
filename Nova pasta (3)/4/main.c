#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[15];
};

void adicionarContato(struct Contato contatos[], int *numContatos) {
    if (*numContatos < 100) { 
        printf("Digite o nome do contato: ");
        scanf("%s", contatos[*numContatos].nome);

        printf("Digite o número de telefone do contato: ");
        scanf("%s", contatos[*numContatos].telefone);

        (*numContatos)++;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("Limite de contatos atingido.\n");
    }
}

void listarContatos(const struct Contato contatos[], int numContatos) {
    printf("Lista de contatos:\n");
    int i;
	for (i = 0; i < numContatos; i++) {
        printf("Nome: %s, Telefone: %s\n", contatos[i].nome, contatos[i].telefone);
    }
}

void buscarContato(const struct Contato contatos[], int numContatos, const char *nomeBusca) {
    int i;
	for (i = 0; i < numContatos; i++) {
        if (strcmp(contatos[i].nome, nomeBusca) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s, Telefone: %s\n", contatos[i].nome, contatos[i].telefone);
            return;
        }
    }
    printf("Contato não encontrado.\n");
}

int main() {
    struct Contato contatos[100];
    int numContatos = 0;
    int opcao;
    char nomeBusca[50];

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato pelo Nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opçao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(contatos, &numContatos);
                break;
            case 2:
                listarContatos(contatos, numContatos);
                break;
            case 3:
                printf("Digite o nome do contato a ser buscado: ");
                scanf("%s", nomeBusca);
                buscarContato(contatos, numContatos, nomeBusca);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção invalida.\n");
        }
    } while (opcao != 4);

    return 0;
}

