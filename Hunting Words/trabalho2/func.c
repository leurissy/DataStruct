#include <stdio.h>
#include <stdlib.h>
#include "node.h"

TNo* TNo_create (char info){
		TNo* node = (TNo*) malloc (sizeof(TNo*));

		if(node){
			node -> info = info;
			node -> prox = NULL;
		}
		return (node);
	}

	TList* TList_create (){
		TList* list = (TList*) malloc (sizeof(TList));

		if(list){
			list -> head = NULL;
		}
		return (list);
	}

	void TList_insert (TList* L, TNo* N){
		if(L -> head == NULL)
			L -> head = N;
		else{
			TNo* temp = L -> head;
			while (temp -> prox != NULL)
				temp = temp -> prox;
			temp -> prox = N;
		}
	}

	void TList_printr (TNo* N){
		if(N){
			printf("%c",N -> info);
			TList_printr(N -> prox);
		}
	}

	void TList_remove_all (TList* L){
		if(L -> head == NULL)
			puts("Lista vazia");
		else{
			TNo* aux = L -> head;
			
			while (aux){
				L -> head = L -> head -> prox;
				free(aux);
				aux = L -> head;
			}
			aux = NULL;
		}
	}

	int insert_word_tlist (TList* L, char* p){
		if (p == NULL)
			return 0;
		int i = 0;
		TNo* temp;
		while (p[i] != '\0' && p[i] != '\n'){
			temp = TNo_create(p[i]);
			if(temp == NULL)
				return 0;
			TList_insert (L, temp);
			i++;
		}
		return 1;
	}