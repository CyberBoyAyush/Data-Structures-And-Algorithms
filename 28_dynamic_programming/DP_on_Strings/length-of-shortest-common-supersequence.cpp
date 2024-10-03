// length of shortest common supersequence
// gfg : https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include<bits/stdc++.h>
using namespace std;

// Approach : Using Longest Common Subsequence
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)
class Solution
{
    public:
    int lcs(string s, string t){
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
        
        return dp[n][m];
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return m + n - lcs(X,Y);
    }
};