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
    element *top;
} stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(char nim[], char nama[], float nilai, stack *S);
void pop(stack *S);
element popS(stack *S);
void printStack(stack S);
