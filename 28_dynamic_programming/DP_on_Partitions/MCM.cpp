// Matrix Chain Multiplication MCM
// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=matrix-chain-multiplication

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)

class Solution{
public:
    int solve(int i, int j, int arr[]){
        // base case
        if(i == j){
            // it means there is only 1 matrix
            return 0;
        }
        
        int mini = INT_MAX; // stores the final answer
        
        // we create partitions for further call
        // k = i -> j-1 => (i,k) , (k+1,j)
        for(int k = i; k<=j-1; k++){
            int steps = (arr[i-1] * arr[k] * arr[j]) +
                        solve(i,k,arr) + solve(k+1,j,arr);
                        
            mini = min(mini,steps);
        }
        
        return mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        return solve(1, N-1, arr); 
    }
};

// Approach 2 : Recursion + Memoization
// Time Complexity : O(n^3)
// Space Complexity : O(n^2)

class Solution{
public:
    int dp[101][101]; // dp[N][N]
    int solve(int i, int j, int arr[]){
        // base case
        if(i == j){
            // it means there is only 1 matrix
            return 0;
        }
        
        // DP call
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int mini = INT_MAX; // stores the final answer
        
        // we create partitions for further call
        // k = i -> j-1 => (i,k) , (k+1,j)
        for(int k = i; k<=j-1; k++){
            int steps = (arr[i-1] * arr[k] * arr[j]) +
                        solve(i,k,arr) + solve(k+1,j,arr);
                        
            mini = min(mini,steps);
        }
        
        return dp[i][j] = mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(1, N-1, arr); 
    }
};

// Approach 3 : Tabulation
// Time Complexity : O(n^3)
// Space Complexity : O(n^2)

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N,0));
        
        // Base case initialization
        for(int i = 0 ; i< N ; i++){
            dp[i][i] = 0;
        }
        
        // filling the rest
        for(int i = N-1; i>=1; i--){
            for(int j = i + 1; j<=N-1; j++){
                int mini = INT_MAX; // stores the final answer
        
                // we create partitions for further call
                // k = i -> j-1 => (i,k) , (k+1,j)
                for(int k = i; k<=j-1; k++){
                    int steps = (arr[i-1] * arr[k] * arr[j]) +
                                dp[i][k] + dp[k+1][j];
                                
                    mini = min(mini,steps);
                }
                
                dp[i][j] = mini;
            }
        }
        return dp[1][N-1];
    }
};