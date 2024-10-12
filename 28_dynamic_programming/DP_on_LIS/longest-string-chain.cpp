// longest-string-chain
// https://leetcode.com/problems/longest-string-chain/

#include <bits/stdc++.h>
using namespace std;

// // Similar to LIS with sorting -> Recursion + Memoization
// Time Complexity : O(n^2)
// Space Complexity : O(n) + O(n) + O(n) = O(n)

class Solution {
public:
    int n;
    int dp[1001][1001];
    bool isPossible(string &s1, string &s2){
        // chekcing length
        if(s1.length() != s2.length() + 1){
            return 0;
        }

        int i = 0;
        int j = 0;

        while(i<s1.length()){
            if(j < s2.length() && s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                // increase i
                i++;
            }

            if (i - j > 1) {
                return false;
            }
        }

        return j == s2.size();
    }

    static bool comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }

    int solve(int idx, int prev_idx, vector<string>& words){
        if(idx == n){
            // idx out of bound
            return 0;
        }

        if(dp[idx][prev_idx+1] != -1){
            return dp[idx][prev_idx+1];
        }

        // two options
        int taken = 0;
        int notTaken = 0;

        // take 
        if(prev_idx == -1 || isPossible(words[idx], words[prev_idx])){
           taken = 1 + solve(idx+1,idx,words); 
        }
        
        // not taken
        notTaken = 0 + solve(idx+1,prev_idx,words);

        return dp[idx][prev_idx+1] = max(taken,notTaken);
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(words.begin(),words.end(),comp);
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,words);
    }
};


// Similar to LIS with sorting -> Tabulation
// Time Complexity : O(n^2)
// Space Complexity : O(n)

class Solution {
public:
    bool isPossible(string &s1, string &s2){
        // chekcing length
        if(s1.length() != s2.length() + 1){
            return 0;
        }

        int i = 0;
        int j = 0;

        while(i<s1.length()){
            if(j < s2.length() && s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                // increase i
                i++;
            }
        }

        if(i == s1.size() && j == s2.size()){
            // both strings exhausted
            return 1;
        }

        return 0;
    }

    static bool comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(),comp); // sort on basis of size

        vector<int> dp(n,1);

        int maxLen = 1;

        for(int i = 0; i<n ; i++){
            for(int j = 0; j<i ; j++){
                if(isPossible(words[i] , words[j])){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        return maxLen;
    }
};