#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char nim[10];
    char nama[50];
    float nilai;
} nilaiMatkul;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    nilaiMatkul kontainer;
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
void add(char nim[], char nama[], float nilai, queue *Q);
void del(queue *Q);
element popS(queue *Q);
void printStack(queue Q);
