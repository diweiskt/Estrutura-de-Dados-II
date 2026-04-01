#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cctype> // Biblioteca para ver se é isupper(letra maiuscula) ou islower(letra minuscula)
#include <iomanip>


using namespace std;

int main(){
  ifstream arq;

  arq.open("gpl3.txt");

  if(!arq){
    cout << "Não abriu" << endl;
    exit(1);
  }
  char ch;
  int frequencia[256] = {}; // "= {}" zera todo o vetor ao iniciar
  while(arq.get(ch)){       // lê cada caracter do arquivo
    frequencia[unsigned(ch)]++; // Incrementa aquele indice daquele car
              // unsigned pega o numero correspondente do char
  }

  for(int i=0; i<256;i++){
    if(frequencia[i] > 0){
        cout << setw(3) << setfill('0') << i       // Mostra o numero do char
             << " "
             << (isprint(i) ? char(i) : ' ')
             << " " 
             << setw(4) << setfill(' ') << frequencia[i] 
             << "\n";
    }
  }

  arq.close();


  return 0;
}