#include "header.h"

void createList(list *L)
{
    (*L).first = -1;
    int i;

    for (i = 0; i < 10; i++)
    {
        /* Proses menginisialisasi isi array */
        (*L).data[i].next = -2;
    }
}

/* Menghitung banyaknya elemen dalam list */
int countElement(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        /* List tidak Kosong */
        int hitung;

        /* Inisialisasi */
        hitung = L.first;

        /* Perulangan hingga menemukan akhir dari list (next = -1) */
        while (hitung != -1)
        {
            /* Proses menghitung elemen list */
            hasil += 1;

            /* Iterasi (maju mengecek elemen selanjutnya) */
            hitung = L.data[hitung].next;
        }
    }

    return hasil;
}

/* Mengembalikan index dari elemen Kosong di list */
int emptyElement(list L)
{
    int hasil = -1;

    if (countElement(L) < 10)
    {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < 10))
        {
            if (L.data[i].next == -2)
            {
                hasil = i;
                ketemu = 1;
            }
            else
            {
                i = i + 1;
            }
        }
    }
    return hasil;
}

/* Menambahkan elemen menjadi elemen paling awal */
void addFirst(char nama[], int populasi, float luas, list *L)
{
    if (countElement(*L) < 10)
    {
        /* Jika List masih terdapat elemen yang Kosong (belum penuh) */
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].container.nama, nama);
        (*L).data[baru].container.populasi = populasi;
        (*L).data[baru].container.luas = luas;

        if ((*L).first == -1)
        {
            /* Jika List masih Kosong (menambahkan elemen pertama) */
            (*L).data[baru].next = -1;
        }
        else
        {
            /* Jika list tidak Kosong (membuat elemen menjadi elemen pertama) */
            (*L).data[baru].next = (*L).first;
        }

        /* Memindahkan pointer/tali first ke arah elemen yang baru ditambahkan */
        (*L).first = baru;
    }
    else
    {
        /* Jika list sudah penuh */
        printf("List sudah penuh. Tidak dapat menambahkan elemen baru.\n");
    }
}

/* Menambahkan elemen selanjutnya */
void addAfter(int prev, char nama[], int populasi, float luas, list *L)
{
    if (countElement(*L) < 10)
    {
        /* Jika List masih terdapat elemen yang Kosong (belum penuh) */
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].container.nama, nama);
        (*L).data[baru].container.populasi = populasi;
        (*L).data[baru].container.luas = luas;

        if ((*L).data[prev].next == -1)
        {
            // Jika ingin menambahkan elemen sebagai elemen terakhir
            (*L).data[baru].next = -1;
        }
        else
        {
            /* Jika ingin menambahkan elemen sebagai elemen sesudah prev */
            (*L).data[baru].next = (*L).data[prev].next;
        }
        (*L).data[prev].next = baru;
    }
    else
    {
        /* Jika list sudah penuh */
        printf("List sudah penuh. Tidak dapat menambahkan elemen baru.\n");
    }
}

/* Menambahkan elemen sebagai elemen terakhir */
void addLast(char nama[], int populasi, float luas, list *L)
{
    if ((*L).first == -1)
    {
        /* Jika list masih Kosong, maka akan menggunakan addFirst */
        addFirst(nama, populasi, luas, L);
    }
    else
    {
        /* Jika list sudah berisikan elemen */
        if (countElement(*L) < 10)
        {
            /* Proses mengecek apakah list sudah penuh atau belum */

            /* Proses mencari elemen terakhir */
            /* Inisialisasi */
            int prev = (*L).first;

            while ((*L).data[prev].next != -1)
            {
                /* Iterasi hingga menemukan elemen terakhir */
                prev = (*L).data[prev].next;
            }
            addAfter(prev, nama, populasi, luas, L);
        }
        else
        {
            /* Jika list sudah penuh */
            printf("List sudah penuh. Tidak dapat menambahkan elemen baru.\n");
        }
    }
}

/* Menghapus elemen pertama dalam list */
void delFirst(list *L)
{
    if ((*L).first != -1)
    {
        /* Mengecek apakah list Kosong atau tidak */

        int hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            /* Jika list berisikan 1 elemen */
            (*L).first = -1;
        }
        else
        {
            (*L).first = (*L).data[hapus].next;
        }

        /* Elemen awal sebelumnya diKosongkan */
        (*L).data[hapus].next = -2;
    }
    else
    {
        /* Jika list Kosong */
        printf("Li$t Ko$ong\n");
    }
}

void delAfter(int prev, list *L)
{
    int hapus = (*L).data[prev].next;

    if (hapus != -1)
    {
        // Jika data[prev].next bukan merupakan data terakhir

        if ((*L).data[hapus].next == -1)
        {
            /* Jika data[hapus] merupakan elemen terakhir */
            (*L).data[prev].next = -1;
        }
        else
        {
            /* Jika data[hapus] merupakan elemen di tengah-tengah */
            (*L).data[prev].next = (*L).data[hapus].next;
        }

        /* Pengosongan elemen */
        (*L).data[hapus].next = -2;
    }
}

void delLast(list *L)
{
    if ((*L).first != -1)
    {
        /* Jika list tidak Kosong */

        if (countElement(*L) == 1)
        {
            /* Proses jika list hanya berisi satu elemen*/
            delFirst(L);
        }
        else
        {
            int hapus = (*L).first;
            int prev;
            while ((*L).data[hapus].next != -1)
            {

                /* Iterasi*/
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }

            /* Elemen sebelum elemen terakhir menjadi elemen terakhir*/
            delAfter(prev, L);
        }
    }
    else
    {
        {
            /* Proses jika list Kosong*/
            printf("Li$t Ko$ong.\n");
        }
    }
}

void printElement(list L)
{
    if (L.first != -1)
    {
        int tunjuk = L.first;
        int i = 1;

        while (tunjuk != -1)
        {
            /* Proses */
            printf("%s - %d orang - %0.2f km2\n", L.data[tunjuk].container.nama, L.data[tunjuk].container.populasi, L.data[tunjuk].container.luas);

            /* Iterasi */
            tunjuk = L.data[tunjuk].next;
            i = i + 1;
        }
    }
    else
    {
        printf("Li$t Ko$ong\n");
    }
}

void delAll(list *L)
{
    int i;
    for (i = countElement(*L); i >= 1; i--)
    {
        delLast(L);
    }
}

void garisPembatas()
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
