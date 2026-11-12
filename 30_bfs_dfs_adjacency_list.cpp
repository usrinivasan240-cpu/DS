// Q30 AIM: Perform BFS and DFS from vertex 1 using the specified adjacency-list graph.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[7];
bool visited[7];

void dfs(int vertex)
{
    visited[vertex] = true;
    cout << vertex << " ";
    for (int next : graph[vertex])
        if (!visited[next]) dfs(next);
}

int main()
{
    int edges[][2] = {{1,2}, {1,3}, {2,4}, {3,4}, {4,5}, {5,6}};
    for (auto &edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    for (auto &list : graph) sort(list.begin(), list.end());

    bool seen[7] = {};
    queue<int> q;
    q.push(1);
    seen[1] = true;

    cout << "BFS from vertex 1: ";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : graph[u])
            if (!seen[v]) seen[v] = true, q.push(v);
    }

    fill(begin(visited), end(visited), false);
    cout << "\nDFS from vertex 1: ";
    dfs(1);
    cout << endl;
    return 0;
}