#include "header.h"

// membuat stack kosong
void createEmpty(stack *S)
{
    (*S).top = NULL;
}

// cek stack kosong
int isEmpty(stack S)
{
    int hasil = 0;
    if (S.top == NULL)
    {
        hasil = 1;
    }
    return hasil;
}

// menghitung jumlah elemen dalam stack
int countElement(stack S)
{
    int hasil = 0;
    if (S.top != NULL)
    {
        element *bantu;

        bantu = S.top;
        while (bantu != NULL)
        {
            hasil++;
            bantu = bantu->next;
        }
    }
    return hasil;
}

// memasukkan elemen kedalam stack
void push(char judul[], int kode, stack *S)
{
    element *baru;
    baru = (element *)malloc(sizeof(element));

    strcpy(baru->kontainer.judul, judul);
    baru->kontainer.kode = kode;

    if ((*S).top == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

// mengeluarkan elemen yang ada di stack
void pop(stack *S)
{
    if ((*S).top != NULL)
    {
        element *hapus = (*S).top;
        if (countElement(*S) == 1)
        {
            (*S).top = NULL;
        }
        else
        {
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("Stack Kosong\n");
    }
}

// print stack buku fiksi
void printStackFiksi(stack S)
{
    printf("Buku Fiksi untuk Rene:\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    if (S.top != NULL)
    {
        element *bantu = S.top;
        int i = 1;
        while (bantu != NULL)
        {
            printf("%d. %s [%d]\n", i, bantu->kontainer.judul, bantu->kontainer.kode);
            bantu = bantu->next;
            i++;
        }
    }
    else
    {
        printf("Rene mangambek.. Jakob pun menangis T-T.\n");
    }
}

// untuk buku yang non fiksi
void printStackNFiksi(stack S)
{
    
    printf("Buku Non-Fiksi untuk Alain:\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    if (S.top != NULL)
    {
        element *bantu = S.top;
        int i = 1;
        while (bantu != NULL)
        {
            printf("%d. %s [%d]\n", i, bantu->kontainer.judul, bantu->kontainer.kode);
            bantu = bantu->next;
            i++;
        }
    }
    else
    {
        printf("Alain pergi.. Huft, Ann harus mencarinya.\n");
    }
}

// prosedur untuk cek jumlah judul buku dan memisahkan ke masing" stack
void filter(stack *S, stack *fiksi, stack *nfiksi, int n) 
{
    // membuat elemen bantu menunjuk ke elemen paling atas
    element *bantu = (*S).top;
    // jika stack tidak kosong
    if ((*S).top != NULL) 
    {
        //looping sebanyak jumlah masukan
        for (int i = 0; i < n; i++) 
        {
            int ascii = 0, len = 0;
            // jumlah panjang string judul buku
            len = strlen(bantu->kontainer.judul);
            // looping untuk menghitung total ASCII
            for (int j = 0; j < len; j++) 
            {
                ascii = ascii + bantu->kontainer.judul[j];
                
            }
            // jika total ASCII ganjil
            if (ascii % 2 != 0) 
            {
                //masukkan ke stack fiksi
                push(bantu->kontainer.judul, bantu->kontainer.kode, fiksi); 
                // popS(S, satu);
            }
            // jika total ASCII genap
            else 
            {
                //masukkan ke stack non-fiksi
                push(bantu->kontainer.judul, bantu->kontainer.kode, nfiksi);
                // popS(S, dua);
            }
            // iterasi
            bantu = bantu->next;
        }
    }
}

