#include "header.h"

int main()
{
    //deklarasi variabel
    int n, m, i;
    //create list
    list L1;
    list L2;
    createList(&L1);
    createList(&L2);
    //scan untuk banyak kromosom
    scanf("%d", &n);
    data kromosom1[n];
    data kromosom2[n];

    for (i = 0; i < n; i++)
    {
        scanf("%s", &kromosom1[i].gen);
        addLast(kromosom1[i].gen, &L1);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%s", &kromosom2[i].gen);
        addLast(kromosom2[i].gen, &L2);
    }
    //scan banyak yang ditukar
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &kromosom1[i].tukar, &kromosom2[i].tukar);
    }
    //print element
    printf("kromosom 1:");
    printElement(L1);
    printf("\n");
    printf("kromosom 2:");
    printElement(L2);

    return 0;
}

