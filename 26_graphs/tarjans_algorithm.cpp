// tarjans Algoritm fro Strongly connected components
// 1. We will use a stack to store the nodes in the order they are visited
// 2. We will use a visited array to keep track of the nodes that are visited
// 3. We will use a lowlink array to keep track of the lowest node that can be visited from the current node
// 4. We will use a onstack array to keep track of the nodes that are on the stack
// 5. We will use a timer to keep track of the time
// 6. We will use a vector of vector to store the graph
// 7. We will use a vector to store the SCC


// Time Complexity: O(V+E)
// Space Complexity: O(V+E)

// GFG : https://www.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1?page=1&difficulty%5B%5D=2&category%5B%5D=Graph&sortBy=submissions
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void DFS(int node,vector<int> adj[],vector<bool> &visited,
	vector<int> &disc,vector<int> &low,stack<int> &st,
	vector<bool>&inStack,vector<vector<int>>&ans,int &timer){
	    
	    visited[node] = 1;
	    disc[node] = low[node] = timer;
	    st.push(node);
	    inStack[node] = 1;
	    
	    // go in neighbuors
	    for(auto &neig : adj[node]){
	        if(!visited[neig]){
	            timer++;
	            DFS(neig,adj,visited,disc,low,st,inStack,ans,timer);
	            low[node] = min(low[node],low[neig]);
	        }
	        else{
	            // neig already visited
	            // check 1 -> if it is present in stakc or not
	            if(inStack[neig]){
	                low[node] = min(low[node],disc[neig]);
	            }
	        }
	    }
	    
	    if(disc[node] == low[node]){
	        vector<int> temp;
	        while(!st.empty() && st.top() != node){
	            temp.push_back(st.top());
	            inStack[st.top()] = 0; // mark not in stack
	            st.pop();
	        }
	        
	        // now popping node elment outside stack
	        temp.push_back(node);
	        inStack[node] = 0;
	        st.pop();
	        
	        sort(temp.begin(),temp.end()); // it needs ans in sorted way
	        
	        ans.push_back(temp); // pushing in final ans
	    }
	}
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<vector<int>> ans;
        vector<int> disc(V);
        vector<int> low(V);
        vector<bool> visited(V,0);
        vector<bool> inStack(V,0);
        stack<int> st;
        
        int timer = 0;
        
        for(int i = 0; i<V ; i++){
            if(!visited[i]){
                DFS(i,adj,visited,disc,low,st,inStack,ans,timer);
            }
        }
        
        sort(ans.begin(),ans.end()); // we need ans in sorted
        
        return ans;
    }
};