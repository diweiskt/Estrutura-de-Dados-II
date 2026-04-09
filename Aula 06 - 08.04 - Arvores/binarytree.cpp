// Binary tree
#include <algorithm>
#include <iostream>
#include <string>

namespace binarytree {

struct node {
    std::string value;
    node* left;
    node* right;
};

node* createnode(const std::string& val)
{
    node* nd = new node;
    nd->value = val;
    nd->left = nd->right = nullptr;
    return nd;
}

// Calcula a altura da árvore
int height(node* root)
{
    if (!root)
        return -1;

    return std::max(height(root->left), height(root->right)) + 1;
}

// Representação por barras
void show(node* root, int level=0)
{
    if (!root){
        std::cout << std::string(level, '\t') << "∅" << "\n";
        return;
    }

    std::cout << std::string(level, '\t') << root->value << "\n";
    if(!root->left && !root->right) return;

    show(root->left, level+1);
    show(root->right, level+1);
}

// Representação por parênteses aninhado
void show2(node* root)
{
    if (!root){
        std::cout << "∅";
        return;
    }

    std::cout << "(" << root->value;

    if(root->left || root->right){
      show2(root->left);
      show2(root->right);
    }
    std::cout << ")";
}
} // namespace binarytree