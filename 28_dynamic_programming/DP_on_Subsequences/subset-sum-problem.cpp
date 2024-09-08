// Subset Sum Equal to Given Sum
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(1)
class Solution{   
public:
    bool solve(vector<int> arr, int index , int sum){
        if(sum == 0)    return true;
        if(index == 0) return(arr[0]==sum);
        
        bool notTake = solve(arr,index-1,sum);
        bool take = false;
        if(arr[index] <= sum){
            take = solve(arr,index-1,sum-arr[index]);
        }
        
        return notTake || take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        return solve(arr, n-1, sum);
    }
};

// Approach 2: Recursion + Memoization
// Time Complexity: O(n*sum)
// Space Complexity: O(n*sum)

class Solution{   
public:
     int dp[101][10001];
    bool solve(vector<int> arr, int index , int sum){
        if(sum == 0)    return true;
        if(index == 0) return(arr[0]==sum);
        
        if(dp[index][sum]!=-1) return dp[index][sum];
        
        bool notTake = solve(arr,index-1,sum);
        bool take = false;
        if(arr[index] <= sum){
            take = solve(arr,index-1,sum-arr[index]);
        }
        
        return dp[index][sum] = notTake || take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(arr, n-1, sum);
    }
};

// Approach 3: Tabulation
// Time Complexity: O(n*sum)
// Space Complexity: O(n*sum)
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
        for(int i = 0 ; i< n; i++){
            dp[i][0] = true;
        }
        
        dp[0][arr[0]] = true;
        
        for(int index = 1; index<n; index++){
            for(int target = 1; target<=sum; target++){
                bool notTake = dp[index-1][target];
                bool take = false;
                if(target >= arr[index]){
                    take = dp[index-1][target-arr[index]];
                }
                dp[index][target] = take || notTake;
            }
        }
        
        return dp[n-1][sum];
    }
};

// Approach 4: Tabulation + Space Optimized
// Time Complexity: O(n*sum)
// Space Complexity: O(sum)

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<bool> prev(sum+1 , 0);
        vector<bool> curr(sum+1,0);
        
        prev[0] = curr[0] = true;
        
        prev[arr[0]] = true;
        
        for(int index = 1; index<n; index++){
            for(int target = 1; target<=sum; target++){
                bool notTake = prev[target];
                bool take = false;
                if(target >= arr[index]){
                    take = prev[target-arr[index]];
                }
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        
        return prev[sum];
    }
};