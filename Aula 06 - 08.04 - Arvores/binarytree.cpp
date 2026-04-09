// Binary tree
#include <string>
#include <algorithm>
#include <iostream>

namespace binarytree{

    struct node{
        std::string value;
        node *left;
        node *right;
    };

    //Função cria new node
    node *createnode(const std::string &val){
        node *nd = new node;
        nd->value = val;
        nd->left = nd->right = nullptr;
        return nd;
    }

    //Calcula a altura da árvore
    int height(node *root){
        if(!root) // if(root==nullptr)
            return -1;

        return std::max(height(root->left), height(root->right)) +1;
    }

    void show(node *root){
        if(!root)
            return;

        std::cout << root->value << "\n";
        if(root->left)
            std::cout << "Esquerda: ";
            show(root->left);

        if(root->right)
            std::cout << "Direita: ";
            show(root->right);

    }
} // namespace binarytree