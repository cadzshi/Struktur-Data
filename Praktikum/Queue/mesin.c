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

void add(char nama[], char nomor[], queue *Q)
{
    element *baru;
    baru = (element *)malloc(sizeof(element));

    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nomor, nomor);
    
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

void priorityQ(char nama[], char nomor[], int priority, queue *Q)
{
    element *baru;
    element *bantu = (*Q).first;
    int i = 0;

    while ((i < priority - 2) && (bantu != NULL))
    {
        bantu = bantu->next;
        i++;
    }

    baru = (element *)malloc(sizeof(element));

    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nomor, nomor);
    
    baru->next = NULL;

    if (priority == 1)
    {

        if ((*Q).first == NULL)
        {
            (*Q).first = baru;
        }

        else
        {
            baru->next = bantu;
            (*Q).first = baru;
        }
    }
    else
    {
        if (priority > countElement(*Q))
        {
            (*Q).last->next = baru;
        }
        else
        {
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
    if (baru->next == NULL)
    {
        (*Q).last = baru;
    }
    baru = NULL;
}

void del(queue *Q1, queue *Q2)
{
    if ((*Q1).first != NULL)
    {
        element *hapus = (*Q1).first;
        if (countElement(*Q1) == 1)
        {
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        }
        else
        {
            (*Q1).first = (*Q1).first->next;
            hapus->next = NULL;
        }
        hapus->next = NULL;
        add(hapus->kontainer.nama, hapus->kontainer.nomor, Q2);
    }
    else
    {
        printf("Stack Kosong\n");
    }
}

void printQueue(queue Q, int urutan)
{
    printf("******************\n");
    printf("Queue %d\n", urutan);
    if (Q.first != NULL)
    {
        element *bantu = Q.first;
        int i = 1;
        while (bantu != NULL)
        {
            printf("%s %s\n", bantu->kontainer.nama, bantu->kontainer.nomor);
            bantu = bantu->next;
        }
    }
    else
    {
        printf("Stack Kosong\n");
    }
}