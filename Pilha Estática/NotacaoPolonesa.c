#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char dados[10];
	int head, MAX;
}TStaticStack;

TStaticStack* TStaticStack_create(){
	TStaticStack* novo = (TStaticStack*)malloc(sizeof(TStaticStack));

	if(novo){
		novo->head = -1;
		novo->MAX = 10;
	}
	return(novo);
}

int TStaticStack_push(TStaticStack *P, char* d){
	if(P->head+1 < P->MAX){
		P->expressao[P->head+1] = d;
		P->head = P->head+1;
		return 1;
	}
	return 0;
}

int TStaticStack_pop(TStaticStack *P, char* *d){
	if(P->head >=0){
		*d = P->expressao[P->head--];
		return 1;
	}
	return 0;
}

int main(){
	TStaticStack* letras = TStaticStack_create();
	TStaticStack* operadores = TStaticStack_create();
	char expressao[30];

	if(S){
		printf("Entre com a expressao: \n");
		scanf("%s", expressao);

		while(expressao[i] != '\0'){
			if(expressao[i] >= 40 && expressao[i] <= 47){
				if(expressao[i] != 40 && expressao[i] != 41){
					TStaticStack_push(operadores, expressao[i]);
				}
			}else{
			 	TStaticStack_push(letras, expressao[i]);
			}
		}


	}

	return 0;
}
