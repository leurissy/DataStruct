#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "matriz.h"

int main(){
	int linhas, colunas, xInicial, yInicial;
	obter_Dimensoes(&linhas, &colunas);
	char **matriz = alocar_Matriz(linhas, colunas), palavra[50];
    preencher_Matriz(matriz, linhas, colunas, &xInicial, &yInicial);
    exibir_Matriz(matriz, linhas, colunas);
	return 0;
}
