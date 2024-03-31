/*
    Saya Sabila Rosad NIM 2106000 mengerjakan Soal TP 5 (PBC123)
    dalam mata kuliah Struktur Data untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
    Aamiin.
*/

// LIBRARY
#include <stdio.h>
#include <malloc.h>

// STRUCT
typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;
typedef struct smp
{
    char kontainer;
    alamatsimpul next;
    alamatjalur arc;
} simpul;

typedef struct jlr
{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul *tujuan;
} jalur;

typedef struct
{
    simpul *first;
} graph;

// PROCEDURE AND FUNCTION
void createEmpty(graph *);
void addSimpul(char, graph *);          
void addJalur(simpul *, simpul *, int); 
simpul *findSimpul(char, graph); 
void findJalur(int[], int, int, char, char[], simpul *, graph); 
void simpan(char[], int, int);            