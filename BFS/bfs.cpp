// bfs
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void addEdge(vector<int>graph[],int u,int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void bfs(vector<int>graph[],int V,int source) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout<<x<<"  ";
        for(int y: graph[x]) {
            if(!visited[y]) {
                visited[y] = true;
                q.push(y);
            }
        }
    }
}

int main()
{
    int V=6;
    vector<int> graph[V];
    // adjacency list
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    bfs(graph,V,0);

    return 0;
}