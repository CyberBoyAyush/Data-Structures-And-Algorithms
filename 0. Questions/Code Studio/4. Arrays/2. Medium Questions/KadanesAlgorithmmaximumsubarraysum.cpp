// Kadane's Algorithm, maximum subarray sum
// https://www.naukri.com/code360/problems/maximum-subarray-sum_630526?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
#include<string>
#include <bits/stdc++.h> 
using namespace std;
long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum = 0;
    long long maxi = LONG_MIN;
    for(int i = 0; i<n; i++){
        sum += arr[i];
        maxi = max(maxi,sum);
        if(sum<0){
            sum = 0;
        }
        if(maxi<0){
            return 0;
        }
    }
    return maxi;
}