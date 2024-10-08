// Best Time to Buy and sell stock - IV
// Leetcode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)
class Solution {
public:
    int n;
    int solve(int i,bool buy,int cap,vector<int>& prices){
        // base cases
        if(cap == 0){
            return 0;
        }

        if(i == n){
            return 0;
        }

        int profit = 0;

        if(buy){ // if we can buy
            profit = max(-prices[i] + solve(i+1,0,cap,prices), // we buy the stock,
                        0 + solve(i+1,1,cap,prices)); // we did not buy the stock 
        }

        else{ // we can sell
            profit = max(prices[i] + solve(i+1,1,cap-1,prices), // we sell the stock
                        0 + solve(i+1,0,cap,prices)); // we did not sell
        }

        return profit;
    }
    int maxProfit(int k,vector<int>& prices) {
        n = prices.size();

        return solve(0,true,k,prices);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n*2*k)
// Space Complexity : O(n*2*k) + O(n) for recursive stack

class Solution {
public:
    int n;
    int solve(int i,bool buy,int cap,vector<int>& prices,vector<vector<vector<int>>> &dp ){
        // base cases
        if(cap == 0){
            return 0;
        }

        if(i == n){
            return 0;
        }

        if(dp[i][buy][cap] != -1){
            return dp[i][buy][cap];
        }

        int profit = 0;

        if(buy){ // if we can buy
            profit = max(-prices[i] + solve(i+1,0,cap,prices,dp), // we buy the stock,
                        0 + solve(i+1,1,cap,prices,dp)); // we did not buy the stock 
        }

        else{ // we can sell
            profit = max(prices[i] + solve(i+1,1,cap-1,prices,dp), // we sell the stock
                        0 + solve(i+1,0,cap,prices,dp)); // we did not sell
        }

        return dp[i][buy][cap] = profit;
    }
    int maxProfit(int k,vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>> dp(n,
                                    vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0,true,k,prices,dp);
    }
};

// Approach 3 : Bottom Up DP -> Tabulation
// Time Complexity : O(n*2*k)
// Space Complexity : O(n*2*k)

class Solution {
public:
    int n;
    int maxProfit(int k,vector<int>& prices) {
        n = prices.size();
        int dp[n+1][2][k+1];
        memset(dp,0,sizeof(dp)); // to avoid base case we set all as 0

        // filling the rest
        for(int i = n-1; i>=0 ; i--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap = 1; cap<=k; cap++){
                    int profit = 0;

                if(buy){ // if we can buy
                    profit = max(-prices[i] + dp[i+1][0][cap], // we buy the stock,
                                0 + dp[i+1][1][cap]); // we did not buy the stock 
                }

                else{ // we can sell
                    profit = max(prices[i] + dp[i+1][1][cap-1], // we sell the stock
                                0 + dp[i+1][0][cap]); // we did not sell
                }

                dp[i][buy][cap] = profit; 
                }
            }
        }

        return dp[0][1][k];
    }
};

// Approach 4 : Bottom Up DP -> Tabulation (Space Optimized)
// Time Complexity : O(n*2*k)
// Space Complexity : O(2*k)

class Solution {
public:
    int n;
    int maxProfit(int k,vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> ahead(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));

        // filling the rest
        for(int i = n-1; i>=0 ; i--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap = 1; cap<=k; cap++){
                    int profit = 0;

                if(buy){ // if we can buy
                    profit = max(-prices[i] + ahead[0][cap], // we buy the stock,
                                0 + ahead[1][cap]); // we did not buy the stock 
                }

                else{ // we can sell
                    profit = max(prices[i] + ahead[1][cap-1], // we sell the stock
                                0 + ahead[0][cap]); // we did not sell
                }

                curr[buy][cap] = profit; 
                }
            }
            ahead = curr;
        }

        return ahead[1][k];
    }
};