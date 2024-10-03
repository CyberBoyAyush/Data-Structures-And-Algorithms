// Shortest Common Supersequence
// Leetcode : https://leetcode.com/problems/shortest-common-supersequence/

#include<bits/stdc++.h>
using namespace std;

// Approach : Using Longest Common Subsequence -> Tabulation
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        // we are doing 1 based indexing here
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        //filling dp
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m ; j++){
                // match
                if(s[i-1] ==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        string ans = "";

        int i = n;
        int j = m;

        while(i>0 && j>0){
            // match
            if(s[i-1] == t[j-1]){
                ans += s[i-1]; // take any s[i-1] or t[i-1]
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                // upwards
                ans += s[i-1];
                i--;
            }
            else{
                // backwards
                ans += t[j-1];
                j--;
            }
        }

        // some length of string maybe left
        while(i>0){
            ans += s[i-1];
            i--;
        }
        while(j>0){
            ans += t[j-1];
            j--;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};