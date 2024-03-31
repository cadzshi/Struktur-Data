/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    Tes Mesin 6 Stack
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
    int harga;
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

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(char nama[], int harga, stack *S);
void pop(stack *S);
void popS(stack *S1, stack *S2);
void printStack1(stack S);
void printStack2(stack S);
