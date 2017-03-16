#include <stdio.h>
#include <stdlib.h>
#include "header.c"
#include <conio.h>

int main(){
    //system("01");
    int m;
    //Graph *G;
    char* pindah;
    printf("Masukan Menu");scanf("%2i",&m);
    switch (m){
        case 1 :Input_data();break;
        case 2 :LihatData();break;
        case 3 :CreateFile();break;
    }



    //DisplayVertex(G);
/*
    //ListVtx Vt;
    //CreateListVertex(&Vt);
    //adrVtx vi = AlocationVtx(pindah);
    //insertVtx(&Vt,vi);
    //DisplayVertex(Vt);
   // ListVtx Vt;
   // DisplayVertex(Vt);
    //printf("Data Yang Di Print");FiletoListVertex(FV);



    /*
    Time_ t,tt,ttt;
    ListArv Larv;
    ListDpt LDpt;
    t=CreateTime(12,45,0);
    tt=CreateTime(18,50,0);
    ttt=CreateTime(19,50,0);


    CreateListArv(&Larv);
    adrArv arv1 = AlocationArv(t);
    adrArv arv2 = AlocationArv(tt);
    adrArv arv3 = AlocationArv(ttt);
    insertFirstTimeArv(&Larv,arv1);
    insertTimeArv(&Larv,arv2);
    insertTimeArv(&Larv,arv3);
    DisplayTimeArv(Larv);

    CreateListDpt(&LDpt);
    adrDpt dpt1 = AlocationDpt(t);
    adrDpt dpt2 = AlocationDpt(tt);
    adrDpt dpt3 = AlocationDpt(ttt);
    insertFirstTimeDpt(&LDpt,dpt1);
    insertTimeDpt(&LDpt,dpt2);
    insertTimeDpt(&LDpt,dpt3);
    DisplayTimeDpt(LDpt);


    Graph G;
    CreateListVertex(&G);
    adrVtx vt1 = AlocationVtx("BTJ");
    adrVtx vt2 = AlocationVtx("KNO");
    adrVtx vt3 = AlocationVtx("PDG");
    adrVtx vt4 = AlocationVtx("PKU");
    adrVtx vt5 = AlocationVtx("BKS");
    adrVtx vt6 = AlocationVtx("DJB");
    adrVtx vt7 = AlocationVtx("PLM");
    adrVtx vt8 = AlocationVtx("TKG");


    insertVtx(&G,vt1);
    insertVtx(&G,vt2);
    insertVtx(&G,vt3);
    insertVtx(&G,vt4);
    insertVtx(&G,vt5);
    insertVtx(&G,vt6);
    insertVtx(&G,vt7);
    insertVtx(&G,vt8);



    DisplayVertex(G);




    ListKKota kta;
    CreateListKKota(&kta);
    adrKKota kkt1= AlocationKKota("BTJ","Banda Aceh");
    adrKKota kkt2= AlocationKKota("KNO","Medan");
    adrKKota kkt3= AlocationKKota("PDG","Padang");
    adrKKota kkt4= AlocationKKota("PKU","Pekanbaru");
    adrKKota kkt5= AlocationKKota("BKS","Bengkulu");
    adrKKota kkt6= AlocationKKota("DJB","Jambi");
    adrKKota kkt7= AlocationKKota("PLM","Palembang");
    adrKKota kkt8= AlocationKKota("TKG","Lampung");
    insertFirstKKota(&kta,kkt1);
    insertKKota(&kta,kkt2);
    insertKKota(&kta,kkt3);
    insertKKota(&kta,kkt4);
    insertKKota(&kta,kkt5);
    insertKKota(&kta,kkt6);
    insertKKota(&kta,kkt7);
    insertKKota(&kta,kkt8);
    //DisplayKKota(kta);

    adrEdg egg1= AlocationEdge(&kta,"Banda Aceh","Padang"); /// BTJ
    adrEdg egg2= AlocationEdge(&kta,"Banda Aceh","Pekanbaru"); /// BTJ
    adrEdg egg3= AlocationEdge(&kta,"Medan","Padang"); ///KNO
    adrEdg egg4= AlocationEdge(&kta,"Medan","Pekanbaru"); /// KNO
    adrEdg egg5= AlocationEdge(&kta,"Medan","Jambi");///KNO
    adrEdg egg6= AlocationEdge(&kta,"Padang","Banda Aceh"); /// BTJ
    adrEdg egg7= AlocationEdge(&kta,"Padang","Medan");///KNO
    adrEdg egg8= AlocationEdge(&kta,"Padang","Jambi");///PDG
    adrEdg egg9= AlocationEdge(&kta,"Padang","Bengkulu");///PDG
    adrEdg egg10= AlocationEdge(&kta,"Padang","Lampung");///PDG
    adrEdg egg11= AlocationEdge(&kta,"Padang","Palembang");///PDG
    InsertEdge(&G,egg1,"BTJ");
    InsertEdge(&G,egg2,"BTJ");
    InsertEdge(&G,egg6,"BTJ");
    InsertEdge(&G,egg3,"KNO");
    InsertEdge(&G,egg4,"KNO");
    InsertEdge(&G,egg5,"KNO");
    InsertEdge(&G,egg7,"KNO");
    InsertEdge(&G,egg8,"PDG");
    InsertEdge(&G,egg9,"PDG");
    InsertEdge(&G,egg10,"PDG");
    InsertEdge(&G,egg11,"PDG");

    Time_ t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11;
    ///  Banda Aceh Padang
    t1=CreateTime(07,00,00);/// DPT
    t2=CreateTime(15,00,00);/// DPT
    t3=CreateTime(01,50,00);///Durasi
    t4=CreateTime(8,50,00);///ARV
    t5=CreateTime(16,50,0);///ARV
    /// Banda Aceh Pekanbaru
    t6=CreateTime(8,15,0);
    t7=CreateTime(18,00,0);
    t8=CreateTime(2,00,00);///Durasi
    t9=CreateTime(10,15,0);
    t10=CreateTime(20,00,0);
    t11=CreateTime(12,45,0);

    adrIE iee1= AlocationIE(&kta,"Banda Aceh","Padang","Garuda","GA-123",t1,t4,t3,1000000);
    adrIE iee2= AlocationIE(&kta,"Banda Aceh","Padang","Lion","JT-137",t2,t5,t3,1000000);
    adrIE iee3= AlocationIE(&kta,"Banda Aceh","Pekanbaru","Garuda","GA-134",t6,t9,t8,1100000);
    adrIE iee4= AlocationIE(&kta,"Banda Aceh","Pekanbaru","Garuda","GA-123",t7,t10,t8,1100000);
    adrIE iee5= AlocationIE(&kta,"Medan","Padang","Garuda","GA-123",t7,t10,t8,1100000);
    adrIE iee6= AlocationIE(&kta,"Medan","Padang","Garuda","GA-123",t7,t10,t8,1100000);
    InsertInfoEdge(&G,iee1,"BTJ","PDG","BTJ");
    InsertInfoEdge(&G,iee2,"BTJ","PDG","BTJ");
    InsertInfoEdge(&G,iee3,"BTJ","PKU","BTJ");
    InsertInfoEdge(&G,iee4,"BTJ","PKU","BTJ");
    InsertInfoEdge(&G,iee5,"KNO","PDG","KNO");
    InsertInfoEdge(&G,iee6,"KNO","PDG","KNO");
DisplayVertextoEdge(G);

ConnettoVertex(G,"BTJ","PDG");
ConnettoVertex(G,"BTJ","PKU");
ConnettoVertex(G,"KNO","PDG");
ConnettoVertex(G,"KNO","DJB");


//adrIE AlocationIE(char* DepartureX, char* ArrivalX, char* NamaPesawatX , char*KodePesawatX, Time_ DPt, Time_ ARv, Time_ DUrasi, long int HargaX)
    /*
    ListIE IE;
    CreateListInfotypeEdge(&IE);
    adrIE nb1= AlocationIE(&kta,"Padang","Banda Aceh","Garuda","GA-167",t,tt,tt,1000000);
    insertFirstIE(&IE,nb1);
    Display_infoType(IE);


    char *Kota;
    Kota=KodeKota(kta,"Padang");
    printf("\n\n%s",Kota);

    ListEdge EG;
    CreateListEdge(&EG);
    adrEdg eg1 = AlocationEdge("Padang","Banda Aceh");
    InsertFirstEdge(&EG,eg1);
    Display_Edge(EG);
*/
    /*
    Time_ t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11;
    ///  Banda Aceh Padang
    t1=CreateTime(07,00,00);/// DPT
    t2=CreateTime(15,00,00);/// DPT
    t3=CreateTime(01,50,00);///Durasi
    t4=CreateTime(8,50,00);///ARV
    t5=CreateTime(16,50,0);///ARV
    /// Banda Aceh Pekanbaru
    t6=CreateTime(8,15,0);
    t7=CreateTime(18,00,0);
    t8=CreateTime(2,00,00);///Durasi
    t9=CreateTime(10,15,0);
    t10=CreateTime(20,00,0);
    t11=CreateTime(12,45,0);

printf("\n======================================================\n");
    ListEdge EG;
    CreateListEdge(&EG);
    adrEdg eg1 = AlocationEdge(&kta,"Banda Aceh","Padang");
    adrEdg eg2 = AlocationEdge(&kta,"Banda Aceh","Pekanbaru");
    InsertFirstEdge(&EG,eg1);
    InsertEdge(&EG,eg2);
    adrIE iee1= AlocationIE(&kta,"Banda Aceh","Padang","Garuda","GA-123",t1,t4,t3,1000000);
    adrIE iee2= AlocationIE(&kta,"Banda Aceh","Padang","Lion","JT-137",t2,t5,t3,1000000);
    adrIE iee3= AlocationIE(&kta,"Banda Aceh","Pekanbaru","Garuda","GA-134",t6,t9,t8,1100000);
    adrIE iee4= AlocationIE(&kta,"Banda Aceh","Pekanbaru","Garuda","GA-123",t7,t10,t8,1100000);
    InsertInfoEdge(&EG,iee1,"BTJ","PDG");
    InsertInfoEdge(&EG,iee2,"BTJ","PDG");
    InsertInfoEdge(&EG,iee3,"BTJ","PKU");
    InsertInfoEdge(&EG,iee4,"BTJ","PKU");
    Display_InfoEdge(EG);

    */
    return 0;

}

