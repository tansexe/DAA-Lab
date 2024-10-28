#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <queue>
#include <stack>

using namespace std;

const int INF = numeric_limits<int>::max();

// Function to read the adjacency matrix from file
vector<vector<int>> readGraphFromFile(const string& filename, int& numVertices) {
    ifstream inputFile(filename);
    inputFile >> numVertices;
    vector<vector<int>> graph(numVertices, vector<int>(numVertices));

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            inputFile >> graph[i][j];
        }
    }

    inputFile.close();
    return graph;
}

// Dijkstra's algorithm to find shortest paths from source
void dijkstra(const vector<vector<int>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    dist[source] = 0;

    // Priority queue to store (distance, vertex) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }

    // Display results
    cout << "Source\tDestination\tCost\tPath\n";
    for (int i = 0; i < n; i++) {
        if (i == source) {
            cout << source + 1 << "\t" << i + 1 << "\t\t" << dist[i] << "\t-\n";
            continue;
        }

        if (dist[i] == INF) {
            cout << source + 1 << "\t" << i + 1 << "\t\tINF\tNo Path\n";
        } else {
            cout << source + 1 << "\t" << i + 1 << "\t\t" << dist[i] << "\t";

            // Reconstruct path from source to i
            stack<int> path;
            for (int v = i; v != -1; v = parent[v]) {
                path.push(v + 1);
            }
            while (!path.empty()) {
                cout << path.top();
                path.pop();
                if (!path.empty()) cout << "->";
            }
            cout << "\n";
        }
    }
}

int main() {
    int numVertices;
    vector<vector<int>> graph = readGraphFromFile("inDiAdjMat1.dat", numVertices);

    cout << "Enter the Source Vertex: ";
    int source;
    cin >> source;
    source -= 1; // Adjust for 0-based indexing

    dijkstra(graph, source);

    return 0;
}
