// Longest Common Substring
// GFG : https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        int dp[n+1][m+1];
        
        for(int i = 0; i<=n ; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j<=m; j++){
            dp[0][j] = 0;
        }
        
        int ans = 0;
        
        for(int i = 1; i<=n ; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return ans;
    }
};


// Space Optimized
class Solution {
  public:
    int longestCommonSubstr(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        
        int ans = 0;
        
        for(int i = 1; i<=n ; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    curr[j] = 1 + prev[j-1];
                    ans = max(ans,curr[j]);
                }
                else{
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        
        return ans;
    }
};