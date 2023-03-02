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

void dfs(vector<int>graph[],int V, vector<bool> &res, vector<int>&disc,vector<int>&low,vector<int>&parent,vector<bool>&vis,int source) {
    static int timer = 0;
    int children = 0;
    disc[source] = low[source] = ++timer;
    vis[source] = true;

    for(auto neighbour: graph[source]) {
        if(neighbour == parent[source])
            continue;
        if(!vis[neighbour]) {
            children++;
            parent[neighbour] = source;
            dfs(graph,V,res,disc,low,parent,vis,neighbour);
            low[source] = min(low[source],low[neighbour]);
            if(parent[source]!=-1 && low[neighbour] >= disc[source]) {
                // i am not a root
                // i am required to be visited in order for the child to be visited
                // therefore i am a crucial component
                // it means I am an articulation point
                res[source] = true;
            }
        } else {
            // already visited
            low[source] = min(low[source], disc[neighbour]);
        }
    }

    if(parent[source] == -1 && children > 1) {
        // if i am the root
        // and also i have more than 1 children
        // then also I am an articulation point
        res[source] = true;
    }
}

void articulationPoint(vector<int>graph[], int V) {
    vector<int>disc(V,-1);
    vector<int>low(V,INT_MAX);
    vector<int>parent(V,-1);
    vector<bool>vis(V,false);

    vector<bool> res(V,false);

    dfs(graph,V,res,disc,low,parent,vis,0);
    
    cout<<endl;
    for(int i=0 ; i<res.size() ; i++) {
        if(res[i] == true) {
            cout<<i<<"   ";
        }
    }
    cout<<endl;
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

    //addEdge(graph,0, 1);
    //addEdge(graph,2, 1);
    //addEdge(graph,2, 0);
    //addEdge(graph,1, 3);
    //addEdge(graph,1, 4);
    //addEdge(graph,1, 6);
    //addEdge(graph,3, 5);
    //addEdge(graph,4, 5);

    articulationPoint(graph,V);

    return 0;
}
