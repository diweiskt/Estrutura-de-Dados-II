/*
beecrowd | 3484
Turma Dividida
Por Marcos José Brusso, UPF BR Brazil

Na escola Brincadeira e Sabedoria Total, a turma do 5º ano está sempre curiosa para a chegada 
do recreio, pois a professora incentiva seus alunos a aprenderem de maneiras divertidas e criativas. 
Numa tarde de sol, ela pensou em dividir os alunos em duas filas, com os mais altos na direita e os 
mais baixos na esquerda. Mas depois a professora percebeu que poderia ficar mais divertido se cada 
fila fosse sempre subdividida em duas com esta mesma lógica. Então ela definiu as seguintes regras para a brincadeira:

Início da Fila: A primeira criança a entrar na brincadeira fica na frente da fila.
Comparação de Altura: Cada nova criança que entrar na brincadeira compara sua altura com a da primeira criança:
Se for mais baixa, vai para a fila da esquerda.
Se for mais alta, vai para a fila da direita.
Subdivisões das Filas: Cada vez que uma criança chega na posição já ocupada por outra criança, ela 
compara sua altura com a altura daquele/a colega até encontrar uma posição livre:
Se for mais baixa, continua indo para a esquerda.
Se for mais alta, continua indo para a direita.
Ao encontrar uma posição livre, fica lá.
Por exemplo, dada a seguinte sequência de crianças entrando na brincadeira, com a respectiva altura 
anotada em centímetros [130, 120, 140, 115, 125, 135, 145, 142, 138] a turma ficaria organizada com a seguinte disposição:



Como a brincadeira se mostrou divertida, a professora solicitou que você escrevesse um programa que, 
dada a ordem de entrada dos alunos na brincadeira, exibe qual é a altura da menor criança que está em 
cada um dos níveis desta estrutura. Entende-se por nível a distância entre a que está no início da fila 
(a primeira a entrar) e cada uma das demais, considerando-se um espaçamento uniforme.

Entrada
A entrada contém um único caso de teste. A primeira linha contém um inteiro N (1 ≤ N < 250) indicando a 
quantidade de alunos na turma. A segunda linha vai conter N inteiros H1, H2, ...., Hn representando a altura 
em centímetros de cada um dos alunos (50 ≤ Hi ≤ 300). Considerar que não existem dois estudantes com exatamente a mesma altura em uma turma.

Saída
A saída é formada por uma sequência de linhas contendo dois inteiros separados por espaço: o número do 
nível (iniciando em 0) e a altura da menor criança que está posicionada naquele nível.
*/

#include <iostream>
#include <queue>

using namespace std;

struct node {
    int value;
    node* left;
    node* right;
};

node* createnode(int val)
{
    node* nd = new node;
    nd->value = val;
    nd->left = nd->right = nullptr;
    return nd;
}

void insert(node *&root, int val){
    if(!root){
        root = createnode(val);
    }
    else if(root->value > val){
        insert(root->left, val);
    }
    else if(root->value < val){
        insert(root->right, val);
    }
}

void show_Por_level(node *root) {
    if (!root) return;

    std::queue<node*> fila;
    fila.push(root);
    int level = 0;

    while (!fila.empty()) {
        int nosNoNivel = fila.size();
        
        node* menorDoNivel = fila.front(); 

        std::cout << level << " " << menorDoNivel->value << endl;

        for (int i = 0; i < nosNoNivel; ++i) {
            node* atual = fila.front();
            fila.pop();

            if (atual->left) fila.push(atual->left);
            if (atual->right) fila.push(atual->right);
        }

        level++;
    }
}

int main(){
    node *root = nullptr;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int altura;
        cin >> altura;
        insert(root,altura);
    }
    show_Por_level(root);


    return 0;
}