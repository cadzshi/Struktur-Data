#include "header.h"

int main()
{
    char nama[50], email[50];
    int telp;

    list L;
    createList(&L);
    
    scanf("%s %d %s", nama, &telp, email);
    addLast(nama, telp, email, &L);
    scanf("%s %d %s", nama, &telp, email);
    addFirst(nama, telp, email, &L);
    scanf("%s %d %s", nama, &telp, email);
    addBefore(L.first->next, nama, telp, email, &L);
    printf("Data Kontak\n");
    pembatas();
    printElement(L);
    pembatas();

    scanf("%s %d %s", nama, &telp, email);
    addAfter(L.first->next, nama, telp, email, &L);
    delAfter(L.first, &L);
    scanf("%s %d %s", nama, &telp, email);
    addAfter(L.first, nama, telp, email, &L);
    scanf("%s %d %s", nama, &telp, email);
    addBefore(L.tail, nama, telp, email, &L);
    delFirst(&L);
    scanf("%s %d %s", nama, &telp, email);
    addAfter(L.tail, nama, telp, email, &L);
    printElement(L);
    


    delLast(&L);
    scanf("%s %d %s", nama, &telp, email);
    addBefore(L.first, nama, telp, email, &L);
    delAfter(L.first, &L);
    scanf("%s %d %s", nama, &telp, email);
    addLast(nama, telp, email, &L);
    printf(")()()()()()()()()()()()()()()()(\n");
    printReverse(L);
    pembatas();


    delAll(&L);
    printElement(L);

   
    return 0;
}