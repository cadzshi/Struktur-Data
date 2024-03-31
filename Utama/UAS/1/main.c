#include "header.h"

int main()
{
    tree T;
    int n;
    char str1, str2[20], str3[20];

    scanf("%d", &n);
    scanf(" %c %s %s", &str1, &str2, &str3);
    makeTree(str1, &T);


    for (int i = 0; i < n + 1; i++)
    {
        scanf(" %c %s %s", &str1, &str2[i], &str3[i]);
    }
    
    printf("simpul anak satu:\n");
    printf("\n");
    printf("simpul daun:\n");
    printf("\n");

    return 0;
}