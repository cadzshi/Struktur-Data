/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    Tes Mesin 4 List Ganda Dinamis
    dalam mata kuliah Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/

//library yang digunakan
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    char nama[50];
    int telp;
    char email[50];
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
void addFirst(char nama[], int telp, char email[], list *L);
void addAfter(elemen *prev, char nama[], int telp, char email[], list *L);
void addLast(char nama[], int telp, char email[], list *L);
void addBefore(elemen *after, char nama[], int telp, char email[], list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void delAll(list *L);
void printElement(list L);
void printReverse(list L);
void pembatas();
