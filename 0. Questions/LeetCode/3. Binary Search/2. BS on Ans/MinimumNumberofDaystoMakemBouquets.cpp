// Minimum Number of Days to Make m Bouquets
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
#include<vector>
#include<iostream>
#include<climits>
using namespace std;
class Solution {
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int cnt = 0, noOfBouqets = 0;
        for(int i = 0; i<n; i++){
            if(bloomDay[i]<=day){
                cnt ++;
            }
            else{
                noOfBouqets += cnt/k;
                cnt = 0;
            }
        }
        noOfBouqets += cnt/k;
        //return noOfBouqets >= m;
        if(noOfBouqets>=m){
            return true;
        }
        else{
            return false;
        }
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Edge case
        long long val=m*1ll*k*1ll;
        int n=bloomDay.size();
        if(val>n){
            return -1;
        }
        int low = INT_MAX , high = INT_MIN , ans = 0;
        for(int i=0 ;i<n;i++){
            low = min(bloomDay[i],low);
            high = max(bloomDay[i],high);
        }
        if((m*k)>n){
            return -1;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay , mid, m, k)){
                ans = mid;
                high = mid -1; // we need minimum so we go to the left part of the array
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};