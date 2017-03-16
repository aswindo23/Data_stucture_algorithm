#include "time.h"
boolean Validasi_time(int Jam, int Menit, int Detik){
    return Jam>=0 && Jam < 24 && Menit>=0 && Menit <60 && Detik >= 0 && Detik <60;
}
boolean Validasi_Time(Time_ T){
    return T.jj>=0 && T.jj < 24 && T.mm>=0 && T.mm <60 && T.dd >= 0 && T.dd <60;
}
Time_ CreateTime(int Jam, int Menit, int Detik){
    Time_ T;
    if(Validasi_time(Jam,Menit,Detik)==true){
        T.jj=Jam;
        T.mm=Menit;
        T.dd=Detik;
    }else{
        T.jj=0;
        T.mm=0;
        T.dd=0;
    }
    return T;
}
void Display_Time(Time_ T){

    if(Validasi_Time(T)==true){
        printf(" %i : %i : %i ",T.jj,T.mm,T.dd);
    }else{
        printf(" %i : %i : %i ",0,0,0);
    }
}
int jamTodetik(Time_ T)
{
    return (T.jj*3600)+(T.mm*60)+T.dd;
}
Time_ detikToJam(int detik)
{
    int jam,menit,Detik;
    Time_ T;
    jam=detik/3600;
    menit=(detik % 3600)/60;
    Detik=(detik % 6000)%60;
    if(Validasi_time(jam,menit,Detik)==true){
        T.jj=jam;
        T.mm=menit;
        T.dd=Detik;
    }else{
         T.jj=0;
        T.mm=0;
        T.dd=0;
    }
    return T;
}
Time_ detikToJam_kh(int detik)
{//     Fungsi Khusus untuk menentukan sisa jam berlalu
    int jam,menit,Detik;
    Time_ T;
    jam=detik/3600;
    menit=(detik % 3600)/60;
    Detik=(detik % 6000)%60;
        T.jj=jam;
        T.mm=menit;
        T.dd=Detik;
    return T;
}
int Selisih(Time_ T, Time_ tt)
{
    int time_1,time_2,selisih;
    time_1=jamTodetik(T);
    time_2=jamTodetik(tt);
    selisih=abs(time_1-time_2);
    return selisih;
}
Time_ SelisihLebih(Time_ t, Time_ tt){
    int selisih;
    Time_ j;
    if ((t.jj<tt.jj) || (t.mm<tt.mm)) {
        selisih=Selisih(tt,t);
        j=detikToJam(selisih);
    }else{
        j.jj=0;
        j.mm=0;
        j.dd=0;
    }
    return j;
}
Time_ SelisihKurang(Time_ t, Time_ tt){
    int time_1,time_2,selisih;
    Time_ j;
    if ((t.jj>tt.jj) || (t.mm>tt.mm)) {
        time_1=jamTodetik(t);
        time_2=jamTodetik(tt);
        selisih=time_1-time_2;
        j=detikToJam_kh(selisih);
    }else{
        j.jj=0;
        j.mm=0;
        j.dd=0;
    }
    return j;
}
void Display_Time_kurang(Time_ T)
{
        printf(" Telah Berlalu (%i : %i : %i) ",T.jj,T.mm,T.dd);
}
Time_ JPlus(Time_ t, Time_ tt){
    int su1,su2,jumlah;
    Time_ j;
    su1=jamTodetik(t);
    su2=jamTodetik(tt);
    jumlah=su1+su2;
    j=detikToJam(jumlah);
    return j;
}
boolean JEqual(Time_ j1, Time_ j2)
{
    return ((j1.jj==j2.jj)&&(j1.mm==j2.mm)&&(j1.dd==j2.dd));
}
boolean JNotEqual(Time_ j1, Time_ j2)
{
    return JEqual(j1,j2)!=true;
}
boolean JLessThan(Time_ j1, Time_ j2){
    int jam1,jam2;
    jam1=jamTodetik(j1);
    jam2=jamTodetik(j2);
    return jam1 <jam2;
}
boolean JgreaterThan(Time_ j1, Time_ j2){
    return JLessThan(j1,j2)!=true;
}
