#include "header.h"

int main()
{
    tree T;
    char input;

    scanf(" %c", &input);
    makeTree(input, &T);

    scanf(" %c", &input);
    addRight(input, T.root);

    scanf(" %c", &input);
    addLeft(input, T.root);

    scanf(" %c", &input);
    addLeft(input, T.root->right);

    scanf(" %c", &input);
    addRight(input, T.root->left);

    scanf(" %c", &input);
    addRight(input, T.root->right);

    scanf(" %c", &input);
    addLeft(input, T.root->left->right);

    scanf(" %c", &input);
    addRight(input, T.root->right->left);

    scanf(" %c", &input);
    addRight(input, T.root->left->right);

    scanf(" %c", &input);
    addRight(input, T.root->right->right);

    scanf(" %c", &input);
    addLeft(input, T.root->right->right);

    scanf(" %c", &input);
    addLeft(input, T.root->left->right->left);

    scanf(" %c", &input);
    addLeft(input, T.root->right->left->right);

    scanf(" %c", &input);
    addRight(input, T.root->right->left->right);

    // printf("Pre Order:\n");
    // printTreePreOrder(T.root);
    printTree("preorder", T.root);

    delLeft(T.root->left->right->left);

    // printf("\nIn Order:\n");
    // printTreeInOrder(T.root);
    printTree("inorder", T.root);

    delRight(T.root->right->right);

    printTree("postorder", T.root);
    // printf("\nPost Order:\n");
    // printTreePostOrder(T.root);
    printf("\n");

    return 0;
}
