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
  char ch;
  while(arq.get(ch)){
    cout << ch;
  }

  arq.close();

  return 0;
}