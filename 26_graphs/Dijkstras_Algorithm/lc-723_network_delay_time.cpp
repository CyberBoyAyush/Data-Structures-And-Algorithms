// Leetcode 723
// Network Delay Time
// https://leetcode.com/problems/network-delay-time/

#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 0 ;i<n ;i++)

// code to find the network delay time using Dijkstra's Algorithm 
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // creationn of adj list
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto & vec : times){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            adj[u].push_back({v,w});
        }
        
        // Applying Dijkstra's Algorithm
        
        // min heap for Dijkstra's Algorithm
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> dist(n + 1,INT_MAX);

        vector<int> Explored(n+1,0);

        dist[k] = 0; // src node dist
        
        pq.push({0,k}); // pq initializiation

        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();

            if(Explored[node]==1)   continue;

            Explored[node] = 1;

            for(auto &v:adj[node]){
                int neighbour = v.first;
                int w = v.second;

                if(!Explored[neighbour] && 
                w + dist[node] < dist[neighbour]){
                    dist[neighbour] = w + dist[node];
                    pq.push({dist[neighbour] , neighbour});
                }
            }
        }

        int ans = INT_MIN;
        
        for(int i = 1; i <= n; i++)
            ans = max(ans, dist[i]);
        
	    return ans == INT_MAX ? -1 : ans; 

    }
};

