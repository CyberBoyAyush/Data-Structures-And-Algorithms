// Count All Subarrays With Given Sum
//https://www.naukri.com/code360/problems/subarray-sums-i_1467103?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // Write Your Code Here
    unordered_map<int,int> m;
    m[0] = 1;
    int sum = 0, count = 0;
    for(int i =0 ; i < arr.size();i++){
        sum += arr[i];
        count += m[sum-k];
        m[sum] += 1;
    }
    return count;
}