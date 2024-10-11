// largest-divisible-subset
// Link: https://leetcode.com/problems/largest-divisible-subset/

#include <bits/stdc++.h>
using namespace std;

// Tabulation And Trace Back
// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();

        vector<int> dp(n,1);
        vector<int> hash(n);

        sort(arr.begin(),arr.end());

        int maxLen = 1;
        int lastIdx = 0;

        for(int i = 0; i<n ; i++){
            hash[i] = i;
            for(int j = 0; j<i; j++){
                if(arr[i] % arr[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > maxLen){
                maxLen = dp[i];
                lastIdx = i;
            }
        }

        // printing LIS == Divisibel subset
        vector<int> temp;
        temp.push_back(arr[lastIdx]);
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            temp.push_back(arr[lastIdx]);
        }

        reverse(temp.begin(),temp.end());
        return temp;
    }
};