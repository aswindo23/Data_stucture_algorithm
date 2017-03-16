#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "time.c"
#include "define.h"
#include "boolean.h"
#include <conio.h>
#include "date.c"


typedef struct kKOta {
    char Kkasal[3];
    char KotaAsal[15];
}DataKota;

typedef struct tPLG {
    char Nama_pelangan[30];
    char No_HandP[13];
    int Jumlah;
}PELANGGAN;

typedef struct tPNP {
    char Nama_penumpang[30];
    char Nama_Pembeli[30];
    char Asal[30];
    char Tujuan[30];
    char Nama_Maskapai[30];
    char kode_Maskapai[7];
    Time_ DPTF;
    Time_ ARVF;
    Time_ DRSF;
    long int Harga;

}PENUMPANG;

typedef struct tVertex *adrVtx;
typedef struct tEdge *adrEdg;
typedef struct tKodeKota *adrKKota;
///==============================================
typedef struct tVertex {
    char* KAsal;
    adrVtx NextVertex;
    adrEdg firstEdge;
}Vertex;/// Recod Untuk Node Vertex

typedef struct {
    adrVtx HeadVtx;
}Graph;/// List Untuk Node Vertex


typedef struct tEdge {
    char* Departure;
    char* KodeDpr;
    char* Arrival;
    char* KodeArv;
    char* NamaPesawat;
    char* KodePesawat;
    Time_ Timedeparture;
    Time_ Timearrival;
    Time_ Durasi;
    long int Harga;
    adrEdg NextEdge;
    adrVtx ConnectVertex; /// Menyambungkan Ke Vertex
}Edge;/// Recod Untuk Node Edege
///===================================================
typedef struct tKodeKota {
    char* Kode;
    char* NamaKota;
    adrKKota NextKKota;
}KKota;/// Recod Untuk Node Kode Kota
typedef struct {
    adrKKota firstKKota;
}ListKKota;/// List Untuk Node KOde Kota

///======================================================
typedef struct tInfoPenerabangan *adrFlight;
typedef struct tInfoPenerabangan {
    int No_Jadwal;
    char* Departure;
    char* KodeDpr;
    char* Arrival;
    char* KodeArv;
    char* NamaPesawat;
    char* KodePesawat;
    Time_ Timedeparture;
    Time_ Timearrival;
    Time_ Durasi;
    long int Harga;
    adrFlight NextFlight;
}Flight;
typedef struct {
    adrFlight firstFlight;
}ListFlight;

///=================================

typedef struct tPenumpang *adrPnp;
typedef struct tListPelangan *adrPlg;
typedef struct tListPelangan
{
    char* NamaPemesan;
    char* NomorHp;
    char* Asal;
    char* KodeAsal;
    char* Tujuan;
    char* KodeTujuan;
    char* Maskapai;
    char* KodePes;
    Time_ TBerangkat;
    Time_ TDatang;
    Time_ TDurasi;
    long int TotalHarga;
    adrPlg NextPlg;
    adrPnp FirstPnp;
}Pelangan;

typedef struct {
    adrPlg FirstPlg;
}ListPelangan;

typedef struct tPenumpang {
    char* NamaPenumpang;
    char* Gelar;
    long int Harga_1;
    adrPnp NextPnp;
}Penumpang;

typedef struct tElstack *adrStk;
typedef struct tElstack {

    int visit;
    adrEdg tmpEdge;
    adrStk NextS;
}Elstk;
typedef struct {
    adrStk Top;
}Stack;

typedef struct tPenerbanganTransit *adrPTr;
typedef struct tTransit *adrTrs;
typedef struct tPenerbanganTransit {
    int no_transit;
    char* Asal;
    char* KodeAsal;
    char* Tujuan;
    char* KodeTujuan;
    adrPTr NextPTransit;
    adrTrs FirstTransit;
}PenerbanganTransit;

typedef struct {
    adrPTr FirstPTr;
}ListPenerbanganTransit;


typedef struct tTransit {
    adrEdg tempEdge;
    Date WaktuBerangkat;
    adrTrs NextTransit;
}Transit;


///==== LIST UNTUK PROSES DFS ====

typedef struct tTMPDSF *adrTDFS;
typedef struct tTMPDSF {
    adrEdg tmpDFS;
    adrTDFS NextTDFS;
}TMPDFS;
typedef struct {
    adrTDFS FirstTDFS;
}ListTDFS;
///==================================================
typedef struct tPenTransit *adrPeTrs;
typedef struct tJadwalP *adrJP;
typedef struct tPenumpangT *adrTPNT;
typedef struct tPenTransit {
    char* Nama_Pemesan;
    char* No_HANDPHONE;
    adrJP Jadwal_FIGHT;
    adrTPNT penumpang_T;
    adrPeTrs NextPeTRS;
}PesanTransit;
typedef struct {
    adrPeTrs FirstPenTransit;
}ListPesantransit;



typedef struct tJadwalP {
    char* DepartureJP;
    char* KodeDprJP;
    char* ArrivalJP;
    char* KodeArvJP;
    char* NamaPesawatJP;
    char* KodePesawatJP;
    Time_ TimedepartureJP;
    Time_ TimearrivalJP;
    Time_ DurasiJP;
    long int HargaJP;
    Date WaktuBerangkatJP;
    adrJP NextJP;
}JPenerbangan;


typedef struct tPenumpangT {
    char* Nama_Penumpang;
    char* Gelar_Penumpang;
    adrTPNT NextTPNT;
}PenumpangT;

typedef struct tVisited *adrVstd;
typedef struct tVisited {
    int visited;
    adrVtx cVisited;
    adrVstd NextVstd;

}Visited;

typedef struct {

    adrVstd FirstVstd;
}ListVstd;

void CreateListVisited(ListVstd *LVSTD);
adrVstd AlocationVisited(int visited, adrVtx cvstd);
void insertFirstVisited(ListVstd *LVSTD, adrVstd vstd);
void insertVisited(ListVstd *LVSTD, adrVstd vstd);
void insertNodeVisited (ListVstd *LVSTD,int visited, adrVtx cvstd );
void dealokasiVisited(adrVstd vstd);


///---------------------------------------------------
void CreateListTPNP (ListPesantransit *LPeT);
adrPeTrs AlocationPemesanT (char* nama_ps, char* no_ps);
void insertFirstPTRANSIT(ListPesantransit *LPeT, adrPeTrs ptrs);
void insertPTRANSIT(ListPesantransit *LPeT, adrPeTrs ptrs);
void insertNODEPTRANSIT(ListPesantransit *LPeT, char* nama, char* no_hp);
adrJP AlokasiTrs(char* dpt, char* kodedpt, char* arv, char* kodearv, char* nama_MP, char* kode_MP, Time_ Tdpr, Time_ Tarv, Time_ Tdrs, long int harga, Date waktu);
void InsertJP(ListPesantransit *LPet, adrJP jp,char* nama_pes);
void InsertNODEJP(ListPesantransit *LPet,adrEdg jpe, Date waktu ,char* nama);
adrTPNT AlokasiTPNT(char* nama_Pe, char* gelar_pe);
void InsertPTNT(ListPesantransit *LPet, adrTPNT tptnt,char* nama_pes);
void InsertNODEPTNT(ListPesantransit *LPet, char* nama_pen, char* gelar_pen,char* nama_pes);
void pesan_penerbangan_transit(ListPenerbanganTransit *LPT, ListPesantransit *LPeT, int no);
///===================================================
///===== Primitive untuk Lits TMP DFS ===============
void CreateListTDFS(ListTDFS *tDFS);
adrTDFS AlocatinTDSF(adrEdg tEdfs);
void InsertFirstTDFS(ListTDFS *tDFS, adrTDFS tdfs);
void InsertTDFS(ListTDFS *tDFS, adrTDFS tdfs);
void InsertNodeTDFS(ListTDFS *tDFS, adrEdg tEdfs);
void DealokasiTDFS(adrTDFS tdfs);
///--------------------------------------------------------
///===== Primitive List Penerbangan Transit =====
void CreateListPenerbananTransit(ListPenerbanganTransit *LPT);
adrPTr AlocationPT(ListKKota *kta,int no_PT, char* KasalD, char* KtujuanA);
void InsertFirstPT(ListPenerbanganTransit *LPT, adrPTr pt);
void InsertPT(ListPenerbanganTransit *LPT, adrPTr pt);
void InsertNodePT(ListPenerbanganTransit *LPT, ListKKota kta,int no_PT, char* KasalD, char* KtujuanA);
void dealokasiPT(adrPTr pt);
void DisplayPT(ListPenerbanganTransit LPT);
adrTrs AlocationTRS(adrEdg t_Edge, Date waktudpr);
void InsertTSR(ListPenerbanganTransit *LPT, adrTrs trs, char* KasalD, char* KtujuanA,int no);
void InsertNodeTRS(ListPenerbanganTransit *LPT, adrEdg t_Edge, char* KasalD, char* KtujuanA, Date waktudpr,int no);
void display_transit(ListPenerbanganTransit LPT);
///===== Primitive Stack ================
void CreatStackEmpty(Stack *S);
adrStk AlocatianS(int Visit, adrEdg tmPedge);
void DealokasiS(adrStk s);
boolean isEmptyS(Stack S);
void PushAdress_S(Stack *S, adrStk s);
void PushS(Stack *S, int Visit,adrEdg tmPedge);
void popS(Stack *S, int *Visit, adrEdg *tmPedge);
///===== Primtive Vertex ================
void CreateListVertex(Graph *G);
adrVtx AlocationVtx( char* Kota );
void InsertNodeVtx(Graph *G, char* Kota);
void insertFirstVtx( Graph *G,adrVtx V);
void insertVtx(Graph *G, adrVtx V);
void DealokasiVtx(adrVtx G);
void DisplayVertex(Graph G);
void DisplayVertextoEdge(Graph G);
boolean SearchVertexAsal(Graph *G, char* kota);
///====== Primitive Edge ======
adrEdg AlocationEdge(ListKKota *kta, char* dpt, char* arv, char* nmMaskapai, char* KDMasakapai, Time_ Tdpt, Time_ Tarv, Time_ Tdrs, long int harga);
void InsertEdge(Graph *Vt, adrEdg Ie,char* KOTA);
void ConnettoVertex(Graph G, char* kotaA, char* kotaT);
void DisplayGraph(Graph G);
///=================================
int Input_data();
void LihatData();
int CreateFile();
void DV(Graph G);
void CrealeFIlE(FILE *FVertex, int n);
void FiletoListVertex(FILE *FVertex);
///====== Kode Kota ===========
void CreateListKKota(ListKKota *Kta);
adrKKota AlocationKKota(char Kkota[3], char* NamaKota);
void insertFirstKKota(ListKKota *Kta, adrKKota KK);
void insertKKota(ListKKota *Kta, adrKKota KK);
void insertNodeKKota (ListKKota *kta, char* KKode, char* Kota);
void dealokasiKKota(adrKKota Kta);
char *KodeKota(ListKKota Kta, char *namaKota);
char *KodeKotatoNama(ListKKota Kta, char *kodeKota);
void DisplayKKota(ListKKota Kta);
///====== Primitive List Penumpang ======
void CreateListFlight(ListFlight *LF);
adrFlight AlocationinfoFlight(ListKKota *kta,int no_jadwal, char* DepartureX, char* ArrivalX, char* NamaPesawatX , char*KodePesawatX, Time_ DPt, Time_ ARv, Time_ DUrasi, long int HargaX);
void InsertFisrtFlight(ListFlight *LF, adrFlight lf);
void InsertFlight(ListFlight *LF, adrFlight lf);
void DealokasiFlight(adrFlight lf);
void DisplayFlight(ListFlight LF);
void InsertADD(ListFlight *LF, ListKKota kta,int no_jadwal ,char* DepartureX, char* ArrivalX, char* NamaPesawatX , char*KodePesawatX, Time_ DPt, Time_ ARv, Time_ DUrasi, long int HargaX);
/// ===== Fungsi dan Prosedure Penerbangan ====
void Penerbangan_langsung(Graph *G,ListKKota kta,ListPelangan *PL,char* KoDPR, char* KoARV);
void Pesan_Penerbangan_langsung( ListFlight *LF, ListPelangan *PL ,int no_pesanan);
void DFS(Graph G,ListKKota kta ,char* asalD, char* tujuanA);
/// ==== Primitive Informasi Pelanggan ====
void CreateListPelangan(ListPelangan *P);
adrPlg AlocationCostumer( char* NamaPlg, char* NoHp,char* asal,char* kdasal ,char* tujuan,char* kdtujuan, char* pesawat, char* kodepesawat, Time_ tDPT, Time_ tARV, Time_ tDRS, long int tHarga);
void InsertFirstPelangan(ListPelangan *P, adrPlg pl);
void InsertPelangan(ListPelangan *P, adrPlg pl);
adrPnp AlocationPassenger( char* Namapenumpang, char* Gelar,long int harga1);
void InsertPassenger(ListPelangan *P, adrPnp pn,char* NamaPlgX);
void DisplayRecordOrder(ListPelangan *P);
void InsertNodePsg(ListPelangan *P,char* namaPLG,char* namaPNP, char* Gelar, long int HARGA1 );
void InsertNodePelangan(ListPelangan *P,char* NamaPlg, char* NoHp,char* asal,char* kdasal ,char* tujuan,char* kdtujuan, char* pesawat, char* kodepesawat, Time_ tDPT, Time_ tARV, Time_ tDRS, long int tHarga);


#endif // HEADER_H_INCLUDED
