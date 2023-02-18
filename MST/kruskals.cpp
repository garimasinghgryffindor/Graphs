// MST
// GREEDY
// KRUSKALS
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void addEdge(vector<pair<int,pair<int,int> > >&graph, int u, int v, int w) {
    graph.push_back(make_pair(w,make_pair(u,v)));
}

int find(vector<int>parent, int u) {
    if(parent[u] < 0) {
        return u;
    }
    return find(parent,parent[u]);
}

void unionby(vector<int>&parent, int u, int v) {
    int pu = find(parent,u) , pv = find(parent, v);
    if(pu != pv) {
        if(parent[pu] < parent[pv]) {
            // i.e; more negative
            parent[pu] += parent[pv];
            parent[pv] = pu;
        } else {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
    }
}

vector<pair<int,pair<int,int> > > kruskals(vector<pair<int,pair<int,int> > > graph, int V) {
    sort(graph.begin() , graph.end());
    vector<int> parent(V, -1);

    vector<pair<int,pair<int,int> > > res;

    for(int i=0 ; i<graph.size() ; i++) {
        if(find(parent,graph[i].second.first) != find(parent,graph[i].second.second)) {
            res.push_back(graph[i]);
            unionby(parent,graph[i].second.first,graph[i].second.second);
        }
    }

    return res;
}

int main()
{
    // the graph
    vector<pair<int,pair<int,int> > > graph;
    int V = 9;
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

    // function call to kruskals
    vector<pair<int,pair<int,int> > > res = kruskals(graph,V);
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


    // printing the mst and calculating the cost of it
    int sum = 0;
    cout<<"weight:    u       v\n";
    for(auto x: res) {
        cout<<x.first<<"          "<<x.second.first<<"       "<<x.second.second<<endl;
        sum+=x.first; 
    }

    cout<<endl<<"cost:   "<<sum<<endl;

    return 0;
}