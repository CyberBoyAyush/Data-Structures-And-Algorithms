// best-time-to-buy-and-sell-stock-with-transaction-fee
// Leetcode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include<bits/stdc++.h>
using namespace std;

// Approach -> Tabulation + Space Optimized

class Solution {
public:
    int n;
    int maxProfit(vector<int>& prices, int fee) {
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
                    long we_sell = prices[idx] - fee + ahead[1];
                     // subtracting fees at the end of successfull transaction
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