// palindrome-partitioning-ii
// leetcode : https://leetcode.com/problems/palindrome-partitioning-ii/submissions/1449876408/

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion + Memoization
// TC : O(expoential)
// SC : O(n)

class Solution {
public:
    int n;
    bool isPalindome(int i, int j, string &s){

        while (i < j) { // Corrected condition here
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, string &s){
        // base case
        if(i == n){
            // string finished
            return 0;
        }

        int minCost = INT_MAX;

        for(int j = i; j<n ; j++){

            // we do partition if string is palindorme
            if(isPalindome(i,j,s)){
                // partition kardo
                int cost = 1 + solve(j+1,s);
                minCost = min(minCost,cost);
            }
        }

        return minCost;
    }
    int minCut(string s) {
        n = s.length();
        return solve(0,s)-1;
    }
};

// Approach 2 : Recursion + Memoization
// TC : O(n^2)
// SC : O(n^2) + O(n)

class Solution {
public:
    int n;
    int dp[2001];
    bool isPalindome(int i, int j, string &s){

        while (i < j) { // Corrected condition here
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, string &s){
        // base case
        if(i == n){
            // string finished
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int minCost = INT_MAX;

        for(int j = i; j<n ; j++){

            // we do partition if string is palindorme
            if(isPalindome(i,j,s)){
                // partition kardo
                int cost = 1 + solve(j+1,s);
                minCost = min(minCost,cost);
            }
        }

        return dp[i] = minCost;
    }
    int minCut(string s) {
        n = s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,s)-1;
    }
};

// Approach 3 : Tabulation
// TC : O(n^2)
// SC : O(n^2)

class Solution {
public:
    int n;
    int dp[2001];
    bool isPalindome(int i, int j, string &s){

        while (i < j) { // Corrected condition here
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        n = s.length();
        memset(dp,0,sizeof(dp));
        for(int i = n-1; i>=0; i--){
            int minCost = INT_MAX;

            for(int j = i; j<n ; j++){

                // we do partition if string is palindorme
                if(isPalindome(i,j,s)){
                    // partition kardo
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost,cost);
                }
            }

            dp[i] = minCost;
        }
        return dp[0]-1;
    }
};