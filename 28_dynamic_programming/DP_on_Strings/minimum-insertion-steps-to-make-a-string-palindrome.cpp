// minimum-insertion-steps-to-make-a-string-palindrome
// leeetcode: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:
    int solve(string s, int i, int j){
        if(i>j){
            // all char exhausted
            return 0;
        }

        if(s[i] == s[j]){
            return solve(s,i+1,j-1);
        }

        return 1 + min(solve(s,i+1,j) , solve(s,i,j-1));
    }
    int minInsertions(string s) {
        return solve(s,0,s.length()-1);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n*n)
// Space Complexity : O(n*n) + O(n) for recursive stack

class Solution {
public:
    int dp[501][501];
    int solve(string &s, int i, int j){
        if(i>j){
            // all char exhausted
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == s[j]){
            return dp[i][j] = solve(s,i+1,j-1);
        }

        return dp[i][j] = 1 + min(solve(s,i+1,j) , solve(s,i,j-1));
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.length()-1);
    }
};

// Approach 3 : Bottom Up DP -> Tabulation
// Time Complexity : O(n*n)
// Space Complexity : O(n*n)

class Solution {
public:
    int dp[501][501];
    int solve(string &s, int i, int j){
        if(i>j){
            // all char exhausted
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == s[j]){
            return dp[i][j] = solve(s,i+1,j-1);
        }

        return dp[i][j] = 1 + min(solve(s,i+1,j) , solve(s,i,j-1));
    }
    int minInsertions(string s) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n)); 
        //STATE: min insertion to make s[i..j] palindrome

        for(int i = 0; i<n ; i++){
            dp[i][i] = 0;
        }

        for(int len = 2; len<=n; len++){
            for(int i = 0; i< n - len + 1; i++){
                int j = i + len - 1;

                // same
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i+1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};