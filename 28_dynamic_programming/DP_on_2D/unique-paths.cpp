// Unique Paths
// Leetcode : https://leetcode.com/problems/unique-paths/

// Approach 1: Recursion
// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int solve(int i, int j){
    if(i == 0 && j == 0)    return 1;
    if(i<0 || j<0)  return 0;

    int up = solve(i-1,j);
    int left = solve(i,j-1);

    return up + left;
}
    int uniquePaths(int m, int n) {
        return solve(m-1,n-1);
    }
};

// Approach 2: Recursion + Memoization
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
int solve(int i, int j, vector<vector<int>> &dp){
    if(i == 0 && j == 0)    return 1;

    if(i<0 || j<0)  return 0;

    if(dp[i][j] != -1)  return dp[i][j];

    int up = solve(i-1,j,dp);
    int left = solve(i,j-1,dp);

    return dp[i][j] = up + left;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};

// Approach 3: Tabulation
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];

        for(int i = 0; i< m ; i++){
            for(int j = 0 ; j< n ; j++){
                if(i == 0 && j == 0)    dp[i][j] = 1;

                else{
                    int up = 0;
                    int left = 0;

                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];

                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

// Approach 4: Tabulation (Optimized)
// Time Complexity: O(m*n)
// Space Complexity: O(n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0); // stores prev row

        for(int i = 0; i< m ; i++){
            vector<int> curr(n,0); // curr row
            for(int j = 0 ; j< n ; j++){
                if(i == 0 && j == 0)    curr[j] = 1;

                else{
                    int up = 0;
                    int left = 0;

                    if(i > 0) up = prev[j];
                    if(j > 0) left = curr[j-1];

                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};