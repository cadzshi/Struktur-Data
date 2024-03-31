/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    Tes Mesin Single List Statis
    dalam mata kuliah Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[50];
    int populasi;
    float luas;
} dataPulau;

typedef struct
{
    dataPulau container;
    int next;
} element;

typedef struct
{
    int first;
    element data[10];
} list;

void createList(list *L);
int countElement(list L);
int emptyelemen(list L);
void addFirst(char nama[50], int populasi, float luas, list *L);
void addAfter(int prev, char nama[50], int populasi, float luas, list *L);
void addLast(char nama[50], int populasi, float luas, list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void garisPembatas();
