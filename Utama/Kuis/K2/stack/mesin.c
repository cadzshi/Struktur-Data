#include "header.h"

void createEmpty(stack *S)
{
    (*S).top = -1;
}

int isEmpty(stack S)
{
    int hasil = 0; // 0 untuk tidak kosong

    if (S.top == -1)
    {
        hasil = 1; // 1 untuk kosong
    }

    return hasil;
}

int isFull(stack S)
{
    int hasil = 0; // 0 untuk tidak full

    if (S.top == 101)
    {
        hasil = 1; // 1 untuk full
    }

    return hasil;
}

void push(char warna[], int panjang, int lebar, char nama[], stack *S)
{
    if (isFull(*S) == 1)
    {
        /*jika stack penuh*/
        printf("stack penuh\n");
    }
    else
    {
        if (isEmpty(*S) == 1)
        {
            /* jika stack kosong */
            (*S).top = 0;
            strcpy((*S).data[0].warna, warna);
            (*S).data[0].panjang = panjang;
            (*S).data[0].panjang = lebar;
            strcpy((*S).data[0].nama, nama);
            
        }
        else
        {
            /* jika stack tidak kosong */
            (*S).top = (*S).top + 1;
            strcpy((*S).data[(*S).top].warna, warna);
            (*S).data[(*S).top].panjang = panjang;
            (*S).data[(*S).top].lebar = lebar;
            strcpy((*S).data[(*S).top].nama, nama);
        }
    }
}

void pop(stack *S)
{
    if ((*S).top == 0)
    {
        /*jika stack berisi satu elemen*/
        (*S).top = -1;
    }
    else
    {
        if ((*S).top != -1)
        {
            /*jika stack tidak kosong*/
            (*S).top = (*S).top - 1;
        }
    }
}

void printStack(stack S)
{
    if (S.top != -1)
    {
        printf("isi stack:\n");
        for (int i = S.top; i >= 0; i--)
        {
            printf("%s ", S.data[i].warna);
            printf("%d ", S.data[i].panjang);
            printf("%d ", S.data[i].lebar);
            printf("%s\n", S.data[i].nama);
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("stack kosong\n");
    }
}

void printStack2(stack S)
{
    if (S.top != -1)
    {
        for (int i = S.top; i >= 0; i--)
        {
            printf("%s ", S.data[i].warna);
            printf("%d ", S.data[i].panjang);
            printf("%d ", S.data[i].lebar);
            printf("%s\n", S.data[i].nama);
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("stack kosong\n");
    }
}