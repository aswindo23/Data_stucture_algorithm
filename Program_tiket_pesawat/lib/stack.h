#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "boolean.h"
#include "define.h"
#include <string.h>
#include <conio.h>

typedef struct tElstack *adrStk;
typedef struct tElstack {

    int visit;
    char* KOTA;
    adrStk NextS;
}Elstk;
typedef struct {
    adrStk Top;
}Stack;

void CreatStackEmpty(Stack *S);
adrStk AlocatianS(int Visit, char* KOTa);
void DealokasiS(adrStk s);
boolean isEmptyS(Stack S);

void PushAdress_S(Stack *S, adrStk s);
void PushS(Stack *S, int Visit,char* Kota);
void popS(Stack *S, int *Visit, char *Kota[3]);


#endif // STACK_H_INCLUDED
