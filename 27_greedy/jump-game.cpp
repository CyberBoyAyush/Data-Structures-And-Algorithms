// Jump game - I
// https://leetcode.com/problems/jump-game/

// Greedy
// Tc - O(n)
// Sc - O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if(i>maxJump) return false;

            maxJump = max(maxJump, i + nums[i]);
        }
        return true;
    }
};