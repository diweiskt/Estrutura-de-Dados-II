/*
beecrowd | 1260
Espécies de Madeira

Coníferas e folhosas (softwoods e hardwoods) são dois grandes grupos de vegetais produtores de madeira. 
As folhosas são aquele grupo de árvores que têm folhas largas, produzem uma fruta ou castanha e geralmente ficam dormentes no inverno.

Os climas temperados da América produzem florestas com centenas de espécies de madeira de lei - árvores 
que compartilham certas características biológicas. Embora o carvalho, bordo e cereja sejam tipos de árvores 
de madeira de lei, são espécies diferentes. Juntas, todas as espécies de madeira folhosas representam 40 por cento das árvores nos Estados Unidos.

Por outro lado, as madeiras macias (Softwoods) ou coníferas, chamadas "cone-bearing", são resinosas amplamente 
disponíveis EUA. Incluem cedro, abeto, cicuta, pinho, abeto vermelho e cipreste. Em uma casa, os resinosas são 
utilizados principalmente como madeira de viga estrutural, mas também podem ser utilizadas em algumas aplicações decorativas.

Usando tecnologia de imagem por satélite, o Departamento de Recursos Naturais elaborou um inventário de todas 
as árvores de um local específico em um determinado dia. Você deverá calcular a fração da população de cada árvore representada por cada uma das espécies.

Entrada
A entrada possui vários casos de teste. A primeira linha de entrada contém um inteiro N que indica o número 
de casos de teste, seguido por uma linha em branco. Cada caso de teste consiste de uma lista com a espécie de 
cada árvore observada pelo satélite, uma árvore por linha. Nenhum nome de espécie é superior a 30 caracteres. 
Não existem mais de 10.000 espécies e não mais de 1.000.000 árvores. Há uma linha em branco entre cada caso de teste consecutivo.

Saída
Para cada caso de teste imprima o nome de cada espécie representada na população, em ordem alfabética, seguida 
pelo percentual da população que representa, com 4 casas decimais. Imprima uma linha em branco entre dois conjuntos de dados consecutivos.
*/

#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;

int main(){

    int N;
    string linha;

    getline(cin, linha);
    linha.erase(remove(linha.begin(), linha.end(), '\r'), linha.end());
    N = stoi(linha);

    for(int i = 0; i < N; i++){
        map<string, int> arvores;
        int total = 0;

        while(getline(cin, linha)){
            linha.erase(remove(linha.begin(), linha.end(), '\r'), linha.end());
            if(linha.empty()) break;
            arvores[linha]++;
            total++;
        }

        if(total == 0){
            i--;
            continue;
        }

        for(auto const& [especie, quantidade] : arvores){
            double porcentagem = (quantidade * 100.0) / total;
            cout << especie << " " << fixed << setprecision(4) << porcentagem << "\n";
        }

        if(i < N - 1)
            cout << "\n";
    }

    return 0;
}