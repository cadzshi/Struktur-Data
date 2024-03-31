/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal TP 3 (BSP23)
    dalam mata kuliah Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/

// LIBRARY
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// DEKLARASI STRUCT
typedef struct
{
    char judul[50];     //judul buku
    int kode;           //kode buku
} data;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    data kontainer;
    alamatelmt next;
} element;

typedef struct
{
    element *top;
} stack;

// DEKLARASI PROSEDUR DAN FUNGSI
void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(char nama[], int harga, stack *S);
void pop(stack *S);
void popS(stack *S1, stack *S2);
void printStackFiksi(stack S);
void printStackNFiksi(stack S);
void filter(stack *S, stack *fiksi, stack *nfiksi, int n); 

