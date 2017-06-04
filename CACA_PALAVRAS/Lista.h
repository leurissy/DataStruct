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
	TDo* aux = L->inicio, *aux2 = aux;
	int i = 0, j, flag = 0, cont = 1, size = TDList_size(L), sizeP = strlen(palavra), encontrada = 0;
	while(aux){
		printf("aux: %c\n", aux->info);
		if(aux->info == palavra[i]){
			j = i+1;
			if(aux->leste->info == palavra[j]){
				int x = j;
				while (aux->leste->info == palavra[x] && palavra[x] != '\n'){
					aux = aux->leste;
					x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					encontrada = 1;	
				}else{
					//So continuo procurando
					encontrada = 0;
				}
				flag = 1;
			}
			if(aux->oeste->info == palavra[j]){
				int x = j;
				while (aux->oeste->info == palavra[x] && palavra[x] != '\n'){
					aux = aux->oeste;
					x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					encontrada = 1;	
				}else{
					//So continuo procurando
					encontrada = 0;
				}
				flag = 2;
			}
			if(aux->norte->info == palavra[j]){
				int x = j;
				while (aux->norte->info == palavra[x] && palavra[x] != '\n'){
					aux = aux->norte;x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					encontrada = 1;	
				}else{
					//So continuo procurando
					encontrada = 0;
				}
				flag = 3;
			}
			if(aux->sul->info == palavra[j]){
				int x = j;
				while (aux->sul->info == palavra[x] && palavra[x] != '\n'){
					aux = aux->sul;x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					encontrada = 1;	
				}else{
					//So continuo procurando
					encontrada = 0;
				}flag = 4;
			}
			if(aux->sudeste->info == palavra[j]){
				int x = j;
				while (aux->sudeste->info == palavra[x] && palavra[x] != '\n'){
					aux = aux->sudeste;x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					encontrada = 1;	
				}else{
					//So continuo procurando
					encontrada = 0;
				}
				flag = 5;
			}
			if(aux->sudoeste->info == palavra[j]){
				int x = j;
				while (aux->sudoeste->info == palavra[x] && palavra[x] != '\n'){
					aux = aux->sudoeste;x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					encontrada = 1;	
				}else{
					//So continuo procurando
					encontrada = 0;
				}
				flag = 6;
			}
			if(aux->nordeste->info == palavra[j]){
				int x = j;
				while (aux->nordeste->info == palavra[x] && palavra[x] != '\n'){
					aux = aux->nordeste;x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					encontrada = 1;	
				}else{
					//So continuo procurando
					encontrada = 0;
				}
				flag = 7;
			}
			if(aux->noroeste->info == palavra[j]){
				int x = j;
				while (aux->noroeste->info == palavra[x] && palavra[x] != '\n'){
					aux = aux->noroeste;x++;
				}
				if(palavra[x] == '\n'){
					//Encontrei palavra
					encontrada = 1;	
				}else{
					//So continuo procurando
					encontrada = 0;
				}
				flag = 8;
			}
    	}else{
			aux = aux->leste;
	        if(aux == NULL){
	        	aux = aux2->sul;
	        	aux2 = aux2->sul;
	        	cont++;
        	}
		}
		if(encontrada == 1){
			break;
		}
	}
	printf("Palavra: %s\n", palavra);
    switch(flag){
    	case 1:
    		printf("Leste\n");
    	break;
    	case 2:
    		printf("Oeste\n");
    	break;
    	case 3:
    		printf("Norte\n");
    	break;
    	case 4:
    		printf("Sul\n");
    	break;
    	case 5:
    		printf("Suldeste\n");
    	break;
    	case 6:
    		printf("Sudoeste\n");
    	break;
    	case 7:
    		printf("Nordeste\n");
    	break;
    	case 8:
    		printf("Noroeste\n");
    	break;
    	default:
    		printf("Palavra n encontrada, linha:%d\n", cont);
    	break;
    }
    return 1;
}
