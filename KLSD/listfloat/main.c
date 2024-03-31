#include "header.h"

int main()
{
    list L;
    createList(&L);
    float numInput;
    int n, i;
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%f", &numInput);
        addFirst(numInput, &L);
    }
    printElement(L);
   
    return 0;
}