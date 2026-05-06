// Diwei Victor Nicolay - 193014

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

void show(node* root, int level = 0)
{
    if (!root) {
        std::cout << std::string(level, '\t') << "∅" << "\n";
        return;
    }

    std::cout << std::string(level, '\t') << root->value << "\n";
    if (!root->left && !root->right)
        return;

    show(root->left, level + 1);
    show(root->right, level + 1);
}

void destroy(node* root)
{
    if (!root)
        return;

    destroy(root->left);
    destroy(root->right);
    delete root;
}

// TODO: criar a sua função aqui
bool is_strict(node* root) {
    if (!root) return true;
    if ((root->left && !root->right) || (!root->left && root->right)) return false;
    return is_strict(root->left) && is_strict(root->right);
}

} 
