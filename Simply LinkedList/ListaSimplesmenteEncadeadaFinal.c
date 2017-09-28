#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int info;
	struct no *prox;
}Tno;

typedef struct{
	Tno *inicio;
}TLinkedList;

TLinkedList* TLinkedList_create(){
	TLinkedList* nova = (TLinkedList*)malloc(sizeof(TLinkedList));
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
	}
	return(novo);
}
//inserir no Final
void TLinkedList_insert(TLinkedList* L, Tno* no){
	if(L->inicio==NULL){
        L->inicio = no;
    }else{
        Tno* tmp = L->inicio;
        while(tmp->prox!=NULL){
            tmp=tmp->prox;
        }
        tmp->prox = no;
    }
}

void TLinkedList_remove(TLinkedList* L, int info){
    /*TDno* tmp;
	for(tmp=L->inicio; tmp!=NULL; tmp=tmp->prox){
		if(tmp->info == info){
			if(tmp == L->inicio){
				L->inicio = L->inicio->prox;
			}
			if(tmp == L->fim){
				L->fim = L->fim->ant;
			}
			TDno* aux = tmp->ant;
			aux->prox = tmp->prox;
			aux = tmp->prox;
			aux->ant = tmp->ant;
			free(tmp);
			
		}
	}*/
}

/*
//Menos memoria porem estoura o processador
//função recursiva
void TLinkedList_print(TLinkedList* L){
	Tno* temp = L-> inicio;
	for(; temp != NULL; temp=temp->prox){
		printf("info = %d\n", temp->info);
	}
}
*/
/* "Mais" memoria porem menos gasto pra processamento */
void TLinkedList_print(TLinkedList* L){
	Tno* tmp;
	for(tmp=L->inicio; tmp!=NULL; tmp=tmp->prox){
		printf("%d\n", tmp->info);
	}
}
int main(){
	int i;
	Tno *temp;

	TLinkedList* L = TLinkedList_create();
	TLinkedList* L2 = TLinkedList_create();
	if(L){
		for(i=2; i<10; i++){
			temp = Tno_create(i);
			if(temp){
				TLinkedList_insert(L, temp);
			}
			TLinkedList_insert(L2, Tno_create(10-i));
		}
	}
	TLinkedList_print(L);
	puts(" ");
	TLinkedList_print(L2);
	return 0;
}
