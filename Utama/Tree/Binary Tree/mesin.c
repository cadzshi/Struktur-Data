#include "header.h"

void makeTree(char c, tree *T)
{
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    baru->kontainer = c;
    baru->left = NULL;
    baru->right = NULL;
    (*T).root = baru;
    baru = NULL;
}

void addLeft(char c, simpul *root)
{
    if (root->left == NULL)
    {
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kontainer = c;
        baru->left = NULL;
        baru->right = NULL;
        root->left = baru;
        baru = NULL;
    }
    else
    {
        printf("sub pohon kiri sudah terisi\n");
    }
}

void addRight(char c, simpul *root)
{
    if (root->right == NULL)
    {
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kontainer = c;
        baru->left = NULL;
        baru->right = NULL;
        root->right = baru;
        baru = NULL;
    }
    else
    {
        printf("sub pohon kanan sudah terisi\n");
    }
}

void delAll(simpul *root)
{
    if (root != NULL)
    {
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}

void delLeft(simpul *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            delAll(root->left);
            root->left = NULL;
        }
    }
}

void delRight(simpul *root)
{
    if (root != NULL)
    {
        if (root->right != NULL)
        {
            delAll(root->right);
            root->right = NULL;
        }
    }
}

void printTreePreOrder(simpul *root)
{
    if (root != NULL)
    {
        printf(" %c\n", root->kontainer);
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
}

void printTreeInOrder(simpul *root)
{
    if (root != NULL)
    {
        printTreeInOrder(root->left);
        printf(" %c\n", root->kontainer);
        printTreeInOrder(root->right);
    }
}

void printTreePostOrder(simpul *root)
{
    if (root != NULL)
    {
        printTreePostOrder(root->left);
        printTreePostOrder(root->right);
        printf(" %c\n", root->kontainer);
    }
}

void copyTree(simpul *root1, simpul **root2)
{
    if (root1 != NULL)
    {
        (*root2) = (simpul *)malloc(sizeof(simpul));
        (*root2)->kontainer = root1->kontainer;
        if (root1->left != NULL)
        {
            copyTree(root1->left, &(*root2)->left);
        }

        if (root1->right != NULL)
        {
            copyTree(root1->right, &(*root2)->right);
        }
    }
}

int isEquel(simpul *root1, simpul *root2)
{
    int hasil = 1;

    if ((root1 != NULL) && (root2 != NULL))
    {
        if (root1->kontainer != root2->kontainer)
        {
            hasil = 0;
        }
        else
        {
            isEquel(root1->left, root2->left);
            isEquel(root1->right, root2->right);
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













