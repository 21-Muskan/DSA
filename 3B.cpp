// B. There are flight paths between cities. If there is a flight between city A and city B
// then there is an edge between the cities. The cost of the edge can be the time that
// flight take to reach city B from A, or the amount of fuel used for the journey.
// Represent this as a graph. The node can be represented by airport name or name of the
// city. Use adjacency list representation of the graph or use adjacency matrix
// representation of the graph. Check whether the graph is connected or not. Justify the
// storage representation used.

// Sample Input and output
// Enter the number of cities: 4
// Enter the number of flights: 3
// Enter the flight path between city A and city B (0-based index): 0 1
// Enter the flight path between city A and city B (0-based index): 1 2
// Enter the flight path between city A and city B (0-based index): 2 3

// Flight Network (Adjacency List):
// City 0 -> 1
// City 1 -> 0 2
// City 2 -> 1 3
// City 3 -> 2

// The flight network is connected.

#include <iostream>
#include <cstring>

using namespace std;

#define MAX_CITIES 100
#define MAX_FLIGHTS 100

struct Graph
{
    int adjList[MAX_CITIES][MAX_FLIGHTS];
    int adjSize[MAX_CITIES];
    int numCities;

    Graph(int cities)
    {
        numCities = cities;
        memset(adjSize, 0, sizeof(adjSize));
    }

    void addFlight(int cityA, int cityB)
    {
        adjList[cityA][adjSize[cityA]++] = cityB;
        adjList[cityB][adjSize[cityB]++] = cityA;
    }

    void dfs(int city, bool visited[])
    {
        visited[city] = true;
        for (int i = 0; i < adjSize[city]; i++)
        {
            int neighbor = adjList[city][i];
            if (!visited[neighbor])
            {
                dfs(neighbor, visited);
            }
        }
    }

    bool isConnected()
    {
        bool visited[MAX_CITIES];
        memset(visited, false, sizeof(visited));
        dfs(0, visited);

        for (int i = 0; i < numCities; i++)
        {
            if (!visited[i])
            {
                return false;
            }
        }
        return true;
    }
    void printGraph()
    {
        for (int i = 0; i < numCities; i++)
        {
            cout << "City " << i << " -> ";
            for (int j = 0; j < adjSize[i]; j++)
            {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int numCities, numFlights;
    cout << "Enter the number of cities: ";
    cin >> numCities;
    cout << "Enter the number of flights: ";
    cin >> numFlights;
    Graph flightGraph(numCities);
    for (int i = 0; i < numFlights; i++)
    {
        int cityA, cityB;
        cout << "Enter the flight path between city A and city B (0-based index): ";
        cin >> cityA >> cityB;
        flightGraph.addFlight(cityA, cityB);
    }

    cout << "\nFlight Network (Adjacency List):" << endl;
    flightGraph.printGraph();
    if (flightGraph.isConnected())
    {
        cout << "\nThe flight network is connected.\n";
    }
    else
    {
        cout << "\nThe flight network is NOT connected.\n";
    }

    return 0;
}
