// 1442. Count Triplets That Can Form Two Arrays of Equal XOR
// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/

#include <bits/stdc++.h>
using namespace std;

// Approach: Prefix XOR
// TC: O(n^2)
// SC: O(n)

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefXOR(arr.begin(),arr.end());

        prefXOR.insert(prefXOR.begin(),0); // inserting 0 at start to calcuate and use prefix sum effectively

        int n = prefXOR.size();

        for(int i = 1; i<n ; i++){
            prefXOR[i] ^= prefXOR[i-1];
        }

        int cnt = 0;
        for(int i = 0; i<n ; i++){
            for(int k = i+1;k<n ; k++){
                if(prefXOR[i] == prefXOR[k]){
                    cnt += k-i-1; // -1 as we appended 0 and arr is modified
                }
            }
        }

        return cnt;

    }
};
