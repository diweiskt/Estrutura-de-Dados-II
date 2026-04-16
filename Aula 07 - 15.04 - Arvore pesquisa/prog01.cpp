#include "binarytree.cpp"
#include <iostream>

using namespace binarytree;

int main()
{
    node* root         = createnode("A");
    root->left         = createnode("B");
    root->left->left   = createnode("D");
    root->left->right  = createnode("E");
    root->right        = createnode("C");
    root->right->left  = createnode("F");
    root->right->right = createnode("G");

    std::cout << "DFS preOrder: ";
    DFS_preOrder(root);

    std::cout << "\nDFS inOrder: ";
    DFS_inOrder(root);

    std::cout << "\nDFS postOrder: ";
    DFS_postOrder(root);

    std::cout << "\nBFS: ";
    BFS(root);

    std::cout << "\n";

    destroy(root);
}

/*
NLR - Pre-order:  A B D E C F G
LNR - In-order:   D B E A F C G
LRN - Post-order: D E B F G C A
BFS:              A B C D E F G
*/