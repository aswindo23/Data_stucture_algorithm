#include "stack.h"

void CreatStackEmpty(Stack *S)
{
    Top(*S)=NULL;
}
adrStk AlocatianS(int Visit, char* KOTa)
{
    adrStk s=(adrStk)malloc(sizeof(Elstk));
    if(s!=NULL){
        visit(s)=Visit;
        KOTA(s)=KOTa;
        NextS(s)=NULL;
    }
    return s;
}
void DealokasiS(adrStk s)
{
    free(s);
}
boolean isEmptyS(Stack S)
{
    if(Top(S)==NULL){
        return true;
    }else{
        return false;
    }
}
void PushAdress_S(Stack *S, adrStk s)
{
    adrStk s2;
    s2=Top(*S);
    NextS(s)=s2;
    Top(*S)=s;
}
void PushS(Stack *S, int Visit,char* Kota)
{
    adrStk s;

    s=AlocatianS(Visit,Kota);
    if(s==NULL){
            printf("Gagal");
    } else {
        PushAdress_S(S,s);
    }
}
void popS(Stack *S, int *Visit, char *Kota[3])
{
    adrStk s;
    s=Top(*S);
    *Visit=visit(s);
    strcpy(Kota,KOTA(s));
    Top(*S)=NextS(s);
    DealokasiS(s);
}
