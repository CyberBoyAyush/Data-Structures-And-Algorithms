#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)



// dfs traversal in a graph
void dfs(int node, vector<int> adj[], vector<int> &visited){
    cout<<node<<" ";
    visited[node] = 1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited);
        }
    }
}

int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    vector<int> adj[vertex];

    int u,v;
    for(int i = 0;i<edges;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // printing the adjacency list
    for(int i = 0;i<vertex;i++){
        cout<<i<<"->";
        for(auto it:adj[i]){
            cout<<it<<" ";
        } cout<<endl;
    }

    // dfs traversal
    vector<int> visited(vertex,0);
    dfs(0,adj,visited);
  return 0;
}