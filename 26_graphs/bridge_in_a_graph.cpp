// Bridge in a Graph
// Leetcode 1192. Critical Connections in a Network
// https://leetcode.com/problems/critical-connections-in-a-network/


// Tarjan's Algorithm
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(int node, int parent,vector<vector<int>> &adj, vector<int> &disc, vector<int> &low,
    vector<bool> &visited, vector<vector<int>> &Bridges, int &count){
        disc[node] = low[node] = count;
        visited[node] = 1;

        // Apply DFS on neighbbours
        for(int v = 0; v<adj[node].size(); v++){
            int neig = adj[node][v];
            if(neig == parent)  continue;
            else if(visited[neig]){
                low[node] = min(low[node],low[neig]);
            }
            else{
                count++; // increasing disc time
                DFS(neig,node,adj,disc,low,visited,Bridges,count);
                //check bridge condt
                if(disc[node] < low[neig]){
                    // bridge found we now push it in Bridges
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(neig);
                    Bridges.push_back(temp);
                }

                // we also update low
                low[node] = min(low[node],low[neig]); 
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Creating Adj List
        vector<vector<int>> adj(n);

        for(int i = 0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>>Bridges; // our final answer
        vector<int> disc(n); // it contains discovery time of node
        vector<int> low(n); // it contains at lowest which node out node can visit
        vector<bool> visited(n,0);

        int count = 0; // use to calculate disc and low

        DFS(0,-1,adj,disc,low,visited,Bridges,count);

        return Bridges;
    }
};