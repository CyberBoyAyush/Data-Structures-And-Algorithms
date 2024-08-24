// House Robber II
// Leetcode : https://leetcode.com/problems/house-robber-ii/

// Approach 1 : Recursion + Memoization
// Time Complexity: O(n)
// Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[101];
    int solve(vector<int> &nums , int i, int n){
        if(i>n) return 0;

        if(t[i] != -1)  return t[i];

        int take = nums[i] + solve(nums,i+2,n);
        int leave = solve(nums,i+1,n);

        return t[i] = max(take,leave);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);
        
        memset(t, -1, sizeof(t));
        
        //case-1 - Take first house 0th index wala house
        
        int take_0th_index_house = solve(nums, 0, n-2);
        
        memset(t, -1, sizeof(t));
        
        //case-2  - Take second house 1st index wala house
        int take_1st_index_house = solve(nums, 1, n-1);
        
        
        return max(take_0th_index_house, take_1st_index_house);
    }
};

// Approach 2 : Tabulation
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)  return nums[0];

        if(n == 2) return max(nums[0],nums[1]);

        vector<int> t(n+1, 0);

        t[0] = 0;

        // taking first
        for(int i = 1 ; i<=n-1; i++){
            int skip = t[i-1];
            int take = nums[i-1] + ((i - 2 )>= 0 ? t[i-2] : 0);

            t[i] = max(take,skip);
        }

        int res1 = t[n-1];

        t.clear();

        // taking last
        t[0] = 0;
        t[1] = 0; // beacuse we skipped first house
        
        for(int i = 2; i<=n ; i++){
            int skip = t[i-1];
            int take = nums[i-1] + ((i - 2 )>= 0 ? t[i-2] : 0);

            t[i] = max(take,skip);
        }
        int res2 = t[n];

        return max(res1,res2);
    }
};

// Approach 3 : Space Optimized Tabulation
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    
    int solve(vector<int>& nums, int l, int r) {
        
        int prevPrev = 0, prev = 0;
        
        for(int i = l; i<=r; i++) {
            int skip = prev;
            int take = nums[i] + prevPrev;
            
            int temp = max(skip, take);
            
            prevPrev = prev;
            prev     = temp;
        }
        
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);
        
        int take_first_house = solve(nums, 0, n-2);
        
        int skip_first_house = solve(nums, 1, n-1);
        
        
        return max(take_first_house, skip_first_house);
    }
};