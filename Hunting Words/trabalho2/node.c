#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
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

Node* create_node (char info){

	Node* node = (Node*) malloc (sizeof(Node));

	if (node){
		node -> info = info;
		int i;
		for (i = 0; i < TAM; i++)
			node -> pointer[i] = NULL;
	}
	return (node);
}

List* create_list (){

	List* list = (List*) malloc (sizeof(List));
	if (list) 
		list -> head = NULL;
	return (list);
}

void insert_list (List* L, Node* N){
	L -> head = N;
}

int fill_list (List* L, char** matriz, int a, int b){

	if (L == NULL)
		return 0;

	Node* aux1, *aux3;
	int i, j;

	aux3 = aux1 = create_node(matriz[0][0]);
	insert_list (L, aux1);

	i = 0;
	for (j = 1; j < b; j++){
		aux1 -> pointer[RIGHT] = create_node(matriz[i][j]);
		if (!aux1 -> pointer[RIGHT]) 
			return 0;
		aux1 -> pointer[RIGHT] -> pointer[LEFT] = aux1;
		aux1 = aux1 -> pointer[RIGHT];
	}

	for (i = 1; i < a; i++){

		aux3 -> pointer[DOWN] = create_node(matriz[i][0]);
		if (!aux3 -> pointer[DOWN])
			return 0;
		aux1 = aux3 -> pointer[DOWN];
		aux1 -> pointer[UP] = aux3;

		for (j = 1; j < b; j++){
			aux1 -> pointer[RIGHT] = create_node(matriz[i][j]);
			if (!aux1 -> pointer[RIGHT])
				return 0;
			aux1 -> pointer[RIGHT] -> pointer[LEFT] = aux1;
			aux1 -> pointer[UP] -> pointer[DOWN_RIGHT] = aux1 -> pointer[RIGHT];
			aux1 -> pointer[RIGHT] -> pointer[UP_LEFT] = aux1 -> pointer[UP];
			aux1 -> pointer[UP] -> pointer[RIGHT] -> pointer[DOWN_LEFT] = aux1;
			aux1 -> pointer[UP_RIGHT] = aux1 -> pointer[UP] -> pointer[RIGHT];
			aux1 -> pointer[UP] -> pointer[RIGHT] -> pointer[DOWN] = aux1 -> pointer[RIGHT];
			aux1 -> pointer[RIGHT] -> pointer[UP] = aux1 -> pointer[UP]-> pointer[RIGHT];
			aux1 = aux1 -> pointer[RIGHT];
		}
		aux3 = aux3 -> pointer[DOWN];
	}
	return 1;
}

char** alocar_matriz_duas_dimensoes (unsigned int a, unsigned int b){

	char **novo = (char**) malloc (a*sizeof(char*));
	
	if (novo){
		int i;
		for (i = 0; i < a; i++){
			novo[i] = (char*) malloc(b*sizeof(char));
			if (novo[i] == NULL)
				return (NULL);
		}
	}
	return (novo);
}

int ler_numero (FILE* f, int* y, int* z){

	//Ler primeira linha do arquivo e salvar os numeros nas variaveis
	char info[30], *token;
	const char s[2] = ",";
	int dimensao[SIZE], i;

	fgets(info, sizeof(info),f);
	token = strtok(info, s);

	while(token != NULL){
		dimensao[i++] = atoi(token);
		token = strtok(NULL, s);
	}

	*y = dimensao[0];
	*z = dimensao[1];
	
	return 1;
}
/*
void imprimir_matriz (char** m, int a, int b){
	
	int i, j;
	for (i = 0; i < a; i++){
		for (j = 0; j < b; j++){
			printf("%c",m[i][j]);
		}
		puts("");
	}	
}
*/
int preencher_matriz (FILE* f, char** matriz, int m, int n){

	//Aloca matriz: dimensao[0]xdimensao[1]
	if(matriz == NULL)
		return 0;
	
	//Se alocou as matrizes com sucesso, salvar matriz from file para matriz
	char info[200];
	int f_size = sizeof(info);
	int i = 0, j;
	while ((fgets(info, f_size, f)) != NULL){
		if (i < m){
			j = 0;
			while (info[j] != '\n' && j < n){
				matriz[i][j] = info[j];
				j++;
			}
		}
		i++;
	}
	return 1;
}
