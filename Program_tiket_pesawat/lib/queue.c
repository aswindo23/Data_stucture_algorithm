#include "queue.h"

void CreateQEmpty(Queue *Q)
{
    Head(*Q)=NULL;
    Tail(*Q)=NULL;
}
adrQue AlocationQueue(int Visti)
{
    adrQue q=(adrQue)malloc(sizeof(Qsea));
    if(q!=NULL){
        visit(q)=Visti;
        NextQ(q)=NULL;
    }
    return q;
}
void DealokasiQ(adrQue q)
{
    free(q);
}
boolean isEmptyQ(Queue Q)
{
    if(Head(Q)==NULL ){
        return true;
    }else{
        return false;
    }

}

void addAddress(Queue *Q, adrQue q)
{
    if(isEmptyQ(*Q)){
        Head(*Q)=q;
        Tail(*Q)=q;
    }else{
        NextQ(Tail(*Q))=q;
        Tail(*Q)=q;
    }
}
void add(Queue *Q, int Visit)
{
    adrQue q;
    q=AlocationQueue(Visit);
    addAddress(Q,q);
}
void DeleteQueue(Queue *Q, int *Visit)
{
    adrQue q;
    *Visit=visit(Head(*Q));
    q=Head(*Q);
    Head(*Q)=NextQ(Head(*Q));
    DealokasiQ(q);
}
