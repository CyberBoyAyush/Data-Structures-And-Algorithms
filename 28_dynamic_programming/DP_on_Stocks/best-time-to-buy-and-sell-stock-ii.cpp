// Best Time to buy and sell stock - II
// Leetcode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:
    int n;
    int solve(int idx, bool buy,vector<int>& prices){
        // base case
        if(idx == n){
            return 0;
        }

        int profit = 0;

        // if we can buy
        if(buy){
            // either we buy or we dont buy
            int we_buy = -prices[idx] + solve(idx+1,0,prices);
            int we_notBuy = 0 + solve(idx+1,1,prices);
            profit = max(we_buy,we_notBuy);
        }
        // we can sell
        else{
            // either we sell or not sell
            int we_sell = prices[idx] + solve(idx+1,1,prices);
            int we_notSell = 0 + solve(idx+1,0,prices);
            profit = max(we_sell,we_notSell);
        }

        return profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        return solve(0,1,prices);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n)
// Space Complexity : O(n) + O(n) for recursive stack

class Solution {
public:
    int n;
    int solve(int idx, bool buy, vector<int>& prices, vector<vector<int>>& dp){
        // base case
        if(idx == n){
            return 0;
        }

        long profit = 0;

        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }

        // if we can buy
        if(buy){
            // either we buy or we dont buy
            long we_buy = -prices[idx] + solve(idx+1,0,prices,dp);
            long we_notBuy = 0 + solve(idx+1,1,prices,dp);
            profit = max(we_buy,we_notBuy);
        }
        // we can sell
        else{
            // either we sell or not sell
            long we_sell = prices[idx] + solve(idx+1,1,prices,dp);
            long we_notSell = 0 + solve(idx+1,0,prices,dp);
            profit = max(we_sell,we_notSell);
        }

        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};

// Approach 3 : Bottom Up DP -> Tabulation
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int n;
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        // Base case
        dp[n][0] = dp[n][1] = 0;

        // filling the rest
        for(int idx = n-1; idx >= 0 ; idx--){
            for(int buy = 0; buy<=1 ; buy++){
                long profit = 0;
                // if we can buy
                if(buy){
                    // either we buy or we dont buy
                    long we_buy = -prices[idx] + dp[idx+1][0];
                    long we_notBuy = 0 + dp[idx+1][1];
                    profit = max(we_buy,we_notBuy);
                }
                // we can sell
                else{
                    // either we sell or not sell
                    long we_sell = prices[idx] + dp[idx+1][1];
                    long we_notSell = 0 + dp[idx+1][0];
                    profit = max(we_sell,we_notSell);
                }

                dp[idx][buy] = profit;
            }
        }

        return dp[0][1];

    }
};


// Approach 4 : Bottom Up DP -> Tabulation (Space Optimized)
// Time Complexity : O(n)
// Space Complexity : O(2)

class Solution {
public:
    int n;
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<int> ahead(2,0);
        vector<int> curr(2,0);

        // Base case
        ahead[0] = ahead[1] = 0;

        // filling the rest
        for(int idx = n-1; idx >= 0 ; idx--){
            for(int buy = 0; buy<=1 ; buy++){
                long profit = 0;
                // if we can buy
                if(buy){
                    // either we buy or we dont buy
                    long we_buy = -prices[idx] + ahead[0];
                    long we_notBuy = 0 + ahead[1];
                    profit = max(we_buy,we_notBuy);
                }
                // we can sell
                else{
                    // either we sell or not sell
                    long we_sell = prices[idx] + ahead[1];
                    long we_notSell = 0 + ahead[0];
                    profit = max(we_sell,we_notSell);
                }

                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};