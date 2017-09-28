#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Matriz.h"

int main(){
	int linhas, colunas;
	obter_Dimensoes(&linhas, &colunas);
	char **matriz = alocar_Matriz(linhas, colunas), palavra[50];
    preencher_Matriz(matriz, linhas, colunas);
    TDList* L = TDList_create();
    Matriz_insertList(L, matriz, linhas, colunas);
    puts(" ");
    TDList_print(L);
    obter_Palavra(palavra);
    procurarPalavras(L, palavra);
	return 0;
}
