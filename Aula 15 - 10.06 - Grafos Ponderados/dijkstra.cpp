#include <climits> // INT_MAX
#include <algorithm>
#include "graph7x7.cpp"

// Encontra vértice com menor distância ainda não visitado (ou -1 se não resta nenhuma opção)
int find_next(int distance[N], bool visited[N]) {
    int imin = -1, min = INT_MAX;
    for (int i = 0; i < N; i++)
        if (!visited[i] && distance[i] < min) { 
            min = distance[i];
            imin = i;
        }
    return imin; 
}

// Algoritmo de Dijkstra
void dijkstra(int graph[N][N], int origin, int distance[N], int previous[N]) {
    bool visited[N];

    // Inicializa arrays
    std::fill_n(visited, N, false);
    std::fill_n(previous, N, -1);
    std::fill_n(distance, N, INT_MAX);

    distance[origin] = 0;
    while(1) {
        int current = find_next(distance, visited);
        if (current == -1) break;  // Todos os vértices restantes são inalcançáveis

        visited[current] = true;
        for (int v = 0; v < N; v++)
            // Para cada vértice adjacente ainda não visitado cuja nova distância encontrada seja inferior à atual
            if (graph[current][v] != 0 && !visited[v] &&
                distance[current] + graph[current][v] < distance[v]) {
                    // Atualiza a distância e o vértice anterior à ele no novo caminho
                    distance[v] = distance[current] + graph[current][v];
                    previous[v] = current;
            }
    }
}
