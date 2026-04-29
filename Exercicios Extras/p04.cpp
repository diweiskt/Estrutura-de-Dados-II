/*
beecrowd | 1424
Problema Fácil de Rujia Liu?

Embora Rujia Liu geralmente escreve problemas difíceis para algumas competições 
(como, por exemplo, competições regionais de Xi'an em 2006, de Pequim em 2007 e 
de Wuhan em 2009, ou competições no UVA OJ como a "Rujia Liu's Presents" 1 e 2), 
ele escreve problemas fáceis algumas vezes (como, por exemplo, o problema "the Coco-Cola Store" 
no UVA-OJ), para encorajar mais pessoas a resolver mais problemas :D

Dado um vetor de inteiros, sua tarefa é encontrar a k-ésima ocorrência (da esquerda para a direita) 
de um inteiro v no vetor. Para tornar o problema mais difícil (e mais interessante!), você deve responder a m consultas deste tipo.

Entrada
Há vários casos de teste. A primeira linha de cada caso de teste contém dois inteiros n e m (1 ≤ n, m ≤ 100.000), 
o número de elementos no vetor e o número de consultas a serem respondidas, respectivamente. 
A próxima linha contém n inteiros positivos não maiores que 1.000.000, que descrevem o vetor. 
As próximas m linhas contém dois inteiros k e v cada (1 ≤ k ≤ n, 1 ≤ v ≤ 1.000.000), descrevendo as consultas.

O arquivo de entrada termina com fim-de-arquivo (EOF). O tamanho do arquivo de entrada não excede 5 Mb.

Saída
Para cada consulta, imprima o índice do vetor (1-indexado) da ocorrência solicitada. Se tal ocorrência não existe, imprima 0 ao invés.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    int n,m;
    while(cin >> n >> m){
        map<int, vector<int>> posicoes;

        for(int a=0;a<n;a++){
            int vl;
            cin >> vl;
            posicoes[vl].push_back(a+1);
        }

        for(int i=0;i<m;i++){
            int k, v;
            cin >> k >> v;

            if (posicoes.count(v) && posicoes[v].size() >= k){
                cout << posicoes[v][k-1] << "\n";
            }
            else{
                cout <<"0\n";
            }
        }
    }
    return 0;
}