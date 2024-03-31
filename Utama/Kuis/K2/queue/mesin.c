#include "header.h"

void createEmpty(queue *Q)
{
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q)
{
    int hasil = 0;
    if (Q.first == NULL)
    {
        hasil = 1;
    }
    return hasil;
}

int countElement(queue Q)
{
    int hasil = 0;
    if (Q.first != NULL)
    {
        element *bantu;

        bantu = Q.first;
        while (bantu != NULL)
        {
            hasil++;
            bantu = bantu->next;
        }
    }
    return hasil;
}

void add(char nama[], char menu[], int harga, int jam, int menit, int detik, queue *Q)
{
    element *baru;
    baru = (element *)malloc(sizeof(element));

    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.menu, menu);
    baru->kontainer.harga = harga;
    baru->kontainer.jam = jam;
    baru->kontainer.menit = menit;
    baru->kontainer.detik = detik;

    baru->next = NULL;
    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
    }
    else
    {
        (*Q).last->next = baru;
    }
    (*Q).last = baru;
    baru = NULL;
}

void del(queue *Q)
{
    if ((*Q).first != NULL)
    {
        element *hapus = (*Q).first;
        if (countElement(*Q) == 1)
        {
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        else
        {
            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
    else
    {
        printf("Stack Kosong\n");
    }
}

void printStack(queue Q)
{
    if (Q.first != NULL)
    {
        element *bantu = Q.first;
        int i = 1;
        while (bantu != NULL)
        {
            printf("%s ", bantu->kontainer.nama);
            printf("%s ", bantu->kontainer.menu);
            printf("%d ", bantu->kontainer.harga);
            printf("%d ", bantu->kontainer.jam);
            printf("%d ", bantu->kontainer.menit);
            printf("%d\n", bantu->kontainer.detik);

            bantu = bantu->next;
            i++;
        }
    }
    else
    {
        printf("Stack Kosong\n");
    }
}