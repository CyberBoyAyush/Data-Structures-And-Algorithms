//  Kth Missing Positive Number
// https://leetcode.com/problems/kth-missing-positive-number/description/
#include<vector>
#include<iostream>
#include<climits>
using namespace std;
// Brute Force Approach Linear Search
// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         for(int i = 0; i<arr.size(); i++){
//             if(arr[i]<=k){
//                 k++;
//             }
//             else{
//                 break;
//             }
//         }
//         return k;
//     }
// };


// Optimal Approacg Using Binary Search.
class Solution{
public:
    int findKthPositive(vector<int>& arr, int k){
            int low = 0, high = arr.size()-1;
            while(low<=high){
                int mid = (low + high)/2;
                int missing = arr[mid] - (mid + 1);
                if(missing<k){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            return low + k;
        }
    };