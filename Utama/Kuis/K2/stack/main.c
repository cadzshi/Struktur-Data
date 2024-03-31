#include "header.h"

int main()
{
    stack S1;
    stack S2;
    createEmpty(&S1);
    createEmpty(&S2);

    char warna[51], nama[51];
    int n, panjang, lebar;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %s", warna, &panjang, &lebar, nama);
        push(warna, panjang, lebar, nama, &S1);
        if (strcmp((S1).data[(S1).top].warna, warna) == 0 &&
            (S1).data[(S1).top].panjang == panjang &&
            (S1).data[(S1).top].lebar == lebar)
        {
            push(warna, panjang, lebar, nama, &S2);
        }
        

    }
    printStack2(S2);
    printf("\n");
    printStack(S1);
    return 0;
}