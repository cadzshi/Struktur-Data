/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal TP 4 (PKBC123)
    dalam mata kuliah Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/
// LIBRARY
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// STRUCT
typedef struct smp *alamatsimpul;
typedef struct smp {
    char container[101];
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct {
    simpul *root;
} tree;

// PROCEDURE AND FUNCTION
void makeTree(char pohon[], tree *T);
void addChild(char pohon[], simpul *root);
void delAll(simpul *root);
void delChild(char nama[], simpul *root);
simpul *findSimpul(char nama[], simpul *root);
void printTreePreOrder(simpul *root, int lvl);
void printTreePostOrder(simpul *root, int lvl);