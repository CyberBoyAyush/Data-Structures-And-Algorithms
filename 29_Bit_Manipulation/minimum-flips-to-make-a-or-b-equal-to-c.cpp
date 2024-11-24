// 1318. Minimum Flips to Make a OR b Equal to c
// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/

#include <bits/stdc++.h>
using namespace std;

// Appraoch 1 : We check every bit from right to left
// TC: O(32)
// SC: O(1)

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        while(a != 0 || b != 0 || c!=0){
            if((c&1) == 1){
                // right most bit is 1

                if((a & 1) == 0 && (b & 1) == 0){
                    // as we have OR so we need only 1 flip
                    flips++;
                }
            }

            else{
                // right most bit is 0
                if((a&1) == 1){
                    //as we are in OR we have to make it 0
                    flips++;
                }
                if((b&1) == 1){
                    //as we are in OR we have to make it 0
                    flips++;
                }
            }

            // removing right most bit
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
    }
};

// Approach 2 -> We can use XOR to check if the bits are different
// TC: O(32)
// SC: O(1)

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = ((a | b) ^ c); //Flips

        // if both bits of a and b are 1 (additional flip)
        int result1 = (a&b);

        int result2 = (result1 & result);

        return __builtin_popcount(result) + __builtin_popcount(result2);
    }
};