#include <cctype>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct wordcount {
  string word;
  int count;
};

const int HASHSIZE = 1000;

// unsigned hashfn(const string &str) {
//   unsigned sum = 0;
//   for (auto c : str)
//     sum += unsigned(c);

//   return sum % HASHSIZE;
// }

unsigned hashfn(const string &str) { // DJB2
  unsigned hash = 5381;
  for (auto c : str)
    hash = hash * 33 + unsigned(c);

  return hash % HASHSIZE;
}

int main() {
  ifstream arq("clarissa.txt");
  // TODO: testar se abriu com sucesso
  char ch;
  string word;
  int nchar = 0, nwords = 0;
  vector<wordcount> distinctwords[HASHSIZE];

  while (arq.get(ch)) { // Lê um caracter por vez
    nchar++;
    if (isalpha(ch)) {       // É letra?
      word += tolower(ch);   // Concatena em minúsculo
    } else if (word != "") { // Não é letra e existe uma palavra
      bool found = false;
      auto h = hashfn(word);
      for (auto &wc : distinctwords[h]) { // para cada palavra contida no vector
        if (wc.word == word) {            // se já existe
          wc.count++;                     // incrementa contagem
          found = true;
          break;
        }
      }
      if (!found) {                            // Não achou
        distinctwords[h].push_back({word, 1}); // Insere com count=1
      }
      word = ""; // Limpa
      nwords++;
    }
  }
  arq.close();

  ofstream csv("dados.csv");
  int total = 0;
  for (int h = 0; h < HASHSIZE; h++) {
    for (auto &wc : distinctwords[h]) {
      csv << "\"" << wc.word << "\";" << wc.count << "\n";
    }
    total += distinctwords[h].size();
    cout << h << '\t' << distinctwords[h].size() << '\n';
  }
  csv.close();

  cout << nchar << " caracteres\n"
       << nwords << " palavras\n"
       << total << " distintas\n";
}