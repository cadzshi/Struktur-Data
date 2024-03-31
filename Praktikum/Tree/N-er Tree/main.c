#include "header.h"

int main()
{
    data baju[100];
    char cari[50];

    int jumlah, counter = 0;
    for (int i = 0; i < 9; i++)
    {
        scanf("%s %s", baju[i].nama, baju[i].ukuran);
    }
    scanf("%s", cari);

    tree T;
    makeTree(baju[0], &T);
    addChild(baju[1], T.root);
    addChild(baju[2], T.root);
    addChild(baju[3], T.root);
    addChild(baju[4], T.root->child->sibling);
    addChild(baju[5], T.root->child->sibling);
    printf("Pohon Data Merchandise:\n================================\n");
    
    jumlah = 0;
    countNode(T.root, &jumlah);
    printTreePreOrder(T.root, jumlah, &counter);
    counter = 0;
    printf("\n");
    printTreePostOrder(T.root, jumlah, &counter);
    counter = 0;
    printf("\n");

    delChild(T.root->child->sibling->child->sibling->kontainer.nama, T.root->child->sibling->kontainer.ukuran, T.root->child->sibling);

    jumlah = 0;
    countNode(T.root, &jumlah);
    printTreePreOrder(T.root, jumlah, &counter);
    counter = 0;
    printf("\n");
    printTreePostOrder(T.root, jumlah, &counter);
    counter = 0;
    printf("\n");

    addChild(baju[6], T.root->child);
    addChild(baju[7], T.root->child->sibling->sibling);
    addChild(baju[8], T.root->child);

    jumlah = 0;
    countNode(T.root, &jumlah);
    printTreePreOrder(T.root, jumlah, &counter);
    counter = 0;
    printf("\n");

   

    tree T2;
    printf("\nArsip Pohon Data Merchandise :\n================================\n");
    printf("Salinan Pohon :\n");
    copyTree(T.root, &T2.root);
    jumlah = 0;
    countNode(T.root, &jumlah);
    printTreePreOrder(T.root, jumlah, &counter);
    if (isEquel(T.root, T2.root) == 1)
    {
        printf("\nSama\n");
    }
    else
    {
        printf("\nTidak Sama\n");
    }

   
    printf("\nData yang dicari:\n================================\n");
    check(cari, T.root->child->child);
    check(cari, T.root->child->sibling);
    check(cari, T.root);
    return 0;
}