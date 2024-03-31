#include "header.h"

int main()
{
    char namaPulau[100];
    int populasiPulau;
    float luasPulau;

    list L;
    createList(&L);

    
    scanf("%s %d %f", &namaPulau, &populasiPulau, &luasPulau);
    addFirst(namaPulau, populasiPulau, luasPulau, &L);

    scanf("%s %d %f", &namaPulau, &populasiPulau, &luasPulau);
    addFirst(namaPulau, populasiPulau, luasPulau, &L);

    scanf("%s %d %f", &namaPulau, &populasiPulau, &luasPulau);
    addAfter(L.first, namaPulau, populasiPulau, luasPulau, &L);

    printElement(L);
    garisPembatas();

    delLast(&L);

    scanf("%s %d %f", &namaPulau, &populasiPulau, &luasPulau);
    addAfter(L.data[L.first].next, namaPulau, populasiPulau, luasPulau, &L);

    scanf("%s %d %f", &namaPulau, &populasiPulau, &luasPulau);
    addLast(namaPulau, populasiPulau, luasPulau, &L);

    printElement(L);
    garisPembatas();


    delAfter(L.data[L.first].next, &L);
    delFirst(&L);
    delLast(&L);

    printElement(L);
    garisPembatas();



    delLast(&L);
    printElement(L);
    garisPembatas();

    
    
    return 0;
}