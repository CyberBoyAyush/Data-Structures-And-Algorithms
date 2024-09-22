// Longest Common Subsequence
// Leetcode : https://leetcode.com/problems/longest-common-subsequence/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:
    int solve(int idx1, int idx2, string &text1, string &text2){
        if(idx1 < 0 || idx2 < 0){
            return 0;
        }

        if(text1[idx1] == text2[idx2]){
            return 1 + solve(idx1-1, idx2-1, text1, text2);
        }

        return max(solve(idx1-1, idx2,text1,text2) , solve(idx1, idx2-1, text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        return solve(m-1,n-1,text1,text2);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n*m)
// Space Complexity : O(n*m) + O(n) for recursive stack

class Solution {
public:
    int dp[1001][1001];
    int solve(int idx1, int idx2, string &text1, string &text2){
        if(idx1 < 0 || idx2 < 0){
            return 0;
        }

        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }

        if(text1[idx1] == text2[idx2]){
            return dp[idx1][idx2] = 1 + solve(idx1-1, idx2-1, text1, text2);
        }

        return dp[idx1][idx2] = max(solve(idx1-1, idx2,text1,text2) , solve(idx1, idx2-1, text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        memset(dp,-1,sizeof(dp));

        return solve(m-1,n-1,text1,text2);
    }
};

// Approach 3 : Bottom Up DP -> Tabulation
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // create dp array
        int n = text1.size();
        int m = text2.size();
        int dp[n+1][m+1];

        // initialization
        for(int i = 0; i<=n ; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j<=m ; j++){
            dp[0][j] = 0;
        }

        // now filling rest
        for(int idx1 = 1; idx1<=n; idx1++){
            for(int idx2 = 1; idx2<=m ; idx2++){
                if(text1[idx1-1] == text2[idx2-1]){
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                }

                else dp[idx1][idx2] = max(dp[idx1-1][idx2] , dp[idx1][idx2-1]);
            }
        }
        return dp[n][m];
    }
};

// Approach 4 : Space Optimized Bottom Up DP -> Tabulation
// Time Complexity : O(n*m)
// Space Complexity : O(m)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // create dp array
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);

        // initialization
        for(int j = 0; j<=m ; j++){
            prev[j] = 0;
        }

        // now filling rest
        for(int idx1 = 1; idx1<=n; idx1++){
            for(int idx2 = 1; idx2<=m ; idx2++){
                if(text1[idx1-1] == text2[idx2-1]){
                    curr[idx2] = 1 + prev[idx2-1];
                }

                else curr[idx2] = max(prev[idx2] , curr[idx2-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};