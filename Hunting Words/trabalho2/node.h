#ifndef NODE_H
#define NODE_H

typedef struct _node{
	char info;
	struct _node *pointer[8];
}Node;

typedef struct{
	Node* head;
}List;

typedef struct _no{
	char info;
	struct _no *prox;
}TNo;

typedef struct{
	TNo* head;
}TList;

/*Funçoes Lists e Nodes com oito ponteiros*/
Node* create_node (char );
List* create_list ();
void insert_list (List* , Node* );
void print_list (List* );

/*Funçoes Lists e nodes simplesmente encadeada*/
TNo* TNo_create (char );
TList* TList_create ();
void TList_insert (TList* , TNo* );
void TList_printr (TNo* );
void TList_remove_all (TList*);

int insert_word_tlist (TList* , char* );

#endif