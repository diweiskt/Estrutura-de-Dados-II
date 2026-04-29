/*
Escrever um programa (letras.cpp) que abre um arquivo cujo nome foi informado pelo usuário. Exibir o percentual de letras 
e o percentual de outros caracteres armazenados no arquivo. Exibir os valores com 1 casa decimal. 
Seguir exatamente o modelo de saída abaixo:
exemplo.txt possui 73.2% de letras e 26.8% de outros caracteres
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    ifstream arq;
    string nome;
    cout << "nome do arquivo: " << endl;
    getline(cin,nome);
    arq.open(nome);

    if(!arq){
        cout << "nao abriu" << endl;
        exit(1);
    }

    char ch;
    double letras = 0, outros = 0;

    while(arq.get(ch)){
        if(isalpha(ch)){
            letras++;
        }
        else{
            outros++;
        }
    }
    arq.close();

    double total = letras + outros;
    double porcentoLetras = letras/total * 100;
    double porcentoOutros = outros/total * 100; 
    cout << nome << " possui " << fixed << setprecision(1) << porcentoLetras << "% de letras e "
         << setprecision(1) << porcentoOutros << "% outros caracteres" << endl;   

    return 0;
}