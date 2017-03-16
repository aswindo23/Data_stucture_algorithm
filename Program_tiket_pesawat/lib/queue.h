#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "boolean.h"
#include "define.h"
#include <string.h>
#include <conio.h>
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct tQsea *adrQue;
typedef struct tQsea {

    int visit;
    adrQue NextQ;
}Qsea;

typedef struct {
    adrQue Head;
    adrQue Tail;
}Queue;

void CreateQEmpty(Queue *Q);
adrQue AlocationQueue(int Visti);
void DealokasiQ(adrQue q);
boolean isEmptyQ(Queue Q);

void addAddress(Queue *Q, adrQue q);
void add(Queue *Q, int Visit);
void DeleteQueue(Queue *Q, int *Visit);
#endif // QUEUE_H_INCLUDED
