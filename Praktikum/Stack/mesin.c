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

void push(char nama[], int harga, stack *S)
{
    element *baru;
    baru = (element *)malloc(sizeof(element));

    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.harga = harga;

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

void popS(stack *S1, stack *S2)
{
    if ((*S1).top != NULL)
    {
        element *hapus = (*S1).top;
        if (countElement(*S1) == 1)
        {
            (*S1).top = NULL;
        }
        else
        {
            (*S1).top = (*S1).top->next;
        }
        hapus->next = NULL;
        if ((*S2).top == NULL)
        {
            hapus->next = NULL;
        }
        else
        {
            hapus->next = (*S2).top;
        }
        (*S2).top = hapus;
        hapus = NULL;
    }
    else
    {
        printf("Stack Kosong\n");
    }
}

void printStack1(stack S)
{
    printf("Buku di S1:\n");
    if (S.top != NULL)
    {
        element *bantu = S.top;
        int i = 1;
        while (bantu != NULL)
        {
            printf("%d. %s Rp.%d\n", i, bantu->kontainer.nama, bantu->kontainer.harga);
            bantu = bantu->next;
            i++;
        }
    }
    else
    {
        printf("- Kosong\n");
    }
}

void printStack2(stack S)
{
    
    printf("\nBuku di S2:\n");
    if (S.top != NULL)
    {
        element *bantu = S.top;
        int i = 1;
        while (bantu != NULL)
        {
            printf("%d. %s Rp.%d\n", i, bantu->kontainer.nama, bantu->kontainer.harga);
            bantu = bantu->next;
            i++;
        }
    }
    else
    {
        printf("- Kosong\n");
    }
}