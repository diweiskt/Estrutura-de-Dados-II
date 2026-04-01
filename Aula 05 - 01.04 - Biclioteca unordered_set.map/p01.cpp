#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    unordered_map<int, string> alunos;

    alunos[987654] = "Fulano de Tal";
    alunos[808080] = "Maria Jose";
    alunos[101010] = "João Binario";

    int mat;
    while(true){
        cout << "Consulta na turma com "
             << alunos.size()
             << " alunos\n";
        cout << "Matricula (0 para sair): ";
        cin >> mat;
        if(mat==0) break;
        if(alunos.count(mat)==0){
            cout << "Matricula não encontrada\n";
        }
        else{
            cout << alunos[mat] << endl;
        }
    }

    return 0;
}