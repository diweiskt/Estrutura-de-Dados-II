#include <cctype>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  ifstream arq("clarissa.txt");
  if(!arq){
    cout << "Não abriu arquivos de entrada\n";
    return 1;
  }
  char ch;
  string word;
  int nchar = 0, nwords = 0;
  unordered_map<string, int> distinctwords;

  while (arq.get(ch)) { // Lê um caracter por vez
    nchar++;
    if (isalpha(ch)) {       // É letra?
      word += tolower(ch);   // Concatena em minúsculo
    } else if (word != "") { // Não é letra e existe uma palavra
      distinctwords[word]++;

      word = ""; // Limpa
      nwords++;
    }
  }
  arq.close();

  ofstream csv("dados.csv");
  for(auto [key, value] : distinctwords){
    csv << '"' << key << '"' << ';' << value << '\n';
  }
  csv.close();

  cout << nchar << " caracteres\n"
       << nwords << " palavras\n"
       << distinctwords.size() << " distintas\n";
}