/*
Ida à Feira

Dona Parcinova costuma ir regularmente à feira para comprar frutas e legumes.
Ela pediu então à sua filha, Mangojata, que a ajudasse com as contas e que fizesse 
um programa que calculasse o valor que precisa levar para poder comprar tudo que 
está em sua lista de compras, considerando a quantidade de cada tipo de fruta ou 
legume e os preços destes itens.

Entrada
A primeira linha de entrada contém um inteiro N que indica a quantidade de idas 
à feira de dona Parcinova (que nada mais é do que o número de casos de teste que 
vem a seguir). Cada caso de teste inicia com um inteiro M que indica a quantidade 
de produtos que estão disponíveis para venda na feira. Seguem os M produtos com seus 
preços respectivos por unidade ou Kg. A próxima linha de entrada contém um inteiro 
P (1 ≤ P ≤ M) que indica a quantidade de diferentes produtos que dona Parcinova deseja comprar. 
Seguem P linhas contendo cada uma delas um texto (com até 50 caracteres) e um valor inteiro, 
que indicam respectivamente o nome de cada produto e a quantidade deste produto.

Saída
Para cada caso de teste, imprima o valor que será gasto por dona Parcinova no seguinte 
/formato: R$ seguido de um espaço e seguido do valor, com 2 casas decimais, conforme o exemplo abaixo.
*/

#include <iostream>
#include <unordered_map>
#include <iomanip>

using namespace std;

int main(){
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        unordered_map<string, double> produtos;
        int M;
        cin >> M;
        for(int j=0;j<M;j++){
            string produto;
            double preco;
            cin >> produto >> preco;
            produtos[produto] = preco;
        }
        int P;
        cin >> P;
        double total = 0;
        for(int j=0;j<P;j++){
            string produto;
            int qtd;
            cin >> produto >> qtd;
            total += produtos[produto] * qtd;
        }
        cout << "R$ " << fixed << setprecision(2) << total << endl;
    }

    return 0;
}