#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Matriz.h"

int main(){
	int linhas, colunas;
	obter_Dimensoes(&linhas, &colunas);
	char palavra[50];
	char **matriz = alocar_Matriz(linhas, colunas);
    preencher_Matriz(matriz, linhas, colunas);
    exibir_Matriz(matriz, linhas, colunas);
    TDList* L = TDList_create();
    Matriz_insertList(L, matriz, linhas, colunas);
    puts(" ");
    TDList_print(L);
    obter_Palavra(palavra);
    printf("palavra: %s", palavra);
	return 1;
}
