// Count Subsets with given sum k
// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <bits/stdc++.h>
using namespace std;

// Appraoch 1 -> Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(1)

class Solution {
public:
    int solve(vector<int>& arr, int index, int sum) {
        if (sum == 0) return 1;
        if (index == 0) return (arr[0] == sum);

        int notTake = solve(arr, index - 1, sum);
        int take = 0;
        if (arr[index] <= sum) {
            take = solve(arr, index - 1, sum - arr[index]);
        }

        return notTake + take;
    }
    int countSubsets(vector<int>& arr, int n, int sum) {
        return solve(arr, n - 1, sum);
    }
};

// Appraoch 2 -> Recursion + Memoization
// Time Complexity: O(n*sum)
// Space Complexity: O(n*sum)

int mod = 1e9 + 7;
int solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp) {
  // base case
  if (index == 0) {
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
int findWays(vector<int> &arr, int sum) {
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
  return solve(n - 1, sum, arr, dp);
}


// Appraoch 3 -> Tabulation
// Time Complexity: O(n*sum)
// Space Complexity: O(n*sum)

int mod = 1e9 + 7;

int findWays(vector<int>& arr, int sum) {
    int n = arr.size();
    
    // DP table where dp[i][j] tells if we can make sum `j` using the first `i+1` elements
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    
    // Base case: If sum is 0, there's always 1 way to form it (by taking no elements).
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    
    // If the first element is less than or equal to the sum, we can form the subset sum with the first element.
    if (arr[0] <= sum) {
        dp[0][arr[0]] = 1;
    }
    
    // Special case: If the first element is 0, there are 2 ways to form sum 0 (include or exclude the zero).
    if (arr[0] == 0) {
        dp[0][0] = 2;
    }

    // Fill the DP table
    for (int idx = 1; idx < n; idx++) {
        for (int target = 0; target <= sum; target++) {
            int notTake = dp[idx - 1][target] % mod;
            int take = 0;
            if (arr[idx] <= target) {
                take = dp[idx - 1][target - arr[idx]] % mod;
            }
            dp[idx][target] = (notTake + take) % mod;
        }
    }
    
    // Return the result for the full array and given sum
    return dp[n - 1][sum];
}

// Appraoch 4 -> Tabulation + Space Optimized
// Time Complexity: O(n*sum)
// Space Complexity: O(sum)

int mod = 1e9 + 7;
class Solution {
public:
    int countSubsets(vector<int>& arr, int n, int sum) {
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        
        if (arr[0] <= sum) {
            dp[arr[0]] = 1;
        }
        
        for (int idx = 1; idx < n; idx++) {
            for (int target = sum; target >= 0; target--) {
                int notTake = dp[target] % mod;
                int take = 0;
                if (arr[idx] <= target) {
                    take = dp[target - arr[idx]] % mod;
                }
                dp[target] = (notTake + take) % mod;
            }
        }
        
        return dp[sum];
    }
};
