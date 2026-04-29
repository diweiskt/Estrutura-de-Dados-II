#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // --- PASSO 1: CARGA DE DADOS (Dicionário de Preços) ---
    // Abrimos o arquivo que contém o "cadastro" dos livros
    ifstream arqLivros("livros.txt");
    if(!arqLivros) { 
        cerr << "Erro ao abrir livros.txt" << endl; 
        return 1; 
    }

    // Criamos um mapa: a CHAVE é o código (string) e o VALOR é o preço (double)
    unordered_map<string, double> tabelaPrecos;
    string cod;
    double preco;

    // Lemos o arquivo de cadastro até o fim
    while(arqLivros >> cod >> preco) {
        tabelaPrecos[cod] = preco; // Armazena no mapa para busca instantânea O(1)
    }
    arqLivros.close(); // Fechar sempre que terminar de usar


    // --- PASSO 2: PROCESSAMENTO DE DEVOLUÇÕES ---
    ifstream arqDevol("devolucoes.txt");
    ofstream relatorio("relatorio_multas.csv"); // Arquivo de SAÍDA

    if(!arqDevol || !relatorio) {
        cerr << "Erro ao abrir arquivos de processamento." << endl;
        return 1;
    }

    // Cabeçalho do CSV (Separado por ponto e vírgula)
    relatorio << "Codigo;Valor_Multa;Status\n";

    string codDevol;
    int dias;
    
    // Variáveis para as estatísticas (itinerários da prova)
    double totalArrecadado = 0;
    string livroMaiorMulta;
    double maiorMulta = -1;
    int totalProcessados = 0;
    int erros = 0;

    // Lemos o arquivo de devoluções (cada linha tem: código e dias de atraso)
    while(arqDevol >> codDevol >> dias) {
        totalProcessados++;
        double valorMulta = 0;
        string status = "OK";

        // VERIFICAÇÃO: O livro existe no nosso mapa de cadastro?
        if(tabelaPrecos.count(codDevol)) {
            // Se existe, calcula a multa: preço_diaria * dias_atraso
            valorMulta = tabelaPrecos[codDevol] * dias;

            // Lógica para descobrir a maior multa individual
            if(valorMulta > maiorMulta) {
                maiorMulta = valorMulta;
                livroMaiorMulta = codDevol;
            }
        } else {
            // Se não existe, status vira Erro e a multa continua 0.00
            status = "Erro";
            erros++;
        }

        totalArrecadado += valorMulta;

        // Gravando no arquivo CSV com 2 casas decimais
        relatorio << codDevol << ";" 
                  << fixed << setprecision(2) << valorMulta << ";" 
                  << status << "\n";
    }

    // --- PASSO 3: EXIBIÇÃO DOS RESULTADOS (Estatísticas) ---
    cout << "=== RELATORIO FINAL ===" << endl;
    cout << "Total Arrecadado: R$ " << fixed << setprecision(2) << totalArrecadado << endl;
    
    if (maiorMulta != -1)
        cout << "Livro com maior multa: " << livroMaiorMulta << " (R$ " << maiorMulta << ")" << endl;

    // Cálculo da Taxa de Erro (Cuidado: usar double no cast para não zerar a divisão)
    double taxaErro = (totalProcessados > 0) ? ((double)erros / totalProcessados) * 100 : 0;
    cout << "Taxa de Erro: " << fixed << setprecision(1) << taxaErro << "%" << endl;

    // Fechar todos os fluxos
    arqDevol.close();
    relatorio.close();

    return 0;
}

/*
Pontos Chave para não esquecer na prova:
tabelaPrecos.count(chave): É a melhor forma de verificar se algo existe no unordered_map 
sem correr o risco de inserir um valor vazio acidentalmente (o que acontece se você usar if(tabela[chave])).

fixed << setprecision(2): Essencial para saídas financeiras e CSVs. Lembre-se de incluir a biblioteca #include <iomanip>.

ofstream relatorio("nome.csv"): Use para criar o arquivo de saída. Se o professor pedir para acrescentar 
dados em um arquivo existente em vez de criar um novo, use ofstream relatorio("nome.csv", ios::app).

Cast para (double): Na hora de calcular porcentagens (Taxa de Erro), se você dividir um int por outro int, 
o C++ vai truncar o resultado (ex: 1 / 2 vira 0). Use (double)erros / total para ter o valor correto.
*/