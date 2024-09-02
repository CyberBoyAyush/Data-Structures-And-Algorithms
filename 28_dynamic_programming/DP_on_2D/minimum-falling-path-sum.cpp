// Minimum Falling Path Sum
// Leetcode : https://leetcode.com/problems/minimum-falling-path-sum/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Recursion -> TLE
// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n)

class Solution {
public:
    int solve(vector<vector<int>>& matrix,int row, int col){
        int n = matrix.size();
        if(row == n-1){
            // last row
            return matrix[row][col]; // return the last value
        }

        int sum = matrix[row][col]; // sum of currect el

        int res = INT_MAX;

        // send 3 cases -> with edge cases handling

        if(row+1 < n)
            res = min(res, sum + solve(matrix, row+1, col));
        
        if(row + 1 < n && col - 1 >= 0)
            res = min(res, sum + solve(matrix, row+1, col-1));
        
        if(row + 1 < n && col + 1 < n)
            res = min(res, sum + solve(matrix, row+1, col+1));

        return res;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int row = 0;
        int res = INT_MAX;
        for(int col = 0 ; col < n; col++){
            res = min(res, solve(matrix, row, col));
        }

        return res;
    }
};

// Approach 2: Recursion + Memoization -> TLE
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& matrix,int row, int col){
        int n = matrix.size();
        if(row == n-1){
            // last row
            return matrix[row][col]; // return the last value
        }

        if(dp[row][col] != -1)  return dp[row][col];

        int sum = matrix[row][col]; // sum of currect el

        int res = INT_MAX;

        // send 3 cases -> with edge cases handling

        if(row + 1 < n)
            res = min(res, sum + solve(matrix, row+1, col));
        
        if(row + 1 < n && col - 1 >= 0)
            res = min(res, sum + solve(matrix, row+1, col-1));
        
        if(row + 1 < n && col + 1 < n)
            res = min(res, sum + solve(matrix, row+1, col+1));

        return dp[row][col] = res;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        memset(dp,-1,sizeof(dp));

        int row = 0;
        int res = INT_MAX;
        for(int col = 0 ; col < n; col++){
            res = min(res, solve(matrix, row, col));
        }

        return res;
    }
};

// Approach 3: Tabulation
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
    int MFS(vector<vector<int>>& A) {
        int m = A.size();
        vector<vector<int>> t(m, vector<int>(m));
        
        //initialization
        for(int col = 0; col<m; col++) {
            t[0][col] = A[0][col];
        }
        
        for(int row = 1; row < m; row++) {
            for(int col = 0; col < m; col++) {
                t[row][col] = A[row][col] + min({t[row-1][col], 
                                                t[row-1][max(0, col-1)], 
                                                t[row-1][min(m-1, col+1)]});
            }
        }

        return *min_element(t[m-1].begin(), t[m-1].end());
        
    }
    int minFallingPathSum(vector<vector<int>>& A) { 
        return MFS(A);
    }
};

// Approach 4: Tabulation (Space Optimized)
// Time Complexity: O(m*n)
// Space Complexity: O(n)

class Solution {
public:
    int MFS(vector<vector<int>>& A) {
        int m = A.size();
        vector<int> prev = A[0];
        
        for(int row = 1; row < m; row++) {
            vector<int> curr(m);
            for(int col = 0; col < m; col++) {
                curr[col] = A[row][col] + min({prev[col], 
                                                prev[max(0, col-1)], 
                                                prev[min(m-1, col+1)]});
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
        
    }
    int minFallingPathSum(vector<vector<int>>& A) { 
        return MFS(A);
    }
};
