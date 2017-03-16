#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "boolean.h"
#include <math.h>
typedef struct {
    int jj;
    int mm;
    int dd;
}Time_;
boolean Validasi_time(int Jam, int Menit, int Detik);
boolean Validasi_Time(Time_ T);
Time_ CreateTime(int Jam, int Menit, int Detik);
void Display_Time(Time_ T);
void Display_Time_kurang(Time_ T);
///Konvektor
int jamTodetik(Time_ T);
Time_ detikToJam(int detik);
int Selisih(Time_ T, Time_ tt);
Time_ SelisihLebih(Time_ t, Time_ tt);
Time_ SelisihKurang(Time_ t, Time_ tt);
Time_ detikToJam_kh(int detik);
Time_ JPlus(Time_ t, Time_ tt);
boolean JEqual(Time_ j1, Time_ j2);
boolean JNotEqual(Time_ j1, Time_ j2);
boolean JLessThan(Time_ j1, Time_ j2);
boolean JgreaterThan(Time_ j1, Time_ j2);
#endif // TIME_H_INCLUDED
