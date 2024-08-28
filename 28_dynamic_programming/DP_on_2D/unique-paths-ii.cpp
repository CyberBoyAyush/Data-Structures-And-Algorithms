// Unique Paths II
// Leetcode : https://leetcode.com/problems/unique-paths-ii/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Recursion + Memoization
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp) {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) {
            // we have a dead end
            return 0;
        }

        if (i == 0 && j == 0)
            return 1;

        if(i < 0 || j < 0)  return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        int up =   f(i-1,j,obstacleGrid,dp);
        int left = f(i,j-1,obstacleGrid,dp);

        return dp[i][j] = (up + left);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m , vector<int>(n,-1));

        return f(m-1,n-1,obstacleGrid,dp);
    }
};

// Approach 2: Tabulation
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int dp[m][n];


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if(obstacleGrid[i][j] == 1) dp[i][j] = 0; // dead end

                else if(i == 0 && j == 0)    dp[i][j] = 1;

                else{
                    int up = 0;
                    int left = 0;

                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];

                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m-1][n-1];
    }
};

// Approach 3: Tabulation (Space Optimized)
// Time Complexity: O(m*n)
// Space Complexity: O(n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> prev(n,0);
        for (int i = 0; i < m; i++) {
            vector<int> curr(n,0);
            for (int j = 0; j < n; j++) {
                
                if(obstacleGrid[i][j] == 1) curr[j] = 0; // dead end

                else if(i == 0 && j == 0)    curr[j] = 1;

                else{
                    int up = 0;
                    int left = 0;

                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];

                    curr[j] = up + left;
                }
            }
            prev = curr;
        }

        return prev[n-1];
    }
};