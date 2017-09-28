#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	typedef struct{
		int info;
	}TData;

	typedef struct{
		TData* data[10];
		int count, MAX;
	}TStaticList;

	TStaticList* TStaticList_create (){

		TStaticList* novo = (TStaticList*)malloc(sizeof(TStaticList));

		if (novo){
			novo -> count = 0;
			novo -> MAX = 10;
		}
		return novo;
	}

	TData* TData_create (){
		TData* novo = (TData*)malloc(sizeof(TData));

		if (novo){
			novo -> info = 0;
		}
		return novo;
	}

	void Fill_TData (TData* d){
		scanf("%d",&(d->info));
	}

	int TStaticList_insert (TStaticList* L, TData* d){

		if (L -> count + 1 <= L-> MAX){
			Fill_TData (d);
			L -> data[L->count++] = d;
			return 1;
		}
		return 0;
	}

	void imprimirTData (TData* d){
		printf("%d ", d-> info);
	}

	void imprimirLista(TStaticList* L, void(*Imprimir)(TData*)){

		int i;
		for (i = 0; i < L -> count; i++){
			imprimirTData (L -> data[i]);
		}
	}

	void ordenar (TStaticList* L){
		int i, j;
		TData* aux;
		int qty = L -> count;

		for (i = 0; i < qty; i++){
			for (j = i+1; j < qty; j++){
				if (L -> data[j] -> info < L -> data[i] -> info){
					aux = L -> data[j];
					L -> data[j] = L -> data[i];
					L -> data[i] = aux;
				}
			}
		}
	}

		int main(){

			//criando lista
			TStaticList* lista = TStaticList_create();

			int i;
			printf("\nDIGITE 10 VALORES ASHUAHUAHUAHAU AMANHA TEM PROVA\n");

			for (i = 0; i < 10; i++)
				TStaticList_insert (lista, TData_create());
	
			puts("");
			imprimirLista (lista, imprimirTData);

			ordenar (lista);
			puts("");

			imprimirLista (lista, imprimirTData);

		}