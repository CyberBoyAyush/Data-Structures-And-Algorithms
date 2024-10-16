// Number of Longest Increasing Subsequence
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/
// https://www.geeksforgeeks.org/number-longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

// Tabulation And Count
// Time Complexity : O(n^2)
// Space Complexity : O(n) + O(n) = O(n)

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,1); // dp array stores the length of LIS ending at i
        vector<int> cnt(n,1); // count array stores the count of LIS ending at i

        for(int i = 0; i<n ; i++){
            for(int j = 0; j<i; j++){
                if(nums[j] < nums[i]){
                    if(dp[i] < dp[j] + 1){ // standard LIS condition
                        // update dp
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[j] + 1 == dp[i]){ // if we have multiple LIS of same length
                        // increase count in count arr
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        int maxVal = *max_element(dp.begin(),dp.end());
        int finalCount = 0;

        for(int i = 0; i< n ; i++){
            if(dp[i] == maxVal){
                finalCount += cnt[i];
            }
        }

        return finalCount;

    }
};