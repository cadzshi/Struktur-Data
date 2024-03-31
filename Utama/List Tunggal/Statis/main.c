#include "header.h"

int main()
{
    list L;
    createlist(&L);
    printf("====================\n");

    addfirst("1", "orang_1", "A", &L);
    addafter(L.first, "2", "orang_2", "A", &L);
    addlast("3", "orang_3", "A", &L);
    printelemen(L);

    printf("====================\n");

    dellast(&L);
    delafter(L.first, &L);
    delfirst(&L);
    printelemen(L);

    printf("====================\n");

    return 0;
}