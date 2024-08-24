// House Robber
// Leetcode : https://leetcode.com/problems/house-robber/

// Approach 1 : Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int> &nums,int i,int n){
        if(i>=n)    return 0;

        // two options
        // steal
        int steal = nums[i] + solve(nums, i+2, n);

        //skip
        int skip = solve(nums,i+1,n);

        return max(steal,skip);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,0,n);
    }
};

// Approach 2 : Memoization + Recursion
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int t[101]; // dp array

    int solve(vector<int> &nums,int i,int n){
        if(i>=n)    return 0;

        if(t[i] != -1){
            return t[i];
        }

        // two options
        // steal
        int steal = nums[i] + solve(nums, i+2, n);

        //skip
        int skip = solve(nums,i+1,n);

        return t[i] = max(steal,skip);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums,0,n);
    }
};

// Approach 3 : Tabulation
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n+1 , -1);

        // intializing t with predefines values we need in tabulation
        t[0] = 0;
        t[1] = nums[0];

        for(int i = 2; i<=n ; i++){
            int steal = nums[i-1] + t[i-2];

            int skip = t[i-1];

            t[i] = max(steal,skip);
        }

        return t[n];
    }
};

// Approach 4 : Optimized space complexity
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        if(n == 1)  return nums[0];

        int prev2 = 0, prev1 = nums[0];

        for(int i = 2 ; i<=n ; i++){
            int skip = prev1;
            int steal = prev2 + nums[i-1];
            int curr = max(steal,skip);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};