#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int valor;
	struct No *proximo;	
}No;

typedef struct{
	No *inicio;
	int tam;
}Lista;

void inserirInicio(Lista *lista, int invalor){
	No *novo = (No*)malloc(sizeof(No));    // ALOCAR ESPAÇO PARA ARMAZENAR VALOR;
	
	if(novo){
		novo->valor = invalor;                 // ESPAÇO DO VALOR RECEBE O VALOR DIGITADO;
		novo->proximo = lista->inicio;         // O PROXIMO DENTRO DO NOVO RECEBE O INÍCIO DA LISTA
		lista->inicio = novo;                  // E O INÍCIO DA LISTA RECEBE A STRUCT "NOVO" INTEIRA (O "NOVO" VIRA O INÍCIO DA LISTA)
		lista->tam++; // aumenta variavel tam pra informar tamanho da lista		
	} else {
		printf("Erro ao alocar memoria!\n");
	}

}

void inserirMeio(Lista *lista, int valor, int anterior){
	No *aux, *novo = (No*)malloc(sizeof(No));
	No *inicio = lista->inicio;
	
	if(novo){
		novo->valor = valor;
		if(lista == NULL){
			inicio = novo;         // SE A LISTA ESTIVER VAZIA, O INICIO DELA RECEBE O VALOR, E O PROXIMO VALOR É NULO (PREPARANDO PARA RECEBER OUTRO)
			novo->proximo = NULL;
		} else {
			aux = inicio;                                   // SE NÃO FOR O PRIMEIRO DA LISTA, CRIA-SE UM AUXILIAR PARA NÃO ALTERAR OS VALORES DA LISTA
			while(aux->valor != anterior && aux->proximo){  // ENQUANTO O VALOR FOR DIFERENTE DO ANTERIOR, E ENQUANTO HOUVER UM PRÓXIMO,
				aux = aux->proximo;                         // PASSA PRO PRÓXIMO ATÉ CHEGAR NO ANTERIOR DE ONDE QUER POR
			}									           	// VAI INSERIR O VALOR NO PRÓXIMO DO ANTERIOR
			novo->proximo = aux->proximo;                   // O LUGAR SEGUINTE DO NOVO RECEBE O VALOR SEGUINTE DO ANTERIOR E O NOVO VIRA O ANTERIOR (O NOVO APONTARÁ PARA O PRÓXIMO)
			aux->proximo = novo;                            // E O VALOR DO ANTERIOR RECEBE O VALOR DO NOVO (O NOVO VAI PARA O SEU LUGAR)
		}
	} else {
		printf("Erro ao alocar memoria!\n");
	}
	lista->tam++;
}

void inserirFim(Lista *lista, int valor){
	No *aux, *novo = (No*)malloc(sizeof(No));
	
	if (novo && aux){
		novo->valor = valor;                       // ESPAÇO DO VALOR RECEBE O VALOR DIGITADO
		novo->proximo = NULL;                        // ESPAÇO PROXIMO RECEBE NULO PQ ACABOU A LISTA
		
		if(lista->inicio == NULL){                   // SE O INCIIO DA LISTA É NULO
			lista->inicio = novo;                    // O INICIO DA LISTA RECEBE O NOVO VALOR
		} else {
			aux = lista->inicio;                      // SENÃO, CRIA-SE UM AUXILIAR NO INÍCIO DA LISTA (para não alterar o valor da lista)
			while(aux->proximo != NULL){               // E PASSA PELA LISTA, INDO PRO PRÓXIMO ATÉ QUE SEJA NULO
				aux = aux->proximo;                    // E O ULTIMO, QUE ERA O PRÓXIMO, RECEBE O NOVO VALOR
			}
			aux->proximo = novo;
		}
		lista->tam++;	
	} else {
		printf("Erro ao alocar memoria!\n");
	}
}

void deletar(Lista *lista, int valor){
	No *inicio = lista->inicio;                // VARIAVEL INICIO
	No *remover = NULL;                        // VARIAVEL REMOVER
	
	if(inicio != NULL && inicio->valor == valor){      // SE O INICIO NÃO FOR NULO E O VALOR FOR IGUAL AO VALOR DIGITADO (SE FOR O PRIMEIRO DA LISTA)
		remover = lista->inicio;         // O NÚMERO A SER REMOVIDO RECEBE O VALOR
		inicio = remover->proximo;       // O INICIO VIRA O PROXIMO
	} else {
		while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor){  // ENQUANTO INICIO NULO, PRÓXIMO INICIO NULO, E VALOR DIFERENTE DO VALOR DIGITADO,
			inicio = inicio->proximo;                                                         // PASSA PRO PRÓXIMO VALOR ATÉ O VALOR SER IGUAL AO VALOR DIGITADO
		}
		if(inicio != NULL && inicio->proximo != NULL){    // SE INICIO NÃO NULO E PRÓXIMO NÃO NULO,
			remover = inicio->proximo;                    // O NÚMERO A SER REMOVIDO RECEBE O VALOR.
			inicio->proximo = remover->proximo;           // E O LUGAR DO PRÓXIMO (REMOVIDO) SERÁ OCUPADO PELO PRÓXIMO DO REMOVIDO.
		}
	}
	if(remover){ // SE REMOVER NÃO FOR NULO
		free(remover); // COMANDO PARA REMOVER DA LISTA;
		lista->tam--; // DIMINUI TAMANHO DA LISTA
	}
}

void imprimir(Lista *lista){
	No *inicio = lista->inicio;       // CRIA UMA VARIÁVEL INICIO QUE RECEBE O INICIO DA LISTA
	printf("Tamanho da lista: %d\n", lista->tam);
	printf("Valores da lista: ");
	while(inicio != NULL){            // SE A LISTA FOR VAZIA, NÃO FARÁ NADA
		printf("%d ", inicio->valor); // IMPRIME VALORES
		inicio = inicio->proximo;     // INICIO RECEBE O PRÓXIMO PRA SER IMPRESSO NA TELA ENQUANTO ELE NÃO FOR NULO (FINAL DA LISTA)
	}
	printf("\n\n");
}

int main(){
	Lista lista;
	int opcao, valor, anterior;
	
	lista.inicio = NULL;
	lista.tam = 0;
	
	do{
		printf("Menu de opcoes:\n(1) Inserir no inicio;\n(2) Inserir no meio;\n(3) Inserir no fim;\n(4) Remover um valor;\n(5) Imprimir;\n(6) Sair.\n-----------------------------------\n");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				printf("Digite o valor a ser inserido: ");
				scanf("%d", &valor);
				inserirInicio(&lista, valor);
				break;
			case 2:
				printf("Digite o valor a ser inserido: ");
				scanf("%d", &valor);
				printf("Digite o valor anterior ao inserido: ");
				scanf("%d", &anterior);
				inserirMeio(&lista, valor, anterior);
				break;
			case 3:
				printf("Digite o valor a ser inserido: ");
				scanf("%d", &valor);
				inserirFim(&lista, valor);
				break;
			case 4:
				printf("Digite o valor a ser removido: ");
				scanf("%d", &valor);
				deletar(&lista, valor);
				break;
			case 5:
				imprimir(&lista);
				break;
			case 6:
				printf("Finalizando...\n");
				break;
			default:
				printf("Opcao Invalida!\n");
				break;
		}
	} while (opcao != 6);
	
	return 0;
}
