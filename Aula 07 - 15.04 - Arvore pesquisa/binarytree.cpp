// Binary tree
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

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

void DFS_preOrder(node *root){
    if(!root) return;                     // Se a árvore é vazia, retorna

    std::cout << root->value << " ";      // visita o nodo   (N)
    DFS_preOrder(root->left);             // visita esquerda (L)
    DFS_preOrder(root->right);            // visita direita  (R)
}

void DFS_inOrder(node *root){
    if(!root) return;

    DFS_inOrder(root->left);
    std::cout << root->value << " ";
    DFS_inOrder(root->right);
}

void DFS_postOrder(node *root){
    if(!root) return;

    DFS_postOrder(root->left);
    DFS_postOrder(root->right);
    std::cout << root->value << " ";
}

void BFS(node *root){
    if(!root) return;

    std::queue<node *> q;

    q.push(root);
    while(!q.empty()){
        auto current = q.front();
        std::cout << current->value << " ";
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
        q.pop(); 
    }
}

// Deleta Arvore inteira
void destroy(node *root){
    if(!root) return;

    destroy(root->left);
    destroy(root->right);
    delete root;
}

} // namespace binarytree

/*
NLR - Pre-order
LNR - In-order
LRN - Post-order
*/