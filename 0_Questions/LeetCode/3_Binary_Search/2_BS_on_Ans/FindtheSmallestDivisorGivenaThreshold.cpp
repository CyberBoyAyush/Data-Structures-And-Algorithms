// Find the Smallest Divisor Given a Threshold
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
#include<vector>
#include<iostream>
#include<climits>
#include<math.h>
using namespace std;
class Solution {
    bool check(vector<int>& nums, int t, int mid){
        int ans = 0;
        for(int i = 0; i<nums.size() ; i++){
            ans  += ceil((double)nums[i] / (double) mid);
        }
        if(ans <= t){
            return true;
        }
        else{
            return false;
        }
    }
    int maxEl(vector<int>& nums){
        int maxi = INT_MAX;
        for(int i = 0 ; i<nums.size();i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1 , high = maxEl(nums);
        int ans = 0;
        while(low<=high){
            long long int mid = low + (high - low)/2;
            if(check(nums,threshold,mid)){
                ans = mid;
                high = mid - 1; // we need smallest
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};