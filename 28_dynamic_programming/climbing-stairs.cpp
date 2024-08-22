// Climbing Stairs
/// LeetCode: 70. Climbing Stairs : https://leetcode.com/problems/climbing-stairs/

// Approach 1 : Memoization
// Time Complexity: O(n)
// Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[46];
    int solve(int n) {
        // memoization

        if (n < 0) {
            // negative stairs
            return 0;
        }

        if (dp[n] != -1)
            return dp[n];

        if (n == 0) {
            return 1; // one way found
        }

        int oneStairs = solve(n - 1);
        int TwoStairs = solve(n - 2);

        return dp[n] = oneStairs + TwoStairs;
    }
    int climbStairs(int n) { 
        memset(dp, -1, sizeof(dp));
        return solve(n); 
    }
};

// Approach 2 : Tabulation
class Solution {
public:
    int climbStairs(int n) {

        if(n == 1 || n == 2 || n == 3){
            return n;
        }
        
        vector<int> arr(n+1);

        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;

        for(int i = 3 ; i<=n ; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }

        return arr[n];
    }
};

// Approach 3 : Optimized space complexity
class Solution {
public:
    int climbStairs(int n) {

        if(n == 1 || n == 2 || n == 3){
            return n;
        }

        int a = 1;
        int b = 2;
        int c = 3;

        for(int i = 3 ; i<=n ; i++){
            c = b + a;
            int temp_b = b;
            b = c;
            a = temp_b;
        }

        return c;
    }
};