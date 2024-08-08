// Number of Operations to Make Network Connected
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
class DisjointSet{
    public:
    vector<int> rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }


    int findParent(int u){
        if(u==parent[u]){
            return u;
        }

        return parent[u] = findParent(parent[u]);
    }

    void UnionByRank(int u , int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }

        else if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }

        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void UnionBySize(int u , int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        
        int cntExtras = 0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            
            // cheking parent
            if(ds.findParent(u) == ds.findParent(v)){
                cntExtras++;
            }
            
            else{
                ds.UnionByRank(u,v);
            }
        }
        
        // fidning the connected or ultimate parent components
        int cntConnected = 0;
        for(int i = 0 ; i<n ; i++){
            if(ds.parent[i] == i){
                cntConnected++;
            }
        }
        
        int ans = cntConnected - 1; // edges must be there
        if(cntExtras >= ans){
            return ans;
        }
        else{
            return -1;
        }
    }
};