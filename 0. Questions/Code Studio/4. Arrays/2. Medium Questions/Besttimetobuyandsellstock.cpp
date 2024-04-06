// Best time to buy and sell stock
// https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock_6194560?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
#include <vector>
using namespace std;
int bestTimeToBuyAndSellStock(vector<int> &prices)
{
    int mini = prices[0];
    int prof = 0;
    int n = prices.size();
    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - mini;
        prof = max(prof, cost);
        mini = min(mini, prices[i]);
    }
    return prof;
}
