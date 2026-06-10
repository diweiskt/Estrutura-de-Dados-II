#include "dijkstra.cpp"
#include <climits> // INT_MAX
#include <fstream>
#include <iostream>

using namespace std;

// Cria .dot dinâmico e exibe
void show(int graph[N][N], int origin, int destination, int distance[N], int previous[N])
{
    ofstream dot("/tmp/grafo.dot");
    dot << "digraph{\n"
           "\trankdir=LR;\n" // Left to Right
           "\tlabel=\"\\nFrom "
        << origin << " to " << destination
        << "\\nTotal distance: "
        << distance[destination]
        << "\";\n"
           "\tlabelloc=b;\n" // Estilo do label: na base
           "\tlabeljust=c;\n" // centralizado
           "\tfontsize=22;\n\n"
           "\tnode[shape=circle, style=filled, fillcolor=gray, fontsize=24];\n" // Estilo dos vértices
           "\tedge[fontsize=20, color=slategray, fontcolor=navy];\n\n"; // Estilo das arestas

    // Cria os vértices
    for (int v = 0; v < N; v++) {
        dot << '\t'
            << v
            << (v == origin ? " [fillcolor=royalblue3, fontcolor=white]" : (v == destination ? " [fillcolor=tomato3, fontcolor=white]" : ""))
            << ";\n";
    }
    dot << '\n';

    // Percorre toda a matriz de adjacências
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j]) // São vértices adjacentes?
                dot << "\t" << i << " -> " << j << " [label=\"" << graph[i][j]
                    << "\"];\n ";
        }
    }
    // Exibe um nodo com tabela HTML. label pode usar layout HTML entre menor/maior : label=< <b>texto</b> >
    dot << "\n\tdistancesTable [shape=plaintext, fontsize=16, style=solid,"
           "label=< <table border=\"1\" "
           "cellborder=\"1\" cellspacing=\"0\">\n"
           "\t\t<tr>"
           "<td><b>To</b></td><td><b>Dist</b></td><td><b>Prev</b></td>"
           "</tr>\n";

    // Percorre toda a tabela de distâncias.
    for (int v = 0; v < N; v++) {
        dot << "\t\t<tr>"
            << "<td"
            << (v == origin ? " bgcolor=\"royalblue3\">" : (v == destination ? " bgcolor=\"tomato3\">" : ">"))
            << v << "</td><td>"
            << (distance[v] == INT_MAX ? "∞" : to_string(distance[v]))
            << "</td><td>"
            << (previous[v] >= 0 ? previous[v] : -1)
            << "</td></tr>\n";
    }
    dot << "\t</table> >];\n";

    dot << "}\n";
    dot.close();
    system("dot -Tx11 /tmp/grafo.dot");
}

int main()
{
    int distance[N], previous[N], origin, destination;

    do {
        cout << "From: ";
        cin >> origin;
    } while (origin < 0 || origin >= N);
    do {
        cout << "To: ";
        cin >> destination;
    } while (destination < 0 || destination >= N);

    dijkstra(graph, origin, distance, previous);
    show(graph, origin, destination, distance, previous);
}
