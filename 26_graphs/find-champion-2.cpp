// 2924. Find Champion II
// https://leetcode.com/problems/find-champion-ii/description/?envType=daily-question&envId=2024-11-26

#include <bits/stdc++.h>
using namespace std;

// Approach: Indegree
// TC: O(V+E)
// SC: O(V)

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            indegree[v]++; // directed graph
        }

        int champ = -1;
        int count = 0;

        for(int i = 0; i<n ; i++){
            if(indegree[i] == 0){
                champ = i;
                count++;

                if(count > 1){
                    return -1;
                }
            }
        }

        return champ;
    }
};