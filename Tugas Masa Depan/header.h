/*
Saya SaSbila Rosad NIM 2106000 mengerjakan 
evaluasi Tugas Masa Depan dalam mata kuliah 
Struktur Data untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

// library
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// variabel global
extern int max[201];

// struct
typedef struct 
{
    char nama[201];
    char ortu[201];
    int gaji;
    int pengalaman;
    int jmlskill;
    char listSkill[201][201];
} data;

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char nama[201];
    char ortu[201];
    int gaji;
    int pengalaman;
    int jmls;
    char listSkill[201][201];
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

// prosedur dan fungsi
void makeTree(char nama[], char ortu[], int gaji, int pengalaman, int jmlSkill, char listSkill[][201], tree *T);
void addchild(char nama[], char ortu[], int gaji, int pengalaman, int jmls, char listSkill[][201], simpul *root);
simpul *findsimpul(char c[], simpul *root);
void printTreePreOrder(simpul *root, int n, int lvl);
void Input(int banyak, char str[], data c[], int n);
void spasi(simpul *root, int len);
void InTree(tree *T, data c[], int banyak);





