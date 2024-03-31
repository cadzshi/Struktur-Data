#include "header.h"

int main()
{
    //membuat list
    list L;
    createList(&L);

    //deklarasi variabel
    int n;                                              //jumlah masukan
    char merk[50], seri[50];                            //merk dan seri
    int kapasitasA, kapasitasN, ketahanan, tahunBeli;   //kapasitas awal, sekarang, ketahanan, tahun beli
    eBaris *b;                                          //menampung alamat elemen baris

    //scan banyaknya masukan
    scanf("%d", &n);

    //looping untuk masukan powerbank
    for (int i = 0; i < n; i++)
    {
        scanf("%s", merk);      
        addLastB(merk, &L);
        b = cariBaris(merk, L);

        scanf("%s %d %d %d %d", seri, &kapasitasA, &ketahanan, &kapasitasN, &tahunBeli);
        addLastK(seri, kapasitasA, ketahanan, kapasitasN, tahunBeli, b);
    }

    //scan tahun pemeriksaan dan batas penurunan
    int tahunPemeriksaan, batasPenurunan;
    scanf("%d %d", &tahunPemeriksaan, &batasPenurunan);

    //print element
    printElement(L);
    
    return 0;
}

/*:"""""""""""""""""""""""""""""""""""""""""""""""""("*/