#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct{
    int in, out;
    int DADOS[N];
}SQueue;

SQueue* SQueue_create(){
	SQueue* nova = (SQueue*)malloc(sizeof(SQueue));
	if(nova){
		nova->in = -1;
		nova->out = -1;
	}
	return(nova);
}

int SQueue_insert(SQueue* F, int dado){

	if((F->in + 1)%N != F->out){
		F->DADOS[(F->in+1)%N] = dado;
		F->in = (F->in +1)%N;
		F->out = (F->out ==-1)? 0: F->out;
		return 1;
	}else{
        printf("Queue overflow\n");
        return 0;
	}
}

void SQueue_remove(SQueue* F, int *dado){
	if (F->out >=0){
		*dado = F->DADOS[F->out];
		F->out = (F->out+1) % N;
		if(F->out >F->in){
			F->in = -1;
			F->out = -1;
		}
	}else
		puts("Fila vazia");
}

void SQueue_print(SQueue* F){
	int i;
	for(i=F->out; i!=F->in; i = (i+1)%N)
    {
		printf("%d\n", F->DADOS[i]);
	}
}

int main(){
    int  i;
	SQueue* F = SQueue_create();

	if(F){
		for(i=0; i<N; i++){
			SQueue_insert(F, i);
		}
	}

	SQueue_print(F);

	SQueue_remove(F, &i);
	puts("\n");
	SQueue_print(F);

	return 0;
}
