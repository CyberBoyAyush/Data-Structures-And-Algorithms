// Longest Palindromic Subsequence
// Leeetcode : https://leetcode.com/problems/longest-palindromic-subsequence/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion + Memoization Using LCS (TLE)
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int j, string s, string t){
        if(i==0 || j == 0){
            return 0; 
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // match
        if(s[i-1]==t[j-1]){
            return dp[i][j] = 1 + solve(i-1,j-1,s,t);
        }

        // not match
        return dp[i][j] = max(solve(i-1,j,s,t), solve(i,j-1,s,t));
    }   
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        return solve(n,n,s,t);
    }
};

// Approach 2 : Bottom Up DP -> Tabulation (Using LCS)
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

class Solution {
public:
    int lcs(string s, string t){
        int n = s.length();

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int i = 1;i<=n; i++){
            for(int j=1; j<=n; j++){
                // match
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());

        return lcs(s,t);
    }
};

// Approach 3 : Recursion + Memoization -> Without LCS (using two pointers)
// Time Complexity : O(n*n)
// Space Complexity : O(n*n)

class Solution {
public:
    int dp[1001][1001];
    int solve(string &s, int i, int j){
        if(i>j){
            return 0; // out of bound
        }

        if(i == j){
            return 1; // same index pe hai 
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == s[j]){
            return dp[i][j] = 2 + solve(s,i+1,j-1);
        }
        else{
            return dp[i][j] = max(solve(s,i+1,j), solve(s,i,j-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.length()-1);
    }
};

// Approach 4 : Bottom Up DP -> Tabulation -> Without LCS (using two pointers)
// Time Complexity : O(n*n)
// Space Complexity : O(n*n)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        vector<vector<int>> t(n, vector<int>(n));
        //t[i][j] = LPS in s[i...j]

        for(int i = 0; i < n; i++) {
            t[i][i] = 1; // 1 length is always a palindrome
        }

        for(int L = 2; L<=n; L++) {
            for(int i = 0; i < n-L+1; i++) {
                int j = i + L - 1;

                if(s[i] == s[j]) {
                    t[i][j] = 2 + t[i+1][j-1];
                } else {
                    t[i][j] = max(t[i][j-1], t[i+1][j]);
                }
            }
        }

        return t[0][n-1]; //LPS of whole string s[0..n-1]

    }
};

// Approach 5 : Bottom Up DP -> Tabulation Using Longest Palindromic Subsequence
// N - Longest Palindromic Subsequence
// Time Complexity : O(n*n)
// Space Complexity : O(n*n)

class Solution {
public:
    int lcs(string s, string t){
        int n = s.length();

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int i = 1;i<=n; i++){
            for(int j=1; j<=n; j++){
                // match
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());

        return lcs(s,t);
    }
    int minInsertions(string s) {
        return s.length() - longestPalindromeSubseq(s);
    }
};