/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    UTS - LOLPWB23 dalam mata kuliah Struktur Data untuk 
    keberkahanNya maka saya tidak melakukan kecurangan 
    seperti yang telah dispesifikasikan.
    Aamiin.
*/
// library
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// deklarasi struct
typedef struct{
    char merk[50];
}dataB;

typedef struct{
    char seri[50];
    int kapasitasA;
    int ketahanan;
    int kapasitasN;
    int tahunBeli;
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

// deklarasi prosedur dan fungsi
void createList(list *L);

int countElementB(list L);
int countElementK(eBaris L);

void addFirstB(char merk[], list *L);
void addFirstK(char seri[], int kapasitasA, int ketahanan, int kapasitasN, int tahunBeli, eBaris *L);

void addAfterB (eBaris* prev, char merk[]);
void addAfterK(eKolom* prev,  char seri[], int kapasitasA, int ketahanan, int kapasitasN, int tahunBeli);

void addLastB(char merk[], list *L);
void addLastK(char seri[], int kapasitasA, int ketahanan, int kapasitasN, int tahunBeli, eBaris *L);

void delFirstK(eBaris *L);
void delAfterK(eKolom* prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);

void delFirstB(list *L);
void delAfterB(eBaris* prev);
void delLastB(list *L);
void delAllB(list *L);

void printElement(list L);
eBaris *cariBaris(char merk[], list L);
