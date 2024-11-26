// sort-integers-by-the-number-of-1-bits
// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using custom comparator
// TC: O(n logn + n) = O(n logn)
// SC: O(n)

class Solution {
public:
    int findBitCnt(int num){
        int cnt = 0;

        while(num != 0){
            cnt += (num & 1); // count bit form right most side and if it is one it adds it

            num >>= 1; // right sift by 1 for futher task
        }

        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {

        auto lambda = [&](int &a, int &b){
            int cA = findBitCnt(a);
            int cB = findBitCnt(b);

            // if both bits cnt is same we sort it in ascneding
            if(cA == cB){
                return a < b;
            }

            return cA<cB; // based on bit count
        };
        
        sort(arr.begin(),arr.end(),lambda);

        return arr;
    }
};

// Approach 2: Using inbuilt function
// TC: O(n logn )
// SC: O(n)

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        auto lambda = [&](int &a, int &b){
            int cA = __builtin_popcount(a); // stl func which counts the setbits
            int cB = __builtin_popcount(b);

            // if both bits cnt is same we sort it in ascneding
            if(cA == cB){
                return a < b;
            }

            return cA<cB; // based on bit count
        };
        
        sort(arr.begin(),arr.end(),lambda);

        return arr;
    }
};