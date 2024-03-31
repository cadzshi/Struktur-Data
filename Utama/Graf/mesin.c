#include "header.h"

void createEmpty(graph *G)
{
    (*G).first = NULL;
}

void addSimpul(char c, graph *G)
{
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    baru->kontainer = c;
    baru->next = NULL;
    baru->arc = NULL;

    if ((*G).first == NULL)
    {
        (*G).first = baru;
    }
    else
    {
        simpul *last = (*G).first;
        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = baru;
    }
}

void addJalur(simpul *awal, simpul *tujuan, int beban)
{

    jalur *baru;
    baru = (jalur *)malloc(sizeof(jalur));
    baru->kontainer_jalur = beban;
    baru->next_jalur = NULL;
    baru->tujuan = tujuan;

    if (awal->arc == NULL)
    {
        awal->arc = baru;
    }
    else
    {
        jalur *last = awal->arc;
        while (last->next_jalur != NULL)
        {
            last = last->next_jalur;
        }
        last->next_jalur = baru;
    }
}

simpul *findSimpul(char c, graph G)
{
    simpul *hasil = NULL;
    simpul *bantu = G.first;

    int ketemu = 0;
    while ((bantu != NULL) && (ketemu == 0))
    {
        if (bantu->kontainer == c)
        {
            hasil = bantu;
            ketemu = 1;
        }
        else
        {
            bantu = bantu->next;
        }
    }
    return hasil;
}

void delJalur(char ctujuan, simpul *awal)
{

    jalur *hapus = awal->arc;

    if (hapus != NULL)
    {
        jalur *prev = NULL;
        int ketemu = 0;
        while ((hapus != NULL) && (ketemu == 0))
        {
            if (hapus->tujuan->kontainer == ctujuan)
            {
                ketemu = 1;
            }
            else
            {
                prev = hapus;
                hapus = hapus->next_jalur;
            }
        }

        if (ketemu == 1)
        {
            if (prev == NULL)
            {
                awal->arc = hapus->next_jalur;
                hapus->next_jalur = NULL;
            }
            else
            {
                if (hapus->next_jalur == NULL)
                {
                    prev->next_jalur = NULL;
                }
                else
                {
                    prev->next_jalur = hapus->next_jalur;
                    hapus->next_jalur = NULL;
                }
            }
            free(hapus);
        }
        else
        {
            printf("tidak ada jalur dengan simpul tujuan\n");
        }
    }
    else
    {
        printf("tidak ada jalur dengan simpul tujuan\n");
    }
}

void delAll(simpul *awal)
{

    jalur *bantu;
    bantu = awal->arc;
    jalur *hapus;

    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next_jalur;
        hapus->next_jalur = NULL;
        free(hapus);
    }
}

void delSimpul(char c, graph *G)
{
    simpul *hapus = (*G).first;
    if (hapus != NULL)
    {
        simpul *prev = NULL;

        int ketemu = 0;
        while ((hapus != NULL) && (ketemu == 0))
        {
            if (hapus->kontainer == c)
            {
                ketemu = 1;
            }
            else
            {
                prev = hapus;
                hapus = hapus->next;
            }
        }
        if (ketemu == 1)
        {
            simpul *bantu;
            bantu = (*G).first;

            while (bantu != NULL)
            {
                if (bantu != hapus)
                {
                    delJalur(hapus->kontainer, bantu);
                }
                bantu = bantu->next;
            }
            delAll(hapus);

            if (prev == NULL)
            {
                (*G).first = hapus->next;
                hapus->next = NULL;
            }
            else
            {
                if (hapus->next == NULL)
                {
                    prev->next = NULL;
                }
                else
                {
                    prev->next = hapus->next;
                    hapus->next = NULL;
                }
            }
            free(hapus);
        }
        else
        {
            printf("tidak ada simpul dengan info karakter masukkan\n");
        }
    }
    else
    {
        printf("tidak ada simpul dengan info karakter masukkan\n");
    }
}

void printGraph(graph G)
{

    simpul *bantu = G.first;

    if (bantu != NULL)
    {
        while (bantu != NULL)
        {
            printf("Simpul : %c\n", bantu->kontainer);

            jalur *bantu_jalur = bantu->arc;

            while (bantu_jalur != NULL)
            {
                printf("  - ada jalur ke simpul : %c dengan beban : %d\n", bantu_jalur->tujuan->kontainer, bantu_jalur->kontainer_jalur);

                bantu_jalur = bantu_jalur->next_jalur;
            }
            bantu = bantu->next;
        }
    }
    else
    {
        printf("graph kosong\n");
    }
}
