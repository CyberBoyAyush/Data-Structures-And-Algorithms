//Split Array Largest Sum
// https://leetcode.com/problems/split-array-largest-sum/description/


#include<vector>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
class Solution {

int countsubarr(vector<int>& nums,int mid){
    int count = 1;
    int subarrsum = 0;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i]+subarrsum<=mid){
            subarrsum += nums[i];
        }
        else{
            count++;
            subarrsum = nums[i];
        }
    }
    return count;

}
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low + high)/2;
            int cnt = countsubarr(nums,mid);
            if(cnt<=k){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};