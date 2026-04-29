#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // 1. Carga de Dados (Preços das multas)
    ifstream arqLivros("livros.txt");
    if(!arqLivros) { cerr << "Erro livros.txt"; return 1; }

    unordered_map<string, double> tabelaPrecos;
    string cod;
    double preco;
    while(arqLivros >> cod >> preco) {
        tabelaPrecos[cod] = preco;
    }
    arqLivros.close();

    // 2. Processamento de Devoluções
    ifstream arqDevol("devolucoes.txt");
    ofstream relatorio("relatorio_multas.csv");
    if(!arqDevol || !relatorio) return 1;

    relatorio << "Codigo;Valor_Multa;Status\n";

    string codDevol;
    int dias;
    double totalArrecadado = 0;
    string livroMaiorMulta;
    double maiorMulta = -1;
    int totalDevolucoes = 0, erros = 0;

    while(arqDevol >> codDevol >> dias) {
        totalDevolucoes++;
        double valorMulta = 0;
        string status = "OK";

        if(tabelaPrecos.count(codDevol)) {
            valorMulta = tabelaPrecos[codDevol] * dias;
            if(valorMulta > maiorMulta) {
                maiorMulta = valorMulta;
                livroMaiorMulta = codDevol;
            }
        } else {
            status = "Erro";
            erros++;
        }

        totalArrecadado += valorMulta;
        relatorio << codDevol << ";" << fixed << setprecision(2) << valorMulta << ";" << status << "\n";
    }

    // 4. Saída no Terminal
    cout << "Total Arrecadado: R$ " << totalArrecadado << endl;
    cout << "Maior Multa: " << livroMaiorMulta << " (R$ " << maiorMulta << ")" << endl;
    cout << "Taxa de Erro: " << (double)erros/totalDevolucoes * 100 << "%" << endl;

    return 0;
}