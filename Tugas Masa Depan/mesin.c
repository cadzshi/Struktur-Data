#include "header.h"

int max[201];

void makeTree(char nama[], char ortu[], int gaji, int pengalaman, int jmls, char listSkill[][201], tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    strcpy(node->nama, nama);
    strcpy(node->ortu, ortu);
    node->gaji = gaji;
    node->pengalaman = pengalaman;
    node->jmls = jmls;
    for (int i = 0; i < jmls; i++)
    {
        strcpy(node->listSkill[i], listSkill[i]);
    }
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addchild(char nama[], char ortu[], int gaji, int pengalaman, int jmls, char listSkill[][201], simpul *root)
{
    if (root != NULL)
    {
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        strcpy(baru->nama, nama);
        strcpy(baru->ortu, ortu);
        baru->gaji = gaji;
        baru->pengalaman = pengalaman;
        baru->jmls = jmls;
        for (int i = 0; i < jmls; i++)
        {
            strcpy(baru->listSkill[i], listSkill[i]);
        }
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

simpul *findsimpul(char c[], simpul *root)
{
    simpul *result = NULL;
    if (root != NULL)
    {
        if (strcmp(root->nama, c) == 0)
        {
            result = root;
        }
        else
        {
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    if (strcmp(bantu->nama, c) == 0)
                    {
                        result = bantu;
                    }
                    else
                    {
                        result = findsimpul(c, bantu);
                    }
                }
                else
                {
                    int found = 0;
                    while ((bantu->sibling != root->child) && (found == 0))
                    {
                        if (strcmp(bantu->nama, c) == 0)
                        {
                            result = bantu;
                            found = 1;
                        }
                        else
                        {
                            result = findsimpul(c, bantu);
                            bantu = bantu->sibling;
                            if (result != NULL)
                            {
                                found = 1;
                            }
                        }
                    }
                    if (found == 0)
                    {
                        if (strcmp(bantu->nama, c) == 0)
                        {
                            result = bantu;
                        }
                        else
                        {
                            result = findsimpul(c, bantu);
                        }
                    }
                }
            }
        }
    }
    return result;
}

void printTreePreOrder(simpul *root, int n, int lvl)
{
    if (root != NULL)
    {
        if (lvl != 0)
        {
            printf("\n");
        }
        for (int i = 0; i < n; i++)
        {
            printf(" ");
        }
        printf("|%s -", root->nama);
        if (root->gaji < 10000000 && root->gaji > 1000000)
        {
            printf(" 1 digit\n");
        }
        else if (root->gaji > 10000000 && root->gaji < 100000000)
        {
            printf(" 2 digit\n");
        }
        else if (root->gaji == 0)
        {
            printf(" 0 digit\n");
        }
        for (int i = 0; i < n; i++)
        {
            printf(" ");
        }
        printf(" - %d\n", root->gaji);
        for (int i = 0; i < n; i++)
        {
            printf(" ");
        }
        printf(" - %d tahun\n", root->pengalaman);
        for (int i = 0; i < root->jmls; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf(" ");
            }
            printf(" - %s\n", root->listSkill[i]);
        }
        n += max[lvl];
        lvl++;

        simpul *bantu = root->child;

        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                printTreePreOrder(bantu, n, lvl);
            }
            else
            {
                while (bantu->sibling != root->child)
                {
                    printTreePreOrder(bantu, n, lvl);
                    bantu = bantu->sibling;
                }
                printTreePreOrder(bantu, n, lvl);
            }
        }
    }
}

void Input(int banyak, char str[], data c[], int n)
{
    char str1[201], str2[201], str3[201], str4[201], str5[201];
    int jmls = 0, pengalaman = 0, gaji = 0,tag = 0;
    int i, i1 = 0, i2 = 0, i3 = 0, i4 = 0;

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '#')
        {
            tag++;
            continue;
        }
        if (tag == 0)
        {
            str1[i] = str[i];
        }
        if (tag == 1)
        {
            str2[i1] = str[i];
            i1++;
        }
        if (tag == 2)
        {
            str3[i2] = str[i];
            i2++;
        }
        if (tag == 3)
        {
            str4[i3] = str[i];
            i3++;
        }
        if (tag == 4)
        {
            str5[i4] = str[i];
            i4++;
        }
    }

    str1[i] = '\0';
    str2[i1] = '\0';
    str3[i2] = '\0';
    for (i = 0; i < strlen(str3); i++)
    {
        gaji *= 10;
        gaji += str3[i] - '0';
    }
    str4[i3] = '\0';
    for (i = 0; i < strlen(str4); i++)
    {
        pengalaman *= 10;
        pengalaman += str4[i] - '0';
    }
    str5[i4] = '\0';
    for (i = 0; i < strlen(str5); i++)
    {
        jmls *= 10;
        jmls += str5[i] - '0';
    }

    strcpy(c[n].nama, str1);
    strcpy(c[n].ortu, str2);
    c[n].gaji = gaji;
    c[n].pengalaman = pengalaman;
    c[n].jmlskill = jmls;
    char listSkill[jmls][201];

    for (i = 0; i < jmls; i++)
    {
        scanf("%s", listSkill[i]);
        strcpy(c[n].listSkill[i], listSkill[i]);
    }
}

void spasi(simpul *root, int len)
{
    int n = root->jmls, i = 0;
    int coba, coba1 = 0, coba2;
    int test[n];

    if (root != NULL)
    {
        for (i = 0; i <= n; i++)
        {
            test[i] = strlen(root->listSkill[i]) + 4;
            if (test[i] > coba1)
            {
                coba2 = test[i];
            }
            coba1 = test[i];
        }

        coba = strlen(root->nama) + 7;

        if (coba > max[len] || coba2 > max[len])
        {
            if (coba2 > max[len])
            {
                max[len] = coba2;
            }
            else if (coba > max[len])
            {
                max[len] = coba;
            }
        }

        len++;

        simpul *bantu = root->child;

        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                spasi(bantu, len);
            }
            else
            {
                while (bantu->sibling != root->child)
                {
                    spasi(bantu, len);
                    bantu = bantu->sibling;
                }
                spasi(bantu, len);
            }
        }
    }
}

void InTree(tree *T, data c[], int banyak)
{
    for (int i = 0; i < banyak; i++)
    {
        if ((strcmp(c[i].ortu, "null") == 0) || strcmp(c[i].ortu, "NULL") == 0)
        {
            makeTree(c[i].nama, c[i].ortu, c[i].gaji, c[i].pengalaman, c[i].jmlskill, c[i].listSkill, T);
        }
        else
        {
            simpul *node = findsimpul(c[i].ortu, (*T).root);
            if (node != NULL)
            {
                addchild(c[i].nama, c[i].ortu, c[i].gaji, c[i].pengalaman, c[i].jmlskill, c[i].listSkill, node);
            }
        }
    }
}