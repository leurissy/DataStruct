#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "node.h"

	int main(int argc, char* argv[]){

		if (argc > 1){
			TList* L = TList_create();
			FILE* f = fopen(argv[1], "r");

			if(L){
				char palavras[100];
				while ((fgets(palavras, sizeof(palavras), f)) != NULL){
					insert_word_tlist (L, palavras);
					TList_printr (L -> head);
					TList_remove_all(L);
				}
			}	
		}
		//Criar uma lista, TNos e imprimir
		

		return 0;
}