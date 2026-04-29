#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string nomeArq;
    // cin >> nomeArq; // Ou fixo se a questão pedir
    ifstream arq("dados.txt");

    if (!arq) {
        cerr << "Erro ao abrir arquivo!" << endl;
        return 1;
    }

    string linha;
    // Para ler linha por linha (útil para nomes com espaços):
    while (getline(arq, linha)) {
        // Remover \r se o arquivo for Windows (comum em maratonas)
        if (!linha.empty() && linha.back() == '\r') linha.pop_back();
        // Processar linha...
    }

    // Para ler palavra por palavra ou números:
    // while (arq >> variavel) { ... }

    arq.close();
}

#include <unordered_map>

unordered_map<string, int> contagem;
string palavra;

while(arq >> palavra) {
    contagem[palavra]++; // Se não existe, cria com 0 e soma 1.
}

// Para iterar e mostrar os resultados:
for (auto const& [palavra, total] : contagem) {
    cout << palavra << ": " << total << endl;
}

// Para verificar se algo existe sem inserir:
if (contagem.find("teste") != contagem.end()) { 
    // existe! 
}

#include <unordered_set>
unordered_set<string> proibidas = {"o", "a", "de", "com"};

if (proibidas.count(palavra)) { // Retorna 1 se existe, 0 se não
    // É uma palavra proibida, pule-a
}

struct node {
    int value; // ou string
    node *left, *right;
};

// --- FUNÇÕES EXTRAS ÚTEIS ---

// 1. Contar total de nós
int countNodes(node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 2. Encontrar o valor Mínimo (em uma BST é o mais à esquerda)
node* findMin(node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

// 3. Verificar se a árvore é estritamente binária (cada nó tem 0 ou 2 filhos)
bool isStrict(node* root) {
    if (!root) return true;
    if ((root->left && !root->right) || (!root->left && root->right)) return false;
    return isStrict(root->left) && isStrict(root->right);
}

// 4. Somar todos os valores (se forem inteiros)
int sumValues(node* root) {
    if (!root) return 0;
    return root->value + sumValues(root->left) + sumValues(root->right);
}

// 5. Mostrar nível específico (Baseado no seu arquivo p07.cpp)
void showLevel(node* root, int target, int current = 0) {
    if (!root) return;
    if (current == target) {
        cout << root->value << " ";
        return;
    }
    showLevel(root->left, target, current + 1);
    showLevel(root->right, target, current + 1);
}

/*
Dicas de Ouro para a Prova (Mindset)
Cuidado com o getline e cin >> misturados: Se você usar cin >> n e depois um getline, o getline vai ler o "Enter" que sobrou no buffer e vir vazio. 
Use cin.ignore() após o cin >>.
Passagem por Referência: Em funções de inserção ou que alteram a árvore, lembre-se de passar o ponteiro por referência: void insert(node* &root, int val). 
Sem o &, a alteração só vale dentro da função.Recursão vs Loop: Se a árvore for muito grande, a recursão pode dar stack overflow. 
Para percursos em largura (BFS), use sempre a Fila (std::queue) conforme seu arquivo binarytree.cpp.Complexidade:unordered_map/set: Busca é $O(1)$ (média). 
Use se a ordem não importar.map/set (comum): Busca é $O(\log n)$. Use se precisar dos dados ordenados.BST: Busca é $O(h)$, onde $h$ é a altura. 
Em uma árvore equilibrada, é $O(\log n)$.O Problema do \r: Se for ler arquivos .txt gerados no Windows em um ambiente Linux (ou Beecrowd), o \r no 
final das strings quebra comparações. Sempre limpe o final da string se for usar getline.
*/