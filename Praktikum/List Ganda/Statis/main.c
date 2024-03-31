#include "header.h"

int main()
{
    char iJenis[50], iNoplat[50], iPemilik[50];
    int iTahun;

    list L;
    createList(&L);

    
    printf("Data Kendaraan\n");

    scanf("%s %s %d %s", &iJenis, &iNoplat, &iTahun, &iPemilik);
    addFirst(iJenis, iNoplat, iTahun, iPemilik, &L);
    scanf("%s %s %d %s", &iJenis, &iNoplat, &iTahun, &iPemilik);
    addLast(iJenis, iNoplat, iTahun, iPemilik, &L);
    scanf("%s %s %d %s", &iJenis, &iNoplat, &iTahun, &iPemilik);
    addAfter(L.first, iJenis, iNoplat, iTahun, iPemilik, &L);
    printElement(L);
    pembatas();
    
    delAfter(L.data[L.first].next, &L);
    scanf("%s %s %d %s", &iJenis, &iNoplat, &iTahun, &iPemilik);
    addAfter(L.first, iJenis, iNoplat, iTahun, iPemilik, &L);
    scanf("%s %s %d %s", &iJenis, &iNoplat, &iTahun, &iPemilik);
    addAfter(L.data[L.tail].prev, iJenis, iNoplat, iTahun, iPemilik, &L);
    delFirst(&L);
    printElement(L);
    pembatas();

    scanf("%s %s %d %s", &iJenis, &iNoplat, &iTahun, &iPemilik);
    addFirst(iJenis, iNoplat, iTahun, iPemilik, &L);
    scanf("%s %s %d %s", &iJenis, &iNoplat, &iTahun, &iPemilik);
    addAfter(L.data[L.first].next, iJenis, iNoplat, iTahun, iPemilik, &L);
    delLast(&L);
    printReverse(L);

    delAll(&L);
    printElement(L);
    pembatas();

    return 0;
}