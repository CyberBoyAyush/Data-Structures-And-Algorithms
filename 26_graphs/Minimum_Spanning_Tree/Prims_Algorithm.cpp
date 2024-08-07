// Prim's Algorithm for Minimum Spanning Tree
// Prim's Algorithm is a Greedy Algorithm used to find the Minimum Spanning Tree of a graph.

// Approach: Using Priority Queue

#include<bits/stdc++.h>
using namespace std;

// TC : O(ElogV) -> E is the number of edges and V is the number of vertices.
// SC : O(V) -> V is the number of vertices.
class Solution
{
	public:
	typedef pair<int,pair<int,int>> P;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Priroty_queue
        priority_queue<P, vector<P> , greater<P>> pq; // minheap
        vector<bool> isMST(V,0);
        vector<int> Parent(V); // temp not needed
        
        int cost = 0;
        
        // psuhing details in pq
        pq.push({0,{0,-1}});
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second.first;
            int par = p.second.second;
            
            if(!isMST[node]){
                isMST[node] = 1;
                cost += wt;
                Parent[node] = par;
                
                // going in neighbours
                for(auto &v:adj[node]){
                    int neighbour = v[0];
                    int weight = v[1];
                    // if the neighbour is not apart of out mst then we push it ij queue
                    if(!isMST[neighbour]){
                        pq.push({weight,{neighbour,node}});
                    }
                }
            }
        }
        return cost;
    }
};