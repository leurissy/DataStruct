typedef struct{
	int dados[10];
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
		P->dados[P->head+1] = d;
		P->head = P->head+1;
		return 1;
	}
	return 0;
}

int TStaticStack_pop(TStaticStack *P, int *d){
	if(P->head >=0){
		*d = P->dados[P->head--];
		return 1;
	}
	return 0;
}

int main(){
	TStaticStack* S = TStaticStack_create();
	int temp;

	if(S){
		do{
			temp = rand()%100;
			printf("Tentando push (%d)\n", temp);
		}while(TStaticStack_push(S, temp));

		while(TStaticStack_pop(S, &temp)){
			printf("%d\n", temp);
		}
	}

	return 0;
}
