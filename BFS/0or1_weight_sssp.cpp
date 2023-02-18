// single source shortest path
// when weight is either 0 or 1
// using bfs
// queue will be deque instead
// weighted graph

#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

void addEdge(vector<pair<int,int> > graph[],int u,int v,int w) {
    graph[u].push_back(make_pair(v,w));
    graph[v].push_back(make_pair(u,w));
}

void bfs(vector<pair<int,int> > graph[],int V,int source) {
    vector<int> dist(V,INT_MAX);

    deque<int> q;
    q.push_back(source);
    dist[source] = 0;

    while(!q.empty()) {
        int x = q.front();
        q.pop_front();
        for(auto y: graph[x]) {
            int node = y.first;
            int weight = y.second;
            if(dist[node] > dist[x] + weight) {
                dist[node] = dist[x] + weight;

                if(weight == 0) {
                    q.push_front(node);
                } else {
                    q.push_back(node);
                }
            }
        }
    }

    for(int i=0 ; i<V ; i++) {
        cout<<dist[i]<<"  ";
    } cout<<endl;
}



int main()
{
    int V=9;
    vector<pair<int,int> > graph[V];
    // adjacency list
    addEdge(graph,0, 1, 0);
    addEdge(graph,0, 7, 1);
    addEdge(graph,1, 7, 1);
    addEdge(graph,1, 2, 1);
    addEdge(graph,2, 3, 0);
    addEdge(graph,2, 5, 0);
    addEdge(graph,2, 8, 1);
    addEdge(graph,3, 4, 1);
    addEdge(graph,3, 5, 1);
    addEdge(graph,4, 5, 1);
    addEdge(graph,5, 6, 1);
    addEdge(graph,6, 7, 1);
    addEdge(graph,7, 8, 1);

    bfs(graph,V,0);

    return 0;
}