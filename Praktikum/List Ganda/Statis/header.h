/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    Tes Mesin 3 List Ganda Statis
    dalam mata kuliah Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/
#include <stdio.h>
#include <string.h>

typedef struct
{
    char jenis[50];
    char nomorPlat[50];
    int tahun;
    char pemilik[50];
} dataKendaraan;

typedef struct
{
    dataKendaraan container;
    int prev;
    int next;
} elemen;

typedef struct
{
    int first;
    int tail;
    elemen data[10];
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char jenis[], char nomorPlat[], int tahun, char pemilik[], list *L);
void addAfter(int before, char jenis[], char nomorPlat[], int tahun, char pemilik[], list *L);
void addLast(char jenis[], char nomorPlat[], int tahun, char pemilik[], list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void pembatas();
void printReverse(list L);