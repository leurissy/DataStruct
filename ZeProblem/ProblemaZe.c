#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
	int info;
	struct no *prox, *ant;
	//struct no *ant;
}Tno;

typedef struct{
	Tno *inicio;
}TCircleList;

TCircleList* TCircleList_create(){
	TCircleList* nova = (TCircleList*)malloc(sizeof(TCircleList));
	if(nova){
		nova->inicio = NULL;
	}
	return(nova);
}

//Cria o TNO* e preenche com info

Tno* Tno_create(int info){
	Tno* novo = (Tno*) malloc(sizeof(Tno));
	if(novo){
		novo->info = info;
		novo->prox = NULL;
		novo->ant = NULL;
	}
	return(novo);
}

void TCircleList_insert(TCircleList* L, Tno* no){
	if(L->inicio==NULL){
        L->inicio = no;
        no->prox = L->inicio;
        no->ant = L->inicio;
    }else{
        no->ant = L->inicio->ant;
        no->ant->prox = no;
        no->prox = L->inicio;
        L->inicio->ant = no;
    }
}

int TCircleList_remove(TCircleList* L, int info){
    if(!L){
    	return 0;
    }
    Tno* tmp=L->inicio, *tmp2;
    if(!tmp){
    	return 0;
    }

	if(tmp->info == info){
		if (tmp->prox == L->inicio){
			L->inicio = NULL;
		}
		else{
            L->inicio->ant->prox = L->inicio->prox;
			L->inicio->prox->ant = L->inicio->ant;
		}
	}else{
		while(tmp->info!=info && tmp!=L->inicio){
			tmp = tmp->prox;
		}
		if (tmp==L->inicio){
			return 0;
		}
		tmp->ant->prox = tmp->prox;
		tmp->prox->ant = tmp->ant;
	}

	free(tmp);
	tmp = NULL;
	return 1;
}

void TCircleList_print(TCircleList* L){
	Tno* tmp;
	for(tmp=L->inicio; tmp->prox!=L->inicio; tmp=tmp->prox){
		printf("%d\n", tmp->info);
	}
	printf("%d\n", tmp->info);
}

int TCircleList_size(TCircleList* L){
	int cont = 0;
	Tno* tmp = L->inicio;
	while(tmp->prox!=L->inicio){
		tmp = tmp->prox;
		cont++;
	}
	printf("size: %d \n", cont);
	return cont;
}

Tno* remove_Ze(TCircleList* L, int n){
	int i, sentido = 0;
	Tno* tmp = L->inicio; Tno* tmp2;
	while(tmp->prox != tmp){
		if (sentido == 0){
			for (i = 0; i < n; i++ ){
				tmp = tmp -> prox;
			}
			sentido = 1;
		}else{
			for (i = 0; i < n; i++){
				tmp = tmp -> ant;
			}
			sentido = 0;
		}
		tmp -> prox -> ant = tmp -> ant;
		tmp -> ant -> prox = tmp -> prox;
		tmp2 = tmp;
		tmp = (sentido) ? tmp -> ant : tmp -> prox;
		free(tmp2);
	}
	return tmp;
}

int main(){
	int i;
	Tno *temp;

	TCircleList* L = TCircleList_create();
	if(L){
		for(i=0; i<12; i++){
			temp = Tno_create(i);
			if(temp){
				TCircleList_insert(L, temp);
			}
		}
	}
	TCircleList_print(L);
	puts(" ");
	remove_Ze(L,2);
	TCircleList_print(L);
	puts(" ");
	return 0;
}
