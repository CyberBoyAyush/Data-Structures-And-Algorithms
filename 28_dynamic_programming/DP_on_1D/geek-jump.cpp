// Geek Jump (Frog Jump)
// https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
class Solution {
  public:
    int solve(int n , vector<int>& height){
        if(n == 0)  return 0;
        
        int left = solve(n-1,height) + abs(height[n] - height[n-1]);
        int right = INT_MAX; // as we will always not call it
        if(n > 1){
            right = solve(n-2,height) + abs(height[n] - height[n-2]);
        }
        
        return min(left,right);
        
    }
    int minimumEnergy(vector<int>& height, int n) {
        return solve(n-1, height);
    }
};

// Approach 2 : Memoization
class Solution {
  public:
    int solve(int n , vector<int>& height, vector<int> &dp){
        if(n == 0)  return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int left = solve(n-1,height, dp) + abs(height[n] - height[n-1]);
        int right = INT_MAX; // as we will always not call it
        if(n > 1){
            right = solve(n-2,height, dp) + abs(height[n] - height[n-2]);
        }
        
        return dp[n] = min(left,right);
        
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1,-1);
        return solve(n-1, height, dp);
    }
};

// Approach 3 : Tabulation
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        
        for(int i = 1 ; i<n ; i++){
            int fs = dp[i-1] + abs(height[i] - height[i-1]);
            int sc = INT_MAX;
            if(i > 1){
                sc = dp[i-2] + abs(height[i] - height[i-2]);
            }
            dp[i] = min(fs,sc);
        }
        
        return dp[n-1];
    }
};

// Approach 4 : Optimized space complexity
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        int prev = 0;
        int prev2 = 0;
        
        for(int i = 1 ; i<n ; i++){
            int fs = prev + abs(height[i] - height[i-1]);
            int sc = INT_MAX;
            if( i > 1){
                sc = prev2 + abs(height[i] - height[i-2]);
            }
            int curri = min(fs,sc);
            prev2 = prev;
            prev = curri;
        }
        
        return prev;
    }
};