// 2433. Find The Original Array of Prefix Xor
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Hash Map
// TC: O(n)
// SC: O(n)

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        unordered_map<int,int> mpp;
        vector<int> res;

        for(auto &ele: encoded){
            mpp[ele]++;
        }

        for(auto &ele: encoded){
            if(mpp[ele] > 0){
                res.push_back(ele);
                mpp[ele]--;
                mpp[ele^res.back()]--;
            }
        }

        return res;
    }
};

// Approach 2: Using Bit Manipulation
// TC: O(n)
// SC: O(n)

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        vector<int> ans;

        ans.push_back(pref[0]);

        for(int i = 1; i<n ; i++){
            ans.push_back(pref[i] ^ pref[i-1]);
        }

        return ans;
    }
};