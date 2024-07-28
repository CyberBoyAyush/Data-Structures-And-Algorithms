// shortest_path_weighted_unidretec_graph.cpp is a snippet to find the shortest path in a weighted unidirectional graph.

#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

// Shortest Path in Weighted Unidirectional Graph
// In this code we have used dijkstra algorithm to find the shortest path in weighted unidirectional graph with 1 based indexing and source as 1 also we used path creation to find the path from source to destination.
vector<int> shortestPath(int V, int m, vector<vector<int>>& edges) {
        // Creating adj list
        vector<pair<int,int>> adj[V+1]; // v+1 bcz 1 based indexing
        // neighbour weight
        
        //pushing values in adj list
        for(int i = 0 ; i<m ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
        
        // Dijkstra Algorithm
        vector<bool> Explored(V+1,0);
        vector<int> dist(V+1,INT_MAX);
        vector<int> parent(V+1,-1);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        dist[1] = 0;
        parent[1] = -1;
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            if(Explored[node] == 1) continue;
            
            Explored[node] = 1; //mark it visited
            
            // relax the edges
            for(auto &v:adj[node]){
                int neighbour = v.first;
                int weight = v.second;
                
                // condt check
                if(!Explored[neighbour] &&
                weight + dist[node] < dist[neighbour]){
                    
                    // updating min weight
                    dist[neighbour] = weight + dist[node];
                    
                    //pushing in pq
                    pq.push({dist[neighbour] , neighbour});
                    
                    // updating parent
                    parent[neighbour] = node; // node will be parent for neighbour
                    
                }
            }
        }
        
        // path creation -> final ans
        vector<int> path;
        if(parent[V] == -1){
            // no path exists
            path.push_back(-1);
            return path;
        }
        int dest = V;
        
        while(dest != -1){
            path.push_back(dest);
            dest = parent[dest];
        }
        
        path.push_back(dist[V]); // bcz we have to return the weight in front of path arr
        reverse(path.begin(),path.end());
        return path;
    }

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> edges;
    fo(i,E){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    vector<int> res = shortestPath(V,E,edges);
    fo(i,res.size()){
        cout<<res[i]<<" ";
    }
    
    return 0;
}