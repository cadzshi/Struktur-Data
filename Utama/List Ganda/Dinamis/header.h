

//library yang digunakan
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    char nim[10];
    char nama[50];
    char nilai[2];
} data;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    data kontainer;
    alamatelmt next;
    alamatelmt prev;
} elemen;

typedef struct 
{
    elemen *first;
    elemen *tail;
} list;

//deklarasi fungsi dan prosedur
void createList(list *L);
int countElement(list L);
void addFirst(char nim[], char nama[], char nilai[], list *L);
void addAfter(elemen *prev, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void delAll(list *L);
void printElement(list L);