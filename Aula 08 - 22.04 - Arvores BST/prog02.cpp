#include "binarytree.cpp"

using namespace binarytree;

int main()
{
    node *root = nullptr;

    BST::insert(root, "20");
    BST::insert(root, "05");
    BST::insert(root, "33");
    BST::insert(root, "17");
    BST::insert(root, "29");
    BST::insert(root, "10");
    BST::insert(root, "98");
    BST::insert(root, "51");

    //show(root);
    DFS_inOrder(root);
    destroy(root);
}