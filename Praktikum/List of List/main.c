#include "header.h"

int main()
{
    int n;
    char genre[50], judul[255];
    int kode;

    list L;
    createList(&L);
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", genre, &kode);
        addLastB(genre, kode, &L);
        eBaris *curr = L.first;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        scanf("%s", judul);
        addFirstK(judul, curr);
        scanf("%s", judul);
        addLastK(judul, curr);
        scanf("%s", judul);
        addAfterK(curr->col->next_kol, judul);
        scanf("%s", judul);
        addFirstK(judul, curr);
    }

    delAfterK(L.first->next->col->next_kol);
    delFirstB(&L);
    delFirstK(L.first);
    printElement(L);
    delAllB(&L);
    printElement(L);

    return 0;
}