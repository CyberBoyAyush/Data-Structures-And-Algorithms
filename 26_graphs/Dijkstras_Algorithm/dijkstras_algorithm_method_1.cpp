// Dijkstra's Algorithm Method 1

#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // creating expolored and dist arr
        vector<bool> Explored(V,0); // bool vector for explore track
        vector<int> dist(V,INT_MAX); 
        dist[S] = 0; // dist from Source to source
        int count = V;
        while(count--){
            // selecting a node which is unexplored and its dist is minimum
            int node = -1; // initial node 
            int value = INT_MAX; // initial value
            
            for(int i = 0; i<V; i++){
                if(!Explored[i] && value > dist[i]){
                    // initializing the new values
                    node = i;
                    value = dist[i];
                }
            }
            
            Explored[node] = 1; // marking node as explored
            
            // relax the edges
            for(int v = 0 ; v < adj[node].size(); v++){
                int neighbour = adj[node][v][0];
                int weight = adj[node][v][1];
                
                // condition check
                if(!Explored[neighbour] &&
                weight + dist[node] < dist[neighbour]){
                    dist[neighbour] = weight + dist[node];
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
    fo(i,V){
        cout<<res[i]<<" ";
    }
    return 0;
}