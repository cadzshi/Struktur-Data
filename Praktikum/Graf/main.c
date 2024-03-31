#include "header.h"

int main()
{
    int input;
    scanf(" %c", &input);

    graph G;
    createEmpty(&G);
    addSimpul('1', &G);
    addSimpul('2', &G);
    addSimpul('3', &G);
    addSimpul('4', &G);
    addSimpul('5', &G);
    addSimpul('6', &G);
    addSimpul('7', &G);
    addSimpul('8', &G);

    simpul *begin = findSimpul('1', G);
    simpul *end = findSimpul('2', G);

    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    begin = findSimpul('1', G);
    end = findSimpul('7', G);

    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    begin = findSimpul('1', G);
    end = findSimpul('5', G);

    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    begin = findSimpul('1', G);
    end = findSimpul('4', G);

    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    begin = findSimpul('2', G);
    end = findSimpul('3', G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    begin = findSimpul('2', G);
    end = findSimpul('6', G);

    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    begin = findSimpul('3', G);
    end = findSimpul('8', G);

    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    begin = findSimpul('4', G);
    end = findSimpul('7', G);

    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    begin = findSimpul('6', G);
    end = findSimpul('8', G);

    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    printGraph(G);
    begin = findSimpul('1', G);

    if ((begin != NULL))
    {
        delJalur(input, begin);
    }
    delSimpul(input, &G);
    printf("==============\n");
    printGraph(G);
    return 0;
}