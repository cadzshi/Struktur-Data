/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    KUIS No 2 - LPKG23 dalam mata kuliah 
    Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/

//library yang digunakan
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    char gen[50];
    int tukar;
} data;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    data kontainer;
    alamatelmt next;
    alamatelmt prev;
} elemen;

typedef struct 
{
    elemen *first;
    elemen *tail;
} list;

//deklarasi fungsi dan prosedur
void createList(list *L);
int countElement(list L);
void addFirst(char gen[], list *L);
void addAfter(elemen *prev, char gen[], list *L);
void addLast(char gen[], list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void delAll(list *L);
void printElement(list L);

