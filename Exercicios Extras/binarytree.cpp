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

// Escrever, na biblioteca binarytree.cpp, a função void show_level(node *root, int level); 
//Ela exibe apenas os nós (nodes) de uma árvore que estão no nível fornecido no segundo parâmetro. 
//Segundo Szwarcfiter "Nível de um nó v é o número de nós do caminho da raiz até o nó v. 
//O nível da raiz é, portanto, igual a 1." Caso não exista nenhum nó naquele nível, a função não deve exibir nada.
void show_level(node *root, int level){
    if (!root){
        return;
    }
    if(level == 1){
        std::cout << root->value << " ";
        return;
    }
    show_level(root->left, level - 1);
    show_level(root->right, level - 1);
}

void pesquisa(node *root, const std::string &val) {
    if (!root) {
        std::cout << val << " nao existe\n";
        return;
    }
    if (root->value == val) {
        std::cout << val << " existe\n";
        return; 
    }
    if (val < root->value) pesquisa(root->left, val);
    else pesquisa(root->right, val);
}

void show_Por_level(node *root) {
    if (!root) return;

    std::queue<node*> fila;
    fila.push(root);
    int level = 0;

    while (!fila.empty()) {
        int nosNoNivel = fila.size();
        
        // Em uma BST, se inserirmos o 'left' antes do 'right', 
        // o primeiro nó retirado da fila em cada nível será o menor.
        node* menorDoNivel = fila.front(); 

        // Imprime o nível e o menor valor separados por espaço
        std::cout << level << " " << menorDoNivel->value << std::endl;

        // Processamos todos os nós do nível atual para colocar os filhos na fila
        for (int i = 0; i < nosNoNivel; ++i) {
            node* atual = fila.front();
            fila.pop();

            // Adiciona os filhos para o próximo nível
            if (atual->left) fila.push(atual->left);
            if (atual->right) fila.push(atual->right);
        }

        level++;
    }
}

} // namespace binarytree

/*
NLR - Pre-order
LNR - In-order
LRN - Post-order
*/