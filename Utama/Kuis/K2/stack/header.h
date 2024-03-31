/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    KUIS 2 No 1 - STGWR23 dalam mata kuliah 
    Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char warna[51];
    char nama[51];
    int lebar;
    int panjang;
} balok;

typedef struct
{
    int top; // elemen paling atas stack
    balok data[51];
} stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(char warna[], int panjang, int lebar, char nama[], stack *S);
void pop(stack *S);
void printStack(stack S);
void printStack2(stack S);