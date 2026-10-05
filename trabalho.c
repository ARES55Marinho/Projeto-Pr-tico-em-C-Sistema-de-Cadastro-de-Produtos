#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define ARQUIVO "produtos.csv"
#define TAM 100

typedef struct {
    char nome[TAM];
    char categoria[TAM];
    float preco;
} Produto;

int conferir(float *preco) {

    if (scanf("%f", preco) != 1) {

        printf("\nDigite apenas numeros!\n");

        while (getchar() != '\n');

        return 0;
    }

    return 1;
}

void cadastrar() {

    Produto p;

    FILE *arquivo;

    arquivo = fopen(ARQUIVO, "a");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    system("cls");

    printf("\n");
    printf("====================================================================\n");
    printf("                    CADASTRO DE PRODUTOS\n");
    printf("====================================================================\n");

    printf("\nDigite o nome do produto: ");
    scanf(" %99[^\n]", p.nome);

    printf("Digite a categoria do produto: ");
    scanf(" %99[^\n]", p.categoria);

    printf("Digite o preco: ");

    while (!conferir(&p.preco)) {
        printf("Digite o preco novamente: ");
    }

    fprintf(arquivo, "%s;%s;%.2f\n",
            p.nome,
            p.categoria,
            p.preco);

    printf("\nProduto salvo com sucesso!\n");
    printf("Nome: %s\n", p.nome);
    printf("Categoria: %s\n", p.categoria);
    printf("Preco: %.2f\n", p.preco);

    fclose(arquivo);

    system("pause");
}

void listarp() {

    Produto p;
    char linha[250];

    FILE *arquivo;

    arquivo = fopen(ARQUIVO, "r");

    if (arquivo == NULL) {
        printf("Arquivo nao encontrado.\n");
        system("pause");
        return;
    }

    system("cls");

    printf("\n");
    printf("====================================================================\n");
    printf("                    LISTA DE PRODUTOS CADASTRADOS\n");
    printf("====================================================================\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {

        sscanf(linha, "%99[^;];%99[^;];%f",
               p.nome,
               p.categoria,
               &p.preco);

        printf("\nNome: %s\n", p.nome);
        printf("Categoria: %s\n", p.categoria);
        printf("Preco: R$ %.2f\n", p.preco);

        printf("--------------------------------------------------------------------\n");
    }

    fclose(arquivo);

    system("pause");
}

void buscarPorNome() {

    char busca[100], linha[200];
    int encontrado = 0;

    FILE *arquivo;

    arquivo = fopen(ARQUIVO, "r");

    if (arquivo == NULL) {
        printf("Arquivo nao encontrado.\n");
        return;
    }

    system("cls");

    printf("\n");
    printf("====================================================================\n");
    printf("                    BUSCAR POR NOME\n");
    printf("====================================================================\n");

    printf("\nDigite o nome do produto: ");
    scanf(" %99[^\n]", busca);

    while (fgets(linha, sizeof(linha), arquivo)) {

        Produto p;

        sscanf(linha, "%99[^;];%99[^;];%f",
               p.nome,
               p.categoria,
               &p.preco);

        if (strcmp(p.nome, busca) == 0) {

            printf("\nProduto encontrado!\n");
            printf("Nome: %s\n", p.nome);
            printf("Categoria: %s\n", p.categoria);
            printf("Preco: R$ %.2f\n", p.preco);

            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nProduto nao encontrado.\n");
    }

    fclose(arquivo);

    system("pause");
}

void buscarPorCategoria() {

    char busca[100], linha[200];
    int encontrado = 0;

    FILE *arquivo;

    arquivo = fopen(ARQUIVO, "r");

    if (arquivo == NULL) {
        printf("Arquivo nao encontrado.\n");
        return;
    }

    system("cls");

    printf("\n");
    printf("====================================================================\n");
    printf("                    BUSCAR POR CATEGORIA\n");
    printf("====================================================================\n");

    printf("\nDigite a categoria: ");
    scanf(" %99[^\n]", busca);

    printf("\nProdutos encontrados:\n");

    while (fgets(linha, sizeof(linha), arquivo)) {

        Produto p;

        sscanf(linha, "%99[^;];%99[^;];%f",
               p.nome,
               p.categoria,
               &p.preco);

        if (strcmp(p.categoria, busca) == 0) {

            printf("%s - R$ %.2f\n",
                   p.nome,
                   p.preco);

            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado nessa categoria.\n");
    }

    fclose(arquivo);

    system("pause");
}

void buscarPreco() {

    float precoMin;
    float precoMax;

    char linha[200];

    int encontrou = 0;

    FILE *arquivo;

    arquivo = fopen(ARQUIVO, "r");

    if (arquivo == NULL) {
        printf("Arquivo nao encontrado.\n");
        return;
    }

    system("cls");

    printf("\n");
    printf("====================================================================\n");
    printf("                    BUSCAR POR FAIXA DE PRECO\n");
    printf("====================================================================\n");

    printf("\nDigite o preco minimo: R$ ");

    while (!conferir(&precoMin)) {
        printf("Digite o preco minimo novamente: R$ ");
    }

    printf("Digite o preco maximo: R$ ");

    while (!conferir(&precoMax)) {
        printf("Digite o preco maximo novamente: R$ ");
    }
	if (precoMin >= precoMax) {
				printf("preço min não pode ser maior que preço max\n");
				system("pause");
				return;
			}
    while (fgets(linha, sizeof(linha), arquivo)) {

        Produto p;

        sscanf(linha, "%99[^;];%99[^;];%f",
               p.nome,
               p.categoria,
               &p.preco);

        if (p.preco >= precoMin && p.preco <= precoMax) {

            printf("\nProduto encontrado!\n");
            printf("Nome: %s\n", p.nome);
            printf("Categoria: %s\n", p.categoria);
            printf("Preco: R$ %.2f\n", p.preco);

            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("\nProduto nao encontrado.\n");
    }

    fclose(arquivo);

    system("pause");
}

void removerProduto() {

    FILE *arquivo;
    FILE *temp;

    temp = fopen("temp.csv", "w");
    arquivo = fopen(ARQUIVO, "r");

    char linha[250];
    char Procura[TAM];

    Produto p;

    int encontrou = 0;

    if (arquivo == NULL) {
        printf("Arquivo nao encontrado\n");

        if (temp != NULL) {
            fclose(temp);
        }

        return;
    }

    if (temp == NULL) {
        printf("Nao foi possivel criar o arquivo temporario.\n");
        fclose(arquivo);
        return;
    }

    system("cls");

    printf("\n");
    printf("====================================================================\n");
    printf("                    REMOVER PRODUTO\n");
    printf("====================================================================\n");

    printf("\nQual produto deseja remover: ");
    scanf(" %99[^\n]", Procura);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {

        char copia[250];

        strcpy(copia, linha);

        strcpy(p.nome, strtok(copia, ";"));
        strcpy(p.categoria, strtok(NULL, ";"));

        p.preco = atof(strtok(NULL, ";\n"));

        if (strcmp(p.nome, Procura) == 0) {

            encontrou = 1;
        }
        else {

            fprintf(temp, "%s", linha);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(ARQUIVO);
    rename("temp.csv", ARQUIVO);

    if (encontrou == 1) {
        printf("\nProduto removido com sucesso!\n");
    }
    else {
        printf("\nProduto nao encontrado.\n");
    }

    system("pause");
}

void atualizar() {

    int encontrou = 0;

    Produto p;

    FILE *arquivo;
    FILE *temp;

    arquivo = fopen(ARQUIVO, "r");
    temp = fopen("temp.csv", "w");

    char linha[250];
    char nomeBusca[100];

    if (arquivo == NULL) {

        printf("Arquivo nao encontrado.\n");

        if (temp != NULL) {
            fclose(temp);
        }

        return;
    }

    if (temp == NULL) {

        printf("\nErro ao criar arquivo temporario.\n");

        fclose(arquivo);

        return;
    }

    system("cls");

    printf("\n");
    printf("====================================================================\n");
    printf("                    ATUALIZAR PRODUTO\n");
    printf("====================================================================\n");

    printf("\nDigite o nome do produto que deseja atualizar: ");
    scanf(" %99[^\n]", nomeBusca);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {

        char copia[250];

        strcpy(copia, linha);

        strcpy(p.nome, strtok(copia, ";"));
        strcpy(p.categoria, strtok(NULL, ";"));

        p.preco = atof(strtok(NULL, ";\n"));

        if (strcmp(p.nome, nomeBusca) == 0) {

            encontrou = 1;

            printf("\nProduto encontrado!\n");

            printf("Digite o novo nome: ");
            scanf(" %99[^\n]", p.nome);

            printf("Digite a nova categoria: ");
            scanf(" %99[^\n]", p.categoria);

            printf("Novo preco: R$ ");

            while (!conferir(&p.preco)) {
                printf("Digite o preco novamente: R$ ");
            }

            fprintf(temp, "%s;%s;%.2f\n",
                    p.nome,
                    p.categoria,
                    p.preco);
        }
        else {

            fprintf(temp, "%s", linha);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(ARQUIVO);
    rename("temp.csv", ARQUIVO);

    if (encontrou == 1) {
        printf("\nProduto atualizado com sucesso!\n");
    }
    else {
        printf("\nProduto nao encontrado.\n");
    }

    system("pause");
}

int main() {

    setlocale(LC_ALL, "");

    int Menu;

    do {

        system("cls");

        printf("\n=========================== Paragon Informatica ===========================\n");

        printf("\n1 - Cadastrar produto");
        printf("\n2 - Listar produtos");
        printf("\n3 - Buscar produto por nome");
        printf("\n4 - Buscar produtos por categoria");
        printf("\n5 - Buscar produtos por faixa de precos");
        printf("\n6 - Remover produto");
        printf("\n7 - Atualizar produto");
        printf("\n0 - Sair");

        printf("\n\nEntre com a opcao desejada: ");
        scanf("%d", &Menu);

        switch (Menu) {

            case 1:
                cadastrar();
                break;

            case 2:
                listarp();
                break;

            case 3:
                buscarPorNome();
                break;

            case 4:
                buscarPorCategoria();
                break;

            case 5:
                buscarPreco();
                break;

            case 6:
                removerProduto();
                break;

            case 7:
                atualizar();
                break;

            case 0:
                printf("\nFinalizando sistema\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                system("pause");
        }

    } while (Menu != 0);

    return 0;
}
