// shortest path in a graph using bfs traversal -> return path

#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

vector<int> shortestPath( vector<pair<int,int>> edges , int N , int M, int src , int dest){
	
	// create adj list
            // map
        unordered_map<int,vector<int>> adj;
            // pushing data in it
        for(int i = 0 ; i< M ; i++){
            int u = edges[i].first - 1;
            int v = edges[i].second - 1;
            
            // mapping
            adj[u].push_back(v); // u->v
            adj[v].push_back(u); // v->u
        }    
        
		// making src and dest 0 based indexing
		src--;
		dest--;

        // creating visited arr and dist array
        vector<int> parent(N,-1);
        vector<bool> vis(N,0);
        
        // creating queue and pushing its value in it
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        
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
                parent[v] = node;
            }
        }
        
		// creating ans
		vector<int> path;

		while(dest!=-1){
			path.push_back(dest+1); // bcz we made it 0 based and ans will be in 1 based
			dest = parent[dest];
		}

		reverse(path.begin(),path.end());
		return path;
	
}


int main(){
    int N = 6;
    int M = 5;
    vector<pair<int,int>> edges = {{1,2},{1,3},{2,4},{3,5},{3,6}};
    int src = 1;
    int dest = 5;
    vector<int> res = shortestPath(edges,N,M,src,dest);
    for(int i = 0 ; i< res.size() ; i++){
        cout<<res[i]<<" ";
    }
  return 0;
}