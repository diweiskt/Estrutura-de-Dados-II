/*
Escrever um programa que recebe o nome de dois arquivos 
e copia o conteúdo do primeiro arquivo para o segundo, 
exceto os espaços em brancos e, ao final, mostra o número 
de caracteres que foram copiados.
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

    ifstream arq;
    string nome1, nome2;

    getline(cin,nome1);

    arq.open(nome1);

    if(!arq){
        cout << "nao abriu" << endl;
        exit(1);
    }
    
    getline(cin,nome2);

    char ch;
    string word;
    int totalCaracteres = 0;

    while(arq.get(ch)){
        if(!(ch==' ')){
            word += ch;
            totalCaracteres++;
        }
    }
    arq.close();

    ofstream copiar(nome2,ios::app); //ios::app acrescenta o conteudo do arq(nome1) para o copiar(nome2) ao inves de substituir
    copiar << word;

    copiar.close();

    cout << "Foram copiados " << totalCaracteres << " caracteres" <<endl;

    return 0;
}