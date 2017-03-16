#include "header.h"

int CreateFile()
{
    FILE *fkodekota;
    fkodekota=fopen("File Kota.txt","ab");
    fclose(fkodekota);
}
int Input_data()
{
    FILE *f_kodekota;
    char jawaban;
    int sudah_benar;
    DataKota Kota;


    /* Buka file */
        if((f_kodekota  = fopen("File Kota.txt", "ab+")) == NULL)
        {
            printf("File tidak dapat diciptakan !\n");
            exit(1);
        }
         do {
                fflush(stdin);     /* Hapus isi penampung keyboard */
                printf("Kode Kota   : ");gets(Kota.Kkasal);//scanf("%s",&Kota.Kkasal);
                //fflush(stdin);
                printf("Nama Kota   : ");gets(Kota.KotaAsal);//scanf("%s",&Kota.KotaAsal);
                fflush(stdin);     /* Hapus isi penampung keyboard */

                /// Merekam Data
                fwrite(&Kota, sizeof(Kota), 1, f_kodekota);
                printf("\nMau merekam data lagi [Y/T] ?");
            do
            {
              jawaban = getchar();
              sudah_benar = ((jawaban == 'Y') || (jawaban == 'y')||(jawaban == 'T') || (jawaban == 't'));
            } while(!sudah_benar);

                printf("\n");
        } while(jawaban == 'Y' || jawaban == 'y');
    fclose(f_kodekota);            /* Tutup file */
}

void LihatData(){
    FILE *f_kodekota;

    int i=1,j=1;
    DataKota Kota;
    //nodeVertex kota;                /* var kota bertipe struktur */
    /* Buka file */

    if((f_kodekota  = fopen("File Kota.txt", "ab+")) == NULL)
    {
        printf("File tidak dapat dibuka !\n");
        exit(1);
    }

    char pindah[3];
    char* ks=0;
    char* nMkota=0;
    char pindah2[20];
    adrVtx v[100];
    ListKKota kta;
    CreateListKKota(&kta);
        while(fread(&Kota,sizeof(Kota), 1, f_kodekota) == 1){
            //fseek(f_struktur,0,SEEK_CUR);





            //strcpy(pindah,Kota.Kkasal);
            //strcpy(pindah2,Kota.KotaAsal);
            printf("Kode Pindah             : %s \n",pindah);
            printf("Alamat Kode Pindah      : %p \n",pindah);
            printf("Kode Kkasal             : %s \n",Kota.Kkasal);
            printf("Alamat Kode Kkasal      : %p \n",Kota.Kkasal);
            printf("Kota Pindah 2           : %s \n",pindah2);
            printf("Alamat Kota  Pindah 2   : %p \n",pindah2);
            printf("Kota Kota Asal          : %s \n",Kota.KotaAsal);
            printf("Alamat Kode Kota Asal   : %p \n",Kota.KotaAsal);
            ks=malloc(sizeof(4));
            strcpy(ks,Kota.Kkasal);

            //printf("SUKSES");
            //printf("Pindah :%s\n ",pindah);
            insertNodeKKota(&kta,Kota.Kkasal,pindah2);

            //printf("Indek No  :%s \n",pindah[j][3]);
            //printf("\n");
            //j+=1;
        }

        fclose(f_kodekota);     /* Tutup file */
        //DisplayVertex(G);
        DisplayKKota(kta);

    printf("\n==========================\n");

}

///====================================================================
///Produre dan fungsi kode kota
void CreateListKKota(ListKKota *Kta)
{
    firstKKota(*Kta)=NULL;
}
adrKKota AlocationKKota(char Kkota[3], char* NamaKota)
{
    adrKKota kta=(adrKKota)malloc(sizeof(KKota));
    if(kta!=NULL){
        Kode(kta)=Kkota;
        NamaKota(kta)=NamaKota;
        NextKKota(kta)=NULL;
    }
    return kta;
}
void insertFirstKKota(ListKKota *Kta, adrKKota KK)
{
    NextKKota(KK)=firstKKota(*Kta);
    firstKKota(*Kta)=KK;
}
void insertKKota(ListKKota *Kta, adrKKota KK)
{

    adrKKota kt=firstKKota(*Kta);
    if(kt!=NULL){
         while(NextKKota(kt)!=NULL){
            kt=NextKKota(kt);
        }
        NextKKota(kt)=KK;
    }else{
        insertFirstKKota(Kta,KK);
    }


}

void insertNodeKKota (ListKKota *kta, char* KKode, char* Kota){

    adrKKota kt;
    kt = AlocationKKota(KKode,Kota);
    insertKKota(kta,kt);

}
void dealokasiKKota(adrKKota Kta)
{
    free(Kta);
}
void DisplayKKota(ListKKota Kta)
{
    adrKKota kt=firstKKota(Kta);
    if(kt==NULL){
        printf("Database Kosong");
    }else{
        while(kt!=NULL){
            printf("\t ");
            printf("%s",Kode(kt));
            printf("\t");
            printf("%s",NamaKota(kt));
            printf("\n");
            kt=NextKKota(kt);
        }
    }
}
char *KodeKota(ListKKota Kta, char *namaKota)
{
    boolean Found=false;
    adrKKota p=firstKKota(Kta);
    if(p==NULL){
        //printf("---");
        return '---';
    }else{
        while(p!=NULL && Found==false ){

            if(strcmp(namaKota,NamaKota(p))==0){
                Found=true;
            }else{
                p=NextKKota(p);
            }
        }
        if(Found==true){
            return Kode(p);
            //printf("%s",Kode(p));
        }else{
            return "NOT";
        }
    }
}

char *KodeKotatoNama(ListKKota Kta, char *kodeKota){
     boolean Found=false;
    adrKKota p=firstKKota(Kta);
    if(p==NULL){
        //printf("---");
        return '---';
    }else{
        while(p!=NULL && Found==false ){

            if(strcmp(kodeKota,Kode(p))==0){
                Found=true;
            }else{
                p=NextKKota(p);
            }
        }
        if(Found==true){
            return NamaKota(p);
            //printf("%s",Kode(p));
        }else{
            return "NOT";
        }
    }
}



///==== Primitive Stack ========
void CreatStackEmpty(Stack *S)
{
    Top(*S)=NULL;
}
adrStk AlocatianS(int Visit, adrEdg tmPedge)
{
    adrStk s=(adrStk)malloc(sizeof(Elstk));
    if(s!=NULL){
        visit(s)=Visit;
        tmpEdge(s)=tmPedge;
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
void PushS(Stack *S, int Visit,adrEdg tmPedge)
{
    adrStk s;

    s=AlocatianS(Visit,tmPedge);
    if(s==NULL){
            printf("Gagal");
    } else {
        PushAdress_S(S,s);
    }

}
void popS(Stack *S, int *Visit, adrEdg *tmPedge)
{
    adrStk s;
    s=Top(*S);
    *Visit=visit(s);
    *tmPedge=tmpEdge(s);
    Top(*S)=NextS(s);
    DealokasiS(s);
}

///===== Primitive Vertex ======

void CreateListVertex(Graph *G){
   HeadVtx(*G)=NULL;
}
adrVtx AlocationVtx( char* Kota )
{
    adrVtx p;

        p=(adrVtx)malloc(sizeof(Vertex));
        if(p!=NULL){
            KAsal(p)=Kota;
            NextVertex(p)=NULL;
            firstEdge(p)=NULL;
        }
    return p;


}
void insertFirstVtx( Graph *G,adrVtx V)
{
    NextVertex(V)=HeadVtx(*G);
    HeadVtx(*G)=V;
}
void insertVtx(Graph *G, adrVtx V)
{
    adrVtx p=HeadVtx(*G);
    if(p!=NULL){
        while(NextVertex(p)!=NULL){
            p=NextVertex(p);
        }
        NextVertex(p)=V;
    }else{
        insertFirstVtx(G,V);
    }
}

void InsertNodeVtx(Graph *G, char* Kota)
{
    adrVtx v;
    v=AlocationVtx(Kota);
    insertVtx(G,v);
}
void DealokasiVtx(adrVtx G)
{
    free(G);
}

void DisplayVertex(Graph G)
{

    adrVtx p=HeadVtx(G);
    if(p==NULL){
        printf("\n\t DataBase Kosong \n");
    }else{
        while(p!=NULL){
                    printf("%s \n",KAsal(p));
                    p=NextVertex(p);
        }
    }
}



///========= Primitive Edge ==========


adrEdg AlocationEdge(ListKKota *kta, char* dpt, char* arv, char* nmMaskapai, char* KDMasakapai, Time_ Tdpt, Time_ Tarv, Time_ Tdrs, long int harga)
{
    adrEdg p=(adrEdg)malloc(sizeof(Edge));
    if(p!=NULL){
        Departure(p)=dpt;
        KodeDpr(p)=KodeKota(*kta,dpt);
        Arrival(p)=arv;
        KodeArv(p)=KodeKota(*kta,arv);
        NamaPesawat(p)=nmMaskapai;
        KodePesawat(p)=KDMasakapai;
        Timedeparture(p)=Tdpt;
        Timearrival(p)=Tarv;
        Durasi(p)=Tdrs;
        Harga(p)=harga;
        NextEdge(p)=NULL;
        ConnectVertex(p)=NULL;
    }
    return p;
}

void InsertEdge(Graph *Vt, adrEdg Ie,char* KOTA)
{
    adrVtx v;
    adrEdg e;
    v=HeadVtx(*Vt);
    while(v!=NULL){
        if(strcmp(KOTA,KAsal(v))==0){
            break;
        }else{
            v=NextVertex(v);
        }
    }
    if(v!=NULL){
        e=firstEdge(v);
        if(e==NULL){
            e=Ie;
            NextEdge(e)=NULL;
            firstEdge(v)=Ie;
        }else{
            while(NextEdge(e)!=NULL){
                e=NextEdge(e);
            }
            NextEdge(e)=Ie;
            NextEdge(Ie)=NULL;
        }
    }
}

void ConnettoVertex(Graph G, char* kotaA, char* kotaT)
{
    adrVtx v=HeadVtx(G);
    adrVtx v2=v;
    adrEdg e;
    boolean VASAL,VTUJUAN;
    VASAL=SearchVertexAsal(&G,kotaA);
    VTUJUAN=SearchVertexAsal(&G,kotaT);
 if(VASAL==true & VTUJUAN == true){

        if(v==NULL){
        printf("\n\n");
        printf("Datebase Kosong");
        printf("\n\n");
    }else{
        ///Mencari ASAL
        while(v!=NULL){
            if(strcmp(kotaA,KAsal(v))==0){
                break;
            }else{
                v=NextVertex(v);
            }
        }
        ///Mencari Tujuan
        while(v2!=NULL){
            if(strcmp(kotaT,KAsal(v2))==0){
                break;
            }else{
                v2=NextVertex(v2);
            }
        }

        e=firstEdge(v);
        adrVtx etov;
            //printf("Kode Berhasil");
        if(e==NULL){
            printf("\n\n");
            printf("Tidak Ada penerbangan Langsung dari %s ke %s",kotaA,kotaT);
            printf("\n\n");
        }else{
            while(e!=NULL){

                if(strcmp(kotaA,KodeDpr(e))==0 && strcmp(kotaT,KodeArv(e))==0){

                    if(ConnectVertex(e)==NULL){
                            //printf("\nTest Banding");
                        break;
                    }else{

                        e=NextEdge(e);
                    }

                    //break;
                }else{
                    e=NextEdge(e);
                }
            }
            if(e==NULL){
                printf("\n\n");
                printf("\t\t\tTidak ditemukan penerbangan Langsung");
                printf("\n\n");
            }else if((strcmp(kotaA,KodeDpr(e))==0 && strcmp(kotaT,KodeArv(e))==0)){
                ConnectVertex(e)=v2;
                printf("\n\n");
                printf("\t\t\tKoneksi dari %s Ke %s Berhasil",KodeDpr(e),KodeArv(e));
                printf("\n\n");
                printf("\n\n");
            }else if((strcmp(kotaA,KodeArv(e))!=0 || strcmp(kotaT,KodeArv(e))!=0)){
                printf("\n\n");
                printf("\t\t\tKoneksi dari %s Ke %s Gagal ",kotaA,kotaT);
                printf("\n\n");
                printf("\n\n");
            }
        }

    }

}
}
void DisplayGraph(Graph G)
{
    adrVtx v;
    adrEdg e;
    adrVtx etov;

    v=HeadVtx(G);
    if(v==NULL){
        printf("\n Database Kosong");
    }else{
        while(v!=NULL){
            printf("\n");
            printf("\t %s ",KAsal(v));
            printf("\n");
            e=firstEdge(v);
            if(e==NULL){
                printf("\n\t\t Database Kosong\n");
            }else{
                while(e!=NULL){
                etov=ConnectVertex(e);
                printf("\n");
                printf("\n");
                printf("\t\t %s",Departure(e));
                printf(" [%s] ",KodeDpr(e));
                printf(" -->  ");
                printf("%s",Arrival(e));
                printf(" [%s] ",KodeArv(e));
                printf("\n");
                printf("\t\t Terkoneksi ke --> %s",KAsal(etov));

                            printf("\n\t\t\t");
                            printf("%s |",Departure(e));
                            printf("%s |",KodeDpr(e));
                            printf("%s |",Arrival(e));
                            printf("%s |",KodeArv(e));
                            printf("%s |",NamaPesawat(e));
                            printf("%s |",KodePesawat(e));
                            printf("| ");
                            Display_Time(Timedeparture(e));
                            printf(" |");
                            Display_Time(Timearrival(e));
                            printf("| ");
                            Display_Time(Durasi(e));
                            printf("| %d",Harga(e));



                    e=NextEdge(e);
                }
            }
            v=NextVertex(v);
        }
    }
}

boolean SearchVertexAsal(Graph *G, char* kota)
{
    adrVtx V;
    V=HeadVtx(*G);
    boolean Found = false;
    if(V==NULL){
        printf("\n Sistem sedang terganggu");
    }else{
        while(V!=NULL && !Found){
            if(strcmp(kota,KAsal(V))==0){
                Found=true;break;
            }else{
                V=NextVertex(V);
            }
        }
        if(Found==true){
            return true;
        }else{
            return false;
        }
    }
}

///===== Primitive Informasi Penerbangan =====

void CreateListFlight(ListFlight *LF)
{
    firstFlight(*LF)=NULL;
}
adrFlight AlocationinfoFlight(ListKKota *kta,int no_jadwal ,char* DepartureX, char* ArrivalX, char* NamaPesawatX , char*KodePesawatX, Time_ DPt, Time_ ARv, Time_ DUrasi, long int HargaX)
{
    adrFlight fl=(adrFlight)malloc(sizeof(Flight));
    if(fl!=NULL){
        No_Jadwal(fl)= no_jadwal;
        Departure(fl)=DepartureX;
        KodeDpr(fl)=KodeKota(*kta,DepartureX);
        Arrival(fl)=ArrivalX;
        KodeArv(fl)=KodeKota(*kta,ArrivalX);
        NamaPesawat(fl)=NamaPesawatX;
        KodePesawat(fl)=KodePesawatX;
        Timedeparture(fl)=DPt;
        Timearrival(fl)=ARv;
        Durasi(fl)=DUrasi;
        Harga(fl)=HargaX;
        NextFlight(fl)=NULL;
    }
    return fl;
}
void InsertFisrtFlight(ListFlight *LF, adrFlight lf)
{
    NextFlight(lf)=firstFlight(*LF);
    firstFlight(*LF)=lf;
}
void InsertFlight(ListFlight *LF, adrFlight lf)
{
    adrFlight Lf= firstFlight(*LF);

    if(Lf!=NULL){
        while(NextFlight(Lf)!=NULL){
            Lf=NextFlight(Lf);
        }
        NextFlight(Lf)=lf;
    }else{
        InsertFisrtFlight(LF,lf);
    }
}
void InsertADD(ListFlight *LF,ListKKota kta,int no_jadwal ,char* DepartureX, char* ArrivalX, char* NamaPesawatX , char*KodePesawatX, Time_ DPt, Time_ ARv, Time_ DUrasi, long int HargaX){

    adrFlight fl=firstFlight(*LF);
    adrFlight lf;
    if(fl==NULL){
        lf=AlocationinfoFlight(&kta,no_jadwal,DepartureX,ArrivalX,NamaPesawatX,KodePesawatX,DPt,ARv,DUrasi,HargaX);
        InsertFisrtFlight(LF,lf);
    }else{
        lf=AlocationinfoFlight(&kta,no_jadwal,DepartureX,ArrivalX,NamaPesawatX,KodePesawatX,DPt,ARv,DUrasi,HargaX);
        InsertFlight(LF,lf);
    }
}
void DealokasiFlight(adrFlight lf)
{
    free(lf);
}
void DisplayFlight(ListFlight LF)
{
        adrFlight lf=firstFlight(LF);
        if(lf==NULL){
            printf("\nPenerbangan Kosong\n");
        }else{

            while(lf!=NULL){
                printf("\n\t\t ---------------------------------------------------\n");
                printf("\t\t %d ",No_Jadwal(lf));
                printf("\t %s (%s)",Departure(lf),KodeDpr(lf));
                printf(" --> %s (%s)",Arrival(lf),KodeArv(lf));
                printf("\n");
                printf("\t\t\t Maskapai         : %s ( %s )",NamaPesawat(lf),KodePesawat(lf));
                printf("\n");
                printf("\t\t\t Berangkat Pukul  : ");Display_Time(Timedeparture(lf));
                printf("\n");
                printf("\t\t\t Tiba Pukul       :");Display_Time(Timearrival(lf));
                printf("\n");
                printf("\t\t\t Durasi           :");Display_Time(Durasi(lf));
                printf("\n");
                printf("\t\t\t Harga            : %d",Harga(lf));
                printf("\n\t\t ---------------------------------------------------\n");
                lf=NextFlight(lf);

            }
        }
}

/// ====== Penerbangan Langsung =====

void Penerbangan_langsung(Graph *G,ListKKota kta,ListPelangan *PL,char* KoDPR, char* KoARV)
{
    adrVtx V;
    adrVtx etov;
    //adrIE ie;
    adrEdg e;
    boolean Found= false;
    boolean Found2= false;
    boolean Found3= false;
    ListFlight LF;
    V=HeadVtx(*G);

    boolean KOTAA=SearchVertexAsal(G,KoDPR);
    boolean KOTAT=SearchVertexAsal(G,KoARV);
    if(KOTAA==true && KOTAT ==true){



    if(V==NULL){  /// Mengecek Vertek NULL atau tidak
        printf("\nSistem Sedang Terganggu coba lagi nanti\n!");
    }else{ /// Jika tidak NULL akan Mengerjakan perintah di bawah

        while(NextVertex(V)!=NULL && !Found){
            if(strcmp(KoDPR,KAsal(V))==0){ /// Mencari Asal Tujuan
                Found=true;
                break;
            }else{
                V=NextVertex(V);
            }
        }
        /// Masuk ke List Edge
        e=firstEdge(V);
        if(Found==true && e!=NULL){
            CreateListFlight(&LF);
            int no=1;

            while(NextEdge(e)!=NULL){
                etov=ConnectVertex(e);
               // printf("Behasil Masuk");
               if(strcmp(KoARV,KodeArv(e))==0){
                    printf("Penerbangan Dari %s Ke %s Tersedia ",KodeDpr(e),KodeArv(e));
                    printf("---> %s \n",KAsal(etov));
                    InsertADD(&LF,kta,no,Departure(e),Arrival(e),NamaPesawat(e),KodePesawat(e),Timedeparture(e),Timearrival(e),Durasi(e),Harga(e));
                  //  printf("Behasil Masuk");
                    //Found2==true;
                    no+=1;
                }
                 e=NextEdge(e);

            }

               DisplayFlight(LF);




        }else if(e==NULL || Found==false){
            printf("Penerbangan Dari %s Kosong ",KAsal(V));

        }
    }
    int noPer;
    printf("\n");
    printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t Pilih Penerbangan ");scanf("%i",&noPer);
    printf("\t\t\t----------------------------------------\n");
    Pesan_Penerbangan_langsung(&LF,&PL,noPer);
    }else{
        printf("\n TIDAK ADA PENERBANGAN KESANA ");
    }
}

void Pesan_Penerbangan_langsung( ListFlight *LF, ListPelangan *PL ,int no_pesanan)
{
       FILE *PF;
       PELANGGAN PE;
    ListKKota kta;
    adrPlg pl;
    adrFlight fl=firstFlight(*LF);
    ListPelangan P;
    CreateListPelangan(&P);
    if(fl==NULL){
        printf("Tidak Ada Penerbangan");
    }else{
        while(NextFlight(fl)!=NULL){
            if(no_pesanan==No_Jadwal(fl)){
                break;
            }else{
                fl=NextFlight(fl);
            }
        }
        char namapemesanX[30];
        char namapemesanX5[30];
        char nohpX[13];
        char namapenumpangX[30];
        char GelarX[3];
        char namaPemesanX2[30];

        long int bayar;
        int i;
        int banyak;
        printf("\n\n\n");
        printf("\t\t\t==========================================\n");
        printf("\t\t\t------------------------------------------\n");
        fflush(stdin);
        printf("\t\t\t Nama Pemesan     : ");gets(namapemesanX);
        printf("\t\t\t No HP Pemesan    : ");gets(nohpX);
        printf("\t\t\t Jumlah Tiket     :");scanf("%d",&banyak);
        printf("\t\t\t==========================================\n");
        bayar=Harga(fl)*banyak;
        InsertNodePelangan(&P,namapemesanX,nohpX,Departure(fl),KodeDpr(fl),Arrival(fl),KodeArv(fl),NamaPesawat(fl),KodePesawat(fl),Timedeparture(fl),Timearrival(fl),Durasi(fl),bayar);


        ///-----------------------------------------------------------



        //PF=fopen("Pelanggan.txt","ab+");
        if((PF = fopen("Pelanggan.txt","ab+"))==NULL)
        {
                printf("\t\t Database Bermasalah");
        }
        strcpy(PE.Nama_pelangan,namapemesanX);
        strcpy(PE.No_HandP,nohpX);
        PE.Jumlah=banyak;
        fwrite(&PE,sizeof(PE),1,PF);
        fclose(PF);

        ///-----------------------------------------------------------




        for(i=1; i<=banyak ; i++){
            printf("\t\t\t------------------------------------------\n");
            printf("\t\t\t Nama Penumpang ke %i     : ",i);fflush(stdin);gets(namapenumpangX);
            printf("\t\t\t Gelar Penumpang ke %i    : ",i);fflush(stdin);gets(GelarX);
            printf("\t\t\t------------------------------------------\n");
            strcpy(namaPemesanX2,namapemesanX);
            InsertNodePsg(&P,namaPemesanX2,namapenumpangX,GelarX,Harga(fl));


            if(strcmp(NamaPesawat(fl),"Lion Air")==0){
                printf("Masuk LION");
                    FILE *JT;
                    PENUMPANG PN;
                if((JT = fopen("Penumpang Lion.txt","ab+"))==NULL)
                {
                    printf("\t\t Database Bermasalah");
                }
                    strcpy(PN.Nama_penumpang,namapenumpangX);
                    strcpy(PN.Nama_Pembeli,namaPemesanX2);
                    strcpy(PN.Asal,Departure(fl));
                    strcpy(PN.Tujuan,Arrival(fl));
                    strcpy(PN.Nama_Maskapai,NamaPesawat(fl));
                    strcpy(PN.kode_Maskapai,KodePesawat(fl));
                    PN.DPTF=Timedeparture(fl);
                    PN.ARVF=Timearrival(fl);
                    PN.DRSF=Durasi(fl);
                    PN.Harga=Harga(fl);

                    fwrite(&PN,sizeof(PN),1,JT);
                    fclose(JT);
                    printf("LEWAT");

            }else{
                     printf("Masuk GARUDA");
                    FILE *GA;
                    PENUMPANG PN;

                 if((GA = fopen("Penumpang Garuda.txt","ab+"))==NULL)
                {
                    printf("\t\t Database Bermasalah");
                }
                    strcpy(PN.Nama_penumpang,namapenumpangX);
                    strcpy(PN.Nama_Pembeli,namaPemesanX2);
                    strcpy(PN.Asal,Departure(fl));
                    strcpy(PN.Tujuan,Arrival(fl));
                    strcpy(PN.Nama_Maskapai,NamaPesawat(fl));
                    strcpy(PN.kode_Maskapai,KodePesawat(fl));
                    PN.DPTF=Timedeparture(fl);
                    PN.ARVF=Timearrival(fl);
                    PN.DRSF=Durasi(fl);
                    PN.Harga=Harga(fl);

                    fwrite(&PN,sizeof(PN),1,GA);
                    fclose(GA);

            }

        }



            DisplayRecordOrder(&P);

    }

}

/// ===== Primitive Fungsi Pelanggan ======
void CreateListPelangan(ListPelangan *P)
{
    FirstPlg(*P)=NULL;
}
adrPlg AlocationCostumer( char* NamaPlg, char* NoHp,char* asal,char* kdasal ,char* tujuan,char* kdtujuan, char* pesawat, char* kodepesawat, Time_ tDPT, Time_ tARV, Time_ tDRS, long int tHarga)
{
    adrPlg p=(adrPlg)malloc(sizeof(Pelangan));
    if(p!=NULL){
        NamaPemesan(p)=NamaPlg;
        NomorHp(p)=NoHp;
        Asal(p)=asal;
        KodeAsal(p)=kdasal;
        Tujuan(p)=tujuan;
        KodeTujuan(p)=kdtujuan;
        Maskapai(p)=pesawat;
        KodePes(p)=kodepesawat;
        TBerangkat(p)=tDPT;
        TDatang(p)=tARV;
        TDurasi(p)=tDRS;
        TotalHarga(p)=tHarga;
        NextPlg(p)=NULL;
        FirstPnp(p)=NULL;
    }
    return p;
}
void InsertFirstPelangan(ListPelangan *P, adrPlg pl)
{
    NextPlg(pl)=FirstPlg(*P);
    FirstPlg(*P)=pl;
}
void InsertPelangan(ListPelangan *P, adrPlg pl)
{
    adrPlg Pl=FirstPlg(*P);
    if(Pl!=NULL){
        while(NextPlg(Pl)!=NULL){
            Pl=NextPlg(Pl);
        }
        NextPlg(Pl)=pl;
    }else{
        InsertFirstPelangan(P,pl);
    }
}
void InsertNodePelangan(ListPelangan *P,char* NamaPlg, char* NoHp,char* asal,char* kdasal ,char* tujuan,char* kdtujuan, char* pesawat, char* kodepesawat, Time_ tDPT, Time_ tARV, Time_ tDRS, long int tHarga)
{
    adrPlg pl=FirstPlg(*P);

    pl = AlocationCostumer(NamaPlg,NoHp,asal,kdasal,tujuan,kdtujuan,pesawat,kodepesawat,tDPT,tARV,tDRS,tHarga);
    InsertPelangan(P,pl);
}
adrPnp AlocationPassenger( char* Namapenumpang, char* Gelar, long int harga1)
{

    adrPnp pn=(adrPnp)malloc(sizeof(Penumpang));

    if(pn!=NULL){
        NamaPenumpang(pn)=Namapenumpang;
        Gelar(pn)=Gelar;
        Harga_1(pn)=harga1;
        NextPnp(pn)=NULL;

    }
    return pn;

}
void InsertPassenger(ListPelangan *P, adrPnp pn, char* NamaPlgX)
{
    adrPlg pl;
    adrPnp pN;
    pl=FirstPlg(*P);
    while(NextPlg(pl)!=NULL){
        if(strcmp(NamaPlgX,NamaPemesan(pl))==0){
            break;
        }else{
            pl=NextPlg(pl);
        }
    }
    if(pl!=NULL){
        pN=FirstPnp(pl);
        if(pN==NULL){
            pN=pn;
            NextPnp(pN)=NULL;
            FirstPnp(pl)=pN;
        }else{
            while(NextPnp(pN)!=NULL){
                    pN=NextPnp(pN);
            }
            NextPnp(pN)=pn;
            NextPnp(pn)=NULL;
        }
    }


}
void InsertNodePsg(ListPelangan *P, char* namaPLG, char* namaPNP, char* Gelar, long int HARGA1 )
{

    adrPnp pl;
    pl=AlocationPassenger(namaPNP,Gelar,HARGA1);
    InsertPassenger(P,pl,namaPLG);

}
void DisplayRecordOrder(ListPelangan *P)
{
    adrPlg pl=FirstPlg(*P);
    adrPnp pn;

    if(pl==NULL){
        printf("Tidak Ada Data Pelangan");
    }else{
        while(pl!=NULL){
            printf("\t\t\t=====================================================\n");
            printf("\t\t\t          Review Booking Tiket                 \n");
            printf("\t\t\t-----------------------------------------------------\n");
            printf("\t\t\t Nama Pemesan         : %s \n",NamaPemesan(pl));
            printf("\t\t\t Nomor Hp             : %s \n",NomorHp(pl));
            printf("\t\t\t %s ",Asal(pl));
            printf(" ( %s ) --->",KodeAsal(pl));
            printf("  %s ",Tujuan(pl));
            printf(" ( %s ) \n",KodeTujuan(pl));
            printf("\t\t\t Maskapai             : %s ",Maskapai(pl));
            printf(" ( %s )\n",KodePes(pl));
            printf("\t\t\t Berangkat Pukul      :");Display_Time(TBerangkat(pl));
            printf("\n");
            printf("\t\t\t Datang Pukul         :");Display_Time(TDatang(pl));
            printf("\n");
            printf("\t\t\t Durasi Penerbangan   :");Display_Time(TDurasi(pl));
            printf(" Hitungan Jam ");
            printf("\n");
            printf("\t\t\t Total Bayar          : %d Rupiah",TotalHarga(pl));
            pn=FirstPnp(pl);
            if(pn==NULL){
                printf("\n\n\n");
                printf("\t\t\t Tidak Ada Penumpang ");
            }else{
                int index=1;
                printf("\n\n");

                printf("\t\t\t Daftar Penumpang \n\n");
                    printf("\t\t\t %-3s  %-20s  %-5s  %-10s","No","Nama Penumpang","Title","Harga");
                    printf("\n");
                while(pn!=NULL){

                    printf("\t\t\t %-3i",index);
                    printf(" %-20s ",NamaPenumpang(pn));
                    printf(" (%-5s) ",Gelar(pn));
                    printf(" %-10i \n",Harga_1(pn));
                    index+=1;
                    pn=NextPnp(pn);
                }
            }
        pl=NextPlg(pl);
        printf("\t\t\t=====================================================");
        }
    }
}

///==================================================
///=== List Primitive TDFS ==========================
void CreateListTDFS(ListTDFS *tDFS)
{
    FirstTDFS(*tDFS)=NULL;
}
adrTDFS AlocatinTDSF(adrEdg tEdfs)
{
    adrTDFS tdfs=(adrTDFS)malloc(sizeof(TMPDFS));
    if(tdfs!=NULL){
        tmpDFS(tdfs)=tEdfs;
        NextTDFS(tdfs)=NULL;
    }
    return tdfs;
}
void InsertFirstTDFS(ListTDFS *tDFS, adrTDFS tdfs)
{
    NextTDFS(tdfs)=FirstTDFS(*tDFS);
    FirstTDFS(*tDFS)=tdfs;
}
void InsertTDFS(ListTDFS *tDFS, adrTDFS tdfs)
{
    adrTDFS tdfs2=FirstTDFS(*tDFS);
    if(tdfs2!=NULL){
        while(NextTDFS(tdfs2)!=NULL){
            tdfs2=NextTDFS(tdfs2);
        }
        NextTDFS(tdfs2)=tdfs;

    }else{
        InsertFirstTDFS(tDFS,tdfs);
    }
}
void InsertNodeTDFS(ListTDFS *tDFS, adrEdg tEdfs)
{
    adrTDFS tdfs;
    tdfs=AlocatinTDSF(tEdfs);
    InsertTDFS(tDFS,tdfs);
}
void DealokasiTDFS(adrTDFS tdfs)
{
    free(tdfs);
}



///==================================================
/// ==== LIST PENERBANGAN TRANSIT =====


void CreateListPenerbananTransit(ListPenerbanganTransit *LPT)
{
    FirstPTr(*LPT)=NULL;
}
adrPTr AlocationPT(ListKKota *kta, int no_PT, char* KasalD, char* KtujuanA)
{
    adrPTr pt=(adrPTr)malloc(sizeof(PenerbanganTransit));
    if(pt!=NULL){
        no_transit(pt)=no_PT;
        Asal(pt)=KodeKotatoNama(*kta,KasalD);
        KodeAsal(pt)=KasalD;
        Tujuan(pt)=KodeKotatoNama(*kta,KtujuanA);
        KodeTujuan(pt)=KtujuanA;
        NextPTransit(pt)=NULL;
        FirstTransit(pt)=NULL;
    }
    return pt;

}
void InsertFirstPT(ListPenerbanganTransit *LPT, adrPTr pt)
{
    NextPTransit(pt)=FirstPTr(*LPT);
    FirstPTr(*LPT)=pt;
}
void InsertPT(ListPenerbanganTransit *LPT, adrPTr pt)
{
    adrPTr ptr=FirstPTr(*LPT);
    if(ptr!=NULL){
            printf("\nMASUK INSERT LAST\n");
        while(NextPTransit(ptr)!=NULL){
            ptr=NextPTransit(ptr);
        }
        NextPTransit(ptr)=pt;
    }else{
        InsertFirstPT(LPT,pt);
    }
}
void InsertNodePT(ListPenerbanganTransit *LPT,ListKKota kta, int no_PT, char* KasalD, char* KtujuanA)
{
    adrPTr ptr;
    ptr=AlocationPT(&kta,no_PT,KasalD,KtujuanA);
    InsertPT(LPT,ptr);
}
void dealokasiPT(adrPTr pt)
{
    free(pt);
}
void DisplayPT(ListPenerbanganTransit LPT)
{
    adrPTr pt=FirstPTr(LPT);
    if(pt!=NULL){
        while(pt!=NULL){
            printf("ASAL : %s",Asal(pt));
            pt=NextPTransit(pt);
        }
    }
}

adrTrs AlocationTRS(adrEdg t_Edge, Date waktudpr)
{
    adrTrs trs=(adrTrs)malloc(sizeof(Transit));
    if(trs!=NULL){
        tempEdge(trs)=t_Edge;
        WaktuBerangkat(trs)=waktudpr;
        NextTransit(trs)=NULL;
    }
    return trs;

}
void InsertTSR(ListPenerbanganTransit *LPT, adrTrs trs,  char* KasalD, char* KtujuanA,int no)
{
    adrPTr ptr=FirstPTr(*LPT);
    boolean FoundT=false;
    if(ptr!=NULL){
        while(ptr!=NULL && !FoundT){
            if(strcmp(KasalD,KodeAsal(ptr))== 0 && strcmp(KtujuanA,KodeTujuan(ptr))== 0 && no==no_transit(ptr)){
                FoundT=true;
                break;
            }else{

                ptr=NextPTransit(ptr);


            }
        }

        if(FoundT==true){
            adrTrs trs1=FirstTransit(ptr);
             if(trs1==NULL){
                    trs1=trs;
                    NextTransit(trs1)=NULL;
                    FirstTransit(ptr)=trs1;
             }else{
                    while(NextTransit(trs1)!=NULL){

                        trs1=NextTransit(trs1);
                    }
                    NextTransit(trs1)=trs;
                    NextTransit(trs)=NULL;
             }

        }
    }
}
void InsertNodeTRS(ListPenerbanganTransit *LPT, adrEdg t_Edge, char* KasalD, char* KtujuanA, Date waktudpr,int no)
{

    adrTrs trs;
    trs=AlocationTRS(t_Edge,waktudpr);
    InsertTSR(LPT,trs,KasalD,KtujuanA,no);

}

void display_transit(ListPenerbanganTransit LPT)
{
    adrPTr ptr=FirstPTr(LPT);
    if(ptr!=NULL){
        while(ptr!=NULL){
            printf("\n\n\n");
            printf(" %i \t",no_transit(ptr));
            printf(" %s (%s) --> %s (%s) \n",Asal(ptr),KodeAsal(ptr),Tujuan(ptr),KodeTujuan(ptr));
            adrTrs trs=FirstTransit(ptr);
            adrEdg e;
            if(trs!=NULL){
                while(trs!=NULL){
                    e=tempEdge(trs);



                            printf("\n");
                            printf("\n\t\t");
                            printf(" %s ",Departure(e));
                            printf(" (%s) --> ",KodeDpr(e));
                            printf(" %s ",Arrival(e));
                            printf(" (%s) \n",KodeArv(e));
                            printf("\t\t");
                            printf("Tanggal Keberangkatan   :");Display_Date(WaktuBerangkat(trs));
                            printf("\n");
                            printf("\t\t Maskapai    : %s ",NamaPesawat(e));
                            printf("[ %s ] ",KodePesawat(e));
                            printf(" Waktu Keberangkatan :");
                            Display_Time(Timedeparture(e));

                            printf(" Waktu Kedatangan    :");
                            Display_Time(Timearrival(e));
                            printf(" Durasi Penerbangan  :");
                            Display_Time(Durasi(e));

                            printf(" Harga               : %d",Harga(e));
                            printf("\n");
                    trs=NextTransit(trs);

                }
            }


            ptr=NextPTransit(ptr);

        }
    }
}

///==================================================




/// INI JANGAN DULU JOK
void DFS(Graph G, ListKKota kta,char* asalD, char* tujuanA)
{
    adrVtx vAsal=HeadVtx(G);
    adrVtx vTujuan=vAsal;
    boolean Found;
    boolean Found2;
    Found2=SearchVertexAsal(&G,tujuanA);
    Found=SearchVertexAsal(&G,asalD);
    if(Found2 == true && Found == true){
        int vis23;
        Stack S;
        CreatStackEmpty(&S);
        adrVtx v=HeadVtx(G);
        boolean fnd=false;
        if(v!=NULL){
            while(v!=NULL && !fnd){
                if(strcmp(KAsal(v),asalD)==0){
                    fnd=true;
                }else{
                    v=NextVertex(v);
                }
            }
            int viste;
            viste=0;
            adrEdg ea=firstEdge(v);
            //==================================
            if(ea!=NULL){
                while(ea!=NULL){
                    PushS(&S,viste,ea);
                    ea=NextEdge(ea);
                }
            }
            //==================================
            Stack tS;
            CreatStackEmpty(&tS);
            ListTDFS tD;
            CreateListTDFS(&tD);
            //==================================
            int c=0;
            do
            {
                boolean fnd2=false;
                int* visit2;
                adrEdg ae;
                popS(&S,&visit2,&ae);
                adrVtx etov1=ConnectVertex(ae);
                if(strcmp(KAsal(etov1),tujuanA)==0){
                   fnd2=true;
                }
                    if(strcmp(asalD,KodeDpr(ae))== 0 || fnd2==true ){///===============
                        boolean fCek=false;
                        adrVtx vcek=HeadVtx(G);
                        boolean cek2;
                        while(vcek!=NULL && !fCek){
                            if(strcmp(KAsal(vcek),KodeArv(ae))==0){
                                fCek=true;
                                break;
                            }else{
                                vcek=NextVertex(vcek);
                            }
                        }
                        if(fCek==true){
                            adrEdg ecek=firstEdge(vcek);
                            adrVtx etovcek;
                            cek2=false;
                            if(ecek!=NULL){
                                while(ecek!=NULL){
                                    etovcek=ConnectVertex(ecek);
                                    if(strcmp(KAsal(etovcek),tujuanA)==0){
                                        cek2=true;
                                        break;
                                    }else{
                                        ecek=NextEdge(ecek);
                                    }
                                }
                            }
                        }
                        if(cek2==true || fnd2==true){
                            ///======= PUSH ke stack untuk Keberangkatan
                            ///======= Insert Ke list untuk Tujuan
                            if(strcmp(KodeDpr(ae),asalD)== 0){
                                PushS(&tS,0,ae);
                            }else if(strcmp(KodeArv(ae),tujuanA)== 0){
                               InsertNodeTDFS(&tD,ae);
                            }
                        }
                    }///============================
                    adrVtx vv2=HeadVtx(G);
                    while(vv2!=NULL){
                        if(strcmp(KAsal(etov1),KAsal(vv2))==0){
                            break;
                        }else{
                            vv2=NextVertex(vv2);
                        }
                    }
                    adrEdg e=firstEdge(vv2);
                    adrVtx etov;
                    adrVtx etovp;
                    adrEdg eprev=e;
                    if(e!=NULL){
                        while(e!=NULL){
                                etov=ConnectVertex(e);
                                etovp=ConnectVertex(eprev);
                                if(strcmp(KAsal(etov),KAsal(etov1))!=0 && visit2!=1  ){
                                            vis23=1;
                                            PushS(&S,vis23,e);
                                e=NextEdge(e);
                                }else{
                                    eprev=e;
                                    e=NextEdge(e);
                                }
                        }
                    }
            }while(!isEmptyS(S) );
            /// Lakukan Proses Perbandingan
                        //===================================
                         /// membuat list transit
                        ListPenerbanganTransit lpt;
                        CreateListPenerbananTransit(&lpt);
                        ///===============================
                        //===================================
                        int* bVisit;
                        adrEdg bEdge;
                        Date z=CreateDate(28,2,2011);
                        int no=1;
                        do
                        {
                            /// POP STACK TS
                            popS(&tS,&bVisit,&bEdge);

                            adrTDFS td=FirstTDFS(tD);
                            adrEdg be;
                            if(td!=NULL){
                                while(td!=NULL){
                                    be=tmpDFS(td);
                                    if(JLessThan(Timearrival(bEdge),Timearrival(be))==true ){
                                        InsertNodePT(&lpt,kta,no,asalD,tujuanA);
                                        InsertNodeTRS(&lpt,bEdge,asalD,tujuanA,z,no);
                                        InsertNodeTRS(&lpt,be,asalD,tujuanA,z,no);
                                        no+=1;
                                    }
                                    td=NextTDFS(td);
                                }
                            }
                        }while(!isEmptyS(tS));
                        display_transit(lpt);
                        /*ListPesantransit *Lpt;
                        int noPer;
                        printf("\nPilih Penerbangan ");scanf("%i",&noPer);

                        pesan_penerbangan_transit(&lpt,&Lpt,noPer);
                        */
        }
    }else{

        printf("SALAH SATU KOTA YANG DI CARI TIDAK DITEMUKAN");
    }
}

///============
/*
void DFS(Graph G, ListKKota kta,char* asalD, char* tujuanA)
{
    adrVtx vAsal=HeadVtx(G);
    adrVtx vTujuan=vAsal;
    boolean Found;
    boolean Found2;
    Found2=SearchVertexAsal(&G,tujuanA);
    Found=SearchVertexAsal(&G,asalD);
    if(Found2 == true && Found == true){
        int vis23;
        Stack S;
        CreatStackEmpty(&S);
        adrVtx v=HeadVtx(G);
        boolean fnd=false;
        if(v!=NULL){
            while(v!=NULL && !fnd){
                if(strcmp(KAsal(v),asalD)==0){
                    fnd=true;
                }else{
                    v=NextVertex(v);
                }
            }
            int viste;
            viste=0;
            adrEdg ea=firstEdge(v);
            //==================================
            if(ea!=NULL){
                while(ea!=NULL){
                    PushS(&S,viste,ea);
                    ea=NextEdge(ea);
                }
            }
            //==================================
            Stack tS;
            CreatStackEmpty(&tS);
            ListTDFS tD;
            CreateListTDFS(&tD);
            //==================================
            int c=0;
            do
            {
                boolean fnd2=false;
                int* visit2;
                adrEdg ae;
                popS(&S,&visit2,&ae);
                adrVtx etov1=ConnectVertex(ae);
                if(strcmp(KAsal(etov1),tujuanA)==0){
                   fnd2=true;
                }
                    if(strcmp(asalD,KodeDpr(ae))== 0 || fnd2==true ){///===============
                        boolean fCek=false;
                        adrVtx vcek=HeadVtx(G);
                        boolean cek2;
                        while(vcek!=NULL && !fCek){
                            if(strcmp(KAsal(vcek),KodeArv(ae))==0){
                                fCek=true;
                                break;
                            }else{
                                vcek=NextVertex(vcek);
                            }
                        }
                        if(fCek==true){
                            adrEdg ecek=firstEdge(vcek);
                            adrVtx etovcek;
                            cek2=false;
                            if(ecek!=NULL){
                                while(ecek!=NULL){
                                    etovcek=ConnectVertex(ecek);
                                    if(strcmp(KAsal(etovcek),tujuanA)==0){
                                        cek2=true;
                                        break;
                                    }else{
                                        ecek=NextEdge(ecek);
                                    }
                                }
                            }
                        }
                        if(cek2==true || fnd2==true){
                            ///======= PUSH ke stack untuk Keberangkatan
                            ///======= Insert Ke list untuk Tujuan
                            if(strcmp(KodeDpr(ae),asalD)== 0){
                                PushS(&tS,0,ae);
                            }else if(strcmp(KodeArv(ae),tujuanA)== 0){
                               InsertNodeTDFS(&tD,ae);
                            }
                        }
                    }///============================
                    adrVtx vv2=HeadVtx(G);
                    while(vv2!=NULL){
                        if(strcmp(KAsal(etov1),KAsal(vv2))==0){
                            break;
                        }else{
                            vv2=NextVertex(vv2);
                        }
                    }
                    adrEdg e=firstEdge(vv2);
                    adrVtx etov;
                    adrVtx etovp;
                    adrEdg eprev=e;
                    if(e!=NULL){
                        while(e!=NULL){
                                etov=ConnectVertex(e);
                                etovp=ConnectVertex(eprev);
                                if(strcmp(KAsal(etov),KAsal(etov1))!=0 && visit2!=1  ){
                                            vis23=1;
                                            PushS(&S,vis23,e);
                                e=NextEdge(e);
                                }else{
                                    eprev=e;
                                    e=NextEdge(e);
                                }
                        }
                    }
            }while(!isEmptyS(S) );
            /// Lakukan Proses Perbandingan
                        //===================================
                         /// membuat list transit
                        ListPenerbanganTransit lpt;
                        CreateListPenerbananTransit(&lpt);
                        ///===============================
                        //===================================
                        int* bVisit;
                        adrEdg bEdge;
                        Date z=CreateDate(28,2,2011);
                        int no=1;
                        do
                        {
                            /// POP STACK TS
                            popS(&tS,&bVisit,&bEdge);

                            adrTDFS td=FirstTDFS(tD);
                            adrEdg be;
                            if(td!=NULL){
                                while(td!=NULL){
                                    be=tmpDFS(td);
                                    if(JLessThan(Timearrival(bEdge),Timearrival(be))==true ){
                                        InsertNodePT(&lpt,kta,no,asalD,tujuanA);
                                        InsertNodeTRS(&lpt,bEdge,asalD,tujuanA,z,no);
                                        InsertNodeTRS(&lpt,be,asalD,tujuanA,z,no);
                                        no+=1;
                                    }
                                    td=NextTDFS(td);
                                }
                            }
                        }while(!isEmptyS(tS));
                        display_transit(lpt);
                        /*ListPesantransit *Lpt;
                        int noPer;
                        printf("\nPilih Penerbangan ");scanf("%i",&noPer);

                        pesan_penerbangan_transit(&lpt,&Lpt,noPer);

        }
    }else{

        printf("SALAH SATU KOTA YANG DI CARI TIDAK DITEMUKAN");
    }
}


void pesan_penerbangan_transit(ListPenerbanganTransit *LPT, ListPesantransit *LPeT, int no)
{
    adrPTr ptr=FirstPTr(*LPT);
    CreateListTPNP(&LPeT);
    boolean ftrs=false;
    if(ptr!=NULL){
        while(ptr!=NULL && !ftrs){
            if(no==no_transit(ptr)){
                ftrs=true;
                break;
            }else{
                ptr=NextPTransit(ptr);
            }
        }
        if(ftrs==true){
        printf("NO : %i",no_transit(ptr));

        /// INSERT PELANGAN
        char namapemesanX[30];
        char nohpX[13];
        char namapenumpangX[30];
        char GelarX[3];
        char namaPemesanX2[30];

        char namaPemesanX3[30];
        long int bayar;
        int i;
        int banyak;
        printf("\n\n\n");
        fflush(stdin);
        printf("Nama Pemesan : ");gets(namapemesanX);
        printf("No HP Pemesan : ");gets(nohpX);
        printf("Pesan Berapa Tiket :");scanf("%d",&banyak);



        insertNODEPTRANSIT(&LPeT,namapemesanX,nohpX);
        /// INPUTKAN NAMA PENUMPANNG


         for(i=1; i<=banyak ; i++){
            printf("Nama Penumpang ke %i : ",i);fflush(stdin);gets(namapenumpangX);
            printf("Gelar Penumpang ke %i : ",i);fflush(stdin);gets(GelarX);
            strcpy(namaPemesanX2,namapemesanX);
            InsertNODEPTNT(&LPeT,namapenumpangX,GelarX,namaPemesanX2);


        }

        adrTrs trs=FirstTransit(ptr);
        adrEdg e;
        Date WaktuT;
            if(trs!=NULL){
                while(trs!=NULL){
                    e=tempEdge(trs);
                    WaktuT=WaktuBerangkat(trs);
                    strcpy(namaPemesanX3,namaPemesanX2);
                    InsertNODEJP(&LPeT,e,WaktuT,namaPemesanX3);
                    trs=NextTransit(trs);
                    ///============================
                }
            }


        }




    }

}


*/
/*

/// LIST PENUMPANG TRANSIT
///=================================================================
void CreateListTPNP (ListPesantransit *LPeT)
{
    FirstPenTransit(*LPeT)=NULL;
}
adrPeTrs AlocationPemesanT (char* nama_ps, char* no_ps)
{
    adrPeTrs ptrs=(adrPeTrs)malloc(sizeof(PesanTransit));
    if(ptrs!=NULL){

        Nama_Pemesan(ptrs)=nama_ps;
        No_HANDPHONE(ptrs)=no_ps;
        Jadwal_FIGHT(ptrs)=NULL;
        penumpang_T(ptrs)=NULL;
        NextPeTRS(ptrs)=NULL;
    }
    return ptrs;
}
void insertFirstPTRANSIT(ListPesantransit *LPeT, adrPeTrs ptrs)
{
    NextPeTRS(ptrs)=FirstPenTransit(*LPeT);
    FirstPenTransit(*LPeT)=ptrs;
}
void insertPTRANSIT(ListPesantransit *LPeT, adrPeTrs ptrs)
{

    adrPeTrs ptr=FirstPenTransit(*LPeT);
    if(ptr!=NULL){
        while(NextPeTRS(ptr)!=NULL){
            ptr=NextPeTRS(ptr);
        }
        NextPeTRS(ptr)=ptrs;
    }else{

        insertFirstPTRANSIT(LPeT,ptrs);
    }
}
void insertNODEPTRANSIT(ListPesantransit *LPeT, char* nama, char* no_hp)
{
    adrPeTrs ptrs;
    ptrs=AlocationPemesanT(nama,no_hp);
    insertPTRANSIT(LPeT,ptrs);
}

adrJP AlokasiTrs(char* dpt, char* kodedpt, char* arv, char* kodearv, char* nama_MP, char* kode_MP, Time_ Tdpr, Time_ Tarv, Time_ Tdrs, long int harga, Date waktu)
{
    printf("MASUK ALOKASI");
    adrJP jp=(adrJP)malloc(sizeof(JPenerbangan));
    if(jp!=NULL){

        DepartureJP(jp)=dpt;
        KodeDprJP(jp)=kodedpt;
        ArrivalJP(jp)=arv;
        KodeArvJP(jp)=kodearv;
        NamaPesawatJP(jp)=nama_MP;
        KodePesawatJP(jp)=kode_MP;
        TimedepartureJP(jp)=Tdpr;
        TimearrivalJP(jp)=Tarv;
        DurasiJP(jp)=Tdrs;
        HargaJP(jp)=harga;
        WaktuBerangkatJP(jp)=waktu;
        NextJP(jp)=NULL;

    }

 return jp;
    printf("MASUK ALOKASI IF");

}
void InsertJP(ListPesantransit *LPet, adrJP jp ,char* nama_pes)
{
    adrPeTrs pt=FirstPenTransit(*LPet);
    boolean fjp=false;
    if(pt!=NULL){
        while(pt!=NULL && !fjp){
            if(strcmp(Nama_Pemesan(pt),nama_pes)==0){
                fjp=true;
                break;
            }else{
                pt=NextPeTRS(pt);
            }
        }

        if(fjp==true){
            adrJP jp1=Jadwal_FIGHT(pt);
            if(jp1!=NULL){
                while(NextJP(jp1)!=NULL){
                    jp1=NextJP(jp1);
                }
                NextJP(jp1)=jp;
            }else{

                jp1=jp;
                NextJP(jp1)=NULL;
                Jadwal_FIGHT(pt)=jp1;
            }
        }



    }
}
void InsertNODEJP(ListPesantransit *LPet,adrEdg jpe, Date waktu ,char* nama)
{
    adrJP jp;
    jp = AlokasiTrs()
    InsertJP(LPet,jp,nama);
}

adrTPNT AlokasiTPNT(char* nama_Pe, char* gelar_pe)
{
    adrTPNT tpnt=(adrTPNT)malloc(sizeof(PenumpangT));
    if(tpnt!=NULL){
        Nama_Penumpang(tpnt)=nama_Pe;
        Gelar_Penumpang(tpnt)=gelar_pe;
        NextTPNT(tpnt)=NULL;
    }
    return tpnt;
}
void InsertPTNT(ListPesantransit *LPet, adrTPNT tptnt, char* nama_pes)
{

    adrPeTrs pt=FirstPenTransit(*LPet);
    boolean fjp=false;
    if(pt!=NULL){
        while(pt!=NULL && !fjp){
            if(strcmp(Nama_Pemesan(pt),nama_pes)==0){
                fjp=true;
                break;
            }else{
                pt=NextPeTRS(pt);
            }
        }

        if(fjp==true){
            adrTPNT tpnt1=penumpang_T(pt);
            if(tpnt1!=NULL){
                while(NextTPNT(tpnt1)!=NULL){
                    tpnt1=NextTPNT(tpnt1);
                }
                NextTPNT(tpnt1)=tptnt;
            }else{

                tpnt1=tptnt;
                NextTPNT(tpnt1)=NULL;
                Jadwal_FIGHT(pt)=tptnt;
            }
        }
    }
}
void InsertNODEPTNT(ListPesantransit *LPet, char* nama_pen, char* gelar_pen,char* nama_pes)
{
    adrTPNT tpnt;
    tpnt=AlokasiTPNT(nama_pen,gelar_pen);
    InsertPTNT(LPet,tpnt,nama_pes);
}

*/
