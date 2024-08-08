// Count Unreachable Pairs of Nodes in an Undirected Graph
// Leetcode 2316 : https://leetcode.com/problems/count-unreachable-nodes-in-connected-graph/

// Approach -> Disjoint Set Union
// TC - O(V+E)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
 
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n , 0);

        // Intiializing the parent
        for(int i = 0 ; i< n ; i++){
            parent[i]=i;
        }

        // Processing the edges and make components
        for(auto &vec:edges){
            int u = vec[0];
            int v = vec[1];

            // Union apply kro
            Union(u,v);
        }

        // Map banalo and find the size
        unordered_map<int,int> mpp;
        for(int i = 0 ; i< n ; i++){
            int fatherNode = find(i);
            mpp[fatherNode]++;
        }

        // find answer using map
        long long result = 0;
        long long remNodes = n;
        for(auto it : mpp){
            int fatherNode = it.first;
            long long size = it.second;

            // final formula
            result += size * (remNodes - size);

            // reducting remnodes
            remNodes -= size;
        }

        return result;
    }
};