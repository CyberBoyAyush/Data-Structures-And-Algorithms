// Best Time to buy and sell stock - III
// Leetcode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

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
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        return solve(0,true,2,prices);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n*2*3)
// Space Complexity : O(n*2*3) + O(n) for recursive stack

class Solution {
public:
    int n;
    int solve(int i,bool buy,int cap,vector<int>& prices,int dp[][2][3]){
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
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        int dp[n+1][2][3];
        memset(dp,-1,sizeof(dp));
        return solve(0,true,2,prices,dp);
    }
};

// Approach 3 : Bottom Up DP -> Tabulation
// Time Complexity : O(n*2*3)
// Space Complexity : O(n*2*3)

class Solution {
public:
    int n;
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        int dp[n+1][2][3];
        memset(dp,0,sizeof(dp));

        // we can omit initializing base cases buy setting up all dp as 0
        // Base Case 1 -> cap == 0
        for(int i = 0 ; i<n ; i++){
            for(int buy = 0; buy<=1; buy++){
                dp[i][buy][0] = 0;
            }
        }

        // Base Case 2 -> i == n
        for(int buy = 0; buy<=1; buy++){
            for(int cap = 0; cap<=2; cap++){
                dp[n][buy][cap] = 0;
            }
        }

        // filling the rest
        for(int i = n-1; i>=0 ; i--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap = 1; cap<=2; cap++){
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

        return dp[0][1][2];
    }
};

// Approach 4 : Bottom Up DP -> Tabulation (Space Optimized)
// Time Complexity : O(n*2*3)
// Space Complexity : O(6)

class Solution {
public:
    int n;
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> ahead(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));

        // filling the rest
        for(int i = n-1; i>=0 ; i--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap = 1; cap<=2; cap++){
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

        return ahead[1][2];
    }
};