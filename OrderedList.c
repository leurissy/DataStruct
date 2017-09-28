typedef struct {
    tno *inicio;
    tno *fim, *ultimo_inserido;
    int any_nos;
    float media_it;
}TLista;


strcut _no{
    void *info;
    struct _no *prox, *ant;//se a lista
    struct _no *skip;
}Tno;

typedef struct{
    Tno* inicio;
    Tno* fim;
}TList;


void setSkip(TList* L, int n){
    int passo;
    Tno* skipado, skipador;

    skipado = L-> inicio;
    skipador = L->inicio;

    while(skipado){
        for (passo= 0; passo<n-1&&skipado; passo++){
            skipado->skip = (passo==0)?skipado->skip:NULL;
            skipado = skipado->prox;
        }
        if(skipado){
            skipador->skip = skipado;
            skipador = skipado;    
        }
    }

}

Tno* buca_com_Skip(TList *L, void *info, void (*cmp)(void*, void*)){
    Tno* aux = L->inicio;
    int cValue;
    while(aux){
        cValue = cmp(info, aux->info);
        if(cValue==0){//são iguais
            return(aux);
        }else{
            if(cValue<0){//info < aux->info (n esta na lista)
                return(NULL);
            }else{//info > aux->info
                if(aux->skip){//tem skip?
                    if(cmp(info, aux->skip->info)>=0){//info>=skip
                        aux = aux->skip;
                        continue;
                    }//esta entre o aux e o ski
                }
                aux = aux->prox;
            }
        }
    }
    return(NULL);
}
