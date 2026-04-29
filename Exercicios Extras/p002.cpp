/*2. Variação A: Comparação de Arquivos (Diferença de Conjuntos)
Cenário: Você tem um arquivo com "Todos os Alunos" e outro com "Alunos que Entregaram". Descubra quem não entregou usando unordered_set.

C++
#include <unordered_set>
// ... (abertura de arquivos)
unordered_set<string> entregaram;
string matricula;

while(arqEntregas >> matricula) entregaram.insert(matricula);

while(arqTodos >> matricula) {
    if(entregaram.find(matricula) == entregaram.end()) {
        cout << "Faltou entregar: " << matricula << endl;
    }
}
3. Variação B: Árvores (Localizar Pai e Nível)
Baseado no seu tree.cpp, uma questão comum é encontrar o nó pai de um valor ou verificar em qual nível ele está.

C++
// Função para encontrar o pai de um nó na BST
node* findParent(node* root, string val, node* parent = nullptr) {
    if (!root) return nullptr;
    if (root->value == val) return parent;
    
    if (val < root->value) 
        return findParent(root->left, val, root);
    else 
        return findParent(root->right, val, root);
}

// Função para retornar o nível de um nó (Raiz = 0)
int getNodeLevel(node* root, string val, int level = 0) {
    if (!root) return -1;
    if (root->value == val) return level;
    
    if (val < root->value) 
        return getNodeLevel(root->left, val, level + 1);
    else 
        return getNodeLevel(root->right, val, level + 1);
}
4. Variação C: Frequência com Ordenação
Se a prova pedir para ler um arquivo e mostrar as palavras e suas contagens em ordem alfabética, você deve trocar unordered_map por map.

C++
#include <map>
map<string, int> frequencia;
// ... leitura do arquivo
for(auto const& [palavra, qtd] : frequencia) {
    cout << palavra << " aparece " << qtd << " vezes." << endl;
}


💡 Dicas Finais para a Prova:
Limpeza de String: Se o arquivo tiver pontuação (vírgulas, pontos), lembre-se de limpar a string antes de inserir no map.

Busca em Árvore: Se a árvore NÃO for de busca (BST), você não pode usar if (val < root->value). Você terá que buscar em ambos os lados: search(root->left) || search(root->right).

Saída CSV: No Excel/CSV, o separador padrão costuma ser ;. Não esqueça de colocar o \n ao final de cada linha do relatório.

Feche os arquivos: Professores tiram pontos se você abrir 10 arquivos e não der close() em nenhum.*/