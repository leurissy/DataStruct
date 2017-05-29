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
		nova->in = 0;
		nova->out = -1;
	}
	return(nova);
}

int SQueue_insert(SQueue* F, int dado){
	if((F->in + 1)%N != F->out){
		F->DADOS[F->in] = dado;
		F->in++;
		return 1;
	}else{
        printf("Queue overflow\n");
        return 0;
	}
}

int SQueue_remove(SQueue* F, int dado){
	if((F->out + 1) % N <= F->in){

	}
}

void SQueue_print(SQueue* F){
	int i;
	for(i=0; i<N; i++){
		printf("%d\n", F->DADOS[i]);
	}
}

int main(){
    int  i;
	SQueue* F = SQueue_create();

	if(F){
		for(i=0; i<13; i++){
			SQueue_insert(F, i);
		}
	}

	SQueue_print(F);

	return 0;
}
