typedef struct no{
	char info;
	struct no *oeste, *leste, *norte, *sul, *noroeste, *nordeste, *sudoeste, *sudeste;
}TDo;

typedef struct{
	TDo *inicio, *fim;
}TDList;

TDList* TDList_create(){
    TDList* nova = (TDList*) malloc (sizeof(TDList));

    if (nova){
        nova->inicio = NULL;
        nova->fim = NULL;
    }
    return nova;
}

TDo* TDo_create(char info){

    TDo* novo = (TDo*) malloc (sizeof(TDo));

    if (novo){
    	int i,j;
    	novo->leste = NULL;
    	novo->oeste = NULL;
        novo->norte = NULL;
        novo->sul = NULL;
        novo->sudeste = NULL;
        novo->sudoeste = NULL;
        novo->nordeste = NULL;
        novo->noroeste = NULL;   
        novo->info = info;
    }
    return novo;
}

int TDList_insert(TDList* L, TDo* no){
    if(L->inicio == NULL){
		L->inicio = no;
		L->fim = no;
	}else{
        no->oeste = L->fim;
		L->fim->leste = no;
		L->fim = no;
    }
    return 0;
}

int Matriz_insertList(TDList* L, char **matriz, int linhas, int colunas){
	if(L == NULL){
		return 0;
	}

	int i=0 , j=0;
	TDo* aux, *aux2;

	aux = TDo_create(matriz[i][j]);
	TDList_insert(L, aux);
	aux2 = aux;

	for(j=1; j<colunas; j++){
		aux->leste = TDo_create(matriz[i][j]);
		if(!aux->leste){
			return 0;
		} 
		aux->leste->oeste = aux;
		aux = aux->leste;
	}
	j=0;

	for(i=1; i<linhas; i++){
		aux2->sul = TDo_create(matriz[i][j]);	
		if(!aux2->sul){
			return 0;
		}
		aux = aux2->sul;
		aux->norte = aux2;

		for(j=1; j<colunas; j++){
			aux->leste = TDo_create(matriz[i][j]);
			if(!aux->leste){
				return 0;
			}
			aux->leste->oeste = aux;
			aux->norte->sudeste = aux->leste;
			aux->leste->noroeste = aux->norte;
			aux->norte->leste->sudoeste = aux;
			aux->nordeste = aux->norte->leste;
			aux->norte->leste->sul = aux->leste;
			aux->leste->norte = aux->norte->leste;
			aux = aux->leste;
		}
		aux2 = aux2->sul;
	}
	return 1;
}

void TDList_print (TDList* L){
    TDo* temp = L -> inicio, *temp2 = temp;

    while(temp){
        printf("|%c", temp -> info);
        temp = temp->leste;
        if(temp == NULL){
        	printf("|");
        	puts(" ");
        	temp = temp2->sul;
        	temp2 = temp2->sul;
        }
    }
}

int procurarPalavras(TDList* C, char* palavra){

}