#include "header.h"

void createEmpty(stack *S)
{
    (*S).top = NULL;
}

int isEmpty(stack S)
{
    int hasil = 0;
    if (S.top == NULL)
    {
        hasil = 1;
    }
    return hasil;
}

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

void push(char nim[], char nama[], float nilai, stack *S)
{
    element *baru;
    baru = (element *)malloc(sizeof(element));

    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.nilai = nilai;

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

element popS(stack *S)
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
        return *hapus;
    }
    else
    {
        printf("Stack Kosong\n");
    }
}

void printStack(stack S)
{
    if (S.top != NULL)
    {
        printf("-------Isi Stack-------\n");
        element *bantu = S.top;
        int i = 0;
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