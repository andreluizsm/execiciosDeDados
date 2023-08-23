#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[100];
    char autor[100];
    int anoPublicacao;
};

void adicionarLivro(struct Livro livros[], int *numLivros) {
    if (*numLivros < 100) { 
        printf("Digite o titulo do livro: ");
        scanf(" %[^\n]", livros[*numLivros].titulo);

        printf("Digite o autor do livro: ");
        scanf(" %[^\n]", livros[*numLivros].autor);

        printf("Digite o ano de publicação do livro: ");
        scanf("%d", &livros[*numLivros].anoPublicacao);

        (*numLivros)++;
        printf("Livro adicionado com sucesso!\n");
    } else {
        printf("Limite de livros atingido.\n");
    }
}

void listarLivros(const struct Livro livros[], int numLivros) {
    printf("Lista de livros:\n");
    int i;
	for ( i = 0; i < numLivros; i++) {
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Ano de Publicaçao: %d\n", livros[i].anoPublicacao);
        printf("\n");
    }
}

void buscarLivroPorAutor(const struct Livro livros[], int numLivros, const char *autorBusca) {
    printf("Livros do autor '%s':\n", autorBusca);
    int i;
	for ( i = 0; i < numLivros; i++) {
        if (strcmp(livros[i].autor, autorBusca) == 0) {
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Ano de Publicaçao: %d\n", livros[i].anoPublicacao);
            printf("\n");
        }
    }
}

int main() {
    struct Livro livros[100];
    int numLivros = 0;
    int opcao;
    char autorBusca[100];

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Buscar Livro por Autor\n");
        printf("4. Sair\n");
        printf("Escolha uma opçao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro(livros, &numLivros);
                break;
            case 2:
                listarLivros(livros, numLivros);
                break;
            case 3:
                printf("Digite o nome do autor para buscar: ");
                scanf(" %[^\n]", autorBusca);
                buscarLivroPorAutor(livros, numLivros, autorBusca);
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

