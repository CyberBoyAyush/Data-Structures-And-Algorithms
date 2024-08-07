// Krushkal Algorithm for Minimum Spanning Tree

#include<bits/stdc++.h>
using namespace std;

class Solution{
 // Approach 2 -> Krushkal's Algorithm
 // Time Complexity : O(ElogE) + O(ElogV) -> O(ElogE) for sorting and O(ElogV) for union find
    // Space Complexity : O(V) + O(V) -> O(V) for parent and O(V) for rank
    
    // find Parent Function
    int findParent(int u , vector<int> &parent){
        if(u==parent[u]){
            return u;
        }
        
        // Asiigning for path compression
        return parent[u] = findParent(parent[u], parent);
    }
    
    // union by rank for check and merge
    void unionByRank(int u, int v , vector<int> &parent,vector<int> &rank){
        // Finding ultimate parent of u and v
        int pu = findParent(u,parent);
        int pv = findParent(v,parent);
        
        // Rank or merge
        if(rank[pu] > rank[pv]){
            parent[pv] = pu; // pv pu me merge hoga
        }
        
        else if(rank[pu] < rank[pv]){
            parent[pu] = pv; // pu pv me merge hoga
        }
        
        else{
            // kisi ko bhi merge kardo
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    
    typedef pair<int,pair<int,int>> P;
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<int> parent(V);
        vector<int> rank(V,0);
        
        // Marking parent of every node itself
        for(int i = 0 ; i< V ; i++){
            parent[i] = i;
        }
        
        // Priority Queue
        // {wt , {u,v} }
        priority_queue<P , vector<P> , greater<P>> pq;
        
        // Pushing details in pq
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int v = adj[i][j][0];
                int wt = adj[i][j][1];
                pq.push({wt, {i, v}});
            }
        }
        
        int cost = 0;
        int edges = 0;
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            
            // Check if they are in same or diff set
            if(findParent(u,parent) != findParent(v,parent)){
                cost += wt;
                unionByRank(u,v,parent,rank);
                edges ++;
            }
            
            if(edges == V-1){
                break;
            }
        }
        return cost;
    }
};