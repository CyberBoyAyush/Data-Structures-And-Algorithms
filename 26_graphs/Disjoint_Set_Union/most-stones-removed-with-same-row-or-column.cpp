// 947. Most Stones Removed with Same Row or Column
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

// Approach -> DFS
// TC - O(N)
// SC - O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void dfs(int node, vector<bool> &visited, vector<vector<int>>& stones){
    visited[node] = 1;
    for(int i = 0 ; i<stones.size(); i++){
        int r = stones[node][0];
        int c = stones[node][1];
        if(!visited[i] && (stones[i][0] == r || stones[i][1] == c)){
            dfs(i,visited,stones);
        }
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n,0);

        int groups = 0; // keeps track of group

        // dfs on not visited
        for(int i = 0; i<n; i++){
            if(visited[i]){
               continue; 
            }
            dfs(i,visited,stones);
            groups++;
        }
        return n - groups;
    }
};

// Approach 2 -> Union Find
// TC - O(N)
// SC - O(N)

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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.resize(n);

        // parent and rank intiialization
        for(int i = 0 ; i< n ; i++){ 
            parent[i] = i;
            rank[i] = 0;
        }


        // creating components (groups) [row and col matrch kr rhe hai toh unko ek group me dalenge]
        for(int i = 0 ; i<n ; i++){
            for(int j = i+ 1; j<n ; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    Union(i,j);
                }
            }
        }

        // finding groups creater (number)

        int groups = 0;
        for(int i = 0 ; i< n ; i++){
            if(parent[i] == i) groups++;
        }

        return n - groups;
    }
};
