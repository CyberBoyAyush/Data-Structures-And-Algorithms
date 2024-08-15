// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

// Appraoch 1 -> Using Dijkstra's Algorithm
// TC - O(n^2 * logn)
// SC - O(n^2)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define P pair<int,int>

    void dijkstra(int n, unordered_map<int,vector<P>> adj, vector<int> &result, int src){
        // Priority Queue for Dijkstra algo
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,src}); // pushing dist from src to src
        fill(result.begin(), result.end(), INT_MAX);
        result[src] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &Pair:adj[node]){
                int adjNode = Pair.first;
                int wt = Pair.second;

                if(d + wt < result[adjNode]){
                    result[adjNode] = d + wt;
                    pq.push({d + wt , adjNode});
                }
            }

        }

    }

    int findResCity(int n,vector<vector<int>> &SPM, int distanceThreshold){
        int resultCity = -1;
        int leastCityReachCnt = INT_MAX;

        for(int i = 0; i<n ; i++){
            int countReach = 0;
            for(int j = 0; j<n ; j++){
                if(i != j && SPM[i][j] <= distanceThreshold){
                    countReach++;
                }
            }

            if(countReach <= leastCityReachCnt){
                leastCityReachCnt = countReach;
                resultCity = i;
            }
        }

        return resultCity;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Using Dijkstra's Algorithm

        // This matrix store the Shortest path from each node to another node
        vector<vector<int>> SPM(n, vector<int>(n, INT_MAX));

        // filling initial matrix of self path
        for (int i = 0; i < n; i++) {
            SPM[i][i] = 0; // dist from self to self will be 0
        }

        // we create adj list
        unordered_map<int,vector<P>> adj;

        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        // calling dijkstra algo for every city
        for(int i = 0; i<n ; i++){
            dijkstra(n, adj, SPM[i], i); // we are send here SPM[i] means we are sending row to dijkstra to fill the answer
        }

        // we find the city by iterating over SPM
        return findResCity(n, SPM, distanceThreshold);

    }
};

// Approach 2 -> Using Bellman Ford Algorithm
// TC - O(n^3)
// SC - O(n^2)
class Solution {
public:
    void bellman(int n, vector<vector<int>>& edges, vector<int> &result, int src){
        fill(begin(result), result.end(), INT_MAX);

        result[src] = 0;

        for(int i = 0 ; i<n ; i++){
            for(auto &edge : edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if(result[u] != INT_MAX && result[u] + wt < result[v]){
                    result[v] = result[u] + wt; // result[u] != INT_MAX for checking out of bound
                }

                if(result[v] != INT_MAX && result[v] + wt < result[u]){
                    result[u] = result[v] + wt; // result[v] != INT_MAX for checking out of bound
                }
            }
        }
    }

    int findResCity(int n,vector<vector<int>> &SPM, int distanceThreshold){
        int resultCity = -1;
        int leastCityReachCnt = INT_MAX;

        for(int i = 0; i<n ; i++){
            int countReach = 0;
            for(int j = 0; j<n ; j++){
                if(i != j && SPM[i][j] <= distanceThreshold){
                    countReach++;
                }
            }

            if(countReach <= leastCityReachCnt){
                leastCityReachCnt = countReach;
                resultCity = i;
            }
        }

        return resultCity;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Using Bellman Ford Algorithm

        // This matrix store the Shortest path from each node to another node
        vector<vector<int>> SPM(n, vector<int>(n, INT_MAX));

        // filling initial matrix of self path
        for (int i = 0; i < n; i++) {
            SPM[i][i] = 0; // dist from self to self will be 0
        }


        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];


            // updating weights in SPM matrix (initial)
            SPM[u][v] = wt;
            SPM[v][u] = wt;
        }

        // calling dbellman ford algo for every city
        for(int i = 0; i<n ; i++){
            bellman(n, edges, SPM[i], i); 
        }

        // we find the city by iterating over SPM
        return findResCity(n, SPM, distanceThreshold);

    }
};

// Approach 3 -> Using Floyd Warshall Algorithm
// TC - O(n^3)
// SC - O(n^2)

class Solution {
public:
    void floydd(int n, vector<vector<int>> &SPM){
        for(int via = 0; via < n ; via++){
            for(int i = 0 ; i< n ; i++){
                for(int j = 0 ; j<n ; j++){
                    SPM[i][j] = min(SPM[i][j] , SPM[via][j] + SPM[i][via]);
                }
            }
        }
    }

    int findResCity(int n,vector<vector<int>> &SPM, int distanceThreshold){
        int resultCity = -1;
        int leastCityReachCnt = INT_MAX;

        for(int i = 0; i<n ; i++){
            int countReach = 0;
            for(int j = 0; j<n ; j++){
                if(i != j && SPM[i][j] <= distanceThreshold){
                    countReach++;
                }
            }

            if(countReach <= leastCityReachCnt){
                leastCityReachCnt = countReach;
                resultCity = i;
            }
        }

        return resultCity;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Using Dijkstra's Algorithm

        // This matrix store the Shortest path from each node to another node
        vector<vector<int>> SPM(n, vector<int>(n, 1e9 + 7));

        // filling initial matrix of self path
        for (int i = 0; i < n; i++) {
            SPM[i][i] = 0; // dist from self to self will be 0
        }


        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];

            SPM[u][v] = wt;
            SPM[v][u] = wt;
        }

        // calling floyd warshall algo for every city
        floydd(n,SPM);

        // we find the city by iterating over SPM
        return findResCity(n, SPM, distanceThreshold);

    }
};