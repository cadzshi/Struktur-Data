/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    TP 1 - BDSG23 dalam mata kuliah Struktur Data untuk 
    keberkahanNya maka saya tidak melakukan kecurangan 
    seperti yang telah dispesifikasikan.
    Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

// DEKLARASI STRUCT
typedef struct
{
    char name[100];
    char technique[100];
    int power;

} jujutsu;

typedef struct elmt *alamatelmt; 
typedef struct elmt
{
    jujutsu kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first; 
} list;

//DEKLARASI PROSEDUR DAN FUNGSI
void createList(list *L);
int countElement(list L);
void addFirst(char name[], char technique[], int power, list *L);
void addAfter(elemen *prev, char name[], char technique[], int power, list *L);
void addLast(char name[], char technique[], int power, list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void delAll(list *L);
void sortinglist(list *L, char soryby[], char tipersort[]);
elemen *qs(elemen *front, elemen *last, char soryby[], char tipersort[]);
elemen *getlast(list *L);
void printElement(list L);
void result(int totalPower);