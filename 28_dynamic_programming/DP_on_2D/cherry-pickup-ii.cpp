// Cherry Pickup II
// Leetcode : https://leetcode.com/problems/cherry-pickup-ii/

// Approach 1: Recursion -> TLE
// Time Complexity: O(8^(m*n))
// Space Complexity: O(m*n)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int c1, int c2){
        int m = grid.size();
        int n = grid[0].size();

        if(row >= m)  return 0; // no cheery out of bound

        int cherryCnt = grid[row][c1]; // if both robs in same cell
        if(c1 != c2){
            // both robs on diff cell
            cherryCnt += grid[row][c2]; // add rob 2 also in it
        }
        
        int ans = INT_MIN;

        // now exploring all 9 options
        for(int i = -1; i<= 1; i++){
            for(int j = -1; j<=1 ; j++){
                int newCol1 = c1 + i;
                int newCol2 = c2 + j;

                if(newCol1 >= 0 && newCol1 < n && newCol2 >= 0 && newCol2 < n){
                    ans = max(ans,solve(grid, row+1, newCol1, newCol2));
                }
            }
        }

        return cherryCnt + ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return solve(grid,0,0,n-1); 
    }
};

// Approach 2: Recursion + Memoization
class Solution {
public:
    int dp[71][71][71];
    int solve(vector<vector<int>>& grid, int row, int c1, int c2){
        int m = grid.size();
        int n = grid[0].size();

        if(row >= m)  return 0; // no cheery out of bound

        if(dp[row][c1][c2] != -1){
            return dp[row][c1][c2];
        }

        int cherryCnt = grid[row][c1]; // if both robs in same cell
        if(c1 != c2){
            // both robs on diff cell
            cherryCnt += grid[row][c2]; // add rob 2 also in it
        }
        
        int ans = INT_MIN;

        // now exploring all 9 options
        for(int i = -1; i<= 1; i++){
            for(int j = -1; j<=1 ; j++){
                int newCol1 = c1 + i;
                int newCol2 = c2 + j;

                if(newCol1 >= 0 && newCol1 < n && newCol2 >= 0 && newCol2 < n){
                    ans = max(ans,solve(grid, row+1, newCol1, newCol2));
                }
            }
        }

        return dp[row][c1][c2] = cherryCnt + ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(grid,0,0,n-1); 
    }
};

// Approach 3: Tabulation -> 3D DP Array
// Time Complexity: O(m*n*n)
// Space Complexity: O(m*n*n)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int t[71][71][71];
        memset(t, -1, sizeof(t));  // Initialize the array with -1
        // t[row][c1][c2] = max cherries collected toll row, c1 by rob 1 + row, c2 by rob 2

        t[0][0][n-1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n-1]; // taking care of edge case here if both are standing in same col rob1 and rob 2

        for(int row = 1 ; row < m ; row++){
            for(int c1 = 0; c1 <= min(n-1,row); c1++){
                for(int c2 = max(0,n - row - 1); c2 < n ; c2 ++){
                    // now taking in mind of all 9 possibilites
                    int prevRowMax = 0;
                    for(int prevCol1 = max(0, c1-1); prevCol1 <= min(n-1, c1 + 1); prevCol1++){
                        for(int prevCol2 = max(0,c2-1) ; prevCol2 <= min(n-1, c2 + 1); prevCol2++){
                            prevRowMax = max(prevRowMax, t[row-1][prevCol1][prevCol2]);
                        }
                    }

                    // filling ans
                    if(c1 == c2){
                        // same col
                        t[row][c1][c2] = prevRowMax + grid[row][c1];
                    }
                    else{
                        t[row][c1][c2] = prevRowMax + grid[row][c1] + grid[row][c2];
                    }
                }
            }
        }

        int res = 0;
        for(int i = 0 ; i< n ;i++){
            for(int j = 0 ; j< n ; j++){
                res = max(res, t[m-1][i][j]);
            }
        }

        return res;
    }
};

// Approach 4: Tabulation -> 2D DP Array
// Time Complexity: O(m*n*n)
// Space Complexity: O(n*n)

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int t[71][71];
        memset(t, -1, sizeof(t));  // Initialize the array with -1
        // t[c1][c2] = max cherries collected till row, c1 by rob 1 + row, c2 by rob 2

        t[0][n-1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n-1]; // taking care of edge case here if both are standing in same col rob1 and rob 2

        for(int row = 1 ; row < m ; row++){
            int temp[71][71];
            memset(temp, -1, sizeof(temp));
            for(int c1 = 0; c1 <= min(n-1,row); c1++){
                for(int c2 = max(0,n - row - 1); c2 < n ; c2 ++){
                    // now taking in mind of all 9 possibilites
                    int prevRowMax = 0;
                    for(int prevCol1 = max(0, c1-1); prevCol1 <= min(n-1, c1 + 1); prevCol1++){
                        for(int prevCol2 = max(0,c2-1) ; prevCol2 <= min(n-1, c2 + 1); prevCol2++){
                            prevRowMax = max(prevRowMax, t[prevCol1][prevCol2]);
                        }
                    }

                    // filling ans
                    if(c1 == c2){
                        // same col
                        temp[c1][c2] = prevRowMax + grid[row][c1];
                    }
                    else{
                        temp[c1][c2] = prevRowMax + grid[row][c1] + grid[row][c2];
                    }
                }
            }

            for(int i = 0 ; i< n ;i++){
                for(int j = 0 ; j< n ; j++){
                    t[i][j] = temp[i][j];
                }
            }
        }

        int res = 0;
        for(int i = 0 ; i< n ;i++){
            for(int j = 0 ; j< n ; j++){
                res = max(res, t[i][j]);
            }
        }
        return res;
    }
};