// Bus Routes
// LeetCode: 815. Bus Routes
// https://leetcode.com/problems/bus-routes/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //edge case
        if(source == target)    return 0;
        unordered_map<int,vector<int>> adj; // key = stops, values = indices

        for(int i = 0 ; i< routes.size(); i++){
            for(auto & stops : routes[i]){
                adj[stops].push_back(i);
            }
        }

        queue<int> q;
        vector<bool> visited(501,0);
        for(auto &route : adj[source]){
            q.push(route);
            visited[route] = 1; // true
        }

        int busCount = 1; // initial kisi bas pe toh chadenge hi
        // do BFS
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int route = q.front();
                q.pop();

                // go in routes 
                for(auto &stop : routes[route]){
                    if(stop == target){
                        return busCount;
                    }
                    
                    // checking stop is present at which other index
                    for(auto &nextRoute : adj[stop]){
                        if(!visited[nextRoute]){
                            visited[nextRoute] = 1; // mark it visited
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};