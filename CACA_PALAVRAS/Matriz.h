int obter_Dimensoes(int *linhas, int *colunas){
	FILE *arq;
	//abrindo o arquivo
	arq = fopen("MATRIZ.txt", "r");
	if(arq == NULL){	//testando se o arquivo foi realmente criado
		printf("Erro na abertura do arquivo!");
		return 0;
	}else{
        //Ler primeira linha do arquivo e salvar os numeros nas variaveis
        int l,c;
		fscanf(arq, "%d,%d", &l, &c);
		*linhas = l; *colunas = c;
		//printf("Linhas: %d \nColunas: %d\n", *linhas, *colunas);
	}
	fclose(arq);
	return 1;
}

char** alocar_Matriz(int l, int c){
	char **matriz = (char**)malloc(l*sizeof(char*));
	if (matriz){
		int i;
		for (i = 0; i < l; i++){
			matriz[i] = (char*) malloc(c*sizeof(char));
			if (matriz[i] == NULL){
				return (NULL);
			}
		}
	}
	return (matriz);
}

/*Função pra preencher a matriz*/
int preencher_Matriz(char **matriz, int linhas, int colunas){
    FILE *arq;
    int i,j;
	//abrindo o arquivo
	arq = fopen("MATRIZ.txt", "r");
	if(arq == NULL){	//testando se o arquivo foi realmente criado
		printf("Erro na abertura do arquivo!");
		return 1;
	}else{
		if(matriz == NULL){
			return 0;
		}
		//Se alocou as matrizes com sucesso, salvar matriz from file para matriz
		char info[200];
		int f_size = sizeof(info);
		int i = 0, j, cont=0;
		while ((fgets(info, f_size, arq)) != NULL){
			if(cont!=0){
				if (i < linhas){
					j = 0;
					while (info[j] != '\n' && j < colunas){
						matriz[i][j] = info[j];
						j++;
					}
				}
				i++;
			}
			cont++;
		}
	}
	fclose(arq);
	return 1;
}

void exibir_Matriz(char **matriz, int linhas, int colunas){
    int i,j;
    puts("\n\t\tCACA-PALAVRAS\n");
    for(i=0 ; i < linhas ; i++){
        for(j=0 ; j < colunas ; j++){
       		printf("|%c", matriz[i][j]);
       		if (j==colunas-1){
       			printf("|");
       		}
		}
		puts(" ");
    }
}

int obter_Palavra(char* palavra){
	FILE *arq;
	arq = fopen("palavras.txt", "r");
	if(arq == NULL){	//testando se o arquivo foi realmente criado
		printf("Erro na abertura do arquivo!");
		return 0;
	}else{
		fscanf(arq, "%s", palavra);
	}
	fclose(arq);
	return 1;
}