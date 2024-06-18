// Capacity To Ship Packages Within D Days
//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
#include<vector>
#include<iostream>
#include<climits>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class Solution {
    int findDays(vector<int>& weights , int mid){
        int days = 1;
        int load = 0;
        for(int i = 0 ; i<weights.size() ; i++){
            if(weights[i] + load > mid){
                days += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            int numDays = findDays(weights,mid);
            if(numDays<=days){
                ans = mid;
                high = mid - 1; // we need minimum
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
};