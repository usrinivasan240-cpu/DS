#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[6];
int discovery[6], low[6], timer = 0;
bool articulation[6];

void dfs(int u, int parent)
{
    discovery[u] = low[u] = ++timer;
    int children = 0;

    for (int v : graph[u])
    {
        if (v == parent) continue;
        if (discovery[v])
            low[u] = min(low[u], discovery[v]);
        else
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (parent != -1 && low[v] >= discovery[u])
                articulation[u] = true;
            children++;
        }
    }

    if (parent == -1 && children > 1)
        articulation[u] = true;
}

int main()
{
    char edges[][2] = {
        {'A','B'}, {'A','C'}, {'B','C'}, {'B','D'},
        {'D','E'}, {'E','F'}, {'D','F'}
    };

    for (auto &edge : edges)
    {
        int u = edge[0] - 'A';
        int v = edge[1] - 'A';
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < 6; i++)
        if (!discovery[i]) dfs(i, -1);

    cout << "Articulation points: ";
    for (int i = 0; i < 6; i++)
        if (articulation[i]) cout << char('A' + i) << " ";
    cout << endl;
    return 0;
}