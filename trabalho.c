#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	setlocale(LC_ALL, "");

	
	int Menu;
	
	do{
		printf("\n=========================== CONTROLE DE PRODUTOS ===========================");
		printf("\n1 - Cadastrar produto");
		printf("\n2 - Listar produtos");
		printf("\n3 - Buscar produto por nome");
		printf("\n4 - Buscar produtos por categoria");
		printf("\n5 - Buscar produtos por faixa de preços");
		printf("\n6 - Remover produto");
		printf("\n7 - Atualizar produto");


		printf("\n0 - Sair");
		printf("\nEntre com a opcao desejada: ");
		scanf("%d", &Menu);
		
		switch(Menu){
			case 1:
				printf("Cadastrar novo produto");
				break;
			case 2:
				printf("Lista de produtos");
				break;
			case 3:
				printf("Buscar produto por nome");
				break;
			case 4: 
				printf("Buscar produtos por categoria");
				break;
			case 5: 
				printf("Buscar produto por faixa de preço");
				break;
			case 6: 
				printf("Remover produto");
				break;	
			case 7: 
				printf("Atualizar produto");
				break;	
			case 0: 
				printf("Obrigado!");
				break;		
				
				system("Pause");
		}

	} while(Menu != 0);


return 0;
}
