// Printing Longest Increasing Subsequence
// https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=printing-longest-increasing-subsequence

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        vector<int> dp(n, 1);    // dp[i] stores the length of LIS ending at index i
        vector<int> hash(n);     // hash[i] stores the index of the previous element in LIS
        
        int maxLen = 1;          // Stores the length of the longest LIS found
        int lastIdx = 0;         // Stores the last index of the LIS

        

        // Calculate dp values and maintain the hash for LIS reconstruction
        for(int i = 0; i < n; i++) {
            // Initialize the hash vector with each element pointing to itself
            hash[i] = i;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;  // Mark j as the previous element of i in the LIS
                }
            }
            // Update the maximum length and last index of the LIS
            if(dp[i] > maxLen) {
                maxLen = dp[i];
                lastIdx = i;
            }
        }

        // Reconstruct the LIS from the hash and lastIdx
        vector<int> temp;
        temp.push_back(nums[lastIdx]);  // Push the last element of the LIS
        
        while(hash[lastIdx] != lastIdx) {  // Trace back using the hash array
            lastIdx = hash[lastIdx];
            temp.push_back(nums[lastIdx]);  // Push the corresponding element
        }
        
        reverse(temp.begin(), temp.end());  // Reverse the sequence to get the correct order
        return temp;
    }
};