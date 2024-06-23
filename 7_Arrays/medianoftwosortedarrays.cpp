#include<bits/stdc++.h>
using namespace std;

// Bruteforce
// TC - O(m+n) 
// SC - O(m+n) 

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();

//         // veector for storing merged arr
//         vector<int> temp(m+n);

//         int i = 0 , j=0, k=0; // 3 pointers for 3 arrays

//         while(i<m && j<n){
//             if(nums1[i] < nums2[j]){
//                 temp[k++] = nums1[i++];
//             }

//             else{
//                 temp[k++] = nums2[j++];
//             }
//         }

//         // in case m and n are different size
//         while(i<m){
//             temp[k++] = nums1[i++];
//         }

//         while(j<n){
//             temp[k++] = nums2[j++];
//         }

//         // now finding median
//         int size = m + n;

//         // for odd size
//         if(size % 2 == 1){ // odd sizee
//             return temp[size / 2];
//         }
        
//         // for even
//         return (temp[size / 2] + temp[size / 2 - 1]) / 2.0;
//     }
// };


// Better 
// TC - O(m+n) 
// SC - O(1) 
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();

//         int size = n + m;

//         int idx1 = (size/2) - 1;
//         int idx2 = size/2;

//         int el1 = -1, el2 = -1; // here we store out elments

//         int i = 0, j = 0 , k = 0;

//         while(i<m && j<n){
//             if(nums1[i] < nums2[j]){
//                 if(k == idx1){
//                     el1 = nums1[i];
//                 }

//                 if(k == idx2){
//                     el2 = nums1[i];
//                 }
//                 i++;
//             }
//             else{
//                 if(k == idx1){
//                     el1 = nums2[j];
//                 }

//                 if(k == idx2){
//                     el2 = nums2[j];
//                 }
//                 j++;
//             }
//             k++;
//         }

//         // for remaining one
//         while(i<m){
//             if(k == idx1){
//                     el1 = nums1[i];
//                 }

//                 if(k == idx2){
//                     el2 = nums1[i];
//                 }
//                 i++;
//                 k++;
//         }

//         while(j<n){
//             if(k == idx1){
//                     el1 = nums2[j];
//                 }

//                 if(k == idx2){
//                     el2 = nums2[j];
//                 }
//                 j++;
//                 k++;
//         }

//         // checking size for returning ans
//         if(size %2 == 1){ //odd
//             return el2;
//         }
//         return (el1 + el2) / 2.0;

//     }
// };


// Binary Search - Optimal
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // we will apply BS in shortest array only
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        // Range for BS will be from 0 --> m
        int low = 0;
        int high = m;

        while(low<=high){
            int px = low + (high - low) / 2; // equivalent to mid
            int py = (m+n+1) / 2 - px; 

            // Left side wale
            int l1 = (px == 0) ? INT_MIN : nums1[px-1];
            int l2 = (px == m) ? INT_MAX : nums1[px];

            //Right side wale
            int r1 = (py == 0) ? INT_MIN : nums2[py-1];
            int r2 = (py == n) ? INT_MAX : nums2[py];

            if(l1<=r2 && r1<=l2){
                if((m + n) % 2 == 1){ //odd
                    return max(l1,r1);
                }
                return (max(l1, r1) + min(l2, r2))/2.0; // for even
            }
            
            else if(l1>r2){
                high = px - 1; //left side jaao
                // px and mid are same
            }
            else{
                low = px + 1;
            }
        }
        return -1;
    }
};