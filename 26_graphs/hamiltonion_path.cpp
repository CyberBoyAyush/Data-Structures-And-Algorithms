// Hamiltonion Path
// GFG : https://www.geeksforgeeks.org/problems/hamiltonian-path2522/1

#include<bits/stdc++.h>
using namespace std;

// Using DFS -> This is for 1 based indexing
// TC : O(N!)
// SC : O(N)
class Solution
{
    public:
    bool DFS(int node, vector<vector<int>> &adj,  vector<bool> &visited, 
    int &count, int N){
        visited[node] = 1;
        
        count++;
        
        if(count==N){
            return 1;
        }
        
        // go in neighbours
        for(auto v:adj[node]){
            if(!visited[v] && DFS(v,adj,visited,count,N)){
                return 1; // found the path
            }
        }
        
        visited[node] = 0; // unvisiting the node path not found
        count--;
        return 0;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // Step 1-> creating adj list
        vector<vector<int>> adj(N);
        
        for(int i = 0; i<M; i++){
            int u = Edges[i][0] - 1;
            int v = Edges[i][1] - 1;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(N,0);
        int count = 0; // counts how many nodes are vsiited
        
        for(int i = 0; i<N ; i++){
            if(DFS(i,adj,visited,count,N)){
                return 1;
            }
        }
        
        return 0;
    }
};