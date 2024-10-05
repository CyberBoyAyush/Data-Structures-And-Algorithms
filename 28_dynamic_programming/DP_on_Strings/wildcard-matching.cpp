// Wildcard Matching
// Leetcode : https://leetcode.com/problems/wildcard-matching/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:
    bool solve(int i, int j, string s, string p){
        // both strings gets exhausted
        if(i<0 && j<0){
            return true;
        }

        // if s gets exhausted and p is still left
        if(i<0 && j>=0){
            // all left chars in p shold be *
            for(int k = 0; k<=j; k++){
                if(p[k] != '*'){
                    return false;
                }
            }

            return true;
        }

        // if p gets exhausted
        if(j < 0 && i>=0){
            return false;
        }

        // matched or ? case
        if(s[i] == p[j] || p[j] == '?'){
            // go less in both strings
            return solve(i-1,j-1,s,p);
        }

        // check for * case
        if(p[j] == '*'){
            // we take and not take *
            return solve(i-1,j,s,p) || solve(i,j-1,s,p);
        }

        else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        return solve(n-1,m-1,s,p);
    }
};


// Approach 2 : Recursion + Memoization
// Time Complexity : O(n*m)
// Space Complexity : O(n*m) + O(n) for recursive stack

class Solution {
public:
    int dp[2001][2001];
    bool solve(int i, int j, string &s, string &p){
        // both strings gets exhausted
        if(i<0 && j<0){
            return true;
        }

        // if s gets exhausted and p is still left
        if(i<0 && j>=0){
            // all left chars in p shold be *
            for(int k = 0; k<=j; k++){
                if(p[k] != '*'){
                    return false;
                }
            }

            return true;
        }

        // if p gets exhausted
        if(j < 0 && i>=0){
            return false;
        }

        // dp call
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // matched or ? case
        if(s[i] == p[j] || p[j] == '?'){
            // go less in both strings
            return dp[i][j] = solve(i-1,j-1,s,p);
        }

        // check for * case
        if(p[j] == '*'){
            // we take and not take *
            return dp[i][j] = solve(i-1,j,s,p) || solve(i,j-1,s,p);
        }

        else{
            return dp[i][j] = false;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        memset(dp,-1,sizeof(dp));
        return solve(n-1,m-1,s,p);
    }
};


// Approach 3 : Recursion + Memoization (1 Based Indexing)
// Time Complexity : O(n*m)
// Space Complexity : O(n*m) + O(n) for recursive stack

class Solution {
public:
    int dp[2001][2001];
    bool solve(int i, int j, string &s, string &p){
        // both strings gets exhausted
        if(i==0 && j==0){
            return true;
        }

        // if s gets exhausted and p is still left
        if(i==0 && j>0){
            // all left chars in p shold be *
            for(int k = 1; k<=j; k++){
                if(p[k-1] != '*'){
                    return false;
                }
            }

            return true;
        }

        // if p gets exhausted
        if(j == 0 && i>0){
            return false;
        }

        // dp call
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // matched or ? case
        if(s[i-1] == p[j-1] || p[j-1] == '?'){
            // go less in both strings
            return dp[i][j] = solve(i-1,j-1,s,p);
        }

        // check for * case
        if(p[j-1] == '*'){
            // we take and not take *
            return dp[i][j] = solve(i-1,j,s,p) || solve(i,j-1,s,p);
        }

        else{
            return dp[i][j] = false;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        memset(dp,-1,sizeof(dp));
        return solve(n,m,s,p);
    }
}; 

// Approach 4 : Bottom Up DP -> Tabulation
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));

        // Base Case -> if(i==0 && j==0)
        dp[0][0] = true;

        // Base Case -> // if s gets exhausted and p is still left(i==0 && j>0)
        for(int j = 1; j<=m ; j++){
            bool flag = true;
            // all left chars in p shold be *
            for(int k = 1; k<=j; k++){
                if(p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        // Base Case -> if(j == 0 && i>0)
        for(int i = 1; i<=n ; i++){
            dp[i][0] = false;
        }

        // filling the rest of table
        for(int i = 1; i<=n ; i++){
            for(int j = 1; j<=m ;j++){
               // matched or ? case
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    // go less in both strings
                    dp[i][j] = dp[i-1][j-1];
                }

                // check for * case
                else if(p[j-1] == '*'){
                    // we take and not take *
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }

                else{
                    dp[i][j] = false;
                } 
            }
        }

        return dp[n][m];
    }
};