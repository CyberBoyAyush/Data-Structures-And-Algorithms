// Rod Cutting Problem
// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n)

class Solution{
  public:
    int solve(int idx,int N, int price[]){
        // base case
        if(idx == 0){
            return N * price[0];
        }
        
        // take and not take
        int notTake = 0 + solve(idx-1,N,price);
        int take = INT_MIN;
        int rodLength = idx+1; // as indexing is 0 based
        if(rodLength <= N){
            take = price[idx] + solve(idx,N-rodLength,price);
        }
        
        return max(take,notTake);
    }
    int cutRod(int price[], int n) {
        return solve(n-1,n,price);
    }
};

// Approach 2: Recursion + Memoization
// Time Complexity: O(n*W)
// Space Complexity: O(n*W) + O(n) for recursive stack

class Solution{
  public:
    int dp[1001][1001];
    int solve(int idx,int N, int price[]){
        // base case
        if(idx == 0){
            return N * price[0];
        }
        
        if(dp[idx][N] != -1){
            return dp[idx][N];
        }
        
        // take and not take
        int notTake = 0 + solve(idx-1,N,price);
        int take = INT_MIN;
        int rodLength = idx+1; // as indexing is 0 based
        if(rodLength <= N){
            take = price[idx] + solve(idx,N-rodLength,price);
        }
        
        return dp[idx][N] = max(take,notTake);
    }
    int cutRod(int price[], int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n-1,n,price);
    }
};

// Approach 3: Tabulation
// Time Complexity: O(n*W)
// Space Complexity: O(n*W)

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1,0));
        
        // initialization
        for(int N = 0 ; N<=n; N++){
            dp[0][N] = N * price[0];
        }
        
        for(int idx = 1; idx< n ; idx++){
            for(int N = 0 ; N<=n ; N++){
                int notTake = 0 + dp[idx-1][N];
                int take = INT_MIN;
                int rodLength = idx + 1; // as indexing is 0 based
                if(rodLength <= N){
                    take = price[idx] + dp[idx][N-rodLength];
                }
                dp[idx][N] = max(take,notTake);
            }
        }
        
        return dp[n-1][n];
    }
};

// Approach 4: Tabulation + Space Optimized
// Time Complexity: O(n*W)
// Space Complexity: O(W)

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1,0));
        
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        
        // initialization
        for(int N = 0 ; N<=n; N++){
            prev[N] = N * price[0];
        }
        
        for(int idx = 1; idx< n ; idx++){
            for(int N = 0 ; N<=n ; N++){
                int notTake = 0 + prev[N];
                int take = INT_MIN;
                int rodLength = idx + 1; // as indexing is 0 based
                if(rodLength <= N){
                    take = price[idx] + curr[N-rodLength];
                }
                curr[N] = max(take,notTake);
            }
            prev = curr;
        }
        
        return prev[n];
    }
};


// Approach 5: Tabulation + Space Optimized in 1D array
// Time Complexity: O(n*W)
// Space Complexity: O(W)

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1,0));
        
        vector<int> prev(n+1,0); // single array optimization
        
        // initialization
        for(int N = 0 ; N<=n; N++){
            prev[N] = N * price[0];
        }
        
        for(int idx = 1; idx< n ; idx++){
            for(int N = 0 ; N<=n ; N++){
                int notTake = 0 + prev[N];
                int take = INT_MIN;
                int rodLength = idx + 1; // as indexing is 0 based
                if(rodLength <= N){
                    take = price[idx] + prev[N-rodLength];
                }
                prev[N] = max(take,notTake);
            }
        }
        
        return prev[n];
    }
};
