#include <iostream>
#include <cctype>
#include <fstream>
#include <vector>

using namespace std;

struct wordcount{
    string word; 
    int count;
};

int main(){

    ifstream arq("gpl3.txt");
    // TODO: testar se abriu com sucesso
    if(!arq){
        cout << "Não abriu" << endl;
        exit(1);
    }

    char ch;
    string word;
    int nchar=0, nwords=0;
    vector<wordcount> distinctwords;

    while(arq.get(ch)){              // Lê um caracter por vez  
        nchar++;               
        if(isalpha(ch)){            // "isalpha siginifica "é letra"
            word += tolower(ch);    // adiciona LETRA no word se for LETRA | tolower transforma tudo em minusculo
        }
        else if(!word.empty()){     // se word não estiver vazio(estiver com letra)
            bool found = false;
            for(auto &wc : distinctwords){   //para cada palavra diferente
                if(wc.word == word){          // se já existe
                    wc.count++;             //incrementa contagem
                    found = true;
                    break;
                }
            }
            if(!found){             // não achou
                distinctwords.push_back({word, 1}); //insere na struct palavra e contador
            }
            word.clear();
            nwords++;           // limpa word
        }
    }
    arq.close();

    cout << nchar << " caracteres\n"
         << nwords << " palavras\n"
         << distinctwords.size() << " distintas\n";
         
    ofstream csv("dados.csv");
    for(auto &wc : distinctwords){
        csv << "\"" << wc.word << "\";" << wc.count << endl; 
    }
    csv.close();

    return 0;
}