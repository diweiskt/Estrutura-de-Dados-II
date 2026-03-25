#include <cctype>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct wordcount {
    string word;
    int count;
};

const int HASHSIZE = 101; // Um número primo maior ajuda a evitar colisões

unsigned hashfn(const string& str) {
    unsigned hash = 0;
    for (char c : str) {
        hash = hash * 31 + unsigned(c); // Multiplicador ajuda na distribuição
    }
    return hash % HASHSIZE;
}

int main() {
    ifstream arq("clarissa.txt");
    if (!arq.is_open()) {
        cerr << "Erro ao abrir o arquivo clarissa.txt" << endl;
        return 1;
    }

    char ch;
    string word = "";
    int nchar = 0, nwords = 0;
    vector<wordcount> hash_table[HASHSIZE];

    while (arq.get(ch)) {
        nchar++;
        if (isalpha(static_cast<unsigned char>(ch))) {
            word += tolower(static_cast<unsigned char>(ch));
        } else if (!word.empty()) {
            nwords++;
            unsigned index = hashfn(word) % HASHSIZE;
            bool found = false;

            // Busca apenas no balde (bucket) específico
            for (auto& wc : hash_table[index]) {
                if (wc.word == word) {
                    wc.count++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                hash_table[index].push_back({word, 1});
            }
            word = ""; 
        }
    }
    arq.close(); // Fecha após ler tudo

    // Gravação dos resultados
    ofstream csv("dados.csv");
    int total_distinct = 0;
    for (int i = 0; i < HASHSIZE; i++) {
        for (const auto& wc : hash_table[i]) {
            csv << "\"" << wc.word << "\";" << wc.count << "\n";
            total_distinct++;
        }
    }
    csv.close();

    cout << "\nDISTRIBUIÇÃO DA TABELA HASH\n\n";

    int total_distintas = 0;
    for (int i = 0; i < HASHSIZE; i++) {
        int tamanho_balde = hash_table[i].size();
        total_distintas += tamanho_balde;

        // Exibe o número do vetor e quantos itens ele contém
        cout << i << "\t| " << tamanho_balde << "\n";
    }

    cout << nchar << "\n caracteres lidos\n"
         << nwords << " palavras totais\n"
         << total_distinct << " palavras distintas\n";

    return 0;
}