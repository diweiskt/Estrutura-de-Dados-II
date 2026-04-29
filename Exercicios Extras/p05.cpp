/*
beecrowd | 1975
Pérolas

VI é uma professora de cálculo muito excêntrica, sempre que corrige as provas dos alunos 
(Que por sinal são provas dificílimas), ela anota todas as pérolas que encontra enquanto corrige, 
para que no dia da entrega ela possa escrever todas no quadro, para deixar os alunos envergonhados 
e que eles nunca mais errem as mesmas coisas.

Sempre que a bronca termina e as provas são entregues, os alunos tentam descobrir quem foi que teve 
mais pérolas no quadro. Como a cada prova os números de pérolas aumentam e os alunos tem que estudar 
muito pois a cada semana acontece uma nova prova de cálculo, eles não tem tempo para verificar todas 
as provas e ver quem apareceu mais vezes no quadro.

Sabendo que você é programador eles pediram sua ajuda para mostrar qual foi o aluno que teve mais pérolas 
escritas no quadro naquele dia.

Entrada
A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém três 
inteiros P, A e R (1 ≤ P, A, R ≤ 104), indicando respectivamente, o número de pérolas, número de 
alunos e a quantidade de respostas dadas por cada aluno. Segue P linhas com as pérolas escritas 
no quadro que terão no máximo 1000 caracteres. Em seguida terão A alunos, para cada aluno a primeira 
linha será seu nome com no máximo 100 caracteres minúsculos de 'a' até 'z', seguindo as R linhas 
mostrando suas respostas. A entrada termina quando P = A = R = 0, e não deve ser processada.

OBS: Ignore as possibilidades de haver entradas de alunos com o mesmo nome ou pérolas repetidas.

Saída
Para cada saída, você deverá imprimir o nome do aluno que teve mais aparições no quadro, 
em caso de empate seu programa deverá mostrar todos os alunos com mais aparições separados por vírgulas em ordem alfabética.
*/

#include <iostream>
#include <unordered_set>
#include <map>

using namespace std;

int main() {
    int P, A, R;

    while (cin >> P >> A >> R && (P != 0 || A != 0 || R != 0)) {
        cin.ignore();

        // Mantemos o unordered_set para busca rápida (O(1))
        unordered_set<string> perolas;
        for(int i = 0; i < P; i++){
            string p;
            getline(cin, p);
            perolas.insert(p);
        }

        // Usamos std::map para os alunos (Chave: nome, Valor: pontos)
        // O map já mantém os nomes em ordem alfabética automaticamente
        map<string, int> listaAlunos;
        int maxPontos = -1;

        for(int i = 0; i < A; i++){
            string nome;
            getline(cin, nome);
            
            int contaPerolas = 0;
            for(int j = 0; j < R; j++){
                string resposta;
                getline(cin, resposta);
                if(perolas.count(resposta)){
                    contaPerolas++;
                }
            }

            listaAlunos[nome] = contaPerolas;
            if(contaPerolas > maxPontos){
                maxPontos = contaPerolas;
            }
        }

        // Agora basta iterar pelo map. Ele já está ordenado por nome!
        bool primeiro = true;
        for(auto const& [nome, pontos] : listaAlunos){
            if(pontos == maxPontos){
                if(!primeiro) cout << ", ";
                cout << nome;
                primeiro = false;
            }
        }
        cout << endl;
    }

    return 0;
}