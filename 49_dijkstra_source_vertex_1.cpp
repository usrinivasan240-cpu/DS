// Q49 AIM: Find shortest paths from vertex 1 using Dijkstra's algorithm and the given edges.
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    const int n = 7;
    int edges[][3] = {
        {1,2,5}, {1,3,2}, {2,3,1}, {2,4,4}, {3,5,7},
        {4,5,3}, {4,6,6}, {5,6,2}, {5,7,8}, {6,7,4}
    };

    vector<pair<int, int>> graph[n + 1];
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], weight = edge[2];
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    vector<int> distance(n + 1, INT_MAX), parent(n + 1, -1);
    vector<bool> visited(n + 1, false);
    distance[1] = 0;

    for (int count = 1; count <= n; count++)
    {
        int u = -1;
        for (int v = 1; v <= n; v++)
            if (!visited[v] && (u == -1 || distance[v] < distance[u]))
                u = v;

        if (u == -1 || distance[u] == INT_MAX) break;
        visited[u] = true;

        for (auto [v, weight] : graph[u])
            if (!visited[v] && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight, parent[v] = u;
    }

    for (int v = 1; v <= n; v++)
    {
        cout << "Vertex " << v << ": ";
        if (distance[v] == INT_MAX)
        {
            cout << "unreachable" << endl;
            continue;
        }
        vector<int> path;
        for (int current = v; current != -1; current = parent[current])
            path.push_back(current);
        reverse(path.begin(), path.end());
        cout << "Path ";
        for (int node : path) cout << node << " ";
        cout << "| Distance = " << distance[v] << endl;
    }
    return 0;
}