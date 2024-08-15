// Kosaraju's Algorithm to find strongly connected components in a graph
// GFG: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// TC - O(V+E)
// SC - O(V+E)

// Steps:
// 1. Find the topological sort of the graph using DFS
// 2. Reverse the edges of the graph
// 3. Pop the elements from the stack and apply DFS on the reversed graph
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void DFS(int node,vector<vector<int>> &adj2,vector<bool> &visited){
	    visited[node] = 1;
	    
	    for(auto &v:adj2[node]){
	        if(!visited[v]){
	            DFS(v,adj2,visited);
	        }
	    }
	}
	void TopoSortDFS(int node,vector<vector<int>>& adj, vector<bool> &visited
	,stack<int> &st){
	    visited[node] = 1;
	    
	    for(auto &v:adj[node]){
	        if(!visited[v]){
	            TopoSortDFS(v,adj,visited,st);
	        }
	    }
	    
	    st.push(node);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // Step 1 -> Find Topological Sort using DFS
        vector<bool> visited(V,0);
        stack<int> st;
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                TopoSortDFS(i,adj,visited,st);
            }
        }
        
        // Step 2 -> Reverse the edges
            // ADJ LIST the stores reverse graph
        vector<vector<int>> adj2(V); 
        
        for(int u = 0; u<V; u++){
            for(auto &v:adj[u]){
                adj2[v].push_back(u); // reversed
            }
        }
        
        // Step 3 -> Popping from stack and applying DFS
        fill(visited.begin(), visited.end(), 0); // reset visited
        int SCC = 0; // stores the count of SCC
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                SCC++; // new scc found
                DFS(node,adj2,visited);
            }
        }
        
        return SCC;
    }
};