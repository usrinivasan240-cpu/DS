#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// The source PDF refers to a graph image; its edge weights are not available
// in the extracted text. Enter the 7x7 weighted adjacency matrix.
// Use 0 for no edge. Vertex 0 represents A, 1 represents B, etc.

int main()
{
    const int n = 7;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the 7x7 adjacency matrix (0 = no edge):\n";
    for (auto &row : graph)
        for (int &weight : row)
            cin >> weight;

    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> inMST(n, false);
    key[0] = 0;
    int totalCost = 0;

    for (int count = 0; count < n; count++)
    {
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;

        if (u == -1 || key[u] == INT_MAX)
        {
            cout << "Graph is disconnected." << endl;
            return 0;
        }

        inMST[u] = true;
        totalCost += key[u];

        for (int v = 0; v < n; v++)
            if (graph[u][v] > 0 && !inMST[v] && graph[u][v] < key[v])
                key[v] = graph[u][v], parent[v] = u;
    }

    cout << "Edges in MST:\n";
    for (int v = 1; v < n; v++)
        cout << char('A' + parent[v]) << " - " << char('A' + v)
             << " : " << key[v] << endl;
    cout << "Total MST weight: " << totalCost << endl;
    return 0;
}