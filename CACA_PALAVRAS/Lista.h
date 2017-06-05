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
		aux2->sul = TDo_create(matriz[i][0]);
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

int TDList_size (TDList* L){
    TDo* temp = L -> inicio, *temp2 = temp;
    int size = 0;
    while(temp){
        temp = temp->leste;
        if(temp == NULL){
        	temp = temp2->sul;
        	temp2 = temp2->sul;
        }
        size++;
    }
    return size;
}

int procurarPalavras(TDList* L, char* palavra){
	TDo* aux = L->inicio, *aux2 = aux, *aux3;
	int i = 0, j, flag = 0, cont = 1, encontrada = 0;
	while(aux){
		if(aux->info == palavra[i]){
			j = i+1;
			aux3 = aux;
			if(aux3->leste && aux3->leste->info == palavra[j]){
				int x = j;
				while (aux3 && aux3->leste && aux3->leste->info == palavra[x] && palavra[x] != '\n'){
					aux3 = aux3->leste;
					x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					flag = 1;
					encontrada = 1;	break;
				}else{
					//So continuo procurando
					encontrada = 0;
				}	
			}
			aux3 = aux;		
			if(aux3->oeste && aux3->oeste->info == palavra[j]){
				int x = j;
				while (aux3 && aux3->oeste && aux3->oeste->info == palavra[x] && palavra[x] != '\n'){
					aux3 = aux3->oeste;
					x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					flag = 2;
					encontrada = 1;	break;
				}else{
					//So continuo procurando
					encontrada = 0;
				}
			}
			aux3 = aux;
			if(aux3->norte && aux3->norte->info == palavra[j]){
				int x = j;
				while (aux3 && aux3->norte && aux3->norte->info == palavra[x] && palavra[x] != '\n'){
					aux3 = aux3->norte;
					x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					flag = 3;
					encontrada = 1;	break;
				}else{
					//So continuo procurando
					encontrada = 0;
				}
			}
			aux3 = aux;
			if(aux3->sul && aux3->sul->info == palavra[j]){
				int x = j;
				while (aux3 && aux3->sul->info == palavra[x] && palavra[x] != '\n'){
					aux3 = aux3->sul;
					x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					flag = 4;
					encontrada = 1;	break;
				}else{
					//So continuo procurando
					encontrada = 0;
				}
			}aux3 = aux;
			if(aux3->sudeste && aux3->sudeste->info == palavra[j]){
				int x = j;
				while (aux3 && aux3->sudeste && aux3->sudeste->info == palavra[x] && palavra[x] != '\n'){
					aux3 = aux3->sudeste;
					x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					flag = 5;
					encontrada = 1;	break;
				}else{
					//So continuo procurando
					encontrada = 0;
				}
			}aux3 = aux;
			if(aux3->sudoeste && aux3->sudoeste->info == palavra[j]){
				int x = j;
				while (aux3 && aux3->sudoeste && aux3->sudoeste->info == palavra[x] && palavra[x] != '\n'){
					aux3 = aux3->sudoeste;
					x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					flag = 6;					
					encontrada = 1;	break;
				}else{
					//So continuo procurando
					encontrada = 0;
				}
			}aux3 = aux;
			if(aux3->nordeste && aux3->nordeste->info == palavra[j]){
				int x = j;
				while (aux3 && aux3->nordeste && aux3->nordeste->info == palavra[x] && palavra[x] != '\n'){
					aux3 = aux3->nordeste;
					x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					encontrada = 1;
					flag = 7;	
					break;
				}else{
					//So continuo procurando
					encontrada = 0;
				}
			}aux3 = aux;
			if(aux3->noroeste && aux3->noroeste->info == palavra[j]){
				int x = j;
				while (aux3 && aux3->noroeste && aux3->noroeste->info == palavra[x] && palavra[x] != '\n'){
					x++;
					aux3 = aux3->noroeste;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					flag = 8;
					encontrada = 1;	break;
				}else{
					//So continuo procurando
					encontrada = 0;
				}
			}
    	}
		aux = aux->leste;
        if(aux == NULL){
        	aux = aux2->sul;
        	aux2 = aux2->sul;
    	}
	}
	printf("Palavra: %s\n", palavra);
    switch(flag){
    	case 1:
    		printf("Direcao: Leste\nLinha: %d", cont);
    	break;
    	case 2:
    		printf("Direcao: Oeste\nLinha: %d", cont);
    	break;
    	case 3:
    		printf("Norte\nLinha: %d", cont);
    	break;
    	case 4:
    		printf("Sul\nLinha: %d", cont);
    	break;
    	case 5:
    		printf("Suldeste\nLinha: %d", cont);
    	break;
    	case 6:
    		printf("Sudoeste\nLinha: %d", cont);
    	break;
    	case 7:
    		printf("Nordeste\nLinha: %d", cont);
    	break;
    	case 8:
    		printf("Noroeste\nLinha: %d", cont);
    	break;
    	default:
    		printf("Palavra n encontrada\n");
    	break;
    }
    return 1;
}
