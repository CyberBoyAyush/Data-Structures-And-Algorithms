// Edit Distance
// Leetcode : https://leetcode.com/problems/edit-distance/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(3^n)
// Space Complexity : O(n)

class Solution {
public:
    int solve(int i, int j, string s, string t){
        // s1 gets exhausted
        if(i<0){
            //we need j + 1 insert operations
            return j+1;
        }

        // s2 gets exhausted
        if(j<0){
            // we need i+1 remove operations 
            return i + 1;
        }

        // gets matched
        if(s[i] == t[j]){
            return 0 + solve(i-1,j-1,s,t); // need 0 operations
        }

        // we can do 3 operations
        int insert = 1 + solve(i,j-1,s,t);
        int del = 1 + solve(i-1,j,s,t);
        int replace = 1 + solve(i-1,j-1,s,t);

        return min({insert,del,replace});
    }
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();

        return solve(n-1,m-1,s,t);
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n*m)
// Space Complexity : O(n*m) + O(n) for recursive stack

class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, string s, string t){
        // s1 gets exhausted
        if(i<0){
            //we need j + 1 insert operations
            return j+1;
        }

        // s2 gets exhausted
        if(j<0){
            // we need i+1 remove operations 
            return i + 1;
        }

        // dp call
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // gets matched
        if(s[i] == t[j]){
            return dp[i][j] = 0 + solve(i-1,j-1,s,t); // need 0 operations
        }

        // we can do 3 operations
        int insert = 1 + solve(i,j-1,s,t);
        int del = 1 + solve(i-1,j,s,t);
        int replace = 1 + solve(i-1,j-1,s,t);

        return dp[i][j] = min({insert,del,replace});
    }
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        memset(dp,-1,sizeof(dp));
        return solve(n-1,m-1,s,t);
    }
};

// Approach 3 : Recursion + Memoization (1 Based Indexing)
// Time Complexity : O(n*m)
// Space Complexity : O(n*m) + O(n) for recursive stack

class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, string s, string t){

        // this code has 1 based indexing

        // s1 gets exhausted
        if(i==0){
            //we need j insert operations
            return j;
        }

        // s2 gets exhausted
        if(j==0){
            // we need i remove operations 
            return i;
        }

        // dp call
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // gets matched
        if(s[i-1] == t[j-1]){
            return dp[i][j] = 0 + solve(i-1,j-1,s,t); // need 0 operations
        }

        // we can do 3 operations
        int insert = 1 + solve(i,j-1,s,t);
        int del = 1 + solve(i-1,j,s,t);
        int replace = 1 + solve(i-1,j-1,s,t);

        return dp[i][j] = min({insert,del,replace});
    }
    int minDistance(string s, string t) {
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
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        // base cases
        for(int i = 0; i<=n ; i++){
            dp[i][0] = i;
        }

        for(int j = 0; j<=m ; j++){
            dp[0][j] = j;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m ; j++){
               // gets matched
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1]; // need 0 operations
                }
                else{
                    // we can do 3 operations
                    int insert = 1 + dp[i][j-1];
                    int del = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];

                    dp[i][j] = min({insert,del,replace});
                }
            }
        }
        return dp[n][m];
    }
};

// Approach 5 : Bottom Up DP -> Tabulation (Space Optimized)
// Time Complexity : O(n*m)
// Space Complexity : O(m)

class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);

        // base cases -> when s2 exhausts and no need to check further
        for(int j = 0; j<=m ; j++){
            prev[j] = j;
        }

        for(int i = 1; i<=n; i++){
            curr[0] = i; // this is for when s1 exhausts and no need to check further
            for(int j = 1; j<=m ; j++){
               // gets matched
                if(s[i-1] == t[j-1]){
                    curr[j] = 0 + prev[j-1]; // need 0 operations
                }
                else{
                    // we can do 3 operations
                    int insert = 1 + curr[j-1];
                    int del = 1 + prev[j];
                    int replace = 1 + prev[j-1];

                    curr[j] = min({insert,del,replace});
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};