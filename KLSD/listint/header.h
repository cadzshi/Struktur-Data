#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    int num;
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
void addFirst(int num, list *L);
void addAfter(elemen* prev, int num, list *L);
void addLast(int num, list *L);
void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);