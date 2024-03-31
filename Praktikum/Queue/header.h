/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    Tes Mesin 7 Queue
    dalam mata kuliah Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char nama[50];
    char nomor[50];
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
void add(char nama[], char nomor[], queue *Q);
void priorityQ(char nama[], char nomor[], int priority, queue *Q);
void del(queue *Q1, queue *Q2);
void printQueue(queue Q, int urutan);