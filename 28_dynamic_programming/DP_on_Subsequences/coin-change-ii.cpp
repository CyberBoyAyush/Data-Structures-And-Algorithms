// Coin Change II
// Leetcode : https://leetcode.com/problems/coin-change-2/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:

    int solve(int idx,int target, vector<int>& coins){
        // base case
        if(idx == 0){
            return (target % coins[0] == 0);
        }

        int notTake = solve(idx-1,target,coins);
        int take = 0;
        if(target >= coins[idx]){
            take = solve(idx,target-coins[idx],coins);
        }

        return notTake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        return solve(n-1,amount,coins);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n*amount)
// Space Complexity : O(n*amount) + O(n) for recursive stack

class Solution {
public:
        int dp[301][5001];
    int solve(int idx,int target, vector<int>& coins){
        // base case
        if(idx == 0){
            return (target % coins[0] == 0);
        }

        if(dp[idx][target] != -1){
            return dp[idx][target];
        }

        int notTake = solve(idx-1,target,coins);
        int take = 0;
        if(target >= coins[idx]){
            take = solve(idx,target-coins[idx],coins);
        }

        return dp[idx][target] = notTake + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        return solve(n-1,amount,coins);
    }
};

// Approach 3 : Tabulation
// Time Complexity : O(n*amount)
// Space Complexity : O(n*amount)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));

        // initialization
        for(int i = 0 ; i<=amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = 1;
            }
        }

        for(int idx = 1; idx<n ; idx++){
            for(int target = 0; target<=amount; target++){
                int notTake = dp[idx-1][target];
                int take = 0;
                if(target>=coins[idx]){
                    take = dp[idx][target-coins[idx]];
                }
                dp[idx][target] = take + notTake;
            }
        }

        return dp[n-1][amount];
    }
};

// Approach 4 : Tabulation + Space Optimized
// Time Complexity : O(n*amount)
// Space Complexity : O(amount)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int> (amount+1,0));
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);

        // initialization
        for(int i = 0 ; i<=amount; i++){
            if(i % coins[0] == 0){
                prev[i] = 1;
            }
        }

        for(int idx = 1; idx<n ; idx++){
            for(int target = 0; target<=amount; target++){
                int notTake = prev[target];
                int take = 0;
                if(target>=coins[idx]){
                    take = curr[target-coins[idx]];
                }
                curr[target] = take + notTake;
            }
            prev = curr;
        }

        return prev[amount];
    }
};