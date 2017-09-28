#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char info;
    struct no*prox;
}Tno;

typedef struct
{
    Tno*inicio;
}Link;

Link*Link_create()
{
    Link* nova = (Link*)malloc(sizeof(Link));
    if(nova)
    {
        nova->inicio=NULL;
    }
    return (nova);
}

Tno*Tno_create(char entrada)
{
    Tno*novo = (Tno*)malloc(sizeof(Tno));
    if(novo)
    {
        novo->info=entrada;
        novo->prox=NULL;
    }
    return (novo);
}

void Link_insert(Link*L,Tno*no)
{
    no->prox=L->inicio;
    L->inicio=no;
}

void Link_insert_end(Link*L,Tno*no)
{
    if(L->inicio==NULL)
    {
        L->inicio=no;
    }
    else
    {
        Tno*temp=L->inicio;
        while(temp->prox!=NULL)
        {
            temp=temp->prox;
        }
        temp->prox=no;
    }
}

void Link_print(Link*L)
{

    Tno*temp=L->inicio;
    while(temp!=NULL)
    {
        printf("%c",temp->info);
        temp=temp->prox;

    }
    printf("\n");
}
int tamanho_lista(Link*L)
{
    int k=0;
    Tno*temp=L->inicio;
    while(temp!=NULL)
    {
        k++;
        temp=temp->prox;
    }
    return k;
}
void estenografia(Link*L,Link*L2,Link*L3)
{
    char host,resu;
    char url[]="resultado.txt";
    FILE*arq;
    arq=fopen(url,"w");
    int i,j;
    Tno*temp=L->inicio;
    Tno*temp2=L2->inicio;
    Tno*temp3;
    for(i=0;i<tamanho_lista(L);i++)
    {
        for(j=0;j<4;j++)
        {
            host=temp->info & 3;
            temp2->info=temp2->info & 252;
            resu= host | temp2->info;
            temp->info=(temp->info>>2);
            temp2=temp2->prox;
            temp3=Tno_create(resu);
            Link_insert_end(L3,temp3);
            fputc(resu,arq);
        }
        temp=temp->prox;
    }
    fclose(arq);
}
void decode()
{
    char MSG1[80],host;
    int i,j;
    FILE*a=fopen("entrada.txt","r");
    FILE*b=fopen("resultado.txt","r");
    char MSG2[80];
    fgets(MSG1,80,a);
    fgets(MSG2,80,b);
    for(i=(strlen(MSG1)-1);i>=0;i--)
    {
        for(j=4;j>=0;j--)
            {
            host=MSG2[j+(i*4)]&3;
            MSG1[i]=MSG1[i]|host;
            if(j>0)
            {
                 MSG1[i]=MSG1[i]<<2;
            }
        }
    }
    printf("%s\n",MSG1);
}
void op1()
{
    int i,k,x;
    char j[20],o[80];
    char url[]="entrada.txt";
    char est[]="alvo.txt";
    FILE*arq;
    FILE*seg;
    seg=fopen(est,"w");
    arq=fopen(url,"w");
    Tno*temp;
    Link*v[3];
    printf("Informe a frase a ser criptografada\n");
    scanf("%s",j);
        do
        {
            printf("Informe a frase alvo: lembre-se que a frase deve ser 4 vezes maior q a que vai\n ser criptografada\n");
            scanf("%s",o);
            if(strlen(o)<(strlen(j)*4))
            {
                printf("String alvo muito curta\n");
            }
        }while(strlen(o)!=(strlen(j)*4));
        for(k=0;k<3;k++)
        {
            v[k]=Link_create();
        }
        for(k=0;k<2;k++)
        {
            if(v[k])
            {
                if(k==0)
                {
                    for(i=0;i<strlen(j);i++)
                    {
                        temp=Tno_create(j[i]);
                        Link_insert_end(v[k],temp);
                        fputc(j[i],arq);
                    }
                }
                if(k==1)
                {
                    for(x=0;x<strlen(o);x++)
                    {
                        temp=Tno_create(o[x]);
                        Link_insert_end(v[k],temp);
                        fputc(o[x],seg);
                    }
                }
            }
        }
        fclose(arq);
        fclose(seg);
        estenografia(v[0],v[1],v[2]);
}
int main()
{
    int op;
    do{
    printf("1- esteganografia 2- decriptografa 0-sair\n");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
    {
        op1();
    }
    case 2:
    {
        decode();
    }
    }
    }while(op!=0);

    return 0;
}
