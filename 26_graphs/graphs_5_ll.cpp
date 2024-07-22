#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)


// creating undirected unwaited graph using adjacency list
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
    return 0;
}