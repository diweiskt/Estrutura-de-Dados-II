#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    unordered_set<int> numeros;
    int n;

    cout << "Digite valores inteiros (0 para sair)\n";
    while(cin >> n && n!=0){
        numeros.insert(n);
    }

    cout << "Tamanho do conjunto: " << numeros.size() << endl;
    cout << "Valores no conjunto\n";
    for(auto num : numeros){
        cout << num << endl;
    }

    return 0;
}