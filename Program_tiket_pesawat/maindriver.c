#include "header.c"

void Attivasi();
void ConnectLocation();
void DisplaY_graph();
void Penerbangan_LIVE();
void Lihat_Penerbangan_transit();
Graph G;
ListKKota kta;
ListPelangan P;

void Pelangan_daftar();
void Pelangan_daftar()
{
    DisplayRecordOrder(&P);
}


void Attivasi(){

    CreateListKKota(&kta);
    adrKKota kkt1= AlocationKKota("BTJ","Banda Aceh");
    adrKKota kkt2= AlocationKKota("KNO","Medan");
    adrKKota kkt3= AlocationKKota("PDG","Padang");
    adrKKota kkt4= AlocationKKota("PKU","Pekanbaru");
    adrKKota kkt5= AlocationKKota("BKS","Bengkulu");
    adrKKota kkt6= AlocationKKota("DJB","Jambi");
    adrKKota kkt7= AlocationKKota("PLM","Palembang");
    adrKKota kkt8= AlocationKKota("TKG","Lampung");

    insertKKota(&kta,kkt1);
    insertKKota(&kta,kkt2);
    insertKKota(&kta,kkt3);
    insertKKota(&kta,kkt4);
    insertKKota(&kta,kkt5);
    insertKKota(&kta,kkt6);
    insertKKota(&kta,kkt7);
    insertKKota(&kta,kkt8);
    //insertNodeKKota(&kta,"CKG","Cengkaren");
    //DisplayKKota(kta);



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
    //DisplayVertex(G);
    Time_ t[1000];
    /// 1. Banda Aceh - Padang
    t[1]=CreateTime(7,00,00);///DPT
    t[2]=CreateTime(15,00,00);///DPT
    t[3]=CreateTime(8,50,00);///ARV
    t[4]=CreateTime(16,00,00);///ARV
    t[5]=CreateTime(1,50,00);///Durasi
    /// 2. Banda Aceh - Pekanbaru
    t[6]=CreateTime(8,15,00);///DPT
    t[7]=CreateTime(18,00,00);///DPT
    t[8]=CreateTime(10,15,00);///ARV
    t[9]=CreateTime(20,00,00);///ARV
    t[10]=CreateTime(2,00,00);///Durasi
    /// 3. Medan - Padang
    t[11]=CreateTime(5,00,00);///DPT
    t[12]=CreateTime(13,15,00);///DPT
    t[13]=CreateTime(6,15,00);///ARV
    t[14]=CreateTime(14,30,00);///ARV
    t[15]=CreateTime(1,15,00);///Durasi
    /// 4. Medan - Pekanbaru
    t[16]=CreateTime(6,00,00);///DPT
    t[17]=CreateTime(14,15,00);///DPT
    t[18]=CreateTime(7,15,00);///ARV
    t[19]=CreateTime(15,15,00);///ARV
    t[20]=CreateTime(1,00,00);///Durasi
    /// 5. Medan - Jambi
    t[21]=CreateTime(7,00,00);///DPT
    t[22]=CreateTime(15,45,00);///DPT
    t[23]=CreateTime(8,45,00);///ARV
    t[24]=CreateTime(17,30,00);///ARV
    t[25]=CreateTime(1,45,00);///Durasi
    /// 6. Padang - Banda Aceh
    t[26]=CreateTime(6,30,00);///DPT
    t[27]=CreateTime(12,00,00);///DPT
    t[28]=CreateTime(8,20,00);///ARV
    t[29]=CreateTime(13,50,00);///ARV
    t[30]=CreateTime(1,50,00);///Durasi
     /// 7. Padang - Medan
    t[31]=CreateTime(7,15,00);///DPT
    t[32]=CreateTime(15,45,00);///DPT
    t[33]=CreateTime(8,30,00);///ARV
    t[34]=CreateTime(17,00,00);///ARV
    t[35]=CreateTime(1,15,00);///Durasi
     /// 8. Padang - Jambi
    t[36]=CreateTime(13,00,00);///DPT
    //t[37]=CreateTime(15,45,00);///DPT
    t[38]=CreateTime(14,00,00);///ARV
    //t[39]=CreateTime(17,30,00);///ARV
    t[40]=CreateTime(1,00,00);///Durasi
     /// 9. Padang - Palembang
    t[41]=CreateTime(4,00,00);///DPT
    t[42]=CreateTime(15,00,00);///DPT
    t[43]=CreateTime(9,30,00);///ARV
    t[44]=CreateTime(16,30,00);///ARV
    t[45]=CreateTime(1,30,00);///Durasi
     /// 10. Padang - Bengkulu
    t[46]=CreateTime(9,00,00);///DPT
    //t[47]=CreateTime(15,45,00);///DPT
    t[48]=CreateTime(9,55,00);///ARV
    //t[49]=CreateTime(1,30,00);///ARV
    t[50]=CreateTime(0,55,00);///Durasi
     /// 11. Padang - Lampung
    t[51]=CreateTime(14,00,00);///DPT
    t[52]=CreateTime(16,45,00);///DPT
    t[53]=CreateTime(15,45,00);///ARV
    t[54]=CreateTime(17,45,00);///ARV
    t[55]=CreateTime(1,45,00);///Durasi
      /// 12. Pekanbaru - Medan
    t[56]=CreateTime(7,00,00);///DPT
    //t[52]=CreateTime(16,45,00);///DPT
    t[58]=CreateTime(8,45,00);///ARV
    //t[54]=CreateTime(17,45,00);///ARV
    t[60]=CreateTime(1,0,00);///Durasi
      /// 13. Pekanbaru - Banda Aceh
    t[61]=CreateTime(8,00,00);///DPT
    t[62]=CreateTime(15,15,00);///DPT
    t[63]=CreateTime(10,00,00);///ARV
    t[64]=CreateTime(17,15,00);///ARV
    t[65]=CreateTime(2,00,00);///Durasi
      /// 14. Pekanbaru - Bengkulu
    t[66]=CreateTime(12,00,00);///DPT
    //t[52]=CreateTime(16,45,00);///DPT
    t[68]=CreateTime(13,20,00);///ARV
    //t[54]=CreateTime(17,45,00);///ARV
    t[70]=CreateTime(1,20,00);///Durasi
      /// 15. Pekanbaru - Lampung
    t[71]=CreateTime(9,00,00);///DPT
    t[72]=CreateTime(17,30,00);///DPT
    t[73]=CreateTime(10,45,00);///ARV
    t[74]=CreateTime(19,15,00);///ARV
    t[75]=CreateTime(1,45,00);///Durasi
      /// 16. Pekanbaru - Palembang
    t[76]=CreateTime(14,15,00);///DPT
    //t[52]=CreateTime(16,45,00);///DPT
    t[78]=CreateTime(15,35,00);///ARV
    //t[54]=CreateTime(17,45,00);///ARV
    t[80]=CreateTime(1,15,00);///Durasi
      /// 17. Bengkulu - Padang
    t[81]=CreateTime(6,15,00);///DPT
    t[82]=CreateTime(16,15,00);///DPT
    t[83]=CreateTime(6,55,00);///ARV
    t[84]=CreateTime(18,10,00);///ARV
    t[85]=CreateTime(0,55,00);///Durasi
      /// 18. Bengkulu - Pekanbaru
    t[86]=CreateTime(7,45,00);///DPT
    t[87]=CreateTime(12,30,00);///DPT
    t[88]=CreateTime(9,05,00);///ARV
    t[89]=CreateTime(13,50,00);///ARV
    t[90]=CreateTime(1,20,00);///Durasi
      /// 19. Bengkulu - Lampung
    t[91]=CreateTime(14,45,00);///DPT
    //t[52]=CreateTime(16,45,00);///DPT
    t[93]=CreateTime(15,40,00);///ARV
    //t[54]=CreateTime(17,45,00);///ARV
    t[95]=CreateTime(0,55,00);///Durasi
      /// 20. Jambi - Medan
    t[96]=CreateTime(5,30,00);///DPT
    //t[87]=CreateTime(12,30,00);///DPT
    t[98]=CreateTime(7,15,00);///ARV
    //t[89]=CreateTime(13,50,00);///ARV
    t[100]=CreateTime(1,45,00);///Durasi
      /// 21. Jambi - Padang
    t[101]=CreateTime(6,00,00);///DPT
    t[102]=CreateTime(12,00,00);///DPT
    t[103]=CreateTime(7,00,00);///ARV
    t[104]=CreateTime(13,00,00);///ARV
    t[105]=CreateTime(1,00,00);///Durasi
      /// 22. Jambi - Lampung
    t[106]=CreateTime(14,00,00);///DPT
    //t[87]=CreateTime(12,30,00);///DPT
    t[108]=CreateTime(15,10,00);///ARV
    //t[89]=CreateTime(13,50,00);///ARV
    t[110]=CreateTime(1,10,00);///Durasi
      /// 23. Palembang - Pekanbaru
    t[111]=CreateTime(7,15,00);///DPT
    t[112]=CreateTime(13,30,00);///DPT
    t[113]=CreateTime(8,30,00);///ARV
    t[114]=CreateTime(14,45,00);///ARV
    t[115]=CreateTime(1,15,00);///Durasi
      /// 24. Pekanbaru - Padang
    t[116]=CreateTime(10,00,00);///DPT
    t[117]=CreateTime(16,00,00);///DPT
    t[118]=CreateTime(11,30,00);///ARV
    t[119]=CreateTime(17,30,00);///ARV
    t[120]=CreateTime(1,30,00);///Durasi
       /// 25. Lampung - Pekanbaru
    t[121]=CreateTime(05,00,00);///DPT
    t[122]=CreateTime(13,00,00);///DPT
    t[123]=CreateTime(6,10,00);///ARV
    t[124]=CreateTime(14,10,00);///ARV
    t[125]=CreateTime(1,45,00);///Durasi
       /// 26. Lampung - Jambi
    t[126]=CreateTime(6,20,00);///DPT
    t[127]=CreateTime(15,15,00);///DPT
    t[128]=CreateTime(7,30,00);///ARV
    t[129]=CreateTime(16,25,00);///ARV
    t[130]=CreateTime(1,10,00);///Durasi
       /// 27. Lampung - Padang
    t[131]=CreateTime(8,00,00);///DPT
    t[132]=CreateTime(14,15,00);///DPT
    t[133]=CreateTime(9,45,00);///ARV
    t[134]=CreateTime(16,00,00);///ARV
    t[135]=CreateTime(1,45,00);///Durasi
       /// 28. Lampung - Bengkulu
    t[136]=CreateTime(11,00,00);///DPT
    //t[117]=CreateTime(16,00,00);///DPT
    t[138]=CreateTime(11,55,00);///ARV
    //t[119]=CreateTime(17,30,00);///ARV
    t[140]=CreateTime(0,55,00);///Durasi

    adrEdg iee1= AlocationEdge(&kta,"Banda Aceh","Padang","Garuda Indonesia","GA-123",t[1],t[3],t[5],1150000);///clear
    adrEdg iee2= AlocationEdge(&kta,"Banda Aceh","Padang","Lion Air","JT-137",t[2],t[4],t[5],756000);///clear
    adrEdg iee3= AlocationEdge(&kta,"Banda Aceh","Pekanbaru","Garuda Indonesia","GA-112",t[6],t[8],t[10],1400000);///clear
    adrEdg iee4= AlocationEdge(&kta,"Banda Aceh","Pekanbaru","Lion Air","JT-068",t[7],t[9],t[10],780000);///clear

    adrEdg iee5= AlocationEdge(&kta,"Medan","Padang","Garuda Indonesia","GA-120",t[11],t[13],t[15],1100000);///clear
    adrEdg iee6= AlocationEdge(&kta,"Medan","Padang","Lion Air","JT-187",t[12],t[14],t[15],421000);///clear
    adrEdg iee7= AlocationEdge(&kta,"Medan","Pekanbaru","Garuda Indonesia","GA-223",t[16],t[18],t[25],1000000);///clear
    adrEdg iee8= AlocationEdge(&kta,"Medan","Pekanbaru","Lion Air","JT-098",t[17],t[19],t[25],382000);///clear
    adrEdg iee9= AlocationEdge(&kta,"Medan","Jambi","Garuda Indonesia","GA-232",t[21],t[23],t[25],1600000);///clear
    adrEdg iee10= AlocationEdge(&kta,"Medan","Jambi","Lion Air","JT-871",t[22],t[24],t[25],800000);///clear

    adrEdg iee11= AlocationEdge(&kta,"Padang","Banda Aceh","Lion Air","JT-137",t[26],t[28],t[30],756000);///clear
    adrEdg iee12= AlocationEdge(&kta,"Padang","Banda Aceh","Garuda Indonesia","GA-123",t[27],t[29],t[30],1150000);///clear
    adrEdg iee13= AlocationEdge(&kta,"Padang","Medan","Lion Air","JT-187",t[31],t[33],t[35],421000);///clear
    adrEdg iee14= AlocationEdge(&kta,"Padang","Medan","Garuda Indonesia","GA-120",t[32],t[34],t[35],1100000);///clear
    adrEdg iee15= AlocationEdge(&kta,"Padang","Jambi","Lion Air","JT--228",t[36],t[38],t[40],378000);///clear
    adrEdg iee16= AlocationEdge(&kta,"Padang","Palembang","Lion Air","JT-084",t[41],t[43],t[45],600000);///clear
    adrEdg iee17= AlocationEdge(&kta,"Padang","Palembang","Garuda Indonesia","JT-137",t[42],t[44],t[45],1570000);///clear
    adrEdg iee18= AlocationEdge(&kta,"Padang","Bengkulu","Lion Air","JT-217",t[46],t[48],t[50],431000);///clear
    adrEdg iee19= AlocationEdge(&kta,"Padang","Lampung","Garuda Indonesia","GA-191",t[51],t[53],t[55],2100000);///clear
    adrEdg iee20= AlocationEdge(&kta,"Padang","Lampung","Lion Air","JT-617",t[52],t[54],t[55],560000);///clear

    adrEdg iee21= AlocationEdge(&kta,"Pekanbaru","Medan","Lion","JT-098",t[56],t[58],t[60],382000);///clear
    adrEdg iee22= AlocationEdge(&kta,"Pekanbaru","Banda Aceh","Lion Air","JT-068",t[61],t[63],t[65],780000);///clear
    adrEdg iee23= AlocationEdge(&kta,"Pekanbaru","Banda Aceh","Garuda Indonesia","GA-112",t[62],t[64],t[65],1400000);///clear
    adrEdg iee24= AlocationEdge(&kta,"Pekanbaru","Bengkulu","Lion","JT-098",t[66],t[68],t[45],520000);///clear
    adrEdg iee25= AlocationEdge(&kta,"Pekanbaru","Lampung","Lion Air","JT-254",t[71],t[73],t[75],620000);///clear
    adrEdg iee26= AlocationEdge(&kta,"Pekanbaru","Lampung","Garuda Indonesia","GA-297",t[72],t[74],t[75],1721000);///clear
    adrEdg iee27= AlocationEdge(&kta,"Pekanbaru","Palembang","Garuda Indonesia","GA-912",t[76],t[78],t[80],1200000);///clear

    adrEdg iee28= AlocationEdge(&kta,"Bengkulu","Padang","Lion Air","JT-217",t[81],t[83],t[85],471000);///clear
    adrEdg iee29= AlocationEdge(&kta,"Bengkulu","Padang","Garuda Indonesia","GA-666",t[82],t[84],t[85],900000);///clear
    adrEdg iee30= AlocationEdge(&kta,"Bengkulu","Pekanbaru","Lion Air","JT-667",t[86],t[88],t[90],630000);///clear
    adrEdg iee31= AlocationEdge(&kta,"Bengkulu","Pekanbaru","Lion","JT-657",t[87],t[89],t[90],680000);///clear
    adrEdg iee32= AlocationEdge(&kta,"Bengkulu","Lampung","Lion Air","JT-337",t[91],t[83],t[95],789000);///clear

    adrEdg iee33= AlocationEdge(&kta,"Jambi","Medan","Lion Air","JT-871",t[96],t[98],t[100],800000);///clear
    adrEdg iee34= AlocationEdge(&kta,"Jambi","Padang","Lion Air","JT-228",t[101],t[103],t[105],350000);///clear
    adrEdg iee35= AlocationEdge(&kta,"Jambi","Padang","Garuda Indonesia","JT-323",t[102],t[104],t[105],900000);///clear
    adrEdg iee36= AlocationEdge(&kta,"Jambi","Lampung","Garuda Indonesia","GA-952",t[106],t[108],t[110],923000);///clear

    adrEdg iee37= AlocationEdge(&kta,"Palembang","Pekanbaru","Lion Air","JT-254",t[111],t[113],t[115],610000);///clear
    adrEdg iee38= AlocationEdge(&kta,"Palembang","Pekanbaru","Garuda Indonesia","GA-912",t[112],t[114],t[115],1200000);///clear
    adrEdg iee39= AlocationEdge(&kta,"Palembang","Padang","Garuda Indonesia","GA-872",t[116],t[118],t[120],1540000);///clear
    adrEdg iee40= AlocationEdge(&kta,"Palembang","Padang","Lion Air","JT-084",t[117],t[119],t[120],600000);///clear

    adrEdg iee41= AlocationEdge(&kta,"Lampung","Pekanbaru","Garuda Indonesia","GA-297",t[121],t[123],t[125],1710000);///clear
    adrEdg iee42= AlocationEdge(&kta,"Lampung","Pekanbaru","Lion Air","JT-139",t[122],t[124],t[125],562000);///clear
    adrEdg iee43= AlocationEdge(&kta,"Lampung","Jambi","Lion","JT-281",t[126],t[128],t[130],673000);///clear
    adrEdg iee44= AlocationEdge(&kta,"Lampung","Jambi","Garuda Indonesia","GA-952",t[127],t[129],t[130],923000);///clear
    adrEdg iee45= AlocationEdge(&kta,"Lampung","Padang","Lion Air","JT-617",t[131],t[133],t[135],570000);///clear
    adrEdg iee46= AlocationEdge(&kta,"Lampung","Padang","Garuda Indonesia","GA-191",t[132],t[134],t[135],2200000);///clear
    adrEdg iee47= AlocationEdge(&kta,"Lampung","Bengkulu","Lion Air","JT-337",t[136],t[138],t[140],671000);///clear



    InsertEdge(&G,iee1,"BTJ");
    InsertEdge(&G,iee2,"BTJ");
    InsertEdge(&G,iee3,"BTJ");
    InsertEdge(&G,iee4,"BTJ");

    InsertEdge(&G,iee5,"KNO");
    InsertEdge(&G,iee6,"KNO");
    InsertEdge(&G,iee7,"KNO");
    InsertEdge(&G,iee8,"KNO");
    InsertEdge(&G,iee9,"KNO");
    InsertEdge(&G,iee10,"KNO");
    InsertEdge(&G,iee11,"PDG");
    InsertEdge(&G,iee12,"PDG");
    InsertEdge(&G,iee13,"PDG");
    InsertEdge(&G,iee14,"PDG");
    InsertEdge(&G,iee15,"PDG");
    InsertEdge(&G,iee16,"PDG");
    InsertEdge(&G,iee17,"PDG");
    InsertEdge(&G,iee18,"PDG");
    InsertEdge(&G,iee19,"PDG");
    InsertEdge(&G,iee20,"PDG");
    InsertEdge(&G,iee21,"PKU");
    InsertEdge(&G,iee22,"PKU");
    InsertEdge(&G,iee23,"PKU");
    InsertEdge(&G,iee24,"PKU");
    InsertEdge(&G,iee25,"PKU");
    InsertEdge(&G,iee26,"PKU");
    InsertEdge(&G,iee27,"PKU");
    InsertEdge(&G,iee28,"BKS");
    InsertEdge(&G,iee29,"BKS");
    InsertEdge(&G,iee30,"BKS");
    InsertEdge(&G,iee31,"BKS");
    InsertEdge(&G,iee32,"BKS");
    InsertEdge(&G,iee33,"DJB");
    InsertEdge(&G,iee34,"DJB");
    InsertEdge(&G,iee35,"DJB");
    InsertEdge(&G,iee36,"DJB");
    InsertEdge(&G,iee37,"PLM");
    InsertEdge(&G,iee38,"PLM");
    InsertEdge(&G,iee39,"PLM");
    InsertEdge(&G,iee40,"PLM");
    InsertEdge(&G,iee41,"TKG");
    InsertEdge(&G,iee42,"TKG");
    InsertEdge(&G,iee43,"TKG");
    InsertEdge(&G,iee44,"TKG");
    InsertEdge(&G,iee45,"TKG");
    InsertEdge(&G,iee46,"TKG");
    InsertEdge(&G,iee47,"TKG");


    printf("\n\n\n\n");
    system("pause");

}

void ConnectLocation()
{
     ConnettoVertex(G,"BTJ","PDG");///1
    ConnettoVertex(G,"BTJ","PDG");///2
    ConnettoVertex(G,"BTJ","PKU");///3
    ConnettoVertex(G,"BTJ","PKU");///4
    ConnettoVertex(G,"KNO","PDG");///5
    ConnettoVertex(G,"KNO","PDG");///6
    ConnettoVertex(G,"KNO","DJB");///7
    ConnettoVertex(G,"KNO","DJB");///8
    ConnettoVertex(G,"KNO","PKU");///9
    ConnettoVertex(G,"KNO","PKU");///10
    ConnettoVertex(G,"PDG","BTJ");///11
    ConnettoVertex(G,"PDG","BTJ");///12
    ConnettoVertex(G,"PDG","KNO");///13
    ConnettoVertex(G,"PDG","KNO");///14
    ConnettoVertex(G,"PDG","DJB");///15
    ConnettoVertex(G,"PDG","PLM");///16
    ConnettoVertex(G,"PDG","PLM");///17
    ConnettoVertex(G,"PDG","BKS");///19
    ConnettoVertex(G,"PDG","TKG");///20
    ConnettoVertex(G,"PDG","TKG");///21
    ConnettoVertex(G,"PKU","KNO");///22
    ConnettoVertex(G,"PKU","BTJ");///23
    ConnettoVertex(G,"PKU","BTJ");///24
    ConnettoVertex(G,"PKU","BKS");///25
    ConnettoVertex(G,"PKU","TKG");///26
    ConnettoVertex(G,"PKU","TKG");///27
    ConnettoVertex(G,"PKU","PLM");///28
    ConnettoVertex(G,"BKS","PDG");///29
    ConnettoVertex(G,"BKS","PDG");///30
    ConnettoVertex(G,"BKS","PKU");///31
    ConnettoVertex(G,"BKS","PKU");///32
    ConnettoVertex(G,"BKS","TKG");///33
    ConnettoVertex(G,"DJB","KNO");///34
    ConnettoVertex(G,"DJB","PDG");///35
    ConnettoVertex(G,"DJB","PDG");///36
    ConnettoVertex(G,"DJB","TKG");///37
    ConnettoVertex(G,"PLM","PKU");///38
    ConnettoVertex(G,"PLM","PKU");///39
    ConnettoVertex(G,"PLM","PDG");///40
    ConnettoVertex(G,"PLM","PDG");///41
    ConnettoVertex(G,"TKG","PKU");///42
    ConnettoVertex(G,"TKG","PKU");///43
    ConnettoVertex(G,"TKG","DJB");///44
    ConnettoVertex(G,"TKG","DJB");///45
    ConnettoVertex(G,"TKG","PDG");///46
    ConnettoVertex(G,"TKG","PDG");///47
    ConnettoVertex(G,"TKG","BKS");///48

}

void DisplaY_graph()
{
    //ConnectLocation();
    //system("cls");
    DisplayGraph(G);
    printf("\n\n\n\n");
    system("pause");
    system("cls");

}

void Penerbangan_LIVE()
{
    char Tujuan[15];
    char ASAL[15];
    char* dpr;
    char* arv;

    printf("\n\n\n\n\n");
    printf("\t\t\t PESAN TIKET PENERBANGAN LANGSUNG  \n");
    printf("\t\t\t ----------------------------------- \n");
    printf("\t\t\t |    KEBERANGKATAN   :");fflush(stdin);gets(ASAL);
    printf("\t\t\t |    KEDATANGAN      :");fflush(stdin);gets(Tujuan);
    printf("\t\t\t ----------------------------------- \n");
    dpr=KodeKota(kta,ASAL);
    arv=KodeKota(kta,Tujuan);
    Penerbangan_langsung(&G,kta,&P,dpr,arv);
    printf("\n\n\n\n");
    system("pause");
    system("cls");

}

void Lihat_Penerbangan_transit()
{
    char Tujuan[15];
    char ASAL[15];
    char* dpr;
    char* arv;

    printf("\n\n\n\n\n");
    printf("\t\t\t LIHAT TIKET PENERBANGAN TRANSIT\n");
    printf("\t\t\t Penerbangan ini hanya melayani 1 kali transit.\n");
    printf("\t\t\t ----------------------------------- \n");
    printf("\t\t\t |    KEBERANGKATAN   :");fflush(stdin);gets(ASAL);
    printf("\t\t\t |    KEDATANGAN      :");fflush(stdin);gets(Tujuan);
    printf("\t\t\t ----------------------------------- \n");
    dpr=KodeKota(kta,ASAL);
    arv=KodeKota(kta,Tujuan);
    DFS(G,kta,dpr,arv);
    printf("\n\n\n\n");
    system("pause");
    system("cls");

}


