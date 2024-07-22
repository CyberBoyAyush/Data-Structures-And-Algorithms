// bfs traversal in a graph

#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)



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

    // bfs traversal
    vector<int> visited(vertex,0);
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
  return 0;
}