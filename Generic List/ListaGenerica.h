typedef struct{
	void* info;
	struct no  *prox;
}TGno;

typedef struct{
	TGno *inicio;
}TGList;

TGList* TGList_insert(){
	TGList* nova = (TGList*)malloc(sizeof(TGList));
	if(nova){
		nova->inicio = NULL;
	}
	return(nova);
}

//insert no fim
int TGList_insert(TGList* L, void* info, unsigned int size){
	TGno* novo = (TGno*)malloc(size(TGno));
	if(!novo){
		return 0;
	}
	//alocar memoria no tamanho(size) da info passada
	novo->info = malloc(size);
	//se novo->info n existir return 0
	if(!(novo->info)){
		return 0;
	}
	//copiar a info pra posição de memoria alocada(novo->info)
	memcpy(novo->info, info, size); //memcpy(local_alocado, info_para copiar, tamanho_info)
	
	novo->prox = NULL;
	novo->ant = NULL;
	if(L->inicio==NULL){
		L->inicio = novo;
	}else{
		novo->prox = L->inicio;
		L->inicio->ant = novo;
		L->inicio = novo;
	}

	return 1;
}

//insert ordenado
int TGList_insereO(TGList** L, void* info, unsigned int size, int (*cmp)(void*, void*)){
	TGno* novo = (TGno*)malloc(sizeof(TGno));
	TGno* aux;
	if(!novo){
		return 0;
	}
	novo->info = malloc(size);
	if(!(novo->info)){
		return 0;
	}
	memcpy(novo->info, info, size);
	novo->prox = NULL;
	novo->ant = NULL;
	if(L->inicio==NULL){
		L->inicio = novo;
	}else{
		aux = L->inicio;
	    while(aux->prox && cmp(aux->info, info) < 0){
	      aux =  aux->prox;
	    }
	    if(cmp(aux->info, info) < 0){
	      //inserir após pois minha info é menor que a info que desejo inserir
	      aux->prox = novo;
	      novo->ant = aux;
	    }else{
	      //inserir antes
	      novo->prox = aux;
	      novo->ant = aux->ant;

	      if(aux->ant){
	      	aux->ant->prox = novo;
	      }
	      aux->ant = novo;

	      if(aux == L->inicio){
	        L->inicio = novo;
	      }
		}
	}
	return 1;
}

void GDList_print(GDList* L, void (*print)(void*)){
  TNo* aux = L->inicio;
  putchar('\n');
  while(aux){
    print(aux->info);
    aux = aux->prox;
  }
  putchar('\n');

}