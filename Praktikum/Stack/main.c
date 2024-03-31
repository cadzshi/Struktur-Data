#include "header.h"

int main()
{
    char nama[255];
    int harga;
    stack S1;
    stack S2;

    createEmpty(&S1);
    createEmpty(&S2);
    printf("==========================\n");
    printStack1(S1);
    printStack2(S2);
    printf("==========================\n");


    scanf("%s %d", nama, &harga);
    push(nama, harga, &S1);
    scanf("%s %d", nama, &harga);
    push(nama, harga, &S2);
    scanf("%s %d", nama, &harga);
    push(nama, harga, &S2);
    printStack1(S1);
    printStack2(S2);
    printf("==========================\n");


    pop(&S1);
    popS(&S2, &S1);
    scanf("%s %d", nama, &harga);
    push(nama, harga, &S1);
    scanf("%s %d", nama, &harga);
    push(nama, harga, &S2);
    scanf("%s %d", nama, &harga);
    push(nama, harga, &S1);
    pop(&S2);
    popS(&S1, &S2);
    printStack1(S1);
    printStack2(S2);
    printf("==========================\n");


    return 0;
}