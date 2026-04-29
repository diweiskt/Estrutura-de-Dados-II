/*
beecrowd | 1200
Operações em ABP I

Marcela recebeu como trabalho de Algoritmos a tarefa de fazer um programa que implemente uma 
Árvore Binária de Pesquisa (ou Busca). O Programa deve aceitar os seguintes comandos:

I n: Insere na árvore binária de pesquisa o elemento n.
INFIXA: lista os elementos já cadastrado segundo o percurso infixo
PREFIXA: lista os elementos já cadastrado segundo o percurso prefixo
POSFIXA: lista os elementos já cadastrado segundo o percurso posfixo
P n: pesquisa se o elemento n existe ou não.
A qualquer momento pode-se inserir um elemento, visitar os elementos previamente inseridos na ordem infixa, 
prefixa ou posfixa ou ainda procurar por um elemento na árvore para saber se o elemento existe ou não.

Entrada
A entrada contém N operações utilizando letras (A-Z,a-z) sobre uma árvore binária de Busca, que inicialmente 
se encontra vazia. A primeira linha de entrada contém a inserção de algum elemento. As demais linhas de entrada 
podem conter quaiquer um dos comandos descritos acima, conforme exemplo abaixo. O final da entrada é determinado pelo final de arquivo (EOF).

Obs: Considere que não serão inseridos elementos repetidos na árvore.

Saída
Cada linha de entrada, com exceção das linhas que contém o comando "I", deve produzir uma linha de saída. 
A saída deve ser de acordo com o exemplo fornecido abaixo. Não deve haver espaço em branco após o último 
caractere de cada linha, caso contrário, sua submissão receberá Presentation Error.
*/
#include <iostream>

using namespace std;

struct node {
    string value;
    node* left;
    node* right;
};

node* createnode(const string& val) {
    node* nd = new node;
    nd->value = val;
    nd->left = nd->right = nullptr;
    return nd;
}

void insert(node *&root, const string &val) {
    if(!root) root = createnode(val);
    else if(val < root->value) insert(root->left, val);
    else if(val > root->value) insert(root->right, val);
}

bool primeiro;

void DFS_inOrder(node *root) {
    if(!root) return;
    DFS_inOrder(root->left);
    if(!primeiro) cout << " ";
    cout << root->value;
    primeiro = false;
    DFS_inOrder(root->right);
}

void DFS_preOrder(node *root) {
    if(!root) return;
    if(!primeiro) cout << " ";
    cout << root->value;
    primeiro = false;
    DFS_preOrder(root->left);
    DFS_preOrder(root->right);
}

void DFS_postOrder(node *root) {
    if(!root) return;
    DFS_postOrder(root->left);
    DFS_postOrder(root->right);
    if(!primeiro) cout << " ";
    cout << root->value;
    primeiro = false;
}

void pesquisa(node *root, const string &val) {
    if (!root) {
        cout << val << " nao existe" << endl;
        return;
    }
    if (root->value == val) {
        cout << val << " existe" << endl;
        return; 
    }
    if (val < root->value) pesquisa(root->left, val);
    else pesquisa(root->right, val);
}

int main() {
    node *root = nullptr;
    string entrada;

    while(cin >> entrada) {
        if(entrada == "I") {
            string elemento;
            cin >> elemento;
            insert(root, elemento);
        }
        else if(entrada == "INFIXA") {
            primeiro = true;
            DFS_inOrder(root);
            cout << "\n";
        }
        else if(entrada == "PREFIXA") {
            primeiro = true;
            DFS_preOrder(root);
            cout << "\n";
        }
        else if(entrada == "POSFIXA") {
            primeiro = true;
            DFS_postOrder(root);
            cout << "\n";
        }
        else if(entrada == "P") {
            string n;
            cin >> n;
            pesquisa(root, n);
        }
    }

    return 0;
}