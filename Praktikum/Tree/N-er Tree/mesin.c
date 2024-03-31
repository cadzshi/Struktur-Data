#include "header.h"

void makeTree(data c, tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    node->kontainer = c;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
    node = NULL;
}

void addChild(data c, simpul *root)
{
    if (root != NULL)
    {
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kontainer = c;
        baru->child = NULL;
        if (root->child == NULL)
        {
            baru->sibling = NULL;
            root->child = baru;
        }
        else
        {

            if (root->child->sibling == NULL)
            {
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            else
            {
                simpul *last = root->child;
                while (last->sibling != root->child)
                {
                    last = last->sibling;
                }
                baru->sibling = root->child;
                last->sibling = baru;
            }
        }
    }
}

void delAll(simpul *root)
{
    if (root != NULL)
    {
        if (root->child != NULL)
        {
            if (root->child->sibling == NULL)
            {

                delAll(root->child);
                free(root);
            }
            else
            {
                simpul *bantu;
                simpul *proses;
                bantu = root->child;
                while (bantu->sibling != root->child)
                {
                    proses = bantu;
                    bantu = bantu->sibling;
                    delAll(proses);
                }
            }
            free(root);
        }
        else
        {
            free(root);
        }
    }
}

void delChild(char nama[], char ukuran[], simpul *root)
{
    if (root != NULL)
    {
        simpul *hapus = root->child;
        if (hapus != NULL)
        {
            if (hapus->sibling == NULL)
            {

                if ((strcmp(root->child->kontainer.nama, nama) == 0) && (root->child->kontainer.ukuran,ukuran))
                {
                    delAll(root->child);
                    root->child = NULL;
                }
                else
                {
                    printf("%s tidak ditemukan\n", nama);
                }
            }
            else
            {

                simpul *prev = NULL;

                int ketemu = 0;
                while ((hapus->sibling != root->child) && (ketemu == 0))
                {
                    if ((strcmp(hapus->kontainer.nama, nama) == 0) && (root->child->kontainer.ukuran,ukuran))
                    {
                        ketemu = 1;
                    }
                    else
                    {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }

                if ((ketemu == 0) && ((strcmp(hapus->kontainer.nama, nama) == 0) && (hapus->kontainer.ukuran,ukuran)))
                {
                    ketemu = 1;
                }
                if (ketemu == 1)
                {
                    simpul *last = root->child;

                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }
                    if (prev == NULL)
                    {

                        if ((hapus->sibling == last) && (last->sibling == root->child))
                        {

                            root->child = last;
                            last->sibling = NULL;
                        }
                        else
                        {

                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else
                    {
                        if ((prev == root->child) && (last->sibling == root->child))
                        {

                            root->child->sibling = NULL;
                        }
                        else
                        {

                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(hapus);
                }
                else
                {
                    printf("%s tidak ditemukan\n", nama);
                }
            }
        }
    }
}

simpul *findSimpul(char c[], simpul *root)
{
    simpul *hasil = NULL;
    if (root != NULL)
    {
        if (strcmp(root->kontainer.nama, c) == 0)
        {
            hasil = root;
        }
        else
        {
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    if (strcmp(root->kontainer.nama, c) == 0)
                    {
                        hasil = bantu;
                    }
                    else
                    {
                        hasil = findSimpul(c, bantu);
                    }
                }
                else
                {
                    int ketemu = 0;
                    while ((bantu->sibling != root->child) && (ketemu == 0))
                    {
                        if (strcmp(root->kontainer.nama, c) == 0)
                        {
                            hasil = bantu;
                            ketemu = 1;
                        }
                        else
                        {
                            hasil = findSimpul(c, bantu);
                            bantu = bantu->sibling;
                            if (hasil != NULL)
                            {
                                ketemu = 1;
                            }
                        }
                    }
                    if (ketemu == 0)
                    {
                        if (strcmp(root->kontainer.nama, c) == 0)
                        {
                            hasil = bantu;
                        }
                        else
                        {
                            hasil = findSimpul(c, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

void check(char c[], simpul *root)
{
    simpul *bantu = findSimpul(c, root);
    if (bantu == NULL)
    {
        printf("%s tidak ditemukan\n", c);
    }
    else
    {
        printf("%s ditemukan\n", c);
    }
}

void printTreePreOrder(simpul *root, int jumlah, int *counter)
{
    if (root != NULL)
    {
        *counter += 1;
        printf("%s %s", root->kontainer.nama, root->kontainer.ukuran);
        if (*counter != jumlah)
        {
            printf("-");
        }

        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                printTreePreOrder(bantu, jumlah, counter);
            }
            else
            {
                while (bantu->sibling != root->child)
                {
                    printTreePreOrder(bantu, jumlah, counter);
                    bantu = bantu->sibling;
                }
                printTreePreOrder(bantu, jumlah, counter);
            }
        }
    }
}

void printTreePostOrder(simpul *root, int jumlah, int *counter)
{
    if (root != NULL)
    {
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                printTreePostOrder(bantu, jumlah, counter);
            }
            else
            {
                while (bantu->sibling != root->child)
                {
                    printTreePostOrder(bantu, jumlah, counter);
                    bantu = bantu->sibling;
                }
                printTreePostOrder(bantu, jumlah, counter);
            }
        }
        *counter += 1;
        printf("%s %s", root->kontainer.nama, root->kontainer.ukuran);
        if (*counter != jumlah)
        {
            printf("-");
        }
    }
}

void copyTree(simpul *root1, simpul **root2)
{
    if (root1 != NULL)
    {
        (*root2) = (simpul *)malloc(sizeof(simpul));
        (*root2)->kontainer = root1->kontainer;
        (*root2)->sibling = NULL;
        (*root2)->child = NULL;
        if (root1->child != NULL)
        {
            if (root1->child->sibling == NULL)
            {
                copyTree(root1->child, &(*root2)->child);
            }
            else
            {
                simpul *bantu1 = root1->child;
                simpul *bantu2 = (*root2)->child;
                while (bantu1->sibling != root1->child)
                {
                    copyTree(bantu1, &bantu2);
                    bantu1 = bantu1->sibling;
                    bantu2 = bantu2->sibling;
                }
                copyTree(bantu1, &bantu2);
            }
        }
    }
}

int isEquel(simpul *root1, simpul *root2)
{
    int hasil = 1;

    if ((root1 != NULL) && (root2 != NULL))
    {
        if ((strcmp(root1->kontainer.nama, root2->kontainer.nama) != 0) && (root1->kontainer.ukuran != root2->kontainer.ukuran))
        {
            hasil = 0;
        }
        else
        {
            if ((root1->child != NULL) && (root2->child != NULL))
            {
                if (root1->child->sibling == NULL)
                {
                    hasil = isEquel(root1->child, root2->child);
                }
                else
                {
                    simpul *bantu1 = root1->child;
                    simpul *bantu2 = root2->child;
                    while (bantu1->sibling != root1->child)
                    {
                        if ((bantu1 != NULL) && (bantu2 != NULL))
                        {
                            hasil = isEquel(bantu1, bantu2);
                            bantu1 = bantu1->sibling;
                            bantu2 = bantu2->sibling;
                        }
                        else
                        {
                            hasil = 0;
                            break;
                        }
                    }
                    hasil = isEquel(bantu1, bantu2);
                }
            }
        }
    }
    else
    {
        if ((root1 != NULL) || (root2 != NULL))
        {
            hasil = 0;
        }
    }
    return hasil;
}

void countNode(simpul *root, int *jumlah)
{
    if (root != NULL)
    {
        *jumlah += 1;
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {

                countNode(bantu, jumlah);
            }
            else
            {

                while (bantu->sibling != root->child)
                {
                    countNode(bantu, jumlah);
                    bantu = bantu->sibling;
                }
                countNode(bantu, jumlah);
            }
        }
    }
}