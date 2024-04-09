// Longest Subarray With Zero Sum
// https://www.naukri.com/code360/problems/longest-subarray-with-zero-sum_6783450?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<bits/stdc++.h>
#include<vector>
using namespace std;
 

int getLongestZeroSumSubarrayLength(vector<int> &arr){

    unordered_map<int, int> mpp;

    int maxi = 0;

    int sum = 0;

    for(int i =0; i< arr.size();i++){

        sum += arr[i];

        if(sum == 0){

            maxi = i +1;

        }

        else{

            if(mpp.find(sum)!= mpp.end()){

                maxi = max(maxi , i - mpp[sum]);

            }else{

                mpp[sum] = i;

            }

        }

    }

    return maxi;

    

}