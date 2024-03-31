/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    Tes Mesin 5 List of List
    dalam mata kuliah Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/


#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char genre[50];
    int kode;
}dataB;

typedef struct{
    char judul[255];
}dataK;

typedef struct eklm* alamatekolom;
typedef struct eklm{
    dataK kontainer_kol;
    alamatekolom next_kol;
}eKolom;

typedef struct ebr* alamatebaris;
typedef struct ebr{
    dataB kontainer;
    eKolom *col;
    alamatebaris next;
}eBaris;

typedef struct{
    eBaris *first;
}list;

void createList(list *L);

int countElementB(list L);
int countElementK(eBaris L);

void addFirstB(char genre[], int kode, list *L);
void addFirstK(char judul[], eBaris *L);

void addAfterB (eBaris* prev, char genre[], int kode);
void addAfterK(eKolom* prev,  char judul[]);

void addLastB(char genre[], int kode, list *L);
void addLastK(char judul[], eBaris *L);

void delFirstK(eBaris *L);
void delAfterK(eKolom* prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);

void delFirstB(list *L);
void delAfterB(eBaris* prev);
void delLastB(list *L);
void delAllB(list *L);

void printElement(list L);

