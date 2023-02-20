// shortest paths from the source to all vertices in the given graph.
//  SSSP
//  BELLMAN FORD
//  DP

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void addEdge(vector<pair<int, int> > graph[], int w, int u, int v)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

void bellmanFord(vector<pair<int, int> > graph[], int V, int source)
{
    vector<int> weights(V, INT_MAX);
    weights[source] = 0;

    
    for (int i = 0; i < V-1; i++)
    {
    //                   ^
    //                   |_____________________ 
    //Relaxing all the edges-->  V-1  Times __|
    //                        |
    //                        V

        for (int i = 0; i < V; i++)
        {
            for (auto x : graph[i])
            {
                int node = x.first;
                int w = x.second;
                if (weights[node] > weights[i] + w)
                {
                    weights[node] = weights[i] + w;
                }
            }
        }
    }

    cout << "Vertex:             Distance from source" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << "             " << weights[i] << endl;
    }

    return;
}

int main()
{
    // the graph
    int V = 9;
    vector<pair<int, int> > graph[9];
    addEdge(graph, 1, 7, 6);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 6, 5);
    addEdge(graph, 4, 0, 1);
    addEdge(graph, 4, 2, 5);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 2, 3);
    addEdge(graph, 7, 7, 8);
    addEdge(graph, 8, 0, 7);
    addEdge(graph, 8, 1, 2);
    addEdge(graph, 9, 3, 4);
    addEdge(graph, 10, 5, 4);
    addEdge(graph, 11, 1, 7);
    addEdge(graph, 14, 3, 5);

    // function call to dijkstra's
    int src = 0;
    bellmanFord(graph, V, src);
    // 1         7      6
    // 2         8      2
    // 2         6      5
    // 4         0      1
    // 4         2      5
    // 6         8      6
    // 7         2      3
    // 7         7      8
    // 8         0      7
    // 8         1      2
    // 9         3      4
    // 10        5      4
    // 11        1      7
    // 14        3      5

    return 0;
}