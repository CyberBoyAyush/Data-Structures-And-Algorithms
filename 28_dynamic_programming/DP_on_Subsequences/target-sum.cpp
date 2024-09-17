// Target Sum
// https://leetcode.com/problems/target-sum/

// We can shred it down to a problem which is partitions with given difference
// We can convert the given problem to the above problem by the following transformation:
// Let's say the sum of the two subsets is sum1 and sum2.
// sum1 + sum2 = totalSum
// sum1 - sum2 = target
// Adding the above two equations, we get:
// 2 * sum1 = target + totalSum
// sum1 = (target + totalSum) / 2
// So, we need to find the number of subsets with sum equal to (target + totalSum) / 2.


// Code :

// Tabulation
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9 + 7;
    int countPartitions(int n, int d, vector<int>& arr) {
        int totSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            totSum += arr[i];
        }

        // Edge case checks
        if (totSum - d < 0)
            return 0;
        if ((totSum - d) % 2 == 1)
            return 0;

        int s2 = (totSum - d) / 2;

        vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));

        // Base case: sum == 0
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1; // There is always 1 way to form sum 0 (by taking no
                          // elements)
        }

        // Special case for the first element (handling when arr[0] == 0)
        if (arr[0] <= s2) {
            dp[0][arr[0]] = 1; // Only 1 way to form sum with the first element
        }
        if (arr[0] == 0) {
            dp[0][0] = 2; // Two ways to form sum 0: include or exclude the zero
        }

        // Fill the dp table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= s2; j++) {
                int notpick = dp[i - 1][j];
                int pick = 0;
                if (arr[i] <= j) {
                    pick = dp[i - 1][j - arr[i]];
                }
                dp[i][j] = (notpick + pick);
            }
        }

        return dp[n - 1][s2];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};