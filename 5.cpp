// 5. A student wants to travel from Source (A) to destination (B). Student books a cab from A to reach B. Calculate a shortest path by avoiding real time traffic to reach destination B.

// Sample Input/Output
// Enter the number of nodes: 5
// Enter the number of edges: 6
// Enter edge (src dest weight): 0 1 10
// Enter edge (src dest weight): 0 2 3
// Enter edge (src dest weight): 1 2 1
// Enter edge (src dest weight): 1 3 2
// Enter edge (src dest weight): 2 1 4
// Enter edge (src dest weight): 2 3 8
// Enter the source node (0 to 4): 0
// Enter the destination node (0 to 4): 3
// The shortest distance from source 0 to destination 3 is 9
// Path: 3 1 0

#include <iostream>
#include <climits>
using namespace std;
#define MAX_NODES 100

int minDistance(int dist[], bool visited[], int numNodes)
{
    int min = INT_MAX, minIndex;
    for (int i = 0; i < numNodes; i++)
    {
        if (!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[MAX_NODES][MAX_NODES], int numNodes, int src, int dest)
{
    int dist[MAX_NODES];
    bool visited[MAX_NODES];
    int prev[MAX_NODES];
    for (int i = 0; i < numNodes; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
        prev[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < numNodes - 1; count++)
    {
        int u = minDistance(dist, visited, numNodes);
        visited[u] = true;
        for (int v = 0; v < numNodes; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
    cout << "The shortest distance from source " << src << " to destination " << dest << " is " << dist[dest] << endl;
    cout << "Path: ";
    int current = dest;
    while (current != -1)
    {
        cout << current << " ";
        current = prev[current];
    }
    cout << endl;
}

int main()
{
    int numNodes, src, dest;
    int graph[MAX_NODES][MAX_NODES];
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            graph[i][j] = 0;
        }
    }

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    for (int i = 0; i < numEdges; i++)
    {
        int u, v, weight;
        cout << "Enter edge (src dest weight): ";
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    cout << "Enter the source node (0 to " << numNodes - 1 << "): ";
    cin >> src;
    cout << "Enter the destination node (0 to " << numNodes - 1 << "): ";
    cin >> dest;
    dijkstra(graph, numNodes, src, dest);

    return 0;
}
