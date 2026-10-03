#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define lproduto "produto.txt"
#define TAM 100

typedef struct {
    char nome[TAM];
    char categoria[TAM];
    float preco;
} Produto;


/* =========================
   Conferir o preço
   ========================= */
int conferir(float *preco) {

    if (scanf("%f", preco) != 1) {

        printf("\nDigite apenas numeros!\n");

        while (getchar() != '\n');

        return 0;
    }

    return 1;
}


/* =========================
   CADASTRAR PRODUTO
   ========================= */
void cadastrar() {

    Produto c;

    FILE *f = fopen(lproduto, "a");

    if (f == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

		system("cls");
        printf("\n");
        printf("====================================================================\n");
        printf("                    CADASTRO DE PRODUTOS                         \n");
        printf("====================================================================\n");

    printf("\nDigite o nome do produto: ");
    scanf(" %99[^\n]", c.nome);

    printf("Digite a categoria do produto: ");
    scanf(" %99[^\n]", c.categoria);

    printf("Digite o preco: ");

    while (!conferir(&c.preco)) {
        printf("Digite o preco novamente: ");
    }

    fprintf(f, "%s;%s;%.2f\n",
            c.nome,
            c.categoria,
            c.preco);

    printf("\nProduto salvo com sucesso!\n");
    printf("Nome: %s\n", c.nome);
    printf("Categoria: %s\n", c.categoria);
    printf("Preco: %.2f\n", c.preco);

    fclose(f);

    system("pause");
}




/* =========================
   Função para listar Produtos
   ========================= */
void listarp() {

    Produto p;
    char linha[250];

    FILE *f = fopen(lproduto, "r");

    if (f == NULL) {
        printf("Arquivo não encontrado.\n");
        system("pause");
        return;
    }

    system("cls");

    printf("\n");
    printf("====================================================================\n");
    printf("                    LISTA DE PRODUTOS CADASTRADOS                   \n");
    printf("====================================================================\n");

    while (fgets(linha, sizeof(linha), f) != NULL) {

        sscanf(linha, "%99[^;];%99[^;];%f",
               p.nome,
               p.categoria,
               &p.preco);

        printf("\nNome: %s\n", p.nome);
        printf("Categoria: %s\n", p.categoria);
        printf("Preco: R$ %.2f\n", p.preco);

        printf("--------------------------------------------------------------------\n");
    }
    fclose(f);
    system("pause");
}






/* =========================
   Função para buscar por nome
   ========================= */

void buscarPorNome() {
    char busca[100], linha[200];
    int encontrado = 0;
    FILE *f = fopen(lproduto, "r");

    if(f == NULL) {
        printf("Arquivo não encontrado.\n");
        return;
    }

		system("cls");
        printf("\n");
        printf("====================================================================\n");
        printf("                    BUSCAR POR NOME                     \n");
        printf("====================================================================\n");
        
        
    printf("\nDigite o nome do produto: ");
    scanf(" %[^\n]", busca);

    while(fgets(linha, sizeof(linha), f)) {
        Produto p;
        sscanf(linha, "%99[^;];%49[^;];%f", p.nome, p.categoria, &p.preco);
        if(strcmp(p.nome, busca) == 0) {
            printf("\nProduto encontrado!\nNome: %s\nCategoria: %s\nPreço: R$ %.2f\n", p.nome, p.categoria, p.preco);
            encontrado = 1;
        }
    }
    if(!encontrado) printf("Produto não encontrado.\n");
    system("pause");
    fclose(f);
}


/* =========================
   Função para buscar por categoria
   ========================= */
void buscarPorCategoria() {
    char busca[50], linha[200];
    int encontrado = 0;
    FILE *f = fopen(lproduto, "r");

    if(f == NULL) {
        printf("Arquivo não encontrado.\n");
        return;
    }

		system("cls");
        printf("\n");
        printf("====================================================================\n");
        printf("                    BUSCAR POR CATEGORIA                    \n");
        printf("====================================================================\n");
        
    printf("\nDigite a categoria: ");
    scanf(" %[^\n]", busca);

    printf("\nProdutos encontrados:\n");
    while(fgets(linha, sizeof(linha), f)) {
        Produto p;
        sscanf(linha, "%99[^;];%49[^;];%f", p.nome, p.categoria, &p.preco);
        if(strcmp(p.categoria, busca) == 0) {
            printf("%s - R$ %.2f\n", p.nome, p.preco);
            encontrado = 1;
        }
    }
    if(!encontrado) printf("Nenhum produto encontrado nessa categoria.\n");
    system("pause");
    fclose(f);
}




/* =========================
   Conferir opção do menu
   ========================= */
int confere(int *Menu) {

    if (scanf("%d", Menu) != 1) {

        printf("\nDigite apenas os numeros dentre as opcoes!\n");

        while (getchar() != '\n');

        return 0;
    }

    return 1;
}






/* =========================
   MENU PRINCIPAL
   ========================= */
int main() {

    int Menu;

    do {

		system("cls");
        printf("\n");
        printf("====================================================================\n");
        printf("                    CONTROLE DE PRODUTOS                           \n");
        printf("====================================================================\n");

        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto por nome\n");
        printf("4 - Buscar produtos por categoria\n");
        printf("5 - Buscar produtos por faixa de preços\n");
        printf("6 - Remover produto\n");
        printf("7 - Atualizar produto\n");
        printf("0 - Sair\n");

        printf("--------------------------------------------------------------------\n");
        printf("Entre com a opcao desejada: ");

while (!confere(&Menu)) {
    printf("Digite a opcao novamente: ");
}

        switch (Menu) {

            case 1:
                cadastrar();
                break;

            case 2:
                printf("\n========== LISTA DE PRODUTOS ==========\n");
                listarp();
                break;

            case 3:
                printf("\n========== BUSCAR PRODUTO POR NOME ==========\n");
                buscarPorNome();
                break;

            case 4:
                printf("\n========== BUSCAR POR CATEGORIA ==========\n");
                buscarPorCategoria();
                break;

            case 5:
                printf("\n========== BUSCAR POR FAIXA DE PREÇOS ==========\n");
                printf("Buscar produtos por faixa de preços\n");
                system("pause");
                break;

            case 6:
                printf("\n========== REMOVER PRODUTO ==========\n");
                printf("Remover produto\n");
                system("pause");
                break;

            case 7:
                printf("\n========== ATUALIZAR PRODUTO ==========\n");
                printf("Atualizar produto\n");
                system("pause");
                break;

            case 0:
                printf("\nObrigado por utilizar o sistema!\n");
                system("cls");
                break;
        }

    } while (Menu != 0);

    return 0;
}
