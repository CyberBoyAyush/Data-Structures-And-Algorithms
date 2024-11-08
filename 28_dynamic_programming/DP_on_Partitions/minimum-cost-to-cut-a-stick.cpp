// Minimum Cost to Cut a Stick
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution {
public:
    int solve(int i, int j, vector<int>& cuts){
        if(i > j){
            return 0;
        }

        int mini = INT_MAX;

        for(int idx = i; idx <= j; idx++){
            int cost = (cuts[j+1] - cuts[i-1]) + solve(i,idx-1,cuts) + solve(idx+1,j,cuts);

            mini = min(mini, cost);
        }

        return mini;
    }
    int minCost(int c, vector<int>& cuts) {
        int n = cuts.size();
        cuts.push_back(c);
        cuts.insert(cuts.begin(),0);

        sort(cuts.begin(),cuts.end());

        return solve(1,n,cuts);
        
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n^3)
// Space Complexity : O(n^2)

class Solution {
public:
    int dp[102][102];
    int solve(int i, int j, vector<int>& cuts){
        if(i > j){
            return 0;
        }

        // dp call
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int mini = INT_MAX;

        for(int idx = i; idx <= j; idx++){
            int cost = (cuts[j+1] - cuts[i-1]) + solve(i,idx-1,cuts) + solve(idx+1,j,cuts);

            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }
    int minCost(int c, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        int n = cuts.size();
        cuts.push_back(c);
        cuts.insert(cuts.begin(),0);

        sort(cuts.begin(),cuts.end());

        return solve(1,n,cuts);
        
    }
};

// Approach 3 : Tabulation
// Time Complexity : O(n^3)
// Space Complexity : O(n^2)

class Solution {
public:
    int dp[102][102];
    int minCost(int c, vector<int>& cuts) {
        memset(dp,0,sizeof(dp));

        // we add c and 0 in back and front for size determination
        int n = cuts.size();

        cuts.push_back(c);
        cuts.insert(cuts.begin(), 0);

        // sorting it
        sort(cuts.begin(),cuts.end());

        for(int i = n; i>=1; i--){
            for(int j = 1; j<=n; j++){
                if(i > j) continue; // handling base case

                int mini = INT_MAX;

                for(int idx = i; idx<=j ; idx++){
                    int cost = (cuts[j+1] - cuts[i-1]) + dp[i][idx-1] + dp[idx+1][j];

                    mini = min(mini,cost);
                }

                dp[i][j] = mini;

            }
        }
        return dp[1][n];
    }
};