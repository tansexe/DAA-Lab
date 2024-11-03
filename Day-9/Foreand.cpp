#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max(); // Use a large value to represent infinity

void floydWarshall(vector<vector<int>> &dist, vector<vector<int>> &next, int n)
{
    // Initialize the `next` matrix for path reconstruction
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (dist[i][j] != INF && i != j)
                next[i][j] = j;

    // Floyd-Warshall algorithm to compute shortest paths
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

vector<int> constructPath(int u, int v, const vector<vector<int>> &next)
{
    // Reconstruct the path from `u` to `v` using the `next` matrix
    if (next[u][v] == -1)
        return {}; // No path exists

    vector<int> path = {u};
    while (u != v)
    {
        u = next[u][v];
        path.push_back(u);
    }
    return path;
}

int main()
{
    ifstream infile("inDiAdjMat2.dat");
    if (!infile)
    {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<int>> next(n, vector<int>(n, -1));

    // Read the adjacency matrix from the file
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int weight;
            infile >> weight;
            if (weight != 0 || i == j)
                dist[i][j] = weight;
        }
    }
    infile.close();

    // Run the Floyd-Warshall algorithm
    floydWarshall(dist, next, n);

    // Display shortest path matrix
    cout << "Shortest path weight matrix:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    // Get user input for source and destination vertices
    int src, dest;
    cout << "Enter the source and destination vertex: ";
    cin >> src >> dest;

    src--; // Convert to zero-based index
    dest--;

    // Get the path from source to destination
    vector<int> path = constructPath(src, dest, next);

    // Display the result
    if (path.empty())
    {
        cout << "No path from vertex " << src + 1 << " to vertex " << dest + 1 << endl;
    }
    else
    {
        cout << "Shortest Path from vertex " << src + 1 << " to vertex " << dest + 1 << ": ";
        for (size_t i = 0; i < path.size(); ++i)
        {
            cout << path[i] + 1; // Convert back to one-based index
            if (i < path.size() - 1)
                cout << "-->";
        }
        cout << "\nPath weight: " << dist[src][dest] << endl;
    }

    return 0;
}
