// Printing Longest Common Subsequence
// We use same approach as that of finding the length of LCS but we keep track of the characters which are common in both strings.

#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Tabulation
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

        string lcs = "";
        int i = n , j = m;
        while(i>0 && j>0){
            // if both char are same
            if(text1[i-1] == text2[j-1]){ // we have 1 based indexing
                lcs.push_back(text1[i-1]);
                // now go back diagnolly
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        
        reverse(lcs.begin(),lcs.end());

        cout<<lcs<<endl;

        return dp[n][m];
    }
};