typedef struct{
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
        novo->info = info;
        /*if(linha==0){//Linha 0
        	if(coluna==0){//L 0 e C 0
        		novo->leste = matriz[linha][coluna+1];
        		novo->sul = matriz[linha+1][coluna];
        		novo->sudeste = matriz[linha+1][coluna+1];
        		novo->oeste = NULL;
	            novo->norte = NULL;
	            novo->sudoeste = NULL;
	            novo->nordeste = NULL;
	            novo->noroeste = NULL;            			
        	}else{//Linha e Coluna !=0 
        		if(coluna==colunas-1){//Linha 0 e Coluna -1
        			novo->leste = NULL;
		    		novo->sul = matriz[linha+1][coluna];
		    		novo->sudeste = NULL;
		    		novo->oeste = matriz[linha][coluna-1];
		            novo->norte = NULL;
		            novo->sudoeste = matriz[linha+1][coluna-1];
		            novo->nordeste = NULL;
		            novo->noroeste = NULL;
        		}else{//Linha 0 e Coluna !=0 && -1
        			novo->leste = matriz[linha][coluna+1];
		    		novo->sul = matriz[linha+1][coluna];
		    		novo->sudeste = matriz[linha+1][coluna+1];
		    		novo->oeste = matriz[linha][coluna-1];
		            novo->norte = NULL;
		            novo->sudoeste = matriz[linha+1][coluna-1];
		            novo->nordeste = NULL;
		            novo->noroeste = NULL;
        		}
        	}
        }else{//Linha !=0
        	if(coluna==0){//Linha !=0 e Coluna 0
        		if(linha==linhas-1){//Linha -1 e Coluna 0
        			novo->leste = matriz[linha][coluna+1];
		    		novo->sul = NULL;
		    		novo->sudeste = NULL;
		    		novo->oeste = NULL;
		            novo->norte = matriz[linha-1][coluna];
		            novo->sudoeste = NULL;
		            novo->nordeste = matriz[linha-1][coluna+1];
		            novo->noroeste = NULL;
    			}else{//Linha !=0 && -1 e Coluna 0
    				novo->leste = matriz[linha][coluna+1];
            		novo->sul = matriz[linha+1][coluna];
            		novo->sudeste = matriz[linha+1][coluna+1];
            		novo->oeste = NULL;
		            novo->norte = matriz[linha-1][coluna];
		            novo->sudoeste = NULL;
		            novo->nordeste = matriz[linha-1][coluna+1];
		            novo->noroeste = NULL;
        		}            			
        	}else{//Linha !=0 e Coluna !=0
        		if(coluna==colunas-1){//Linha !=0 e Coluna -1
        			if(linha==linhas-1){//Linha !=0 && ==-1 e Coluna -1
            			novo->leste = NULL;
			    		novo->sul = matriz[linha+1][coluna];
			    		novo->sudeste = NULL;
			    		novo->oeste = matriz[linha][coluna-1];
			            novo->norte = NULL;
			            novo->sudoeste = matriz[linha+1][coluna-1];
			            novo->nordeste = NULL;
			            novo->noroeste = NULL;
        			}else{//Linha !=0 e Coluna -1
        				novo->leste = NULL;
			    		novo->sul = matriz[linha+1][coluna];
			    		novo->sudeste = NULL;
			    		novo->oeste = matriz[linha][coluna-1];
			            novo->norte = matriz[linha-1][coluna];
			            novo->sudoeste = matriz[linha+1][coluna-1];
			            novo->nordeste = NULL;
			            novo->noroeste = matriz[linha-1][coluna-1];
            		}
        		}else{//Linha !=0 e Coluna !=0 && -1
        			if(linha==linhas-1){//Linha !=0 && ==-1 e Coluna !=0 && -1
            			novo->leste = matriz[linha][coluna+1];
			    		novo->sul = NULL;
			    		novo->sudeste = NULL;
			    		novo->oeste = matriz[linha][coluna-1];
			            novo->norte = matriz[linha-1][coluna];
			            novo->sudoeste = NULL;
			            novo->nordeste = matriz[linha-1][coluna+1];
			            novo->noroeste = matriz[linha-1][coluna-1];
        			}else{//Linha !=0 && -1 e Coluna !=0 && -1
        				novo->leste = matriz[linha][coluna+1];
			    		novo->sul = matriz[linha+1][coluna];
			    		novo->sudeste = matriz[linha+1][coluna+1];
			    		novo->oeste = matriz[linha][coluna-1];
			            novo->norte = matriz[linha-1][coluna];
			            novo->sudoeste = matriz[linha+1][coluna-1];
			            novo->nordeste = matriz[linha-1][coluna+1];
			            novo->noroeste = matriz[linha-1][coluna-1];
        			}
        			
        		}
        	}
        }*/
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
	int i , j;
	for (i = 0; i < 1; ++i){
		for (j = 0; j < colunas; ++j){
			TDList_insert(L, TDo_create(matriz[i][j]));
		}
	}
	return 0;
}

void TDList_print (TDList* L){
    TDo* temp = L -> inicio;

    while (temp){
        printf("%c ", temp -> info);
        temp = temp -> leste;
    }
}