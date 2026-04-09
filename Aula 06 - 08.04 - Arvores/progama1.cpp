#include "binarytree.cpp"
#include <iostream>

using namespace binarytree;

int main(){
    node *root=createnode("A");
    root->left = createnode("B");
    root->right = createnode("C");
    root->left->left = createnode("D");
    root->left->right = createnode("E");
    root->left->right->left = createnode("F");

    std::cout << "Altura: " << height(root) << "\n\n";
    show(root);

    return 0;
}