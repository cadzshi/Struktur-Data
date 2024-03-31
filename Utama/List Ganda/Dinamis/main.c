#include "header.h"

int main(){

list L;
createList(&L);
printElement(L);
printf("=============\n");

addFirst("1", "orang_1","A", &L);
addAfter(L.first, "2", "orang_2", "A", &L);
addLast("3", "Orang_3", "A", &L);
printElement(L);

delLast(&L);
delAfter(L.first, &L);
delFirst(&L);
printElement(L);

printf("=============\n");

return 0;
}