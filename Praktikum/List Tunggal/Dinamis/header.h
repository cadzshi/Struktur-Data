/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    Tes Mesin 2 Single List Dinamis
    dalam mata kuliah Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char group[50];
    char nama[50];
    int tahun;
}data;

typedef struct elmt* alamatelmt;
typedef struct elmt{
    data kontainer;
    alamatelmt next;
}elemen;

typedef struct{
    elemen* first;
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nama[], char group[], int tahun, list *L);
void addAfter(elemen* prev, char nama[], char group[], int tahun, list *L);
void addLast(char nama[], char group[], int tahun, list *L);
void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void pembatas();
