// Delete Operations for Two Strings
// https://leetcode.com/problems/delete-operation-for-two-strings/

#include<bits/stdc++.h>
using namespace std;

// Approach : Using Longest Common Subsequence
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

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
    int minDistance(string word1, string word2) {
        int longestCount = longestCommonSubsequence(word1, word2);
        return (word1.size() - longestCount) + (word2.size() - longestCount);
    }
};