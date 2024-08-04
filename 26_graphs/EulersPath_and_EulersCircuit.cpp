// Eulers Path and Eulers Circuit
// Eulerian Path is a path in graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.

// GFG : https://www.geeksforgeeks.org/eulerian-path-and-circuit/
// Eulerian Path and Circuit for undirected graph

#include<bits/stdc++.h>
using namespace std;

// Conditions for Eulers Path:
// 1. All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges).
// 2. Any 0 or 2 certices can have odd degree.

// Conditions for Eulers Circuit:
// 1. All vertices have even degree.
// 2. All vertices are connected.

class Solution {
public:
    void DFS(int node, vector<int>adj[], vector<bool> &visited){
        visited[node] = 1; // marking it visited
        
        for(int &v : adj[node]){
            if(!visited[v])
                DFS(v,adj,visited);
        }
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Finding the Degree of every node
	    vector<int> deg(V,0);
	    int oddDegCnt = 0;
	    for(int i = 0 ; i< V; i++){
	        // Calculating the degree
	        deg[i] = adj[i].size();
	        
	        // Calculating the odd deg nodes
	        if(deg[i] % 2 == 1){
	            oddDegCnt++; // if oddDegCnt is != 0 then it cant be a Eulers Circuit
	        }
	    }
	    
	    if(oddDegCnt!=0 && oddDegCnt!=2){
	        // it cant be euler's path also
	        return 0;
	    }   
	    
	    
	    // Now checking all Non Zero nodes should be connected
	    vector<bool> visited(V,0);
	    // DFS
	    for(int i = 0 ; i < V; i++){
	        if(deg[i]!=0){ // degree exists
	            DFS(i,adj,visited);
	            break;
	        }
	    }
	    
	    // if any node with non zero deg is not visited return 0 
	    // EP cant exists
	    for(int i = 0 ; i< V; i++){
	        if(visited[i]==0 && deg[i]!=0){
	            return 0;
	        }
	    }
	    
	    /// Any one of euleriacn cu=ircuit or path will exits
	    if(oddDegCnt==0){
	        return 2; // eulerian circuit
	    }
	    
	    else{
	        // Eulerian path
	        return 1;
	    }
	}
};

// We are returning 0 if no eulerian path or circuit exists
// 1 if eulerian path exists
// 2 if eulerian circuit exists

// TC : O(V+E) SC : O(V)
