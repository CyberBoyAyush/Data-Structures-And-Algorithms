// Path with Minimum Effort
// LC 1631
// https://leetcode.com/problems/path-with-minimum-effort/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,pair<int,int>> P;

    vector<vector<int>> directions{{0,1} , {-1,0} , {0,-1} , {1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> res(m , vector<int>(n,INT_MAX));

        priority_queue<P, vector<P> , greater<P>> pq; // minheap

        // Applying dijkstra's Algorithm
        res[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff = pq.top().first;
            auto coord = pq.top().second;
            int row = coord.first;
            int col = coord.second;

            pq.pop();

            for(auto dir : directions){
                int nrow = row + dir[0];
                int ncol = col +dir[1];

                //check condt -> inbound
                if(nrow >= 0 && nrow<m && ncol >= 0 && ncol < n ){
                    int absDiff = abs(heights[row][col] - heights[nrow][ncol]);
                    int maxDiff = max(diff,absDiff);

                    if(res[nrow][ncol] > maxDiff){
                       res[nrow][ncol] = maxDiff;
                       pq.push({res[nrow][ncol] , {nrow,ncol}}) ;
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};

// Time complexity : O(m*n*log(m*n))
// Space complexity : O(m*n)