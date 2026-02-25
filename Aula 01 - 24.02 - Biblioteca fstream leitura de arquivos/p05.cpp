//Exemplo de escrita em csv

#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ofstream tab;
    tab.open("tabela.csv");

    for(int i=0;i<100;i++){
        tab << dec << i << ";" << i * 10 << ";"
            << hex << uppercase << i << endl;
    }
    //i;i*10;hex(i)
    tab.close();

    return 0;
}