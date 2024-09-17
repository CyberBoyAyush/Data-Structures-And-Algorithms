// Unbounded Knapsack
// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution{
public:
    int solve(int idx,int W, int val[], int wt[]){
        // Base case
        if (idx == 0) {
            if (wt[0] <= W) {
                return (W / wt[0]) * val[0];  // Only pick if wt[0] fits in W
            } else {
                return 0;  // If wt[0] is too large, no value can be picked
            }
        }
        
        int notPick = 0 + solve(idx-1,W,val,wt);
        int pick = INT_MIN;
        if(wt[idx] <= W){
            pick = val[idx] + solve(idx,W-wt[idx],val,wt);
        }
        
        return max(pick,notPick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        return solve(N-1,W,val,wt);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n*W)
// Space Complexity : O(n*W) + O(n) for recursive stack

class Solution{
public:
    int dp[1001][1001];
    int solve(int idx,int W, int val[], int wt[]){
        // Base case
        if (idx == 0) {
            if (wt[0] <= W) {
                return (W / wt[0]) * val[0];  // Only pick if wt[0] fits in W
            } else {
                return 0;  // If wt[0] is too large, no value can be picked
            }
        }
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        int notPick = 0 + solve(idx-1,W,val,wt);
        int pick = INT_MIN;
        if(wt[idx] <= W){
            pick = val[idx] + solve(idx,W-wt[idx],val,wt);
        }
        
        return dp[idx][W] = max(pick,notPick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(N-1,W,val,wt);
    }
};

// Approach 3 : Tabulation
// Time Complexity : O(n*W)
// Space Complexity : O(n*W)

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W+1, 0));
        
        // initialization
        for(int weight = 0 ; weight<=W; weight++){
            if (wt[0] <= W) {
                dp[0][weight] = (weight / wt[0]) * val[0];  // Only pick if wt[0] fits in W
            } else {
                dp[0][weight] = 0;  // If wt[0] is too large, no value can be picked
            }
        }
        
        // filling rest
        for(int idx = 1; idx<N ; idx++){
            for(int weight = 0 ; weight<=W; weight++){
                int notPick = 0 + dp[idx-1][weight];
                int pick = INT_MIN;
                if(weight >= wt[idx]){
                    pick = val[idx] + dp[idx][weight-wt[idx]];
                }
                dp[idx][weight] = max(pick,notPick);
            }
        }
        return dp[N-1][W];
    }
};

// Approach 4 : Tabulation + Space Optimized
// Time Complexity : O(n*W)
// Space Complexity : O(W)

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // vector<vector<int>> dp(N, vector<int>(W+1, 0));
        vector<int> prev(W+1,0);
        vector<int> curr(W+1,0);
        
        // initialization
        for(int weight = wt[0] ; weight<=W; weight++){
            if (wt[0] <= W) {
                prev[weight] = (weight / wt[0]) * val[0];  // Only pick if wt[0] fits in W
            } else {
                prev[weight] = 0;  // If wt[0] is too large, no value can be picked
            }
        }
        
        // filling rest
        for(int idx = 1; idx<N ; idx++){
            for(int weight = 0 ; weight<=W; weight++){
                int notPick = 0 + prev[weight];
                int pick = INT_MIN;
                if(weight >= wt[idx]){
                    pick = val[idx] + curr[weight-wt[idx]];
                }
                curr[weight] = max(pick,notPick);
            }
            prev = curr;
        }
        return prev[W];
    }
};

// Approach 5 : Tabulation + Space Optimized in 1D
// Time Complexity : O(n*W)
// Space Complexity : O(W)

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W+1,0);
        
        // initialization
        for(int weight = wt[0] ; weight<=W; weight++){
            if (wt[0] <= W) {
                dp[weight] = (weight / wt[0]) * val[0];  // Only pick if wt[0] fits in W
            } else {
                dp[weight] = 0;  // If wt[0] is too large, no value can be picked
            }
        }
        
        // filling rest
        for(int idx = 1; idx<N ; idx++){
            for(int weight = W ; weight>=0; weight--){
                int notPick = 0 + dp[weight];
                int pick = INT_MIN;
                if(weight >= wt[idx]){
                    pick = val[idx] + dp[weight-wt[idx]];
                }
                dp[weight] = max(pick,notPick);
            }
        }
        return dp[W];
    }
};