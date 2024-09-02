// Triangle
// LEEtcode 120: https://leetcode.com/problems/triangle/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Recursion
// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n)

class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& a,int n){
        if(i==n-1){
            return a[n-1][j];
        }

        int down = a[i][j] + solve(i+1,j,a,n);
        int diagnol = a[i][j] + solve(i+1,j+1,a,n);

        return min(down , diagnol);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        return solve(0,0,triangle,n);
    }
};

// Approach 2: Recursion + Memoization
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& a,int n){
        if(i==n-1){
            return a[n-1][j];
        }

        if(dp[i][j] != -1)  return dp[i][j];

        int down = a[i][j] + solve(i+1,j,a,n);
        int diagnol = a[i][j] + solve(i+1,j+1,a,n);

        return dp[i][j] = min(down , diagnol);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,triangle,n);
    }
};

// Approach 3: Tabulation
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        int dp[n][n];

        for(int j = 0; j<n ; j++){
            dp[n-1][j] = a[n-1][j];
        }

        for(int i = n-2; i>=0; i--){
            for(int j = i ; j>= 0; j--){
                int down = a[i][j] + dp[i+1][j];
                int diagnol = a[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down,diagnol);
            }
        }

        return dp[0][0];
    }
};

// Approach 4: Tabulation (Space Optimized)
// Time Complexity: O(m*n)
// Space Complexity: O(n)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> front(n);

        for(int j = 0; j<n ; j++){
            front[j] = a[n-1][j];
        }

        for(int i = n-2; i>=0; i--){
            vector<int> curr(n);
            for(int j = i ; j>= 0; j--){
                int down = a[i][j] + front[j];
                int diagnol = a[i][j] + front[j+1];

                curr[j] = min(down,diagnol);
            }
            front = curr;
        }

        return front[0];
    }
};