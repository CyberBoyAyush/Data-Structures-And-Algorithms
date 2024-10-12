// longest-bitonic-subsequence
//https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

#include <bits/stdc++.h>
using namespace std;

// Using Lis to fill two dp array and compute
// TC - O(n x n)
// SC - O(2 * n) -> Two Dp array

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        if (n == 1) return 0;  // Edge case when there's only one element.
        vector<int> dp1(n,1); // front inc
        vector<int> dp2(n,1); // back inc
        
        // filling dp1
        for(int i = 0 ; i< n ; i++){
            for(int j = 0; j<i ; j++){
                if(nums[i] > nums[j]){
                    dp1[i] = max(dp1[i], 1 + dp1[j]);
                }
            }
        }
        
        // filling dp2
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = n-1; j>i ; j--){
                if(nums[i] > nums[j]){
                    dp2[i] = max(dp2[i], 1 + dp2[j]);
                }
            }
        }
        
        // finding the max of both
        int maxi = 0;
        for(int i = 0; i< n ; i++){
            if(dp1[i]!=1 && dp2[i]!=1) 
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
        
        return maxi;
    }
};