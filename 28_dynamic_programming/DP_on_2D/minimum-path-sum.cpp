// Minimum Path Sum
// Leetcode : https://leetcode.com/problems/minimum-path-sum/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Recursion
// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n)

class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& grid, int m,int n){
        // we reached to the final stage
        if(i == m-1 && j == n-1)    return grid[i][j]; // final ans

        if(i == m-1){
            // last row -> we can only go in right
            return grid[i][j] + solve(i,j+1,grid,m,n);
        }
        else if(j == n-1){
            // last col -> can go only in down
            return grid[i][j] + solve(i+1,j,grid,m,n);
        }
        else{
            // explore both
            return grid[i][j] + min(solve(i,j+1,grid,m,n) , solve(i+1,j,grid,m,n));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return solve(0,0,grid,m,n);
    }
};

// Approach 2: Recursion + Memoization
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
    int t[201][201]; // as t range is till 200
    int solve(int i, int j,vector<vector<int>>& grid, int m,int n){
        // we reached to the final stage
        if(i == m-1 && j == n-1)    return grid[i][j]; // final ans

        // Memo
        if(t[i][j] != -1)   return t[i][j];

        if(i == m-1){
            // last row -> we can only go in right
            return t[i][j] = grid[i][j] + solve(i,j+1,grid,m,n);
        }
        else if(j == n-1){
            // last col -> can go only in down
            return t[i][j] = grid[i][j] + solve(i+1,j,grid,m,n);
        }
        else{
            // explore both
            return t[i][j] = grid[i][j] + min(solve(i,j+1,grid,m,n) , solve(i+1,j,grid,m,n));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        memset(t,-1,sizeof(t));

        return solve(0,0,grid,m,n);
    }
};

// Approach 3: Tabulation
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> t(m,vector<int>(n));

        // t[i][j] = min path sum to reach till grid[i][j]

        // filling the initial [0][0]

        t[0][0] = grid[0][0]; // min path sum to reach from 0,0 will be 0,0

        // filling the first row
        for(int col = 1; col < n; col++){
            // left aaye hai hum
            t[0][col] = grid[0][col] + t[0][col-1];
        }

        // filling the first col
        for(int row = 1; row < m; row++){
            // left aaye hai hum
            t[row][0] = grid[row][0] + t[row-1][0];
        }

        // now filling the remaining
        for(int i = 1; i<m ; i++){
            for(int j = 1; j<n ; j++){
                t[i][j] = grid[i][j] + min(t[i-1][j] , t[i][j-1]);
            }
        }

        return t[m-1][n-1];
    }
};

// Approach 4: Tabulation (Space Optimized)
// Time Complexity: O(m*n)
// Space Complexity: O(n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // t[i][j] = min path sum to reach till grid[i][j]

        // filling the initial [0][0]

        grid[0][0] = grid[0][0]; // min path sum to reach from 0,0 will be 0,0

        // filling the first row
        for(int col = 1; col < n; col++){
            // left aaye hai hum
            grid[0][col] = grid[0][col] + grid[0][col-1];
        }

        // filling the first col
        for(int row = 1; row < m; row++){
            // left aaye hai hum
            grid[row][0] = grid[row][0] + grid[row-1][0];
        }

        // now filling the remaining
        for(int i = 1; i<m ; i++){
            for(int j = 1; j<n ; j++){
                grid[i][j] = grid[i][j] + min(grid[i-1][j] , grid[i][j-1]);
            }
        }

        return grid[m-1][n-1];
    }
};