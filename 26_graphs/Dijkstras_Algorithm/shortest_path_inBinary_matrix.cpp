// shortest_path_inBinary_matrix.cpp

// Leetcode 1091

// https://leetcode.com/problems/shortest-path-in-binary-matrix/

// Approach 1 -> Using BFS Method

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> directions {
        {1, 1}, {1, 0}, {0, 1}, {-1, -1}, {1, -1}, { -1, 1 } , {-1,0} ,
        {0,-1}
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // edge cases
        if (m == 0 || n == 0 || grid[0][0] != 0) {
            return -1;
        }

        // Starting BFS
        queue<pair<int, int>> q;
        q.push({0, 0});

        grid[0][0] = 1; // marking it as visited

        int level = 0; // identicated how many levels we have traveled

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                // final condition archieved
                if (x == m - 1 && y == n - 1) {
                    return level + 1;
                }

                // traverse in all 8 directions
                for(auto dir : directions){
                    int nrow = x + dir[0];
                    int ncol = y + dir[1];

                    // checking safe conditons and not visied
                    if(nrow>=0 && nrow<m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol]==0){
                        // safe and 0
                        q.push({nrow,ncol});
                        grid[nrow][ncol] = 1; // marking it visited
                    }
                }
            }
            level++;
        }
        return -1; // we never found it
    }
};

// Approach 2 : Using Dijkstra's Algorithm (Priority_Queue)
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{{1, 1},  {1, 0},  {0, 1},  {-1, -1},
                                   {1, -1}, {-1, 1}, {-1, 0}, {0, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // edge cases
        if (m == 0 || n == 0 || grid[0][0] != 0) {
            return -1;
        }

        // Appling Dijkstra's Algorithm Using Priority_Queue

        // Result (dist vector) will be 2d here
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}}); // pushing the source

        dist[0][0] = 0; // dist from src to src


        while (!pq.empty()) {
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            // going in the neighbours
            for (auto dir : directions) {
                int nrow = row + dir[0];
                int ncol = col + dir[1];

                // checking safe condt
                int distance = 1; // default dist is 1 only

                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
                    grid[nrow][ncol] == 0 && d + distance < dist[nrow][ncol]) {

                    pq.push({(d + distance), {nrow, ncol}});
                    dist[nrow][ncol] = d + distance;

                }
            }
        }
        if (dist[m - 1][n - 1] == INT_MAX) {
            return -1;
        }

        return dist[m - 1][n - 1] + 1;
    }
};