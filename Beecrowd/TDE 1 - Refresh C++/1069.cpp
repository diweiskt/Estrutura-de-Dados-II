/*
Diamantes e areia

João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes "<>". 
Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de diamante, 
novos diamantes poderão se formar. Se ele tem como uma entrada .<...<<..>>....>....>>>., três
diamantes são formados. O primeiro é retirado de <..>, resultando  .<...<>....>....>>>. 
Em seguida o segundo diamante é retirado, restando .<.......>....>>>. O terceiro diamante é então 
retirado, restando no final .....>>>., sem possibilidade de extração de novo diamante.

Entrada
Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a 
seguir é um caso de teste que contém até 1000 caracteres, incluindo "<,>, ."

Saída
Você deve imprimir a quantidade de diamantes possíveis de serem extraídos em cada caso de entrada.
*/

#include <iostream>

using namespace std;

int main(){

    int N;
    string testes;

    cin >> N;
    for(int i=0;i<N;i++){
        int diamantes = 0;
        int esqEsperando = 0;

        cin >> testes;
        for(char ch : testes){
            if(ch == '<'){
                esqEsperando++;
            }
            else if(ch == '>' && esqEsperando > 0){
                diamantes++;
                esqEsperando--;
            }
        }
        cout << diamantes << endl;
    }


    return 0;
}