#include "header.h"

int main()
{
    list L;
    createList(&L);
    int numInput;
    int n, i;
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &numInput);
        addFirst(numInput, &L);
    }
    printElement(L);
   
    return 0;
}