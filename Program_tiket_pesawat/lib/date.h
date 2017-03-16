#ifndef Date_H_INCLUDED
#define Date_H_INCLUDED
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "boolean.h"
#include <math.h>

typedef struct {
    int day;
    int mount;
    int year;
}Date;
boolean Validasi_Date(int Day, int Mount, int Year);
boolean ValidasiDate(Date d);
Date CreateDate(int Day, int Mount, int Year);
void Display_Date(Date d);
boolean Kabisat(Date d);
int JumlahHari(Date d);
//Perbandingan
boolean LebihDari(Date d, Date dd);
boolean KurangDari(Date d, Date dd);
boolean sama(Date d, Date dd);
boolean Notsama(Date d, Date dd);
Date NextDay(Date d);

#endif // Date_H_INCLUDED
