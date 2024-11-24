// single-number-ii
// https://leetcode.com/problems/single-number-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Hash Map
// TC: O(n)
// SC: O(n)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(auto num : nums){
            mpp[num]++;
        }

        for(auto it: mpp){
            if(it.second==1){
                return it.first;
            }
        }

        return -1;
    }
};

// Approach 2: Using Bit Manipulation
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for(int i = 0 ; i<32; i++){
            int mask = 1<<i; // check that bit (using or)

            int countZero = 0;
            int countOne = 0;

            for(int &num : nums){
                if((num & mask) == 0){
                    // i th bit is 0
                    countZero++;
                }
                else{
                    countOne++; // ith bit is 1
                }
            }

            // now from above loop we have count of bit at ith bit
            if(countOne % 3 == 1){
                // means it is extra
                result = (result | mask); // it makes ith bit of result 1
            }

            // for 0 we need to do nothing as it will be already 0
        }

        return result;
    }
};
