// C++ Program to check if there is a negative weight cycle
// =====================================================
//          Floyd Warshall Algorithm
// =====================================================
// Floyd Warshall's all pairs shortest paths algorithm
// works for graphs with negative edge weights because
// the correctness of the algorithm does not depend on edge's
// weight being non-negative,
// while the correctness of Dijkstra's algorithm is based on this fact.
// =====================================================
// Floyd Warshall Algorithm based solution is discussed
// that works for both connected and disconnected graphs.
// =======================================================
#include<bits/stdc++.h>
using namespace std;

#define V 4
const int INF = 1e9;

void printSolution(int dist[][V]);

bool negCyclefloydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++){
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // If distance of any vertex from itself
    // becomes negative, then there is a negative
    // weight cycle.
    for (int i = 0; i < V; i++)
        if (dist[i][i] < 0)
            return true;

    return false;
}


int main()
{
    // A negative cycle is one in which the overall
    // sum of the cycle comes negative.
    /* Let us create the following weighted graph
            1
    (0)----------->(1)
    /|\             |
     |              |
  -1 |              | -1
     |             \|/
    (3)<-----------(2)
           -1       */

    int graph[V][V] = { {0   , 1   , INF , INF},
                        {INF , 0   , -1  , INF},
                        {INF , INF , 0   ,  -1},
                        {-1  , INF , INF ,   0}};

    if (negCyclefloydWarshall(graph)) cout << "Yes";
    else cout << "No";

    return 0;
}
