#include "header.h"

int main()
{
    //Deklarasi variabel
    char nameInput[100], techniqueInput[100];   //input nama dan teknik
    char sortInput[10], typeInput[10];          //tipe sorting
    int powerInput, totalPower = 0;             //input power dan jumlah power
    
    list L;
    createList(&L);

    do
    {
        scanf("%s", nameInput);                                 //scan nama
        if (strcmp(nameInput, "DOMAIN_EXPANSION") != 0)         //jika bukan DOMAIN_EXPANSION, maka
        {
            scanf("%s %d", techniqueInput, &powerInput);        //scan teknik dan jumlah power
            addLast(nameInput, techniqueInput, powerInput, &L); //langsung tambahkan data
            totalPower += powerInput;                           //menjumlahkan semua power
        }

    } while (strcmp(nameInput, "DOMAIN_EXPANSION") != 0);       // scan selama nama bukan DOMAIN_EXPANSION
    
    scanf("%s %s", sortInput, typeInput);   //scan tipe sorting
    sortinglist(&L, sortInput, typeInput);  //sorting dulu
    printElement(L);                        //print element
    result(totalPower);                     //print hasil kemenangan
    

    return 0;
}