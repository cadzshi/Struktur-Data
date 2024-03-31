#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
    (*L).tail = NULL;
}

int countElement(list L)
{
    int hasil = 0;
    if (L.first != NULL)
    {
        elemen *tunjuk;

        tunjuk = L.first;
        while (tunjuk != NULL)
        {
            hasil = hasil + 1;
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

void addFirst(char gen[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.gen, gen);
    

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

void addAfter(elemen *before, char gen[], list *L)
{
    if (before != NULL)
    {
        elemen *baru;
        baru = (elemen *)malloc(sizeof(elemen));
        strcpy(baru->kontainer.gen, gen);
       
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

void addLast(char gen[], list *L)
{
    if ((*L).first == NULL)
    {
        addFirst(gen, L);
    }
    else
    {
        addAfter((*L).tail, gen, L);
    }
}


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
            hapus->next;
        }
        free(hapus);
    }
}

void delAfter(elemen *before, list *L)
{
    elemen *hapus = before->next;
    if (hapus != NULL)
    {
        if (hapus->next == NULL)
        {
            (*L).tail = before;
            before->next = NULL;
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

void delAll(list *L)
{
    
    if (countElement(*L) != 0)
    {
        
        int i;

        for (i = countElement(*L); i >= 1; i--)
        {
            delLast(L);
            
        }
    }
}

void printElement(list L)
{
    if (L.first != NULL)
    {
        elemen *tunjuk = L.first;
        int i = 1;
        while (tunjuk != NULL)
        {
            printf("%s ", tunjuk->kontainer.gen);
            tunjuk = tunjuk->next;
            i++;
        }
    }
    else
    {
        printf("List Kosong.\n");
    }
}

// void swap (list *L1, list *L2)
// {

// }


