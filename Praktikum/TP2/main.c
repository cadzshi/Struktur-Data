#include "header.h"

int main()
{
    //Deklarasi Variabel
    char nama[101];  // Nama makanan
    float rating;    // Rating makanan
    int harga;       // Harga makanan

    list L;         
    createList(&L); 
    
    // scan sampe nemu "udah"
    do
    {
        scanf("%s", nama);                      //scan nama
        if (strcmp(nama, "udah") != 0)          //jika bukan udah, maka
        {
            scanf("%f %d", &rating, &harga);    //scan rating dan harga
            addLast(nama, rating, harga, 0, &L);   // tambahkan data ke elemen
        }

    } while (strcmp(nama, "udah") != 0);        //scan selama input != udah 

    // sort rating makanan secara descending
    bs(&L, "rating");
    // print sebelum filter
    printElement(&L);
    //cek yang ingin dihapus sekaligus print
    checkDelete(&L);
    //sort harga makanan
    bs(&L, "harga");
    //print setelah difilter
    printFilter(&L);

    return 0;
}