/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    KUIS No 1 - LMPR23 dalam mata kuliah 
    Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char status[50];
    int harga;
} data;

typedef struct
{
    data container;
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
void addFirst(char nama[], char status[], int harga, list *L);
void addAfter(int before, char nama[], char status[], int harga, list *L);
void addLast(char nama[], char status[], int harga, list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void pembatas();
void printReverse(list L);