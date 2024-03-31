/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    Tes Mesin 9 N-er Tree
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
    char ukuran[10];
} data;

typedef struct smp *alamatsimpul;
typedef struct smp
{
    data kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(data c, tree *T);
void addChild(data c, simpul *root);
void delAll(simpul *root);
void delChild(char nama[], char ukuran[], simpul *root);
simpul *findSimpul(char c[], simpul *root);
void printTreePreOrder(simpul *root, int jumlah, int *counter);
void printTreePostOrder(simpul *root, int jumlah, int *counter);
void copyTree(simpul *root1, simpul **root2);
int isEquel(simpul *root1, simpul *root2);
void countNode(simpul *root, int *jumlah);
void check(char c[], simpul *root);