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

void add(char nim[], char nama[], float nilai, queue *Q)
{
    element *baru;
    baru = (element *)malloc(sizeof(element));

    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.nilai = nilai;
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
        printf("-------Isi Stack-------\n");
        element *bantu = Q.first;
        int i = 1;
        while (bantu != NULL)
        {
            printf("=====================\n");
            printf("elemen ke   : %d\n", i);
            printf("NIM         : %s\n", bantu->kontainer.nim);
            printf("Nama        : %s\n", bantu->kontainer.nama);
            printf("Nilai       : %f\n", bantu->kontainer.nilai);
            bantu = bantu->next;
            i++;
        }
    }
    else
    {
        printf("Stack Kosong\n");
    }
}