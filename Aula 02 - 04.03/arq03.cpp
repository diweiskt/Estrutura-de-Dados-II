#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cctype> // Biblioteca para ver se é isupper(letra maiuscula) ou islower(letra minuscula)

using namespace std;

int main(){
  ifstream arq;
  int cont=0;

  arq.open("gpl3.txt");

  if(!arq){
    cout << "Não abriu" << endl;
    exit(1);
  }
  char ch;
  int maiusculas = 0, minusculas = 0, quantos_as = 0;
  while(arq.get(ch)){
    if(isupper(ch)){
        maiusculas++;
    }
    else if(islower(ch)){
        minusculas++;

        if(ch=='a' || ch=='A')
            quantos_as++;
    }
  }

  arq.close();
  cout << maiusculas << " letras maiúsculas\n"
       << minusculas << " letras minúsculas\n"
       << quantos_as << " As encontrados" << endl;

  return 0;
}