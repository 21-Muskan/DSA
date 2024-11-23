// 4. You are given an undirected weighted graph with nodes and edges. The nodes are
// numbered from and to. Find the total weight of the minimum spanning tree, as well as
// one specific minimum spanning tree using Prims/Kruskal’s algorithm. Note that there
// may be multiple different minimum spanning trees. You need to construct any one of
// them.

// Sample Input/Output
// Enter the number of nodes: 4
// Enter the number of edges: 5
// Enter edge (src dest weight): 0 1 10
// Enter edge (src dest weight): 0 2 6
// Enter edge (src dest weight): 0 3 5
// Enter edge (src dest weight): 1 3 15
// Enter edge (src dest weight): 2 3 4

// Edges in the Minimum Spanning Tree:
// 2 -- 3 == 4
// 0 -- 3 == 5
// 0 -- 1 == 10
// Total weight of the Minimum Spanning Tree: 19

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_EDGES = 100;
const int MAX_NODES = 100;
struct Edge
{
    int src, dest, weight;
};
Edge edges[MAX_EDGES];
int parent[MAX_NODES];

int find(int u)
{
    if (u == parent[u])
    {
        return u;
    }
    return parent[u] = find(parent[u]);
}

void unionSets(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV)
    {
        parent[rootV] = rootU;
    }
}

bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}

void kruskalMST(int numEdges, int numNodes)
{
    sort(edges, edges + numEdges, compareEdges);
    for (int i = 0; i < numNodes; i++)
    {
        parent[i] = i;
    }
    int totalWeight = 0;
    int edgesInMST = 0;
    cout << "Edges in the Minimum Spanning Tree:" << endl;

    for (int i = 0; i < numEdges; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (find(u) != find(v))
        {
            unionSets(u, v);
            totalWeight += weight;
            edgesInMST++;
            cout << u << " -- " << v << " == " << weight << endl;
        }

        if (edgesInMST == numNodes - 1)
        {
            break;
        }
    }

    cout << "Total weight of the Minimum Spanning Tree: " << totalWeight << endl;
}

int main()
{
    int numEdges, numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++)
    {
        cout << "Enter edge (src dest weight): ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    kruskalMST(numEdges, numNodes);

    return 0;
}
