// Design a graph with a shortest path calculator
// Leetcode : https://leetcode.com/problems/design-graph-with-shortest-path-calculator/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 -> Using Dijkstra's Algorithm
class Graph {
public:
unordered_map<int,vector<pair<int,int>>> adj;
priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
int N;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        for(auto & edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v,wt});
    }
    
    int shortestPath(int node1, int node2) {
        //Applying Dijkstra's Algorithm
        vector<int> dist(N,INT_MAX);
        dist[node1] = 0;
        pq.push({0,node1});

        while(!pq.empty()){
            int d  = pq.top().first;
		    int node = pq.top().second;
		    pq.pop();

            // going in neighbours
            for(auto v : adj[node]){
                int neighbour = v.first;
                int wt = v.second;

                if(d + wt < dist[neighbour]){
                    dist[neighbour] = d + wt;
                    pq.push({d + wt , neighbour});
                }
            }
        }
         return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};


// Approach 2 -> Using Floyd Warshall Algorithm
class Graph {
public:
    vector<vector<int>> adj;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        adj = vector<vector<int>>(n, vector<int>(n,1e9));
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
            adj[u][v] = wt;
        }
        
        // Not diagnol set 0
        for(int i = 0; i<N; i++){
            adj[i][i] = 0;
        }

        // Floyd Warshal Algo
        for(int k = 0; k< N ; k++){
            for(int i = 0 ; i< N ; i++){
                for(int j = 0 ; j < N ; j++){
                    adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        
        for(int i = 0; i<N; i++) {
            for(int j = 0; j<N; j++) {
                // via new edge check karo
                adj[i][j] = min(adj[i][j], adj[i][u] + wt + adj[v][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return adj[node1][node2] == 1e9 ? -1:adj[node1][node2];
    }
};
