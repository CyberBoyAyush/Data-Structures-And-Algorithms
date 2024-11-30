//  * This file contains the implementation of a solution to the problem of finding a valid arrangement of pairs using Euler's Path and Hierholzer's Algorithm.
//  * 
//  * Hierholzer's Algorithm is used to find an Eulerian path or circuit in a graph. An Eulerian path is a path in a graph that visits every edge exactly once. 
//  * The algorithm works by repeatedly following unused edges until it returns to the starting vertex, forming a cycle. If there are any unused edges left, 
//  * it starts a new cycle from one of the vertices in the current cycle that has unused edges. The final path is obtained by combining these cycles.
//  * 
//  * The approach involves the following steps:
//  * 1. Build the adjacency list and other maps (in-degree and out-degree).
//  * 2. Find the starting node for traversal based on the in-degree and out-degree conditions.
//  * 3. Perform a depth-first search (DFS) to construct the Eulerian path.
//  * 4. Build the result by reversing the Eulerian path and formatting it as required.
//  * 
//  * Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
//  * Space Complexity: O(V), where V is the number of vertices.

// 2097. Valid Arrangement of Pairs
// https://leetcode.com/problems/valid-arrangement-of-pairs/description/?envType=daily-question&envId=2024-11-30

#include <bits/stdc++.h>
using namespace std;

// Approach: Using Euler's Path and Hierholzer's Algorithm
// TC - (V + E)
// SC - (V)

// Hierholzer's Algorithm 

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // step 1 -> buidl adj list and other maps
        unordered_map<int, vector<int>> adj;

        // build indegree and outdegree to find starting point for graph(euler)
        unordered_map<int, int> outDegree;
        unordered_map<int, int> inDegree;
        // {node, indegree/outdegree}

        // filling adj, indegree and outdegree
        for(auto &edge:pairs){
            int u = edge[0];
            int v = edge[1];

            // filling adj
            adj[u].push_back(v);

            // filling indeg and outdeg
            inDegree[v]++;
            outDegree[u]++;
        }

        // step 2: find the startNode for traversal (outDeg - inDeg == 1)
        int startNode = pairs[0][0]; // we take any random node from pairs as initial
        for(auto &it:adj){
            int node = it.first;

            // check indeg and outdeg
            if(outDegree[node] - inDegree[node] == 1){
                // validf starting node for traversal
                startNode = node; // value is found and updated
                break;
            }
        }

        // simply do DFS
        vector<int> EulerPath; // final ans
        stack<int> st; // for dfs

        st.push(startNode); // initial Node

        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                // if ther eis edge for curr node to  proces in adj list
                int neig = adj[curr].back(); // take neig from back
                adj[curr].pop_back(); // popping it from back (adj list)
                // push in satck for traversal
                st.push(neig);
            }
            else{
                // no neig to process
                // push in euler path
                EulerPath.push_back(curr);

                // popping it
                st.pop();
            }
        }

        // step 3: building result
        reverse(EulerPath.begin(), EulerPath.end()); // as it is from stakc so it is reversed

        vector<vector<int>> res;

        for(int i = 0; i< EulerPath.size()-1; i++){
            res.push_back({EulerPath[i],EulerPath[i+1]});
        }

        return res;
    }
};