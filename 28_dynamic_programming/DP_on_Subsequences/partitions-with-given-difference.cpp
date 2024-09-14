// Partitions with Given Difference
// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion + Memo
// Tc : O(n*sum)
// Sc : O(n*sum)
class Solution {
  public:
  int mod = 1e9 + 7;
    int solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        // base case
        if (index == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || arr[0] == target)
                return 1;
            return 0;
        }
        if (dp[index][target] != -1)
            return dp[index][target];
        int notpick = solve(index - 1, target, arr, dp) % mod;
        int pick = 0;
        if (arr[index] <= target)
            pick = solve(index - 1, target - arr[index], arr, dp) % mod;
        return dp[index][target] = (pick + notpick) % mod;
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
        int totSum = 0;
        for(int i=0; i<arr.size();i++){
            totSum += arr[i];
        }
        
        //Checking for edge cases
        if(totSum-d<0) return 0;
        if((totSum-d)%2==1) return 0;
        
        int s2 = (totSum-d)/2;
        
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));
        return solve(n-1,s2,arr,dp);
    }
};

// Approach 2: Tabulation
// Tc : O(n*sum)
// Sc : O(n*sum)

class Solution {
  public:
  int mod = 1e9 + 7;
    int countPartitions(int n, int d, vector<int>& arr) {
    int totSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        totSum += arr[i];
    }

    // Edge case checks
    if (totSum - d < 0) return 0;
    if ((totSum - d) % 2 == 1) return 0;

    int s2 = (totSum - d) / 2;

    vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));

    // Base case: sum == 0
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1; // There is always 1 way to form sum 0 (by taking no elements)
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
            dp[i][j] = (notpick + pick) % mod;
        }
    }

    return dp[n - 1][s2];
}
};