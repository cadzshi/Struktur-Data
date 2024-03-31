/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    KUIS 2 No 2 - QKDVR23 dalam mata kuliah 
    Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char nama[50];
    char menu[50];
    int harga, jam, menit, detik;
} data;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    data kontainer;
    alamatelmt next;
} element;

typedef struct
{
    element *first;
    element *last;
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char nama[], char menu[], int harga, int jam, int menit, int detik, queue *Q);
void del(queue *Q);
void printStack(queue Q);
