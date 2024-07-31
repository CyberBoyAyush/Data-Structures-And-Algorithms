// This is the code for Bellman Ford Algorithm

#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

// Bellman Ford Algorithm
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Dist arr creation
        vector<int> dist(V,1e8); // 1e8 -> 10^8
        dist[S] = 0; // dist from source to source
        int e = edges.size();
        
        
        // Step 1 -> Relax all the edges (V-1 Times)
        for(int i = 0; i<V-1; i++){
            for(int j = 0; j<e ; j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];
                
                //edge case for 1e8 value present at node
                if(dist[u] == 1e8)  continue;
                // condt check
                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                }
            }
        }
    
        
        // Step 2: Detetct The Cycle
        for(int j = 0; j<e ; j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];
                
                //edge case for 1e8 value present at node
                if(dist[u] == 1e8)  continue;
                
                // condt check
                if(dist[u] + weight < dist[v]){
                    // any got updated means cycle is detected
                    vector<int> ans;
                    ans.push_back(-1);
                    return ans;
                }
            }
            
            return dist;
    }
};

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> edges;
    fo(i,E){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int S;
    cin>>S;
    Solution obj;
    vector<int> res = obj.bellman_ford(V,edges,S);
    fo(i,V){
        cout<<res[i]<<" ";
    }
    return 0;
}