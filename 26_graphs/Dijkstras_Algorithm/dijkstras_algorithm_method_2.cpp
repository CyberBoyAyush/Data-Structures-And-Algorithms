// Dijkstra's Algorithm Method 2 -> using priority queue (min heap)

#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

// Method 2  -> Using Min Heap
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        // creating explored and visited arr
        vector<bool> Explored(V,0);
        vector<int> dist(V,INT_MAX);
        dist[S] = 0; // initializing S dist as 0
        
        // min heap for operations
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        // initalize the pq
        pq.push({0,S});  // {dist,node}
        
        // we do operations in queue
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            // if already explored
            if(Explored[node]==1)  continue;
            
            Explored[node] = 1; // make id explored
            
            // relax the edges
            for(auto & v : adj[node]){
                int neighbour = v[0];
                int weight = v[1];
                
                // condt
                if(!Explored[neighbour] &&
                dist[node] + weight < dist[neighbour]){
                    dist[neighbour] = dist[node] + weight;
                    pq.push({dist[neighbour] , neighbour});
                }
            }
        }
        
        return dist;
    }

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj[V];
    fo(i,E){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int S;
    cin>>S;
    vector<int> res = dijkstra(V,adj,S);
    fo(i,V) cout<<res[i]<<" ";
    return 0;
}