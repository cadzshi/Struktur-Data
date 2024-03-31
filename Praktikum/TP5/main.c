#include "header.h"

int main()
{
    //deklarasi variabel
    graph G;       // graph
    simpul *begin; // node awal
    simpul *end;   // node akhir

    createEmpty(&G); // buat graph

    char path[256];         // array untuk menyimpan node yg nanti akan di print
    char x, y;              // input node
    int visited[26], z, n, i = 0;  // array penentu node, beban node, banyaknya input        

    //scan input jumlah
    scanf("%d", &n); 
    // lakukan looping sebanyak jumlah n
    while (i < n)
    {
        scanf(" %c %c %d", &x, &y, &z); // masukan input
        // tambahkan node
        addSimpul(x, &G);
        addSimpul(y, &G);

        // cari node yg berhubungan
        begin = findSimpul(x, G); // awal node
        end = findSimpul(y, G);   // tujuan nodenya

        if ((begin != NULL) && (end != NULL)) // bila keduanya tidak NULL makan akan di tambahkan
        {
            addJalur(begin, end, z); // tambahkan jalurnya
        }
        i++;
    }
    
    scanf(" %c %c", &x, &y); // inputkan keberadaan bintang dan partnernya
    // lakukan looping sebanyak jumlah huruf yang berguna untuk nanti menentukan node sudah di kunjungi atau belum
    for (int i = 0; i < 26; i++)
    {
        visited[i] = 0; // set ke 0 menandai kalau blm pernah dikunjungi
    }

    simpul *temp = findSimpul(x, G);            // cari posisi bintang
    findJalur(visited, 0, 0, y, path, temp, G); // masuk ke prosedur cari partner

    return 0;
}