#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int telefone;
    struct no *prox;
}Contato;

typedef struct{
    Contato *inicio;
}TAgendaList;

TAgendaList* TAgendaList_create(){
    TAgendaList* nova = (TAgendaList*)malloc(sizeof(TAgendaList));
    if(nova){
        nova->inicio = NULL;
    }
    return(nova);
}

Contato* Contato_create(int telefone){
    Contato* novo = (Contato*)malloc(sizeof(Contato));
    if(novo){
        novo->telefone = telefone;
        novo->prox = NULL;
    }
    return(novo);
}

void TAgendaList_insert(TAgendaList* A, Contato* C){
    if(A->inicio==NULL){
        A->inicio = C;
    }else{
        Contato* tmp = A->inicio;
        while(tmp->prox!=NULL){
            tmp=tmp->prox;
        }
        tmp->prox = C;
    }
}

void TAgendaList_print(TAgendaList* A){
    Contato* tmp;
    for(tmp=A->inicio; tmp!=NULL; tmp=tmp->prox){
        printf("%d\n", tmp->telefone);
    }
}

int main(){
	int i, op = 0;
	Contato *temp;
    TAgendaList* A = TAgendaList_create();

    if(A){
		for(i=2; i<10; i++){
			temp = Contato_create(i);
			if(temp){
				TAgendaList_insert(A, temp);
			}
		}
	}
	TAgendaList_print(A);
	puts(" ");

    /*while(op!=4){
        printf("Escolha uma opcao: \n");
        printf("1 - Criar Agenda\n");
        printf("2 - Adicionar Contato\n");
        printf("3 - Mostrar Contatos\n");
        printf("4 - Sair\n");
        scanf("%d", op);
        switch(op){
            case 1:
                printf("Lista criada com sucesso\n");
            break;
            case 2:
                scanf("%d", number);
                temp = Contato_create(number);
                if(temp){
                    TAgendaList_insert(A, temp);
                    printf("Contato criado com sucesso\n");
			    }
            break;
            case 3:
                TAgendaList_print(A);
            break;
            case 4:
                exit(0);
            break;
            default:
                printf("Opcao invalida\n");
        }
    }*/

	return 0;
}
