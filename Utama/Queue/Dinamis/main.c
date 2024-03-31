#include "header.h"

int main()
{
    queue Q;
    createEmpty(&Q);
    printStack(Q);
    printf("====================\n");

    add("123456", "Nana", 64.75, &Q);
    add("120012", "Rudi", 60.75, &Q);
    add("123903", "Nona", 71.75, &Q);
    printStack(Q);

    printf("====================\n");

    del(&Q);
    del(&Q);
    printStack(Q);

    printf("====================\n");

    return 0;
}