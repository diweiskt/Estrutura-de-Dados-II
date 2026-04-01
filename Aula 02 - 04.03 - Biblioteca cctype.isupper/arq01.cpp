#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main(){
  ifstream arq;
  int cont=0;

  arq.open("gpl3.txt");
  
  if(!arq){
    cout << "Não abriu" << endl;
    exit(1);
  }
  string linha;

  while(getline(arq, linha)){
    cout << linha << endl;
    cont++;
  }

  arq.close();
  cout << "\nForam lidas " << cont << " linhas\n";

  return 0;
}