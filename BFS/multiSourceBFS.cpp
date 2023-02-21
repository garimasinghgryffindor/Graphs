// bfs
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void addEdge(vector<int>graph[],int u,int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void bfs(vector<int>graph[],int V,int sources[]) {
    vector<bool> visited(V+1, false);
    queue<int> q;
    int n = sizeof(sources)/sizeof(sources[0]);
    vector<int>dist(V+1,INT_MAX);
    // pushing all the sources in the queue
    for(int i=0 ; i<n ; i++) {
        q.push(sources[i]);
        dist[sources[i]] = 0;
        visited[sources[i]] = true;
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int y: graph[x]) {
            if(!visited[y]) {
                visited[y] = true;
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }


    // printing the distances
    for(int i=1 ; i<V+1 ; i++) {
        cout<<i<<" :      "<<dist[i]<<endl;
    }
    return;
}

int main()
{
    int V=6;
    vector<int> graph[V+1];
    // adjacency list
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 6);
    addEdge(graph, 2, 6);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 6);
    addEdge(graph, 5, 4);
    addEdge(graph, 6, 5);
    addEdge(graph, 3, 4);
    addEdge(graph, 5, 3);

    int sources [] = {1,5};

    bfs(graph,V,sources);

    return 0;
}