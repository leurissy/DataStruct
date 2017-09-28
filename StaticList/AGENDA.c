#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[128], telefone[32];
}Contato;

typedef struct{
    Contato* contatos[100];
    int cont;
    int max;
 }Agenda;

Agenda* agenda_Cria(){

    Agenda* nova = (Agenda*)malloc(sizeof(Agenda));

    if(nova){
        nova -> max = 100;
        nova -> cont = -1; //vazia
        //nova -> contatos = NULL;
    }return(nova);

}

 //retorna 1 se deu certo e 0 se deu errado
int agenda_Inserir(Agenda* A, Contato* C){
    if(A->cont+1 <100){
        A->contatos[A->cont+1] = C;
        A->cont++;
        return(1);
    }return(0);
}

// retorna um contato preenchido ou null se adequado
Contato* contato_Criar_e_Preencher(){

    Contato* novo = (Contato*)malloc(sizeof(Contato));

    if(novo){
        printf("Entre com o nome do contato\n");
        scanf("%s", novo -> nome);
        printf("Entre com o numero e do contato\n");
        scanf("%s", novo -> telefone);
    }return(novo);

}

void agenda_Mostrar(Agenda* A){

    int i=0;
    puts(" ");
    printf("\t AGENDA:");
    for(i=0; i<A->cont; i++){
        puts(" ");
        printf("\tNome: %s \n\tTelefone: %s \n", A->contatos[i]->nome, A->contatos[i]->telefone);
        puts(" ");
    }

}

int menu(){
    int op;
    printf("\n 1 -> Para Inserir\n 2 -> Para Mostrar\n");
    puts(" 0 -> Para Sair ");
    puts(" ");
    puts(" Digite sua opcao: ");
    scanf("%d", &op);
    return op;
}

int main(int argc, char*argv[]){
    Contato* temp;
    Agenda* A = agenda_Cria();
while(1){
    if(A){
        switch(menu()){

            case 1:
                temp = contato_Criar_e_Preencher();
                if(temp){
                    if(agenda_Inserir(A, temp))
                        puts("Contato inserido com sucesso");
                    else
                        puts("Agenda Cheia");
                    }else{
                        puts("Nao pude criar contato");
                    }
            break;

            case 2:
                agenda_Mostrar(A);
            break;

            case 0:
                exit(0);
            break;

            default:
                puts("Opcao invalida");
        }
    }
}

return 0;
}
