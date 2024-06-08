#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RESTAURANTE{
	char nome[50];
	char endereco[100];
	char comida[50];
	int nota;
	struct RESTAURANTE *proximo;
	struct RESTAURANTE *inicio;
}Restaurante;

Restaurante *criarNo(char nome[50], char endereco[100], char comida[50], int nota) {
    Restaurante *novo = (Restaurante *)malloc(sizeof(Restaurante));
    strcpy(novo->nome, nome);
    strcpy(novo->endereco, endereco);
    strcpy(novo->comida, comida);
    novo->nota = nota;
    novo->proximo = NULL;
    return novo;
}

void inserirRestaurante(Restaurante **cabeca, char nome[50], char endereco[100], char comida[50], int nota) {
    Restaurante *novo = criarNo(nome, endereco, comida, nota);
    if (*cabeca == NULL) {
        *cabeca = novo;
    } else {
        Restaurante *aux = *cabeca;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void imprimirPorNota(Restaurante *cabeca, int nota){
	Restaurante *aux = cabeca;
	while(aux != NULL){
		if(aux->nota == nota){
			printf("\nNome do Restaurante: %s", aux->nome);
			printf("Endereco: %s", aux->endereco);
			printf("Tipo de Comida: %s", aux->comida);
			printf("Nota do Restaurante: %d\n", aux->nota);
		}
		aux = aux->proximo;
	}
	printf("\n\n");
}

void imprimirPorComida(Restaurante *cabeca, char comida[50]){
	Restaurante *aux = cabeca;
	while(aux != NULL){
		if(strcmp(aux->comida, comida) == 0){
			printf("\nNome do Restaurante: %s", aux->nome);
			printf("Endereco: %s", aux->endereco);
			printf("Tipo de Comida: %s", aux->comida);
			printf("Nota do Restaurante: %d\n", aux->nota);
		}
		aux = aux->proximo;
	}
	printf("\n\n");
}

void imprimir(Restaurante *cabeca) {
    Restaurante *aux = cabeca;
    while (aux != NULL) {
		printf("\nNome do Restaurante: %s", aux->nome);
		printf("Endereco: %s", aux->endereco);
		printf("Tipo de Comida: %s", aux->comida);
		printf("Nota do Restaurante: %d\n", aux->nota);
		aux = aux->proximo;
	}
	printf("\n\n");
}

int main(){
	Restaurante *cabeca = NULL;
	int opcao, nota;
	char nome[50], endereco[100], comida[50];
	do{
		printf("--------------------------------------------------\n");
		printf("Menu de opcoes:\n");
		printf("(1) Cadastrar novo restaurante;\n");
		printf("(2) Mostrar restaurantes;\n");
		printf("(3) Mostrar restaurantes por nota;\n");
		printf("(4) Mostrar restaurantes com determinado tipo de comida;\n");
		printf("(5) Alterar informacoes do restaurante;\n");
		printf("(6) Remover informacoes ou restaurante;\n");
		printf("(7) Sair;\n--------------------------------------------------\n");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1: //inserir novo restaurante
				fflush(stdin);
				printf("Insira o nome do restaurante: ");
				fgets(nome, 50, stdin);
				printf("Insira o endereco do restaurante: ");
				fgets(endereco, 100, stdin);
				printf("Insira o tipo de comida do restaurante: ");
				fgets(comida, 50, stdin);
				printf("Insira a nota do restaurante (de 0 a 5): ");
				scanf("%d", &nota);
				while(nota<0 or nota>5){
					printf("Valor invalido! Digite novamente: ");
					scanf("%d", &nota);
				}
				getchar();
				inserirRestaurante(&cabeca, nome, endereco, comida, nota);
				printf("~~~~Restaurante cadastrado com sucesso!~~~~\n");
				break;
			case 2: //mostrar restaurantes
				imprimir(cabeca);
				break;
			case 3: //mostrar restaurantes por nota
			    printf("Digite a nota desejada: ");
  			 	scanf("%d", &nota);
  			  	imprimirPorNota(cabeca, nota);
				break;
			case 4: //mostrar restaurantes com determinado tipo de comida
				fflush(stdin);
				printf("Digite o tipo de comida desejado: ");
				fgets(comida, 50, stdin);
				imprimirPorComida(cabeca, comida);
				break;
			case 5: //alterar informacoes
				break;
			case 6: //remover informacoes ou restaurante
				break;
			case 7: //sair
				printf("Finalizando...");
				break;
			default:
				printf("Valor invalido!\n");
				break;
		}
	} while (opcao != 7);
	
	return 0;
}
