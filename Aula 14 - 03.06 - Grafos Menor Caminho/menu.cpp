#include "digraph.cpp"
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

char menu()
{
    char opcao;
    while (true) {
        cout << "[\x1b[31mI\x1b[0mncluir] "
             << "[\x1b[31mE\x1b[0mxcluir] "
             << "[Seguir \x1b[31mU\x1b[0msuário] "
             << "[\x1b[31mD\x1b[0mFS] "
             << "[\x1b[31mC\x1b[0maminho] "
             << "[Exibir \x1b[31mR\x1b[0mede] "
             << "[\x1b[31mS\x1b[0mair] > ";
        cin >> opcao;
        cin.ignore();
        opcao = toupper(opcao);
        if (opcao == 'C' || opcao == 'I' || opcao == 'E' || opcao == 'U' || opcao == 'D' || opcao == 'R' || opcao == 'S') {
            return opcao;
        }
        cout << "\x1b[1;38;5;221;48;5;88mOpção inválida. Tente novamente.\x1b[0m\n";
    }
}

void add_user(UPF::digraph<string>& rede)
{
    cout << "Nome do usuário: ";
    string name;
    getline(cin, name);
    rede.insert_node(name);
}

void follow_user(UPF::digraph<string>& rede)
{
    string from, to;
    cout << "Nome do seguidor: ";
    getline(cin, from);
    cout << "Quem irá seguir: ";
    getline(cin, to);
    rede.insert_link(from, to);
}

void remove_user(UPF::digraph<string>& rede)
{
    cout << "Nome do usuário: ";
    string name;
    getline(cin, name);
    rede.remove(name);
}

void user_dfs(UPF::digraph<string>& rede)
{
    cout << "Usuário inicial: ";
    string name;
    getline(cin, name);
    rede.DFS_from(name);
}

void path(UPF::digraph<string>& rede)
{
    string start, end;
    cout << "Inicial: ";
    getline(cin, start);
    cout << "Final: ";
    getline(cin, end);
    auto path = rede.shortest_path(start, end);
    if (path.empty()) {
        std::cout << "Nenhum caminho encontrado\n";
    } else {
        for (auto p : path)
            std::cout << p->value << " ";
        std::cout << "\n";
    }
}

int main()
{
    UPF::digraph<string> rede;
    char opcao;

    rede.load("rede.txt");
    do {
        opcao = menu();

        switch (opcao) {
        case 'I':
            add_user(rede);
            break;
        case 'E':
            remove_user(rede);
            break;
        case 'U':
            follow_user(rede);
            break;
        case 'D':
            user_dfs(rede);
            break;
        case 'R':
            rede.show();
            break;
        case 'C':
            path(rede);
            break;
        case 'S':
            break;
        }
    } while (opcao != 'S');

    rede.save("rede.txt");
    return 0;
}
