#include "header.h"

int main()
{
    // deklarasi variable
    data buku;
    int n;
    stack SUtama;
    stack SFiksi;
    stack SNFiksi;

    //membuat stack
    createEmpty(&SUtama);
    createEmpty(&SFiksi);
    createEmpty(&SNFiksi);

    //input jumlah masukan
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &buku.kode, buku.judul); //scan kode dan judul buku
        push(buku.judul, buku.kode, &SUtama);   //push ke stack utama
    }

    //memfilter stack utama
    filter(&SUtama, &SFiksi, &SNFiksi, n);

    //output
    printStackFiksi(SFiksi);
    printf("\n");
    printStackNFiksi(SNFiksi);
    
    return 0;
}