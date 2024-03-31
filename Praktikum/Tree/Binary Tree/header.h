/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal 
    Tes Mesin 8 Binary Tree
    dalam mata kuliah Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char kontainer;
    alamatsimpul left;
    alamatsimpul right;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(char c, tree *T);
void addLeft(char c, simpul *root);
void addRight(char c, simpul *root);
void delAll(simpul *root);
void delLeft(simpul *root);
void delRight(simpul *root);
void printTreePreOrder(simpul *root);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEquel(simpul *root1, simpul *root2);
void printTree(char tipe[], simpul *root);