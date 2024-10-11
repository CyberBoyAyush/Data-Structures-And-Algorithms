// longest-increasing-subsequence
// Leetcode : https://leetcode.com/problems/longest-increasing-subsequence/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:
    int n;
    int solve(int idx, int prev_idx, vector<int> &nums){
        // base case
        if(idx == n){
            return 0;
        }

        int len;

        // Not Take Case
        len = 0 + solve(idx+1,prev_idx,nums);

        // Take Case
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
            // it is LIS
            len = max(len, 1 + solve(idx+1,idx,nums)); // idx become previdx for next iterations
        }

        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        return solve(0,-1,nums);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(N x N)
// Space Complexity : O(N x N) + O(N)

class Solution {
public:
    int n;
    int dp[2500][2501];
    int solve(int idx, int prev_idx, vector<int> &nums){
        // base case
        if(idx == n){
            return 0;
        }

        // dp call
        if(dp[idx][prev_idx + 1] != -1){
            return dp[idx][prev_idx + 1]; // prev_idx + 1 beacuse we handle -1 case so we need shifting
        }

        int len;

        // Not Take Case
        len = 0 + solve(idx+1,prev_idx,nums);

        // Take Case
        if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
            // it is LIS
            len = max(len, 1 + solve(idx+1,idx,nums)); // idx become previdx for next iterations
        }

        return dp[idx][prev_idx + 1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums);
    }
};

// Approach 3 : Bottom Up DP -> Tabulation
// Time Complexity : O(N x N)
// Space Complexity : O(N)

class Solution {
public:
    int n;
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0)); // base case already set as 0

        // as we are shifting indexes for prev-idx we have to use prev_idx + 1 or idx + 1
        // to shift indexes 

        // filling rest
        for(int idx = n-1; idx >= 0; idx--){
            for(int prev_idx = idx-1; prev_idx>=-1; prev_idx--){
                int len;

                // Not Take Case
                len = 0 + dp[idx+1][prev_idx+1];

                // Take Case
                if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
                    // it is LIS
                    len = max(len, 1 + dp[idx+1][idx+1]); // idx become previdx for next iterations
                }

                dp[idx][prev_idx + 1] = len;
            }
        }

        return dp[0][-1+1]; // as idx is shifted dp[0][-1] we use dp[0][-1+1]
    }
};

// Approach 4 : Bottom Up DP -> Tabulation (Space Optimized)
// Time Complexity : O(N x N)
// Space Complexity : O(N)

class Solution {
public:
    int n;
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<int> next(n+1,0); // base case already set as 0
        vector<int> curr(n+1,0); // base case already set as 0

        // as we are shifting indexes for prev-idx we have to use prev_idx + 1 or idx + 1
        // to shift indexes 

        // filling rest
        for(int idx = n-1; idx >= 0; idx--){
            for(int prev_idx = idx-1; prev_idx>=-1; prev_idx--){
                int len;

                // Not Take Case
                len = 0 + next[prev_idx+1];

                // Take Case
                if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
                    // it is LIS
                    len = max(len, 1 + next[idx+1]); // idx become previdx for next iterations
                }

                curr[prev_idx + 1] = len;
            }
            next = curr;
        }

        return next[-1+1]; // as idx is shifted dp[0][-1] we use dp[0][-1+1]
    }
};

// Approach 5 : Intutive Easy Approach
// TC - O(N^2)
// SC  - O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,1);

        int maxLIS = 1;

        for(int i = 0; i<n ; i++){
            for(int j = 0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1 );
                    maxLIS = max(maxLIS, dp[i]);
                }
            }
        }
        return maxLIS;
    }
};

// Approach 6 : Binary Search
// TC - O(NlogN)
// SC - O(N)

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       vector<int> temp;
       temp.push_back(a[0]);
       for(int i = 1; i<n ; i++){
           if(a[i]>temp.back()){
               temp.push_back(a[i]);
           }
           else{
               auto ind = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
               temp[ind] = a[i];
           }
       }
       
       return temp.size();
    }
};