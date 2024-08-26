// 1911. Maximum Alternating Subsequence Sum
// Problem Link: https://leetcode.com/problems/maximum-alternating-subsequence-sum/

// Appraoch 1: Recursion + Memoization
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
typedef long long ll;
    int n;
    ll t[100001][2]; // stores the maximum sum till ith index with flag 0 or 1
    ll solve(int idx , vector<int>& nums, bool flag){
        if(idx >= n)    return 0;

        if(t[idx][flag] != -1)    return t[idx][flag];

        // condt 1 -> skip
        ll skip = solve(idx+1,nums,flag);

        // condt 2 -> take
        ll val = nums[idx];

        if(flag == false){
            val *= -1;
        }

        ll take = solve(idx+1,nums,!flag) + val;

        return t[idx][flag] = max(skip,take);

    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0,nums,true);
    }
};

// Approach 2: Tabulation
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long>> t(n+1, vector<long>(2,0)); // even:0 , odd:1

        for(int i = 1 ; i<n+1 ; i++){
            //even
            t[i][0] = max(t[i-1][1] - nums[i-1] , t[i-1][0]);

            // odd
            t[i][1] = max(t[i-1][0] + nums[i-1] , t[i-1][1]);
        }

        return max(t[n][0], t[n][1]);
    }
};

// Approach 3: Optimized Tabulation
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even = 0, odd = 0;

        for(int i = 0 ; i<nums.size() ; i++){
            long long temp = even;
            even = max(even, odd - nums[i]);
            odd = max(odd, temp + nums[i]);
        }

        return max(even, odd);
    }
};