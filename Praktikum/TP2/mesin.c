#include "header.h"

// CREATE LIST
void createList(list *L)
{
    (*L).first = NULL;
    (*L).tail = NULL;
}

// COUNT ELEMENT
int countElement(list L)
{
    int hasil = 0; 

    if (L.first != NULL) 
    {
        elemen *tunjuk; 
        tunjuk = L.first;

        while (tunjuk != NULL)
        {
            hasil++;

            // iterasi
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

// ADD FIRST
void addFirst(char nama[], float rating, int harga, int hapus, list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.rating = rating;
    baru->kontainer.harga = harga;
    baru->kontainer.hapus = hapus;
    
    if ((*L).first == NULL) 
    {
        baru->prev = NULL; 
        baru->next = NULL; 
        (*L).tail = baru;
    }
    else 
    {
        baru->next = (*L).first; 
        baru->prev = NULL;
        (*L).first->prev = baru;
    }

    (*L).first = baru; 
    baru = NULL;       
}

// ADD AFTER
void addAfter(elemen *before, char nama[], float rating, int harga, int hapus, list *L)
{
    if (before != NULL)
    {
        elemen *baru; 
        baru = (elemen *)malloc(sizeof(elemen));

        // isi elemen
        strcpy(baru->kontainer.nama, nama);
        baru->kontainer.rating = rating;
        baru->kontainer.harga = harga;
        baru->kontainer.hapus = hapus;

        if (before->next == NULL) 
        {
            baru->next = NULL;
            (*L).tail = baru;
        }
        else 
        {
            baru->next = before->next;
            baru->next->prev = baru;
        }

        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}
void addBefore(elemen *after, char nama[], float rating, int harga, int hapus, list *L)
{
    if (after != NULL)
    {
        elemen *baru;
        baru = (elemen *)malloc(sizeof(elemen));
        strcpy(baru->kontainer.nama, nama);
        baru->kontainer.rating = rating;
        baru->kontainer.harga = harga;
        baru->kontainer.hapus = hapus;

        if (after->prev == NULL)
        {
            baru->prev = NULL;
            (*L).first = baru;
        }
        else
        {
            baru->prev = after->prev;
            after->prev->next = baru;
        }
        baru->next = after;
        after->prev = baru;
        baru = NULL;
    }
}

// ADD LAST
void addLast(char nama[], float rating, int harga, int hapus, list *L)
{
    if ((*L).first == NULL) 
    {
        addFirst(nama, rating, harga, hapus, L);
    }
    else
    {
        addAfter((*L).tail, nama, rating, harga, hapus, L);
    }
}

// DEL FIRST
void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        elemen *hapus = (*L).first;

        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else
        {
            (*L).first = (*L).first->next; 
            (*L).first->prev = NULL;
            hapus->next = NULL; 
        }
        free(hapus);
    }
}

// DEL AFTER
void delAfter(elemen *before, list *L)
{
    if (before != NULL)
    {
        elemen *hapus = before->next;

        if (hapus != NULL)
        {
            if (hapus->next == NULL)
            {
                before->next = NULL;
                (*L).tail = before;
            }
            else
            {
                before->next = hapus->next;
                hapus->next->prev = before;
                hapus->next = NULL;
            }

            hapus->prev = NULL;
            free(hapus);
        }
    }
}

// DEL LAST
void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }
        else
        {
            delAfter((*L).tail->prev, L);
        }
    }
}

// DEL ALL
void delAll(list *L)
{
    if (countElement(*L) != 0)
    {
        for (int i = countElement(*L); i >= 1; i--)
        {
            delLast(L);
        }
    }
}

// PRINT ELEMENT SEBELUM DIFILTER
void printElement(list *L)
{
    if (L->first != NULL) 
    {
        elemen *tunjuk = L->first;

        pembatas();
        printf("|----- List Makanan Sebelum difilter -----|\n");
        while (tunjuk != NULL) 
        {

            printf(" %s -", tunjuk->kontainer.nama);
            printf(" Rp%d -", tunjuk->kontainer.harga);
            printf(" Rating:%0.1f\n", tunjuk->kontainer.rating);

            // iterasi
            tunjuk = tunjuk->next;
        }
    }
    else
    {
        printf("List Kosong.\n"); 
    }
}

// PRINT ELEMENT YANG DI DELETE
void checkDelete(list *L)
{
    // deklarasi 
    elemen *tunjuk = (*L).first;    // tunjuk yang diisi oleh awal dari list
    int flag = 0;                   // flag sebagai penanda

    printf("|--------- Makanan yang dihapus ----------|\n");
    // looping untuk mengecek apakah nama makanan ganjil, dengan cara hapus dalam kontainer diganti menjadi 1
    while (tunjuk != NULL)
    {
        // jika jumlah panjang huruf nama makanan ganjil, maka
        if (strlen(tunjuk->kontainer.nama) % 2 != 0)
        {
            tunjuk->kontainer.hapus = 1;    // hapus dalam kontainer tunjuk diubah menjadi 1
            flag++;                         // flag bertambah
        }
        tunjuk = tunjuk->next;              // tunjuk berubah ke nextnya
    }
    // memanggil prosedur untuk menghapus element pada list
    if (flag > 0)       // jika flag lebih dari 0
    {   
        hapus(L);       // maka jalankan prosedur hapus
    }
    else
    {
        printf(" -\n");  // jika tidak ada yang  
    }
}

// prosedur untuk menghapus element pada list dan menampilkan kodenya yang dihapus
void hapus(list *L)
{
    // deklarasi tunjuk2 diisi oleh list pertama
    elemen *tunjuk2 = (*L).first;
    // looping untuk mengecek hapus dalam kontainer apakah 1 atau 0, kalau 1 element tersebut ditampilkan kodenya lalu dihapus
    while (tunjuk2 != NULL)
    {
        // jika hapus dalam kontainer tunjuk2 adalah 1
        if (tunjuk2->kontainer.hapus == 1)
        {
            // menampilkan kode dalam kontainer tunjuk2
            printf(" %s telah dihapus.\n", tunjuk2->kontainer.nama);

            if (tunjuk2->prev == NULL) // jika element tersebut merupakan element awal
            {
                delFirst(L); // memanggil prosedur delFirst untuk menghapus element pertama
            }
            else if (tunjuk2->next == NULL) // jika element tersebut merupakan element akhir
            {
                delLast(L); // memanggil prosedur delLast untuk menghapus element akhir
            }
            else // jika element berada di tengah list
            {
                // before diisi oleh tunjuk2 prev nya
                elemen *before = tunjuk2->prev;
                delAfter(before, L); // memanggil prosedur delAfter untuk menghapus element setelah before
            }
            tunjuk2 = (*L).first; // tunjuk2 direset dari awal
        }
        else
        {
            tunjuk2 = tunjuk2->next; // tunjuk2 diisi oleh next nya
        }
    }
}

//print elemen yang telah di filter
void printFilter(list *L)
{
    printf("|----- List Makanan Setelah difilter -----|\n");
    if (L->first != NULL) 
    {
        elemen *tunjuk = L->first;
        while (tunjuk != NULL) 
        {

            printf(" %s -", tunjuk->kontainer.nama);
            printf(" Rp%d -", tunjuk->kontainer.harga);
            printf(" Rating:%0.1f\n", tunjuk->kontainer.rating);

            // iterasi
            tunjuk = tunjuk->next;
        }
        pembatas();
    }
    else
    {
        printf(" Yahh ujang gabisa icip icip makanan...\n"); 
        pembatas();
    }
}

// prosedur swap
void swap(elemen *tunjuk1, elemen *tunjuk2, list *L) 
{
    elemen *sebelum = tunjuk1->prev, *sesudah = tunjuk2->next;

    if (countElement(*L) == 2) // jika didalemnya cuman ada 2 elemen
    {
        L->first = tunjuk2; // ini tukernya tail sama first doang
        L->tail = tunjuk1;
        L->first->prev = NULL;
        L->tail->next = NULL;
        L->first->next = L->tail;
        L->tail->prev = L->first;
    }
    else // jika lebih dari 2 nih
    {
        if (tunjuk1 == L->first) // jika kondisi tunjuk1nya di awal
        {
            sesudah->prev = L->first; // pegangin dulu 
            L->first = tunjuk2;       // baru ditukar tukar
            tunjuk1->next = tunjuk2->next;
            tunjuk2->next = tunjuk1;
            tunjuk1->prev = tunjuk2;
            tunjuk2->prev = NULL; // karena tunjuk2 ini jadi yg awal, maka prevnya harus null
        }
        else if (tunjuk2 == L->tail) // jika kondisi tunjuk2 di akhir
        {
            sebelum->next = L->tail; // mirip sama yang tadi si cuman bedanya ini teh yang di akhr, jadi pegangin dulu
            L->tail = tunjuk1;       // baru tuker tukerin
            tunjuk1->prev = tunjuk2;
            tunjuk2->prev = tunjuk1->prev;
            tunjuk2->next = tunjuk1;
            tunjuk1->next = NULL; // tidak lupa tunjuk1 nextnya NULL ya
        }
        else // ini jika ditengah
        {
            sesudah->prev = tunjuk1;       // pegangin yang tunjuk1
            sebelum->next = tunjuk2;       // terus arahin ppinter sebelum ke yang tunjuk2
            tunjuk1->next = tunjuk2->next; // baru tuker tukeran
            tunjuk2->next = tunjuk1;
            tunjuk2->prev = tunjuk1->prev;
            tunjuk1->prev = tunjuk2;
        }
    }
}

// prosedur buble sort
void bs(list *L, char type[]) 
{
    int swapped; // ini untuk perulangannya
    elemen *tunjuk;

    if (L->first != NULL) // sort hanya akan berjalan jika ada elemen
    {
        if (strcmp(type, "rating") == 0) 
        {
            do // masuk ke perulangan
            {
                tunjuk = L->first;           // set tunjuk dari l first
                swapped = 0;                 // set swap jadi 0
                while (tunjuk->next != NULL) // jika tunjuk next tidak null
                {
                    if (tunjuk->kontainer.rating < tunjuk->next->kontainer.rating) 
                    {
                        swap(tunjuk, tunjuk->next, L); // tuker
                        swapped = 1;                   // set ininya ke satu
                    }
                    else // jika bukan maka iterasi
                    {
                        tunjuk = tunjuk->next;
                    }
                }

            } while (swapped == 1);
        }
        else 
        {
            do
            {
                tunjuk = L->first;
                swapped = 0;
                while (tunjuk->next != NULL)
                {
                    if (tunjuk->kontainer.harga > tunjuk->next->kontainer.harga)
                    {
                        swap(tunjuk, tunjuk->next, L);
                        swapped = 1;
                    }
                    else
                    {
                        tunjuk = tunjuk->next;
                    }
                }

            } while (swapped == 1);
        }
    }
}
// prosedur pembatas
void pembatas()
{
    printf("===========================================\n");
}