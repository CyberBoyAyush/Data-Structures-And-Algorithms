// Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/

// We use the same approach as the Subset Sum Problem.
// We need to find if there is a subset of the given array with sum equal to half of the total sum of the array.
// If we can find such a subset, then the remaining elements will also have the same sum.
// So, we can partition the array into two subsets with equal sum.
// If the total sum of the array is odd, then we can't partition the array into two subsets with equal sum.
// So, we return false in that case.
// If the total sum of the array is even, then we can find if there is a subset with sum equal to half of the total sum of the array.
// We can use the same approach as the Subset Sum Problem to solve this problem.

// Optimized Approach: Tabulation + Space Optimized
// Time Complexity: O(n*sum)
// Space Complexity: O(sum)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsetSum(vector<int> arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum + 1, 0);
        vector<bool> curr(sum + 1, 0);

        prev[0] = curr[0] = true;

        if (arr[0] <= sum) {
            prev[arr[0]] = true;  // Only set this if arr[0] is within the bounds of sum
        }

        for (int index = 1; index < n; index++) {
            for (int target = 1; target <= sum; target++) {
                bool notTake = prev[target];
                bool take = false;
                if (target >= arr[index]) {
                    take = prev[target - arr[index]];
                }
                curr[target] = take || notTake;
            }
            prev = curr;
        }

        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;

        for(int i = 0 ; i< n ; i++){
            totalSum += nums[i];
        }

        int sum = totalSum / 2;

        if(totalSum % 2 != 0)    return false;   

        return(isSubsetSum(nums,sum));
    }
};