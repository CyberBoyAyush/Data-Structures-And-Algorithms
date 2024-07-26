// shortest path in a graph using bfs traversal -> dist only

#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // create adj list
            // map
        unordered_map<int,vector<int>> adj;
            // pushing data in it
        for(int i = 0 ; i< M ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            // mapping
            adj[u].push_back(v); // u->v
            adj[v].push_back(u); // v->u
        }    
        
        // creating visited arr and dist array
        vector<int> dist(N,-1);
        vector<bool> vis(N,0);
        
        // creating queue and pushing its value in it
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        dist[src] = 0;
        
        // bfs tarversal
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            //go to neighbours
            for(int & v : adj[node]){
                // check if it is visited or not
                if(vis[v])  continue;
                
                vis[v] = 1;
                q.push(v);
                dist[v] = dist[node] + 1;
            }
        }
        return dist;
    }

int main(){
    int N = 6;
    int M = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{2,4},{2,5}};
    int src = 0;
    vector<int> res = shortestPath(edges,N,M,src);
    for(int i = 0 ; i< N ; i++){
        cout<<res[i]<<" ";
    }
  return 0;
}