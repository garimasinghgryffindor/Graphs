//shortest paths from the source to all vertices in the given graph.
// SSSP
// GREEDY
// DIJKSTRA

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

void addEdge(vector< pair<int,int> >graph[], int w, int u, int v) {
    graph[u].push_back(make_pair(v,w));
    graph[v].push_back(make_pair(u,w));
}

void dijkstra(vector< pair<int,int> > graph[], int V,int source) {
    vector<int> weights(V,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    pq.push(make_pair(0,source));
    weights[source] = 0;

    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        for(auto x: graph[node]) {
            int nodex = x.first;
            int weightx = x.second;
            if(weights[nodex] > weights[node] + weightx) {
                weights[nodex] = weights[node] + weightx;
                pq.push(make_pair(weights[nodex],nodex));
            }
        }
    }

    cout<<"\nnode     dist\n";
    for(int i=0 ; i<V ; i++) {
        cout<<i<<"        "<<weights[i]<<endl;
    }
    
    return;
}

int main()
{
    // the graph
    int V = 9;
    vector< pair<int,int> > graph[9];
    addEdge(graph,1,7,6);
    addEdge(graph,2,8,2);
    addEdge(graph,2,6,5);
    addEdge(graph,4,0,1);
    addEdge(graph,4,2,5);
    addEdge(graph,6,8,6);
    addEdge(graph,7,2,3);
    addEdge(graph,7,7,8);
    addEdge(graph,8,0,7);
    addEdge(graph,8,1,2);
    addEdge(graph,9,3,4);
    addEdge(graph,10,5,4);
    addEdge(graph,11,1,7);
    addEdge(graph,14,3,5);

    // function call to dijkstra's
    int src = 0;
    dijkstra(graph,V,src);
//1         7      6
//2         8      2
//2         6      5
//4         0      1
//4         2      5
//6         8      6
//7         2      3
//7         7      8
//8         0      7
//8         1      2
//9         3      4
//10        5      4
//11        1      7
//14        3      5

    return 0;
}