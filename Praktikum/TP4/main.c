#include "header.h"

int main() 
{
    //deklarasi variable
    tree T;                                     //pohon            
    char query[101], str1[101], str2[101];      //masukan query
    int stop = 0, last = 0, i, n = 1, lvl = 0;  //penanda

    //selama stop masih 0
    while (stop == 0) 
    {
        //scan query
        scanf("%s", &query);
        //jika != END; maka,
        if (strcmp(query, "END;") != 0) 
        {
            //jika querynya MAKETREE
            if (strcmp(query, "MAKETREE") == 0) 
            {
                scanf("%s", &str1);
                last = strlen(str1);
                str1[last - 1] = '\0';
                makeTree(str1, &T);
            }
            //jika querynya CHILD
            else if (strcmp(query, "CHILD") == 0) 
            {
                scanf("%s %s", &str1, &str2);
                last = strlen(str2);
                str2[last - 1] = '\0';
                simpul *find = NULL;
                find = findSimpul(str2, T.root);
                if (find != NULL) 
                {
                    addChild(str1, find);
                }
            }
            //jika querynya DELCHILD
            else if (strcmp(query, "DELCHILD") == 0) 
            {
                scanf("%s %s", &str1, &str2);
                last = strlen(str2);
                str2[last - 1] = '\0';
                simpul *find = NULL;
                find = findSimpul(str2, T.root);
                if (find != NULL) 
                {
                    delChild(str1, find);
                }
            }
            //jika querynya PREORDER
            else if (strcmp(query, "PREORDER;") == 0) 
            {
                //print secara preorder
                printf("Output %d:\n", n);
                printf("=========\n");
                printTreePreOrder(T.root, lvl);
                n++;
            }
            //jika querynya POSTORDER
            else if (strcmp(query, "POSTORDER;") == 0) 
            {
                //print secara postorder
                printf("Output %d:\n", n);
                printf("=========\n");
                printTreePostOrder(T.root, lvl);
                n++;
            }
            stop = 0;
        }
        //jika querynya END;
        else if (strcmp(query, "END;") == 0) 
        {
            stop = 1;   //stop menjadi 1
        }
        //masih menerima selain query
        else 
        {
            stop = 0;
        }
    }
    printf("=========\n");

    return 0;
}