#include "header.h"

int main()
{
    list L;
    createList(&L);
    char kataInput[100];
    int n, i;
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%s", &kataInput);
        addFirst(kataInput, &L);
    }
    printElement(L);
   
    return 0;
}