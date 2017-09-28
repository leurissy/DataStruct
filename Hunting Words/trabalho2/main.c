#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

#define TAM 8
#define SIZE 2
#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3
#define UP_RIGHT 4
#define UP_LEFT 5
#define DOWN_RIGHT 6
#define DOWN_LEFT 7

char** alocar_matriz_duas_dimensoes (unsigned int , unsigned int );
int ler_numero (FILE* , int* , int* );
int preencher_matriz (FILE* , char** , int , int );
//void imprimir_matriz (char** , int , int );
int fill_list (List* L, char** matriz, int a, int b);
void imprimir_list_matriz (List* );
void direcao (int );
void procurar_palavra (List* , TList* );

int main(int argc, char* argv[]){
	
	if (argc > 1){

		char* url = argv[1];
		FILE* file = fopen(url, "r");
		if (file){
			int m, n;
			ler_numero (file, &m, &n);
			char **matriz = alocar_matriz_duas_dimensoes(m,n);
			preencher_matriz (file, matriz, m, n);
			List *L_matriz = create_list();
			fclose(file);
			if (fill_list(L_matriz, matriz, m, n) == 1){
				imprimir_list_matriz (L_matriz);
				
				FILE * file_palavras = fopen (argv[2],"r");

				if (file_palavras){

					TList *palavra_procurada = TList_create();
					char palavra_string[100];

					while ((fgets(palavra_string, sizeof(palavra_string), file_palavras)) != NULL){
						insert_word_tlist (palavra_procurada, palavra_string);
						procurar_palavra (L_matriz, palavra_procurada);
						TList_remove_all(palavra_procurada);
					}
					fclose(file_palavras);
				}
			}
		}else
			puts("Ponteiro nao encontrado, null");
	}else
		puts("Insira o nome do arquivo\n");

    return(0);
}

void imprimir_list_matriz (List* L){

	Node* aux_i, *aux_j;
	int i = 1;
	printf("\t\t\t ");
		for (aux_j = L -> head; aux_j != NULL; aux_j = aux_j -> pointer[RIGHT]){
			if (i > 9)
				printf(" %d ",i++);
			else
				printf("  %d ",i++);
		}

	puts("");
	i = 1;
	for (aux_i = L -> head; aux_i != NULL; aux_i = aux_i -> pointer[DOWN]){
		printf("\t\t\t  --------------------------------------------------------------------------------\n");
		if (i < 10){
			printf("\t\t     %d",i);
		}
		else
			printf("\t\t     %d",i);

		printf("\t |");
		for (aux_j = aux_i; aux_j != NULL; aux_j = aux_j -> pointer[RIGHT]){
			printf(" %c |",aux_j -> info);
		}
		i++;
		puts("");
	}
	printf("\t\t\t  --------------------------------------------------------------------------------\n");
}

void direcao (int direcao){
	switch(direcao){
		case 0:
			puts("Para cima");
		break;
		case 1:
			puts("Para Baixo");
		break;
		case 2:
			puts("Para Direita");
		break;
		case 3:
			puts("Para Esquerda");
		break;
		case 4:
			puts("Diagonal Superior Direita");
		break;
		case 5:
			puts("Diagonal Superior Esquerda");
		break;
		case 6:
			puts("Diagonal Inferior Direita");
		break;
		case 7:
			puts("Diagonal Inferior Esquerda");
		break;
		default :
			puts("Nao encontrado");
	}
}

void procurar_palavra (List* L, TList* L_palavra){
	TNo* temp = L_palavra -> head, *aux_x;
	Node* aux_i, *aux_j, *aux_z;

	int a = 1, b, i;

	for (aux_i = L -> head; aux_i != NULL; aux_i = aux_i -> pointer[DOWN]){
		b = 1;
		for (aux_j = aux_i; aux_j != NULL; aux_j = aux_j -> pointer[RIGHT]){

			if (aux_j -> info == temp -> info){
				
				for (i = 0; i < TAM; i++){
					if (aux_j -> pointer[i]){
						if (temp -> prox -> info == aux_j -> pointer[i] -> info){
							aux_x = temp;
							aux_z = aux_j;

							while (aux_x != NULL && aux_z != NULL){
								if (aux_x -> info != aux_z -> info)
									break;
								aux_x = aux_x -> prox;
								aux_z = aux_z -> pointer[i];
							}

							if (aux_x == NULL){
								TList_printr (L_palavra -> head);
								printf("\t\t - Primeira letra em (%d,%d) \t\t\t- ",a, b);
								direcao(i);
								i = TAM;
							}
						}
					}	
				}
			}
			b++;
		}
		a++;	
	}
}
