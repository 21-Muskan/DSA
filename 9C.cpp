// C. Given a 2D matrix tsp[][], where each row has the array of distances from that indexed city to all 
// the other cities and -1 denotes that there doesn’t exist a path between those two indexed cities. The 
// task is to print minimum cost in TSP cycle.
// Input: 
// tsp[][] = {{-1, 10, 15, 20}, -
// {10, -1, 35, 25}, 
// {15, 35, -1, 30}, 
// {20, 25, 30, -1}};

// Enter the number of cities: 4
// Enter the TSP matrix (-1 for no path): 
// -1 10 15 20
// 10 -1 35 25
// 15 35 -1 30
// 20 25 30 -1

// The minimum cost of the TSP cycle is: 80

#include <iostream>
#include <climits>
using namespace std;
#define INF INT_MAX

const int N = 10;
int tsp(int tspMatrix[N][N], int n, int pos, int mask, int dp[N][1 << N]) 
{ 
    if (mask == ((1 << n) - 1)) {
        return tspMatrix[pos][0] == -1 ? INF : tspMatrix[pos][0]; 
    }
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    int answer = INF;
    for (int city = 0; city < n; city++) {
        if (city != pos && (mask & (1 << city)) == 0 && tspMatrix[pos][city] != -1) {
            int newAnswer = tspMatrix[pos][city] + tsp(tspMatrix, n, city, mask | (1 << city), dp);
            answer = min(answer, newAnswer);
        }
    }
    return dp[pos][mask] = answer;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;
    int tspMatrix[N][N]; 
    int dp[N][1 << N];   
    cout << "Enter the TSP matrix (-1 for no path): \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tspMatrix[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = -1;
        }
    }
    int minCost = tsp(tspMatrix, n, 0, 1, dp);
    if (minCost == INF) {
        cout << "No complete TSP path exists." << endl;
    } else {
        cout << "The minimum cost of the TSP cycle is: " << minCost << endl;
    }
    return 0;
}
