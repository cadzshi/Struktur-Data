#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
    float nilai;
} nilaiMatkul;

typedef struct
{
    int first;
    int last;
    nilaiMatkul data[10];
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
void add(char nim[], char nama[], float nilai, queue *Q);
void del(queue *Q);
void printStack(queue Q);
