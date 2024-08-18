// Reusable code for Disjoint set union DSU
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class UnionFind {
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
};

// Initialize parent and rank vectors
        // for (int i = 0; i < n; i++) {
        //     parent[i] = i;
        //     rank[i] = 0;
        // }