#include <cctype>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct wordcount {
  string word;
  int count;
};

int main() {
  ifstream arq("clarissa.txt");
  // TODO: testar se abriu com sucesso
  char ch;
  string word;
  int nchar = 0, nwords = 0;
  vector<wordcount> distinctwords;

  while (arq.get(ch)) { // Lê um caracter por vez
    nchar++;
    if (isalpha(ch)) {       // É letra?
      word += tolower(ch);   // Concatena em minúsculo
    } else if (word != "") { // Não é letra e existe uma palavra
      bool found = false;
      for (auto &wc : distinctwords) { // para cada palavra contida no vector
        if (wc.word == word) {         // se já existe
          wc.count++;                  // incrementa contagem
          found = true;
          break;
        }
      }
      if (!found) {                         // Não achou
        distinctwords.push_back({word, 1}); // Insere com count=1
      }
      word = ""; // Limpa
      nwords++;
    }
  }
  arq.close();
  cout << nchar << " caracteres\n"
       << nwords << " palavras\n"
       << distinctwords.size() << " distintas\n";

  ofstream csv("dados.csv");
  for(auto &wc : distinctwords){
    csv << "\"" << wc.word << "\";" << wc.count << "\n";
  }
  csv.close();
}