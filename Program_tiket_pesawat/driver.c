#include "MainDriver.c"
#include <time.h>

void Admin();
void Pelanggan();
void KONEKSI();

int main()

{
    ///==== Aktivasi Data ====
    Attivasi();
    ConnectLocation();
    system("cls");
    printf("\n\n\n\n");
    system("pause");
    FILE *PF;
    FILE *GA;
    FILE *JT;
    PF=fopen("Pelanggan.txt","ab+");
    GA=fopen("Penumpang Garuda.txt","ab+");
    JT=fopen("Penumpang Lion.txt","ab+");
    fclose(JT);
    fclose(GA);
    fclose(PF);
    ///=======================


    /// KAMUS DATA MENU
    char jawaban;
    int sudah_benar;
    int i;
    int lj,k;


    printf("\n\n\n\n\n\n");
    printf("\t\t\t TRAVEKOLA APPS\n");
    printf("\t\t\t APLIKASI BOOKING TIKET PESAWAT ON C \n\n\n");
    printf("\t\t\t PT. TRAVEKOLA INDONESIA TKB\n");

        for(k=1;k<=100;k++ ){
            printf("\n\n\n\n\n\n");
            printf("\t\t\tSedang Memuat % Data %i ",k);printf("Persen");
            system("cls");

        }
//====
    time_t lt;
    lt=time(NULL);
    printf(ctime(&lt));
    printf("\n%67s","|||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n%67s","-------------------------------------------------------");
    printf("\n%67s","             PT TRAVEKOLA INDONESIA                ");
    printf("\n%67s","-------------------------------------------------------");
    printf("\n\n%67s","            APLIKASI TIKET ON PROGRAM                  ");
    printf("\n%67s","                     MENU PROGRAM                     ");
    printf("\n\n%67s","                                                       ");
    printf("\n\t\t 1. ADMIN");
    printf("\n\t\t 2. PELANGGAN");
    printf("\n\t\t 5. Keluar");
    printf("\n\n%67s","|||||||||||||||||||||||||||||||||||||||||||||||||||||||");

do
    {


        printf("\n\t\t Masukan Menu :");

    scanf("%d",&i);
    system("cls");
    switch(i){
    case 1 : Admin();break;
    case 2 : Pelanggan();break;
    case 5 : exit(1);break;
    default : printf("\nSalah Menu");

    }
    time_t lt;
    lt=time(NULL);
    printf(ctime(&lt));
    printf("\n%67s","|||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n%67s","-------------------------------------------------------");
    printf("\n%67s","             PT TRAVEKOLA INDONESIA                ");
    printf("\n%67s","-------------------------------------------------------");
    printf("\n\n%67s","            APLIKASI TIKET ON PROGRAM                  ");
    printf("\n%67s","                     MENU PROGRAM                     ");
    printf("\n\n%67s","                                                       ");
    printf("\n\t\t 1. ADMIN");
    printf("\n\t\t 2. PELANGGAN");
    printf("\n\t\t 5. Keluar");
    printf("\n\n%67s","|||||||||||||||||||||||||||||||||||||||||||||||||||||||");

    printf("\nUlang Menu Lagi [Y/T] ?");

        do {
            jawaban = getchar();
            sudah_benar = ((jawaban == 'Y') || (jawaban == 'y')
            ||(jawaban == 'T') || (jawaban == 't'));
        } while(!sudah_benar);

        system("cls");
        printf("\n");
    } while(jawaban == 'Y' || jawaban == 'y');
}


void Admin()
{


    char jawaban;
    int sudah_benar;
    FILE *pf;
    int i;

    char adminID[20];
    char pass[20];
    printf("\n\n\n\n\n");
    printf("\t\t\t LOGIN TERLEBIH DAHULU \n");
    printf("\t\t\t ----------------------------------- \n");
    printf("\t\t\t |    ID ADMIN        :");fflush(stdin);gets(adminID);
    printf("\t\t\t |    Passoword ADMIN :");fflush(stdin);gets(pass);
    printf("\t\t\t ----------------------------------- \n");
    if(strcmp(adminID,"ADMIN")==0 && strcmp(pass,"ADMIN")==0){
        printf("\nSilahkan Lanjutkan");
        system("cls");
    }else{
        printf("Maaf ID ADMIN dan PASSOWORD SALAH MAKA ANDA AKAN KELUAR");
        exit(0);
    }


//====
    time_t lt;
    lt=time(NULL);
    printf(ctime(&lt));
    printf("\n%67s","|||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n%67s","-------------------------------------------------------");
    printf("\n%67s","             PT TRAVEKOLA INDONESIA                ");
    printf("\n%67s","-------------------------------------------------------");
    printf("\n\n%67s","          HALAMAN ADMIN                  ");
    printf("\n%67s","                     MENU ADMIN                   ");
    printf("\n\n%67s","                                                       ");
    printf("\n\t\t 1. AKTIVASI");
    printf("\n\t\t 2. LIHAT KONEKSI KOTA");
    printf("\n\t\t 3. TAMPILKAN SELURUH PENERBANGAN");
    printf("\n\t\t 4. LIHAT PELANGGAN");
    printf("\n\t\t 5. TAMBAHKAN PENERBANGAN");
    printf("\n\t\t 6. Keluar");
    printf("\n\n%67s","|||||||||||||||||||||||||||||||||||||||||||||||||||||||");

do
    {







        printf("\n\t\t Masukan Menu :");

    scanf("%d",&i);
    system("cls");
    switch(i){
    case 1 : Attivasi();break;
    case 2 : KONEKSI();system("cls");break;
    case 3 : DisplaY_graph();break;
    case 4 : Pelangan_daftar();break;
    case 5 :printf("\n MAAF SEDANG PERBAIKAN");break;
    case 6 : exit(1);break;
    default : printf("\nSalah Menu");

    }
    time_t lt;
    lt=time(NULL);
    printf(ctime(&lt));
    printf("\n%67s","|||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n%67s","-------------------------------------------------------");
    printf("\n%67s","             PT TRAVEKOLA INDONESIA                ");
    printf("\n%67s","-------------------------------------------------------");
    printf("\n\n%67s","          HALAMAN ADMIN                  ");
    printf("\n%67s","                     MENU ADMIN                   ");
    printf("\n\n%67s","                                                       ");
    printf("\n\t\t 1. AKTIVASI");
    printf("\n\t\t 2. LIHAT KONEKSI KOTA");
    printf("\n\t\t 3. TAMPILKAN SELURUH PENERBANGAN");
    printf("\n\t\t 4. LIHAT PELANGGAN");
    printf("\n\t\t 5. TAMBAHKAN PENERBANGAN");
    printf("\n\t\t 6. Keluar");
    printf("\n\n%67s","|||||||||||||||||||||||||||||||||||||||||||||||||||||||");

    printf("\nUlang Menu Lagi [Y/T] ?");

        do {
            jawaban = getchar();
            sudah_benar = ((jawaban == 'Y') || (jawaban == 'y')
            ||(jawaban == 'T') || (jawaban == 't'));
        } while(!sudah_benar);

        system("cls");
        printf("\n");
    } while(jawaban == 'Y' || jawaban == 'y');

}
void Pelanggan()
{

    char jawaban;
    int sudah_benar;

    int i;


//====
    time_t lt;
    lt=time(NULL);
    printf(ctime(&lt));
    printf("\n%67s","|||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n%67s","-------------------------------------------------------");
    printf("\n%67s","             PT TRAVEKOLA INDONESIA                ");
    printf("\n%67s","-------------------------------------------------------");
    printf("\n\n%67s","          APLIKASI PESAN TIKET ON PROGRAM C          ");
    printf("\n%67s","                     MENU USER                   ");
    printf("\n\n%67s","                                                       ");
    printf("\n\t\t 1. LIHAT PENERBANGAN LANGSUNG");
    printf("\n\t\t 2. LIHAT  DAN PESAN TIKET PENERBANGAN LANGSUNG");
    printf("\n\t\t 3. LIHAT PENERBANGAN TRANSIT");
    printf("\n\t\t 4. LIHAT  DAN PESAN TIKET PENERBANGAN TRANSIT");
    printf("\n\t\t 5. CEK PESANAN");
    printf("\n\t\t 6. Keluar");
    printf("\n\n%67s","|||||||||||||||||||||||||||||||||||||||||||||||||||||||");

do
    {


        printf("\n\t\t Masukan Menu :");

    scanf("%d",&i);
    system("cls");
    switch(i){
    case 1 : printf("\n MAAF SEDANG PERBAIKAN");break;
    case 2 : Penerbangan_LIVE();break;
    case 3 : Lihat_Penerbangan_transit();break;
    case 4 : printf("\n MAAF SEDANG PERBAIKAN");break;
    case 5 : printf("\n MAAF SEDANG PERBAIKAN");break;
    case 6 : exit(1);break;
    default : printf("\nSalah Menu");

    }
    time_t lt;
    lt=time(NULL);
    printf(ctime(&lt));
    printf("\n%67s","|||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n%67s","-------------------------------------------------------");
    printf("\n%67s","             PT TRAVEKOLA INDONESIA                ");
    printf("\n%67s","-------------------------------------------------------");
    printf("\n\n%67s","          APLIKASI PESAN TIKET ON PROGRAM C          ");
    printf("\n%67s","                     MENU USER                   ");
    printf("\n\n%67s","                                                       ");
    printf("\n\t\t 1. LIHAT PENERBANGAN LANGSUNG");
    printf("\n\t\t 2. LIHAT  DAN PESAN TIKET PENERBANGAN LANGSUNG");
    printf("\n\t\t 3. LIHAT PENERBANGAN TRANSIT");
    printf("\n\t\t 4. LIHAT  DAN PESAN TIKET PENERBANGAN TRANSIT");
    printf("\n\t\t 5. CEK PESANAN");
    printf("\n\t\t 6. Keluar");
    printf("\n\n%67s","|||||||||||||||||||||||||||||||||||||||||||||||||||||||");

    printf("\nUlang Menu Lagi [Y/T] ?");

        do {
            jawaban = getchar();
            sudah_benar = ((jawaban == 'Y') || (jawaban == 'y')
            ||(jawaban == 'T') || (jawaban == 't'));
        } while(!sudah_benar);

        system("cls");
        printf("\n");
    } while(jawaban == 'Y' || jawaban == 'y');

}


void KONEKSI()

{
    int jawab_no;
    printf("Sebelum Anda Melihat Koneksi Maka Terlebih Dahulu Anda Harus MENGAKTIFKAN DATA");
    printf("\n");
    printf("\n 1. Aktifkan (Tekan [1])");
    printf("\n 2. Tidak (Tekan [0]) Untuk Keluar");
    printf("\n Respon : ");scanf("%i",&jawab_no);

    if(jawab_no==1){
        Attivasi();
        system("cls");
        printf("\n DATA TELAH TERAKTIVASI");
    }else{
        exit(0);
    }

    int konek;
    printf("Lihat Koneksi [Tekan [1]");scanf("%i",&konek);
    if(konek==1){
        ConnectLocation();
    }else{
        printf("ANDA SALAH INPUT MAKA AKAN KELUAR");
        exit(0);
    }
    printf("\n\n\n\n");
    printf("\n\n\n\n");
    system("pause");

}
