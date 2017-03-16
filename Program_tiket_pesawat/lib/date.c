#include "Date.h"

boolean Validasi_Date(int Day, int Mount, int Year)
{
    if((Day>=0 && Day <32) && (Mount >=0 && Mount<13 ) &&(Year>=0)){
        return true;
    }else{
        return false;
    }
}
boolean ValidasiDate(Date d){
    if(d.day>=0 && d.day<=31 && d.mount >= 1 && d.mount <= 12 && d.year >=0){
        return true;
    }else {
        return false;
    }
}
Date CreateDate(int Day, int Mount, int Year)
{
    Date d;
    if(Validasi_Date(Day,Mount,Year)==true){
        d.day=Day;
        d.mount=Mount;
        d.year=Year;
    }else{
        d.day=0;
        d.mount=0;
        d.year=0;

    }
    return d;
}
void Display_Date(Date d)
{
    if(ValidasiDate(d)==true){
        printf(" %i-%i-%i ",d.day,d.mount,d.year);
    }else{
        printf(" %i-%i-%i ",00,00,0000);
    }
}

boolean Kabisat(Date d){

    if(d.year%400==0 || d.year%4==0){
       return true;
    }else {
        return true;
    }


}
int JumlahHari(Date d)
{
    if(d.mount==2){
        if(Kabisat(d)==true){
            return 29;
        }else{
            return 28;
        }
    }else{
        if(d.mount==4 || d.mount== 6 || d.mount==9|| d.mount==11){
            return 30;
        }else{
            return 31;
        }
    }
}

int SelisihHari(Date d,Date dd)
{
       return ((dd.year-d.year)*365+(dd.mount-d.mount)*30+(dd.day-d.day));
}

boolean LebihDari(Date d, Date dd)
{
    if(SelisihHari(d,dd)>0){
        return true;
    }else{
        return false;
    }
}

boolean KurangDari(Date d, Date dd)
{
    if(SelisihHari(d,dd)<0){
        return true;
    }else{
        return false;
    }
}

boolean sama(Date d, Date dd)
{
    if((d.year==dd.year)&&(d.mount==dd.mount)&&(d.day==dd.day))
        return true;
    else
        return false;
}

boolean Notsama(Date d, Date dd)
{
    if(sama(d,dd)==true) return false; else return true;
}

Date NextDay(Date d)
{
    Date dd;
    dd=d;
    dd.day=dd.day+1;
    if(dd.day>JumlahHari(dd)){
        dd.day=1;
        dd.mount=dd.mount+1;
        if(dd.mount>12){
            dd.year=dd.year+1;
            dd.mount=1;
        }

    }
    return dd;
}

