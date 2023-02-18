// single source shortest path
// when weight is either 0 or 1
// using bfs
// queue will be deque instead
// weighted graph

// for weight ranging from 0 to 10

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

    queue<int> q[15];
    q[0].push(source);
    dist[source] = 0;

    while(1) {
        for(int i=0 ; i<15 ; i++) {
            while(!q[i].empty()) {
                int x = q[i].front();
                q[i].pop();
                for(auto y: graph[x]) {
                    int node = y.first;
                    int weight = y.second;
                    if(dist[node] > dist[x] + weight) {
                        dist[node] = dist[x] + weight;

                        q[weight].push(node);
                    }
                }
            }
        }

        int f=0;
        for(int i=0 ; i<15 ; i++) {
            if(!q[i].empty()) {
                f=1;
                break;
            }
        }
        if(f==0)
            break;
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
    addEdge(graph,0, 1, 4);
    addEdge(graph,0, 7, 8);
    addEdge(graph,1, 2, 8);
    addEdge(graph,1, 7, 11);
    addEdge(graph,2, 3, 7);
    addEdge(graph,2, 8, 2);
    addEdge(graph,2, 5, 4);
    addEdge(graph,3, 4, 9);
    addEdge(graph,3, 5, 14);
    addEdge(graph,4, 5, 10);
    addEdge(graph,5, 6, 2);
    addEdge(graph,6, 7, 1);
    addEdge(graph,6, 8, 6);
    addEdge(graph,7, 8, 7);

    bfs(graph,V,0);

    return 0;
}