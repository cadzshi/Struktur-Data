#include "header.h"

int main()
{
    char namaIdol[50], groupIdol[50];
    int tahunIdol;

    list L;
    createList(&L);

       
    scanf("%s %s %d", &namaIdol, &groupIdol, &tahunIdol);
    addFirst(namaIdol, groupIdol, tahunIdol, &L);

    scanf("%s %s %d", &namaIdol, &groupIdol, &tahunIdol);
    addLast(namaIdol, groupIdol, tahunIdol, &L);

    scanf("%s %s %d", &namaIdol, &groupIdol, &tahunIdol);
    addAfter(L.first->next, namaIdol, groupIdol, tahunIdol, &L);

    pembatas(); 
    printElement(L);
    pembatas();

    delAfter(L.first->next, &L);
    delLast(&L);

    printElement(L);
    
    delAll(&L);
    printElement(L);
    pembatas();

    scanf("%s %s %d", &namaIdol, &groupIdol, &tahunIdol);
    addLast(namaIdol, groupIdol, tahunIdol, &L);

    scanf("%s %s %d", &namaIdol, &groupIdol, &tahunIdol);
    addFirst(namaIdol, groupIdol, tahunIdol, &L);

    delFirst(&L);

    printElement(L);
    pembatas();

    scanf("%s %s %d", &namaIdol, &groupIdol, &tahunIdol);
    addFirst(namaIdol, groupIdol, tahunIdol, &L);

    printElement(L);
    
    


    return 0;
}