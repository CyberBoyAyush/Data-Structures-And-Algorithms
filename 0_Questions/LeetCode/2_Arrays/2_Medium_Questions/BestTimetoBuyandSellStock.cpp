// Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int prof = 0;
        int n = prices.size();
        for(int i= 1; i<n;i++){
             int cost = prices[i] - mini;
             prof = max(prof,cost);
             mini = min(mini, prices[i]);
            }
        return prof;
    }
};