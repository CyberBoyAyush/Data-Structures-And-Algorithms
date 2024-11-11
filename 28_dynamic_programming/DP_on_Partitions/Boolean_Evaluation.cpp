// Boolean Evaluation
// Gfg : https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
// Coding Ninjas : https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(4^n)
// Space Complexity : O(n)

#define ll long long

int mod = 1000000007;

long long solve(int i, int j, bool isTrue, string & exp){
    // base case

    if(i > j){
        return 0;
    }

    if(i == j){ // single element
        if(isTrue == 1){ // we need true
            return exp[i] == 'T';
        }
        else{ // we need false
            return exp[i] == 'F';
        }
    }

    long long ways = 0;

    for(int idx = i+1; idx<=j-1; idx = idx+2){
        ll lt = solve(i,idx-1,1,exp);
        ll lf = solve(i,idx-1,0,exp);
        ll rt = solve(idx+1,j,1,exp);
        ll rf = solve(idx+1,j,0,exp);

        if(exp[idx] == '&'){
            if(isTrue) ways = (ways + (lt * rt) % mod) % mod;
            else    ways = (ways + (lt * rf)% mod + (lf*rt) % mod + (lf * rf) % mod) % mod;
        }
        else if(exp[idx] == '|'){
            if(isTrue) ways = (ways + (lt * rt)% mod + (lf*rt) % mod + (lt * rf) % mod) % mod;
            else    ways = (ways + (lf * rf) % mod) % mod;
        }
        else{ // '^' xor
            if(isTrue){
                ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
            }
            else{
                ways = (ways + (lt * rt) % mod + (lf * rf) % mod)%mod;
            }
        }
    }

    return ways;

}

int evaluateExp(string & exp) {
    int n = exp.length();
    return solve(0,n-1,1,exp);
}

// Approach 2 : Recursion + Memo
// TC : O(n*n*2)
// SC : O(n*n*2) + O(n)

#define ll long long

int mod = 1000000007;

long long solve(int i, int j, bool isTrue, string & exp, vector<vector<vector<ll>>> &dp){
    // base case

    if(i > j){
        return 0;
    }

    if(i == j){ // single element
        if(isTrue == 1){ // we need true
            return exp[i] == 'T';
        }
        else{ // we need false
            return exp[i] == 'F';
        }
    }

    if(dp[i][j][isTrue] != -1){
        return dp[i][j][isTrue];
    }

    long long ways = 0;

    for(int idx = i+1; idx<=j-1; idx = idx+2){
        ll lt = solve(i,idx-1,1,exp,dp);
        ll lf = solve(i,idx-1,0,exp,dp);
        ll rt = solve(idx+1,j,1,exp,dp);
        ll rf = solve(idx+1,j,0,exp,dp);

        if(exp[idx] == '&'){
            if(isTrue) ways = (ways + (lt * rt) % mod) % mod;
            else    ways = (ways + (lt * rf)% mod + (lf*rt) % mod + (lf * rf) % mod) % mod;
        }
        else if(exp[idx] == '|'){
            if(isTrue) ways = (ways + (lt * rt)% mod + (lf*rt) % mod + (lt * rf) % mod) % mod;
            else    ways = (ways + (lf * rf) % mod) % mod;
        }
        else{ // '^' xor
            if(isTrue){
                ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
            }
            else{
                ways = (ways + (lt * rt) % mod + (lf * rf) % mod)%mod;
            }
        }
    }

    return dp[i][j][isTrue] = ways;

}

int evaluateExp(string & exp) {
    int n = exp.length();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return solve(0,n-1,1,exp,dp);
}

// Appraoch 3 : Tabulation
// TC : O(n*n*2)
// SC : O(n*n*2)

#define ll long long
const int mod = 1000000007;

int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n - 1; j++) {
            // Base case 1: i > j is an invalid case, so continue.
            if (i > j) continue;
            
            for (int isTrue = 0; isTrue <= 1; isTrue++) {
                // Base case 2: i == j, evaluate the single character.
                if (i == j) {
                    if (isTrue == 1) dp[i][j][isTrue] = exp[i] == 'T';
                    else dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }

                // Recurrence logic:
                ll ways = 0;
                for (int ind = i + 1; ind <= j - 1; ind += 2) {
                    ll lT = dp[i][ind - 1][1];
                    ll lF = dp[i][ind - 1][0];
                    ll rT = dp[ind + 1][j][1];
                    ll rF = dp[ind + 1][j][0];

                    if (exp[ind] == '&') {
                        if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
                    }
                    else if (exp[ind] == '|') {
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod) % mod;
                    }
                    else {
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n - 1][1];
}