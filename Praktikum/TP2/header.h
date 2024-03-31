/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    TP 2 - LMB23 dalam mata kuliah Struktur Data untuk 
    keberkahanNya maka saya tidak melakukan kecurangan 
    seperti yang telah dispesifikasikan.
    Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

// DEKLARASI STRUCT
typedef struct
{
    char nama[101];     // nama makanan
    float rating;       // rating makanan
    int harga;          // harga makanan
    int hapus;          // penanda
} makanan;

typedef struct elmt *alamatelmt; 
typedef struct elmt
{
    makanan kontainer;
    alamatelmt prev;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first; 
    elemen *tail;
} list;

// DEKLARASI PROSEDUR DAN FUNGSI
void createList(list *L);
int countElement(list L);

void addFirst(char nama[], float rating, int harga, int hapus, list *L);
void addAfter(elemen *before, char nama[], float rating, int harga, int hapus, list *L);
void addLast(char nama[], float rating, int harga, int hapus, list *L);

void delFirst(list *L);
void delAfter(elemen *before, list *L);
void delLast(list *L);
void delAll(list *L);

void printElement(list *L);
void printFilter(list *L);
void checkDelete(list *L);
void hapus(list *L);

void swap(elemen *tunjuk1, elemen *tunjuk2, list *L); 
void bs(list *L, char type[]);         

void pembatas();