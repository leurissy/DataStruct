#include <stdio.h>
#include <stdlib.h>
#define ANTES_DO_INICIO 0
#define APOS_O_FIM 1
typedef struct _no{
	int info;
	struct _no* *prox, *ant;
}TDno;

typedef struct{
	TDno *inicio, *fim;
}TDList;

TDno* TDno_create(int info){
	TDno* novo = (TDno*)malloc(sizeof(TDno));
	if(novo){
		novo->prox = NULL;
		novo->ant = NULL;
		novo->info = info;
	}
	return(novo);
}

TDList* TDList_create(){
	TDList* nova = (TDList*)malloc(sizeof(TDList));
	if(nova){
		nova->inicio = NULL;
		nova->fim = NULL;
	}
	return(nova);
}
//insert do rafael
void TDList_insert2(TDList* L, TDno* no, char policy){
	if(L->inicio == NULL){
		L->inicio = no;
		L->fim = no;
	}else{
		if(policy==ANTES_DO_INICIO){
			no->prox = L->inicio;
			L->inicio->ant = no;
			L->inicio = no;
		}else if(policy==APOS_O_FIM){
			no->ant = L->fim;
			L->fim->prox = no;
			L->fim = no;
		}else{
			TDno* aux = L->inicio;
			while(aux!=NULL){
				if (aux->info > no->info) break;
				aux = aux->prox;
			}
			if(aux==NULL){
				//novo->info é maior que todos os elementos da lista
				no->ant = L->fim;
				L->fim->prox = no;
				L->fim = no;
			}else{
			    if(aux->ant==NULL){
                    TDList_insert(L,no,ANTES_DO_INICIO);
			    }else{
                    no->ant = aux->ant;
                    aux->ant->prox = no;
                    no->prox = aux;
                    aux->ant = no;
			    }
			}
		}
	}
}

int TDList_insert(TDList* L, TDno* no){
	if(L->inicio == NULL){
		L->inicio = no;
		L->fim = no;
	}else{
		no->ant = L->fim;
		L->fim->prox = no;
		L->fim = no;
	}
	return 0;
}

int TDList_remove(TDList* L, int info){
	TDno* tmp;
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
			return 1;
		}
	}
	return 0;
}


int TDList_print(TDList* L){
	TDno* tmp;
	for(tmp=L->inicio; tmp!=NULL; tmp=tmp->prox){
		printf("%d\n", tmp->info);
	}
}

int main(){
	int i;
	TDno *temp;

	TDList* L = TDList_create();
	TDList* L2 = TDList_create();
	if(L){
		for(i=10; i>0; i--){
			temp = TDno_create(i);
			if(temp){
				TDList_insert(L, temp);
			}
			TDList_insert2(L2, TDno_create(i), 1);
		}
	}
	TDList_print(L2);
	TDList_remove(L2, 1);
	puts(" ");
	TDList_print(L2);

	return 0;
}
