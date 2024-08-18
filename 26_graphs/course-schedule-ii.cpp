// Course Schedule II
// Link: https://leetcode.com/problems/course-schedule-ii/

// Approach -> Topological Sort
// TC - O(V+E)
// SC - O(V+E)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        unordered_map<int, vector<int>> adj;
        vector<int> inDeg(n,0);
        queue<int> q;

        for(auto &vec : prerequisites){
            int u = vec[0];
            int v = vec[1];
            adj[v].push_back(u);
            inDeg[u]++;
        }

        // psuhing indegree 0 nodes in 
        int count = 0;
        vector<int> res;
        for(int i = 0; i<n ; i++){
            if(inDeg[i] == 0){
                res.push_back(i);
                q.push(i);
                count++;
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v:adj[u]){
                inDeg[v] --;
                if(inDeg[v] == 0){
                    res.push_back(v);
                    q.push(v);
                    count++; 
                }
            }
        }

        if(count == n){
            return res;
        }
        else{
            return {};
        }
    }
};