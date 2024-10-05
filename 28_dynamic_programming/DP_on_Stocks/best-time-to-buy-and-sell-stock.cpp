// Best Time to buy and sell stock
// Leetcode : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0]; // taking 1st as minimum
        int profit = 0;

        for(int i = 1; i<prices.size(); i++){
            int cost = prices[i] - mini; // we find the cost of curr with prev
            profit = max(profit,cost);
            mini = min(mini,prices[i]); // updating the minimum
        }

        return profit;
    }
};