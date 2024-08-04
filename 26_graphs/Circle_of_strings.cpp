// Circle Of Strings
// GFG : https://www.geeksforgeeks.org/problems/circle-of-strings4530/1?page=1&difficulty%5B%5D=1&category%5B%5D=Graph&sortBy=submissions

#include<bits/stdc++.h>
using namespace std;

// Appraoch -> Most Optimal Approach
// 1. Create a graph with 26 vertices.
// 2. Create a directed edge from first char to last char of each string.
// 3. Check if the graph has a eulerian circuit.
// 4. If it has then return 1 else 0.

// TC: O(N) + O(26) + O(26) + O(26) + O(26) + O(26) + O(26) = O(N)
// SC: O(26) + O(26) + O(26) + O(26) = O(26)
class Solution
{
    public:
    void DFS(int node, vector<int> adj[], vector<bool> &visited){
        visited[node] = 1;
        
        for(int &v:adj[node]){
            if(!visited[v]){
                DFS(v,adj,visited);
            }
        }
    }
    int isCircle(int N, vector<string> A)
    {
        // Creating edges on the basis of first nad last char
        
        // Adj list adn finding inDeg and outDeg 
        vector<int> adj[26];
        vector<int> inDeg(26,0);
        vector<int> outDeg(26,0);
        for(int i = 0 ; i<N ; i++){
            string temp = A[i];
            int u = temp[0] - 'a'; // converting in int
            int v = temp[temp.size()-1] - 'a';
            adj[u].push_back(v);
            outDeg[u]++;
            inDeg[v]++;
        }
        
        // Checking for eulerian circuit
        for(int i = 0 ; i<26; i++){
            if(inDeg[i] != outDeg[i]){
                return 0; // EC not present
            }
        }
        
        // Check for all edges aprt of single components
        vector<bool> visited(26,0);
        int node = A[0][0] - 'a'; // sending first node
        DFS(node,adj,visited);
        
        for(int i = 0 ; i<26 ; i++){
            if(inDeg[i] != 0 && visited[i] == 0){
                return 0 ; // ec does not exists
            }
        }
        
        return 1;
    }
};