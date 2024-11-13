// partition-array-for-maximum-sum
// Leetcode : https://leetcode.com/problems/partition-array-for-maximum-sum/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:
    int n;
    int solve(int idx, int k, vector<int> &arr){
        if(idx == n){
            return 0;
        }

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = 0;

        for(int i = idx; i<min(idx+k,n); i++){
            len++; // elements in that current partition
            maxi = max(maxi,arr[i]);
            int sum = (len*maxi) + solve(i+1,k,arr);
            maxAns = max(maxAns, sum);
        }

        return maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();

        return solve(0,k,arr);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n^2)
// Space Complexity : O(n) + O(n) for recursion stack

class Solution {
public:
    int n;
    int dp[501];
    int solve(int idx, int k, vector<int> &arr){
        if(idx == n){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = 0;

        for(int i = idx; i<min(idx+k,n); i++){
            len++; // elements in that current partition
            maxi = max(maxi,arr[i]);
            int sum = (len*maxi) + solve(i+1,k,arr);
            maxAns = max(maxAns, sum);
        }

        return dp[idx] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,k,arr);
    }
};

// Approach 3 : DP Tabulation
// Time Complexity : O(n^2)
// Space Complexity : O(n)

class Solution {
public:
    int n;
    int dp[501];
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(dp,0,sizeof(dp));
        

        for(int idx = n - 1; idx>= 0; idx--){
            int len = 0;
            int maxi = INT_MIN;
            int maxAns = 0;

            for(int i = idx; i<min(idx+k,n); i++){
                len++; // elements in that current partition
                maxi = max(maxi,arr[i]);
                int sum = (len*maxi) + dp[i+1];
                maxAns = max(maxAns, sum);
            }

            dp[idx] = maxAns;
        }

        return dp[0];
    }
};