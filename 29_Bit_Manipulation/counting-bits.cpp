// counting-bits
// https://leetcode.com/problems/counting-bits/

#include <bits/stdc++.h>
using namespace std;

// Approach 1 -> Using inbuilt func
// TC: O(n logn)
// SC: O(n)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);

        for(int i = 0; i< n+1; i++){
            res[i] = __builtin_popcount(i);
        }

        return res;
    }
};

// Approach 2 -> Using Bit Manipulation
// TC: O(n)
// SC: O(n)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);

        res[0] = 0; // binary of 0 is 0
        for(int i = 1; i< n+1; i++){
            // if odd index
            if(i % 2 != 0){
                res[i] = res[i/2]+1;
            }
            else{
                res[i] = res[i/2];
            }
        }

        return res;
    }
};