// Coin Change
// Leetcode : https://leetcode.com/problems/coin-change/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:
    int solve(int idx , int target, vector<int> &coins){
        if(idx == 0){
            if(target % coins[idx] == 0){
                return target / coins[idx];
            }
            else{
                return 1e9;
            }
        }

        int notTake = 0 + solve(idx-1,target,coins);
        int take = INT_MAX;
        if(coins[idx] <= target){
            take = 1 + solve(idx,target-coins[idx],coins); // we did not reduce 1 to idx as we have inifinite supply of coins
        }

        return min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int res = solve(n-1,amount,coins);
        if(res == 1e9){
            return -1;
        }

        return res;
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n*amount)
// Space Complexity : O(n*amount)

class Solution {
public:
    int solve(int idx , int target, vector<int> &coins, vector<vector<int>> &dp){
        if(idx == 0){
            if(target % coins[idx] == 0){
                return target / coins[idx];
            }
            else{
                return 1e9;
            }
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        int notTake = 0 + solve(idx-1,target,coins,dp);
        int take = INT_MAX;
        if(coins[idx] <= target){
            take = 1 + solve(idx,target-coins[idx],coins,dp); // we did not reduce 1 to idx as we have inifinite supply of coins
        }

        return dp[idx][target] = min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int res = solve(n-1,amount,coins,dp);
        if(res == 1e9){
            return -1;
        }

        return res;
    }
};

// Approach 3 : Tabulation
// Time Complexity : O(n*amount)
// Space Complexity : O(n*amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        // Initialization
        for(int target = 0 ; target<=amount; target++){
            if(target % coins[0] == 0){
                dp[0][target] = target / coins[0];
            }
            else{
                dp[0][target] = 1e9;
            }
        }

        // filling rest
        for(int idx = 1 ; idx<n ; idx++){
            for(int target = 0 ; target <= amount; target ++){
                int notTake = 0 + dp[idx-1][target];
                int take = INT_MAX;
                if (coins[idx] <= target) {
                take = 1 + dp[idx][target-coins[idx]];
                // we did not reduce 1 to idx as we have inifinite supply of coins
                }

                dp[idx][target] = min(take,notTake);
            }
        }

        return (dp[n-1][amount] == 1e9) ? -1 : dp[n-1][amount];
    }
};

// Approach 4 : Tabulation + Space Optimized
// Time Complexity : O(n*amount)
// Space Complexity : O(amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);
        
        // Initialization
        for(int target = 0 ; target<=amount; target++){
            if(target % coins[0] == 0){
                prev[target] = target / coins[0];
            }
            else{
                prev[target] = 1e9;
            }
        }

        // filling rest
        for(int idx = 1 ; idx<n ; idx++){
            for(int target = 0 ; target <= amount; target ++){
                int notTake = 0 + prev[target];
                int take = INT_MAX;
                if (coins[idx] <= target) {
                take = 1 + curr[target-coins[idx]];
                // we did not reduce 1 to idx as we have inifinite supply of coins
                }

                curr[target] = min(take,notTake);
            }
            prev = curr;
        }

        return (prev[amount] == 1e9) ? -1 : prev[amount];
    }
};