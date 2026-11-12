// Q59 AIM: Implement Kruskal's MST algorithm using union-find.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int source, destination, weight;
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

class DisjointSet
{
    vector<int> parent, rankValue;

public:
    DisjointSet(int n) : parent(n), rankValue(n, 0)
    {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int value)
    {
        if (parent[value] != value)
            parent[value] = find(parent[value]);
        return parent[value];
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (rankValue[a] < rankValue[b]) swap(a, b);
        parent[b] = a;
        if (rankValue[a] == rankValue[b]) rankValue[a]++;
        return true;
    }
};

int main()
{
    int vertices, edgeCount;
    cout << "Number of vertices and edges: ";
    cin >> vertices >> edgeCount;

    vector<Edge> edges(edgeCount);
    cout << "Enter each edge as: source destination weight (vertices 0 to n-1)" << endl;
    for (Edge &edge : edges)
        cin >> edge.source >> edge.destination >> edge.weight;

    sort(edges.begin(), edges.end());
    DisjointSet sets(vertices);
    int totalCost = 0, selected = 0;

    cout << "Edges selected for MST:" << endl;
    for (const Edge &edge : edges)
        if (sets.unite(edge.source, edge.destination))
        {
            cout << edge.source << " - " << edge.destination
                 << " : " << edge.weight << endl;
            totalCost += edge.weight;
            selected++;
            if (selected == vertices - 1) break;
        }

    if (selected != vertices - 1)
        cout << "The graph is disconnected; no spanning tree exists." << endl;
    else
        cout << "Minimum total cost: " << totalCost << endl;
    return 0;
}