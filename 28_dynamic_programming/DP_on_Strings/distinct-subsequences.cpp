// Distinct Subsequences
// Leetcode : https://leetcode.com/problems/distinct-subsequences/description/

#include<bits/stdc++.h>
using namespace std;

// Appraoch 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:
    int solve(int i, int j, string s, string t){
        if(j<0){
            // main matching string exhausted
            return 1;
        }

        if(i<0){
            return 0; // nothing more to match 
        }

        if(s[i] == t[j]){
            return (solve(i-1,j,s,t) + solve(i-1,j-1,s,t));
        }
        else{
            return solve(i-1,j,s,t);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        return solve(n,m,s,t);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n*m)
// Space Complexity : O(n*m) + O(n) for recursive stack

class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int j, string s, string t){
        if(j<0){
            // main matching string exhausted
            return 1;
        }

        if(i<0){
            return 0; // nothing more to match 
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == t[j]){
            return dp[i][j] = (solve(i-1,j,s,t) + solve(i-1,j-1,s,t));
        }
        else{
            return dp[i][j] = solve(i-1,j,s,t);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        memset(dp,-1,sizeof(dp));
        return solve(n,m,s,t);
    }
};

// Approach 3 : Recursion + Memoization (1 Based Indexing)
// Time Complexity : O(n*m)
// Space Complexity : O(n*m) + O(n) for recursive stack
class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int j, string s, string t){
        if(j==0){
            // main matching string exhausted
            return 1;
        }

        if(i==0){
            return 0; // nothing more to match 
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i-1] == t[j-1]){
            return dp[i][j] = (solve(i-1,j,s,t) + solve(i-1,j-1,s,t));
        }
        else{
            return dp[i][j] = solve(i-1,j,s,t);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        memset(dp,-1,sizeof(dp));
        return solve(n,m,s,t);
    }
};

// Approach 4 : Bottom Up DP -> Tabulation
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<double>> dp(n+1, vector<double>(m+1,0));

        // initialization -> when s2 exhausts and no need to check further
        for(int i = 0; i<=n ; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i<=n ; i++){
            for(int j = 1; j<=m ; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (int)dp[n][m];
    }
};

// Approach 5 : Bottom Up DP -> Tabulation (Space Optimized)
// Time Complexity : O(n*m)
// Space Complexity : O(m)

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<double> prev(m+1,0);
        vector<double> curr(m+1,0);

        // initialization -> when s2 exhausts and no need to check further
        prev[0] = curr[0] = 1;

        for(int i = 1; i<=n ; i++){
            for(int j = 1; j<=m ; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j] + prev[j-1];
                }
                else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return (int)prev[m];
    }
};