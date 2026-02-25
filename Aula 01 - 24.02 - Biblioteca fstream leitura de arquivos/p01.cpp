/* Primeiro exemplo de entrada de dados
    utilizando um arquivo externo
*/

#include <iostream>
#include <fstream>  // lib para manipular arquivos

using namespace std;

int main(){
    int n;
    ifstream arq;
    arq.open("numeros.txt"); // tenta abrir o arquivo
    if(!arq){ // Se não abriu o arquivo, faça isso:
        cout << "não foi possivel abrir o arquivo!" << endl;
        exit(1); // Termina a execução do programa
    }
    // semelhante a while(cin >> n) p/ entradas do teclado
    while(arq >> n){ // enquanto tiver conteudo no arquivo, passa para o n
        cout << n * 3 << endl;
    }

    // Sempre que abre um arquivo, em seguida deve fechar
    arq.close(); // fecha o uso do arquivo pelo programa

    return 0;
}