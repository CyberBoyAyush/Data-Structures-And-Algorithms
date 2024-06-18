// Binary Search
// https://leetcode.com/problems/binary-search/
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {

   int s = 0;

   int n =nums.size();

   int e = n -1;

   int mid = s + (e-s)/2;

 

   while(s<=e)

   {

       if(nums[mid]==target)

       {

           return mid;

       }

       else if(nums[mid]>target)

       {

           e = mid -1;

       }

       else

       {

           s = mid + 1;

       }

    mid = s +(e-s)/2;

   }

    return -1 ;

    }
};