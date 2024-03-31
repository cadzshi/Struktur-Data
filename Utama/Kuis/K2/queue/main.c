#include "header.h"

int main()
{
    queue Q1;
    createEmpty(&Q1);

    data cust;
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d %d %d %d", cust.nama, cust.menu, &cust.harga, &cust.jam, &cust.menit, &cust.detik);
        if (cust.jam < 22)
        {
            add(cust.nama, cust.menu, cust.harga, cust.jam, cust.menit, cust.detik, &Q1);
        }
        
    }
    scanf("%d", &k);

    printStack(Q1);
    
    return 0;
}