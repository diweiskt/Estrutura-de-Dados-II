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