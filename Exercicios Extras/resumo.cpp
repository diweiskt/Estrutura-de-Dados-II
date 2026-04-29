#include <iostream>
#include <string>
#include <algorithm> // Necessário para o std::max
#include <queue>     // Necessário para a BFS (Busca em Largura)

namespace tree {

    struct node {
        std::string value;
        node *left;
        node *right;
    };

    // Cria um novo nó isolado
    node *create_node(const std::string &str_value) {
        node *p = new node;
        p->value = str_value;
        p->left = nullptr;
        p->right = nullptr;
        return p;
    }

    // Calcula a altura (maior distância da raiz até uma folha)
    int height(node *root) {
        if (root == nullptr) return -1; // Árvore vazia tem altura -1
        return std::max(height(root->left), height(root->right)) + 1;
    }

    // --- TRAVESSIAS DFS (Busca em Profundidade) ---

    // Pré-Ordem: Raiz -> Esquerda -> Direita
    void DFS_pre(node *root) {
        if (!root) return;
        std::cout << root->value << " ";
        DFS_pre(root->left);
        DFS_pre(root->right);
    }

    // Em-Ordem: Esquerda -> Raiz -> Direita (Em BST, gera os dados ordenados)
    void DFS_in(node *root) {
        if (!root) return;
        DFS_in(root->left);
        std::cout << root->value << " ";
        DFS_in(root->right);
    }

    // Pós-Ordem: Esquerda -> Direita -> Raiz (Útil para deletar a árvore)
    void DFS_post(node *root) {
        if (!root) return;
        DFS_post(root->left);
        DFS_post(root->right);
        std::cout << root->value << " ";
    }

    // --- TRAVESSIA BFS (Busca em Largura / Por Nível) ---
    void BFS(node *root) {
        if (!root) return;
        std::queue<node *> fila;
        fila.push(root);

        while (!fila.empty()) {
            node *aux = fila.front();
            fila.pop();
            std::cout << aux->value << " ";
            
            if (aux->left) fila.push(aux->left);
            if (aux->right) fila.push(aux->right);
        }
    }

    // --- OPERAÇÕES DE BST (Árvore Binária de Busca) ---

    // Inserção Lógica: Menores à esquerda, maiores à direita
    // Importante: Passagem por REFERÊNCIA (node* &root) para alterar o ponteiro original
    void BST_insert(node * &root, const std::string &val) {
        if (!root) {
            root = create_node(val);
        } else if (val < root->value) {
            BST_insert(root->left, val);
        } else if (val > root->value) {
            BST_insert(root->right, val);
        }
    }

    // Busca um valor: Retorna o endereço do nó se achar, ou nullptr
    node* BST_find(node *root, const std::string &val) {
        if (!root || root->value == val) return root;
        if (val < root->value) return BST_find(root->left, val);
        return BST_find(root->right, val);
    }

    // Encontra o Pai de um nó específico
    node* find_parent(node *root, const std::string &val, node *parent = nullptr) {
        if (!root) return nullptr;
        if (root->value == val) return parent; // Se achei o valor, retorno quem me chamou (o pai)

        if (val < root->value) 
            return find_parent(root->left, val, root);
        else 
            return find_parent(root->right, val, root);
    }

    // Limpeza de memória (Obrigatório em C++)
    void destroy(node * &root) {
        if (!root) return;
        destroy(root->left);
        destroy(root->right);
        delete root;
        root = nullptr;
    }
}