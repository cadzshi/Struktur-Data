#include "header.h"

// CREATE LIST
void createList(list *L)
{
    (*L).first = NULL;
}

// COUNT ELEMENT
int countElement(list L)
{
    int hasil = 0; 

    if (L.first != NULL) 
    {
        elemen *tunjuk; 
        tunjuk = L.first;

        while (tunjuk != NULL)
        {
            hasil++;

            
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

// ADD FIRST
void addFirst(char name[], char technique[], int power, list *L)
{

    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.name, name);
    strcpy(baru->kontainer.technique, technique);
    baru->kontainer.power = power;
    

    if ((*L).first == NULL) 
    {
        baru->next = NULL; 
    }
    else 
    {
        baru->next = (*L).first; 
    }

    (*L).first = baru; 
    baru = NULL;       
}

// ADD AFTER
void addAfter(elemen *prev, char name[], char technique[], int power, list *L)
{

    elemen *baru; 
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.name, name);
    strcpy(baru->kontainer.technique, technique);
    baru->kontainer.power = power;
    
    if (prev->next == NULL) 
    {
        baru->next = NULL;
    }
    else 
    {
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

// ADD LAST
void addLast(char name[], char technique[], int power, list *L)
{
    if ((*L).first == NULL)
    {
        addFirst(name, technique, power, L);
    }
    else
    {
        elemen *prev = (*L).first;

        while (prev->next != NULL) 
        {
            prev = prev->next;
        }

        addAfter(prev, name, technique, power, L);
    }
}

// DEL FIRST
void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        elemen *hapus = (*L).first;

        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
        }
        else
        {
            (*L).first = (*L).first->next; 
            hapus->next = NULL;            
        }

        free(hapus);
    }
}

// DEL AFTER
void delAfter(elemen *prev, list *L)
{
    elemen *hapus = prev->next;

    if (hapus != NULL)
    {
        if (hapus->next == NULL)
        {
            prev->next = NULL;
        }
        else
        {
            prev->next = hapus->next;
            hapus->next = NULL;
        }

        free(hapus);
    }
}

// DEL LAST
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
            elemen *hapus = (*L).first;
            elemen *prev;

            while (hapus->next != NULL)
            {
                prev = hapus;
                hapus = hapus->next;
            }
            delAfter(prev, L);
        }
    }
}

// DEL ALL
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

// PRINT ELEMENT
void printElement(list L)
{
    if (L.first != NULL) 
    {
        elemen *tunjuk = L.first;
        while (tunjuk != NULL) 
        {

            printf("%s ", tunjuk->kontainer.name);
            printf("%s ", tunjuk->kontainer.technique);
            printf("%d\n", tunjuk->kontainer.power);

            // iterasi
            tunjuk = tunjuk->next;
        }
    }
    else
    {
        printf("List Kosong.\n"); 
    }
}

elemen *qs(elemen *front, elemen *last, char sorting[], char typesort[])
{

    if (last == NULL || front == NULL || front == last) 
    {
        return front;
    }

    elemen *pivot = last; // deklarasi pivot sebagai element akhir
    elemen *curr = front; // lalu curr sebagai front
    elemen *prev = NULL;  // dan prevnya null
    while (curr != pivot) // selama curr!= pivot,
    {
        elemen *currnext = curr->next;    // deklarasi currnext yaitu curr->nextnya
        if (strcmp(sorting, "Technique") == 0) // jika sorting berdasarkan teknik
        {
            if (strcmp(typesort, "Ascend") == 0) // jika sortingnya adalah ascending
            {

                if (strcmp(curr->kontainer.technique, pivot->kontainer.technique) > 0) 
                {
                    if (prev == NULL) 
                    {
                        front = currnext; 
                    }
                    else 
                    {
                        prev->next = currnext;
                    }
                    curr->next = last->next; 
                    last->next = curr;      
                    last = curr;             
                }
                else
                {
                    prev = curr; 
                }
                curr = currnext;
            }
            else
            {
                if (strcmp(curr->kontainer.technique, pivot->kontainer.technique) < 0) //jika sortingnya adalah descending
                {
                    if (prev == NULL)
                    {
                        front = currnext;
                    }
                    else
                    {
                        prev->next = currnext;
                    }
                    curr->next = last->next;
                    last->next = curr;
                    last = curr;
                }
                else
                {
                    prev = curr;
                }
                curr = currnext;
            }
        }
        if (strcmp(sorting, "Power") == 0) //jika sorting berdasarkan power
        {
            if (strcmp(typesort, "Ascend")) //jika sortingnya adalah Ascending
            {
                if (curr->kontainer.power < pivot->kontainer.power)
                {
                    if (prev == NULL)
                    {
                        front = currnext;
                    }
                    else
                    {
                        prev->next = currnext;
                    }
                    curr->next = last->next;
                    last->next = curr;
                    last = curr;
                }
                else
                {
                    prev = curr;
                }
                curr = currnext;
            }
            else
            {
                if (curr->kontainer.power > pivot->kontainer.power) //jika sortingnya descending
                {
                    if (prev == NULL)
                    {
                        front = currnext;
                    }
                    else
                    {
                        prev->next = currnext;
                    }
                    curr->next = last->next;
                    last->next = curr;
                    last = curr;
                }
                else
                {
                    prev = curr;
                }
                curr = currnext;
            }
        }
    }
    if (pivot != last) // jika pivot bukan last
    {
        pivot->next = qs(pivot->next, last, sorting, typesort); // maka pivot nextnya di rekursi lagi fungsi ini
    }
    return qs(front, prev, sorting, typesort); // return front, lalu si lastnya itu diganti prev (sama seperti algoritma qs biasanya)
}

// PROSEDUR SORT
void sortinglist(list *L, char sorting[], char typesort[]) 
{
    elemen *front = L->first; 
    elemen *last = getlast(L);
    L->first = qs(front, last, sorting, typesort);
}

// FUNGSI MENDAPATKAN TAIL (digunakan di qs)
elemen *getlast(list *L) 
{
    elemen *tunjuk = L->first;                     // deklarasi elemen 
    while (tunjuk != NULL && tunjuk->next != NULL) // lalu ini perulangan belum nyampe ke elemen akhir
    {
        tunjuk = tunjuk->next; 
    }
    return tunjuk; // lalu return elemen yang di belakang
}

// PROSEDUR KEMENANGAN
void result(int totalPower)
{
    if (totalPower % 2 == 0 )   //jika jumlah power genap, maka
    {
        printf("LOSE\n");
    }
    else                        //jika ganjil, maka
    {
        printf("WIN\n");
    }
}