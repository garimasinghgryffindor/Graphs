// ALL PAIR SHORTEST PATH
// FLOYD WARSHALL
// DP

#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int> >&graph,int u,int v,int w) {
    graph[u][v] = w;
}

void printDist(vector<vector<int> >graph) {
    int n = graph.size();
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(graph[i][j] == INT_MAX)
                cout<<"INF    ";
            else
                cout<<graph[i][j]<<"      ";
        }
        cout<<endl;
    }
}

void floydWarshall(vector<vector<int> >graph) {
    int n = graph.size(); 
    for(int i=0 ; i<n ; i++) {
        // source vertex
        for(int j=0 ; j<n ; j++) {
            // destination vertex
            for(int k=0 ; k<n ; k++) {
                // the "via" vertex
                if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX && graph[i][j] > graph[i][k]+graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    printDist(graph);
}

int main()
{
    int n = 5;
    vector<vector<int> > graph(n,vector<int>(n,INT_MAX));
    for(int i=0 ; i<n ; i++) {
        graph[i][i] = 0;
    }
    addEdge(graph,0,3,5);
    addEdge(graph,3,2,10);
    //addEdge(graph,1,2,3);
    //addEdge(graph,2,3,1);
    
    //graph.push_back({ 0, 5, INT_MAX, 10 });
    //graph.push_back({INT_MAX, 0, 3, INT_MAX});
    //graph.push_back({INT_MAX, INT_MAX, 0, 1});
    //graph.push_back({INT_MAX, INT_MAX, INT_MAX, 0});

    floydWarshall(graph);

    return 0;
}