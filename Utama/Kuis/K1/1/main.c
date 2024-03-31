#include "header.h"

int main()
{
    //deklarasi variabel
    int n, i;
    //create list
    list L1;
    createList(&L1);
    //scan datanya
    scanf("%d", &n);
    data proreg[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &proreg[i].harga);
        scanf("%s", &proreg[i].nama);
        scanf("%s", &proreg[i].status);
        addLast(proreg[i].nama, proreg[i].status, proreg[i].harga, &L1);
    }
    //print element
    printElement(L1);

    return 0;
}