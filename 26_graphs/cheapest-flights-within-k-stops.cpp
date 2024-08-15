// Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

// TC - O(E*n)
// SC - O(n)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);

        // step 1 -> creating adj list
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto &vec:flights){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];

            adj[u].push_back({v,wt});
        }

        // BFS
        int level = 0;
        queue<pair<int,int>> q;
        q.push({src,0}); // storing {node,weight}
        dist[src] = 0; // dist from src to src will be 0

        while(!q.empty() && level <= k){
            int size = q.size();

            while(size--){
                int u = q.front().first;
                int d = q.front().second;
                q.pop();

                // going in neighbours
                for(auto &p:adj[u]){
                    int v = p.first;
                    int cost = p.second;

                    if(dist[v] > d + cost){
                        dist[v] = d + cost;
                        q.push({v, d + cost});
                    }
                }
            }
            level++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};