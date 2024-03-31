#include "header.h"

int main()
{
    graph G;
    createEmpty(&G);

    int n, njalur, bobot;
    char simpul1, simpul2;
    char awal, akhir;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c %c %d", &simpul1, &simpul2, &bobot);
    }
    scanf(" %c %c", &awal, &akhir);
    scanf("%d", &njalur);

    
    
    return 0;
}