// Topological sort

#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public: 
    // DFS -> Recursion and Stack
	void DFS(int node,vector<int> adj[], vector<bool> &visited, stack<int> &st){
	    // amrking node as visited
	    visited[node] = 1;
	    
	    // traversal
	    for(auto i:adj[node]){
	        if(!visited[i]){
	            DFS(i,adj,visited,st);
	        }
	    }
	    
	   // pushing value in stack as backtrack
	   st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // visited arr
	    vector<bool> visited(V,0);
	    
	   // stack for storing th elements
	   stack<int> st;
	   
	   // for univisted check
	   for(int i = 0; i<V; i++){
	       if(!visited[i]){
	           DFS(i,adj,visited,st);
	       }
	   }
	   
	   // pushing value of stack in the answer arr
	   vector<int> ans;
	   while(!st.empty()){
	       ans.push_back(st.top());
	       
	       st.pop();
	   }
	   
	   return ans;
	}

// BFS -> Kahn's Algorithm
	vector<int> topoSort(int V, vector<int> adj[]){
	    vector<int> inDegree(V,0);
	    
	    // calculating indegree for every node
	    for(int u = 0; u<V; u++){
	        for(auto &v:adj[u]){
	            inDegree[v]++;
	        }
	    }
	    
	    // queue for bfs
	    queue<int> q;
	    for(int i = 0 ;i<V; i++){
	        if(inDegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    // result creation and bfs
	    vector<int> ans;
	    
	    while(!q.empty()){
	        int u = q.front();
	        ans.push_back(u);
	        q.pop();
	        
	        for(auto &v:adj[u]){
	            inDegree[v]--;
	            
	            // aur agar indegree 0 hogyi aajao q me
	            if(inDegree[v]==0)
	                q.push(v);
	        }
	    }
	    return ans;
	}

};

// Approach -> Topological Sort (Kaahn's Algorithm)

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> adj(V);

        queue<int> que;
        vector<int> indegree(V, 0);
        int count = 0;
        // 1 Reversing the edges
        for (int u = 0; u < V; u++) {
            for (int& v : graph[u]) {
                adj[v].push_back(u);
                indegree[u]++;
            }
        }

        // 2. Fill que, indegree with 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                que.push(i);
                count++;
            }
        }

        // 3. Simple BFS
        vector<bool> safe(V, false);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            safe[u] = true;

            for (int& v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    que.push(v);
                    count++;
                }
            }
        }

        vector<int> safeNodes;
        for (int i = 0; i < V; i++) {
            if (safe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};