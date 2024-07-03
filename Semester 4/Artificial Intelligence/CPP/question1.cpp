#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_VERTICES = 10;

int cost[MAX_VERTICES][MAX_VERTICES];
int n, m, v;
vector<bool> visited(MAX_VERTICES, false); // Efficient visited tracking

void depthFirstSearch(int vertex) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int j = 0; j < n; j++) {
        if (cost[vertex][j] == 1 && !visited[j]) {
            depthFirstSearch(j);
        }
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges (source vertex, destination vertex):\n";
    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        cost[i][j] = 1;  // Assuming undirected graph (cost[j][i] = 1 for directed)
    }

    cout << "Enter the initial vertex: ";
    cin >> v;

    cout << "Depth-First Search (DFS) Traversal:\n";
    depthFirstSearch(v);

    return 0;
}
