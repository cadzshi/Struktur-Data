#include "header.h"

int main()
{
    stack S;
    createEmpty(&S);
    printStack(S);
    printf("====================\n");

    push("123456", "Nana", 64.75, &S);
    push("120012", "Rudi", 60.75, &S);
    push("123903", "Nona", 71.75, &S);
    printStack(S);

    printf("====================\n");

    pop(&S);
    element *hapus;
    *hapus = popS(&S);
    printf("%s %s %f!!!!\n", hapus->kontainer.nim, hapus->kontainer.nama, hapus->kontainer.nilai);
    pop(&S);
    printStack(S);

    printf("====================\n");

    return 0;
}