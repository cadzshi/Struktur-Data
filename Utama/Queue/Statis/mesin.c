#include "header.h"

void createEmpty(queue *Q)
{
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmpty(queue Q)
{
    int hasil = 0;
    if (Q.first == -1)
    {
        hasil = 1;
    }
    return hasil;
}

int isFull(queue Q)
{
    int hasil = 0;
    if (Q.last == 9)
    {
        hasil = 1;
    }
    return hasil;
}

void add(char nim[], char nama[], float nilai, queue *Q)
{
    if (isEmpty(*Q) == 1)
    {
        (*Q).first = 0;
        (*Q).last = 0;
        strcpy((*Q).data[0].nim, nim);
        strcpy((*Q).data[0].nama, nama);
        (*Q).data[0].nilai = nilai;
    }
    else
    {
        if (isFull(*Q) != 1)
        {
            (*Q).last = (*Q).last + 1;
            strcpy((*Q).data[(*Q).last].nim, nim);
            strcpy((*Q).data[(*Q).last].nama, nama);
            (*Q).data[(*Q).last].nilai = nilai;
        }
        else
        {
            printf("Queue Penuh\n");
        }
    }
}

void del(queue *Q)
{
    if ((*Q).last == 0)
    {
        (*Q).first = -1;
        (*Q).last = -1;
    }
    else
    {
        int i;
        for (i = ((*Q).first + 1); i <= (*Q).last; i++)
        {
            strcpy((*Q).data[i - 1].nim, (*Q).data[i].nim);
            strcpy((*Q).data[i - 1].nama, (*Q).data[i].nama);
            (*Q).data[i - 1].nilai = (*Q).data[i].nilai;
        }
        (*Q).last = (*Q).last - 1;
    }
}

void printStack(queue Q)
{
    if (Q.first != -1)
    {
        printf("-------Isi Queue-------\n");
        int i;
        for (i = Q.last; i >= Q.first; i--)
        {
            printf("=====================\n");
            printf("elemen ke   : %d\n", i);
            printf("NIM         : %s\n", Q.data[i].nim);
            printf("Nama        : %s\n", Q.data[i].nama);
            printf("Nilai       : %f\n", Q.data[i].nilai);
        }
    }
    else
    {
        printf("Stack Kosong\n");
    }
}