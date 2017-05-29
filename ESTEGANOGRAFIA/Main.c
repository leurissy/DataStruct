#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	char number;
	struct no* next;
}No;

typedef struct{
	No* head;
}TLinkedList;

//criar lista

TLinkedList* TLinkedList_create(){
	TLinkedList* nova = (TLinkedList*)malloc(sizeof(TLinkedList));
	if(nova){
		nova->head = NULL;
	}
	return(nova);
}

//criar No
No* No_create(char number){
	No* novo = (No*)malloc(sizeof(No));

	if(novo){
		novo->number = number;
		novo->next = NULL;
	}
	return(novo);
}

//inserir dado no final da lista
void TLinkedList_insert(TLinkedList* L, No* no){
	if(L->head==NULL){
		L->head = no;
	}else{

		No* tmp = L->head;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next = no;
	}
}

void TLinkedList_print(TLinkedList* L){
	No* tmp;
	for(tmp=L->head; tmp!=NULL; tmp=tmp->next){
		printf("%c", tmp->number);
	}
}

int TLinkedList_size(TLinkedList* L){
	if(L->head == NULL){
		printf("EMPTY LIST\n");
		return 0;
	}else{
		int cont=0;
		No* aux = L->head;

		while(aux!=NULL){
			aux = aux->next;
			cont++;
		}
		return cont;
	}
}

void Convert_Mask(int mask, int *maskI, int *maskF){
    *maskF = 3 - mask;
    *maskI = 252 - mask;
}

TLinkedList* StringForList(char *msg){
    int i;
    TLinkedList* L = TLinkedList_create();

    for(i=0; i<strlen(msg); i++){
        TLinkedList_insert(L, No_create(msg[i]));
    }

    return(L);
}

TLinkedList* StringForListIn(char *msg){
    int i;
    TLinkedList* L = TLinkedList_create();

    for(i=(strlen(msg)-2); i>=0; i--){
        TLinkedList_insert(L, No_create(msg[i]));
    }

    return(L);
}

void Esteganografia(TLinkedList* L1, TLinkedList* L2, TLinkedList* L, int maskI, int maskF, int mask){
	int i,j;
	char result, host;
	FILE *arq_cod;
	//abrindo o arquivo
	arq_cod = fopen("msg.txt", "w");
	if(arq_cod == NULL){	//testando se o arquivo foi realmente criado
		printf("Erro na abertura do arquivo!");
		return 1;
	}


	No* temp1 = L1->head;
    No* temp2 = L2->head;

	for (i = 0; i<TLinkedList_size(L1); ++i){
		for (j = 0; j < 4; ++j){
			host = temp1->number & (maskF + mask);
			temp2->number = temp2->number & (maskI + mask);
			result = host | temp2->number;

			TLinkedList_insert(L, No_create(result));
			fprintf(arq_cod,"%c",result);
			temp1->number = (temp1->number>>2);
            temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}

	fclose(arq_cod);
}
/*
void Desteganografia(TLinkedList* L1){
	int i,j;
	char *MSG, host;

	MSG = (char*)malloc(80*sizeof(char));

	FILE  *arq_msg;
	//abrindo o arquivo com tipo de abertura r
	arq_msg = fopen("msg.txt", "r");
    if(arq_msg == NULL){	//testando se o arquivo foi realmente criado
		printf("Erro na abertura do arquivo!");
		return 1;
	}else{
	    i=0;
	    while((fscanf(arq_msg,"%c",&MSG[i]))!=EOF) i++;
	}

	TLinkedList* D = StringForListIn(MSG);
	No* temp = D->head;


	for (i = 0; i <(TLinkedList_size(D)-1); i++){
		for (j = 0; j <4; j++){
            temp->number = temp->number &3;
			host = temp->number &252;
			temp->number = temp->number | host;
            if(j>3){
                temp->number = (temp->number<<2);
            }
		}
		temp = temp->next;
	}
	printf("\nMSG Decodificada: \n");
    TLinkedList_print(D);
}
*/
int main(){

    int mask, maskI, maskF;
	char *msg1, *msg2, *res;

	msg1 = (char*)malloc(100*sizeof(char));
	msg2 = (char*)malloc(100*sizeof(char));
	res = (char*)malloc(100*sizeof(char));

	printf("Entre com a mensagem1: \n");
	scanf("%s",msg1);
    fflush(stdin);

	do{
		printf("Entre com a mensagem2:\n");
		scanf("%s",msg2);
	}while(strlen(msg2)<(strlen(msg1)*4));

    printf("Entre com a mascara: \n");
	scanf("%d",&mask);

	puts(" ");
	printf("Mensagem a ser escondida: %s\n", msg1);
	printf("Mensagem onde sera escondida: %s\n", msg2);
	printf("Mascara: %d\n", mask);
    puts(" ");
	TLinkedList* L = TLinkedList_create();
	TLinkedList* L1 = StringForList(msg1);
	TLinkedList* L2 = StringForList(msg2);

    Convert_Mask(mask, &maskI, &maskF);
	Esteganografia(L1, L2, L, maskI, maskF, mask);
    printf("Mensagem Codificada: \n");
	TLinkedList_print(L);

	return 0;
}
