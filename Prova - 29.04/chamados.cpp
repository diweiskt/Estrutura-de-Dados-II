// Diwei Victor Nicolay - 193014
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>

using namespace std;

int main(){

    ifstream arq;
    arq.open("atendimentos_2.txt"); // tenta abrir o arquivo
    if(!arq){ // Se não abriu o arquivo, faça isso:
        cout << "não foi possivel abrir o arquivo!" << endl;
        exit(1); // Termina a execução do programa
    }

    unordered_map<string, int> atendimentos;

    string linha;
    char ch;
    int totalAtendimento = 0;
    while(getline(arq,linha)){
        if(linha != ""){
            atendimentos[linha]++;
            totalAtendimento++;
        }
    }
    for (auto const& [palavra, total] : atendimentos) {
        cout << "";
}

    arq.close();

    double porcento;

    ofstream csv("atendimentos.csv");
        csv << "Funcionario,Percentual\n";
    for(auto [funcionario, value]: atendimentos ){
        porcento = (value * 100.0) / totalAtendimento;
        csv << funcionario << ',' << fixed << setprecision(4)<< porcento << '\n';
    }
    csv.close();

    cout << totalAtendimento << " atendimentos\n";

    return 0;
}