// best-time-to-buy-and-sell-stock-with-cooldown
// Leetcode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(3^n)
// Space Complexity : O(n)

class Solution {
public:
    int n;
    int solve(int i, bool buy, vector<int> &prices){
        if(i >= n){
            return 0;
        }

        int profit = 0;
        
        if(buy){
            profit = max(-prices[i] + solve(i+1,0,prices), // we buy
                            0 + solve(i+1,1,prices)); // we did not buy
        }
        else{
            // sell
            profit = max(prices[i] + solve(i+2,1,prices), // we sell it (cooldown)
                            0 + solve(i+1,0,prices));
        }

        return profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        return solve(0,true,prices);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n)
// Space Complexity : O(n) + O(n) for recursive stack

class Solution {
public:
    int n;
    int dp[5001][2];
    int solve(int i, bool buy, vector<int> &prices){
        if(i >= n){
            return 0;
        }

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;
        
        if(buy){
            profit = max(-prices[i] + solve(i+1,0,prices), // we buy
                            0 + solve(i+1,1,prices)); // we did not buy
        }
        else{
            // sell
            profit = max(prices[i] + solve(i+2,1,prices), // we sell it (cooldown)
                            0 + solve(i+1,0,prices));
        }

        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,true,prices);
    }
};

// Approach 3 : Bottom Up DP -> Tabulation
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int n;
    int dp[5001][2];
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp,0,sizeof(dp));

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                int profit = 0;
        
                if(buy){
                    profit = max(-prices[i] + dp[i+1][0], // we buy
                                    0 + dp[i+1][1]); // we did not buy
                }
                else{
                    // sell
                    profit = max(prices[i] + dp[i+2][1], // we sell it (cooldown)
                                    0 + dp[i+1][0]);
                }

                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

// Approach 4 : Bottom Up DP -> Tabulation (Space Optimized)
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int n;
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<int> ahead(2,0);
        vector<int> ahead2(2,0);
        vector<int> curr(2,0);

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                int profit = 0;
        
                if(buy){
                    profit = max(-prices[i] + ahead[0], // we buy
                                    0 + ahead[1]); // we did not buy
                }
                else{
                    // sell
                    profit = max(prices[i] + ahead2[1], // we sell it (cooldown)
                                    0 + ahead[0]);
                }

                curr[buy] = profit;
            }
            ahead2 = ahead;
            ahead = curr;
        }
        return curr[1];
    }
};