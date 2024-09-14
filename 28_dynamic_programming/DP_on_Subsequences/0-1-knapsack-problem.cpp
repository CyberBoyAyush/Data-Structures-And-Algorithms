// O 1 KnapSack Problem
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n)

class Solution {
  public:
  int solve(int idx, int W, vector<int>& wt, vector<int>& val){
      if(idx == 0){
          if(wt[idx] <= W) return val[0];
          else{
              return 0;
          }
      }
      
      int notTake = 0 + solve(idx-1, W, wt, val);
      int Take = INT_MIN;
      if(wt[idx]<=W){
          Take = val[idx] + solve(idx-1,W-wt[idx],wt,val);
      }
      
      return max(Take,notTake);
  }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        return solve(n-1,W,wt,val);
    }
};

// Approach 2: Recursion + Memoization
// Time Complexity: O(n*W)
// Space Complexity: O(n*W)

class Solution {
  public:
  int dp[1001][1001];
  int solve(int idx, int W, vector<int>& wt, vector<int>& val){
      if(idx == 0){
          if(wt[idx] <= W) return val[0];
          else{
              return 0;
          }
      }
      
      if(dp[idx][W] != -1)  return dp[idx][W];
      
      int notTake = 0 + solve(idx-1, W, wt, val);
      int Take = INT_MIN;
      if(wt[idx]<=W){
          Take = val[idx] + solve(idx-1,W-wt[idx],wt,val);
      }
      
      return dp[idx][W] = max(Take,notTake);
  }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        memset(dp,-1,sizeof(dp));
        return solve(n-1,W,wt,val);
    }
};

// Approach 3: Tabulation
// Time Complexity: O(n*W)
// Space Complexity: O(n*W)

class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1,0));
        
        for(int w = wt[0]; w<=W; w++){
            dp[0][w] = val[0];
        }
        
        for(int idx = 1; idx<n ; idx++){
            for(int weight = 0 ; weight<=W; weight++){
                int notTake = 0 + dp[idx-1][weight];
                int take = INT_MIN;
                if(wt[idx] <= weight){
                    take = val[idx] + dp[idx-1][weight-wt[idx]];
                }
                
                dp[idx][weight] = max(take,notTake);
            }
        }
        
        return dp[n-1][W];
    }
};

// Approach 4: Tabulation + Space Optimized
// Time Complexity: O(n*W)
// Space Complexity: O(W)

class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<int> prev(W+1,0);
        vector<int> curr(W+1,0);
        
        for(int w = wt[0]; w<=W; w++){
            prev[w] = val[0];
        }
        
        for(int idx = 1; idx<n ; idx++){
            for(int weight = 0 ; weight<=W; weight++){
                int notTake = prev[weight];
                int take = INT_MIN;
                if(wt[idx] <= weight){
                    take = val[idx] + prev[weight-wt[idx]];
                }
                
                curr[weight] = max(take,notTake);
            }
            prev = curr;
        }
        
        return prev[W];
    }
};

// Approach 5: Tabulation + Space Optimized
// Time Complexity: O(n*W)
// Space Complexity: O(W)

class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<int> dp(W+1,0);
        
        for(int idx = 0; idx<n ; idx++){
            for(int weight = W ; weight>=wt[idx]; weight--){
                dp[weight] = max(dp[weight],val[idx]+dp[weight-wt[idx]]);
            }
        }
        
        return dp[W];
    }
};