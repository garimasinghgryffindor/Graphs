// bridges
// using dfs
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void addEdge(vector<int>graph[],int u,int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs(vector<int>graph[],int V, vector<pair<int,int> > &res, vector<int>&disc,vector<int>&low,vector<int>&parent,vector<bool>&vis,int source) {
    static int timer = 0;
    vis[source] = true;
    disc[source] = low[source] = ++timer;

    for(auto neighbour: graph[source]) {
        if(neighbour == parent[source])
            continue;
        if(!vis[neighbour]) {
            parent[neighbour] = source;
            dfs(graph,V,res,disc,low,parent,vis,neighbour);

            low[source] = min(low[neighbour], low[source]);

            if(low[neighbour] > low[source]) {
                res.push_back(make_pair(source, neighbour));
            }
        } 
        else {
            // ie; already been visited
            // not a parent
            // therefore, a cycle
            low[source] = min(low[source], disc[neighbour]);
        }
    }
}

void bridges(vector<int>graph[], int V) {
    vector<int>disc(V,-1);
    vector<int>low(V,INT_MAX);
    vector<int>parent(V,-1);
    vector<bool>vis(V,false);

    vector<pair<int,int> > res;

    dfs(graph,V,res,disc,low,parent,vis,0);
    
    cout<<endl;
    for(auto x: res) {
        cout<<x.first<<"    "<<x.second<<endl;
    }
}

int main()
{
    int V=6;
    vector<int> graph[V];
    // adjacency list
    addEdge(graph,1, 0);
    addEdge(graph,0, 2);
    addEdge(graph,2, 1);
    addEdge(graph,0, 3);
    addEdge(graph,3, 4);

    bridges(graph,V);

    return 0;
}
