#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int carro[10];
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

int TStaticStack_push(TStaticStack *P, int d){
	if(P->head+1 < P->MAX){
		P->carro[P->head+1] = d;
		P->head = P->head+1;
		return 1;
	}
	return 0;
}

int TStaticStack_pop(TStaticStack *P, int *d){
	if(P->head >=0){
		*d = P->carro[P->head--];
		return 1;
	}
	return 0;
}

void TStaticStack_estacionar(TStaticStack *P, int placa){
    if(TStaticStack_push(P, placa)==1){
    	puts("Carro estacionado com sucesso!");
    }else{
    	puts("Estacionamento cheio");
    }
}

int main(){
	TStaticStack* P = TStaticStack_create();
	TStaticStack* AUX = TStaticStack_create();
	int temp, op,placa;

	if(P){

		printf("Gostaria  de inserir um carro? s- 1/n - 0 \n");
		scanf("%d",&op);
		while(op!=0){
			printf("Carro: \n");
			scanf("%d", &placa);
			TStaticStack_estacionar(P, placa);
			printf("Gostaria  de inserir um carro? s- 1/n - 0 \n");
			scanf("%d",&op);
		}

		printf("Qual carro vc quer remover? \n");
		scanf("%d", &placa);

        TStaticStack_pop(P, &temp);

		do{
			printf("removemos carro: %d\n", temp);
			TStaticStack_push(AUX, temp);
			TStaticStack_pop(P, &temp);
		}while(temp!=placa);

		TStaticStack_pop(P, &temp);

		while(TStaticStack_pop(AUX, &temp)){
			printf("voltamos o carro: %d pro lugar\n", temp);
			TStaticStack_push(P, temp);
		}

	}

	return 0;
}
