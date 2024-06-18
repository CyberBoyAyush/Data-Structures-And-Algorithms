//Next Permutation
//https://leetcode.com/problems/next-permutation/
#include<vector>
using namespace std;
#include<algorithm>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
    }
};