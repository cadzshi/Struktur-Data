#include "header.h"

int main()
{
    data perang;
    queue Q1, Q2;

    createEmpty(&Q1);
    createEmpty(&Q2);

    scanf("%s %s", perang.nama, perang.nomor);
    add(perang.nama, perang.nomor, &Q1);
    scanf("%s %s", perang.nama, perang.nomor);
    add(perang.nama, perang.nomor, &Q1);
    scanf("%s %s", perang.nama, perang.nomor);
    priorityQ(perang.nama, perang.nomor, 2, &Q1);
    printQueue(Q1, 1);

    del(&Q1, &Q2);
    printQueue(Q1, 1);
    printQueue(Q2, 2);

    scanf("%s %s", perang.nama, perang.nomor);
    priorityQ(perang.nama, perang.nomor, 1, &Q1);
    scanf("%s %s", perang.nama, perang.nomor);
    priorityQ(perang.nama, perang.nomor, 99, &Q1);
    printQueue(Q1, 1);

    del(&Q1, &Q2);
    del(&Q1, &Q2);
    scanf("%s %s", perang.nama, perang.nomor);
    add(perang.nama, perang.nomor, &Q1);

    printQueue(Q1, 1);
    printQueue(Q2, 2);
    printf("******************\n");

    return 0;
}

/*
add
add
add priority 2
print q1
del
print q1
print q2
add priority 1
add priotiy 99
print q1
del
del
add
print q1
print q2*/