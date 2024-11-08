// Burst Baloons
// Link: https://leetcode.com/problems/burst-balloons/

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:
    int solve(int i, int j, vector<int>& nums){
        // base case
        if(i>j){
            return 0;
        }

        int maxi = INT_MIN;

        // as we need to burst every baloon
        for(int idx = i; idx<=j; idx++){
            int coins = (nums[i-1] * nums[idx] * nums[j+1]) 
                        + solve(i, idx-1, nums) + solve(idx+1,j,nums);

            maxi = max(maxi,coins);
        }

        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // pushing 1 on both sides for coin calculations
        nums.push_back(1);
        nums.insert(nums.begin(),1);

        return solve(1,n,nums);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n^3)
// Space Complexity : O(n^2)

class Solution {
public:
    int dp[301][301];
    int solve(int i, int j, vector<int>& nums){
        // base case
        if(i>j){
            return 0;
        }

        // dp call
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int maxi = INT_MIN;

        // as we need to burst every baloon
        for(int idx = i; idx<=j; idx++){
            int coins = (nums[i-1] * nums[idx] * nums[j+1]) 
                        + solve(i, idx-1, nums) + solve(idx+1,j,nums);

            maxi = max(maxi,coins);
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();

        // pushing 1 on both sides for coin calculations
        nums.push_back(1);
        nums.insert(nums.begin(),1);

        return solve(1,n,nums);
    }
};

// Approach 3 : Tabulation
// Time Complexity : O(n^3)
// Space Complexity : O(n^2)

class Solution {
public:
    int dp[302][302];
    int maxCoins(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        int n = nums.size();

        // pushing 1 on both sides for coin calculations
        nums.push_back(1);
        nums.insert(nums.begin(),1);

        // filling dp
        for(int i = n ; i>=1; i--){
            for(int j = 1 ; j<=n ; j++){
                if(i > j)   continue; // base case handled
                int maxi = INT_MIN;

                // as we need to burst every baloon
                for(int idx = i; idx<=j; idx++){
                    int coins = (nums[i-1] * nums[idx] * nums[j+1]) 
                                + dp[i][idx-1] + dp[idx+1][j];

                    maxi = max(maxi,coins);
                }

                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};