// Candy
// leetcode: https://leetcode.com/problems/candy/

// Approach -> Greedy with extra space
// TC - O(N)
// SC - O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        // L2R and R2L vectors
        vector<int> L2R(n,1);
        vector<int> R2L(n,1);

        //filling L2R array
        for(int i = 1 ; i<n ; i++){
            if(ratings[i] > ratings[i-1]){
                L2R[i] = max(L2R[i] , L2R[i-1] + 1); 
            }
        }

        // filling R2L array
        for(int i = n-2 ; i>=0 ; i--){
            if(ratings[i] > ratings[i+1]){
                R2L[i] = max(R2L[i] , R2L[i+1] + 1);
            }
        }

        // finding result
        int result = 0;
        for(int i= 0; i<n ; i++){
            result += max(L2R[i] , R2L[i]);
        }

        return result;
    }
};

// Appraoch 2 -> Greedy with O(1) space
// TC - O(N)
// SC - O(1)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int candy = n; // intial everyone has 1 candy

        int i = 1; // we are starting from 1

        while(i<n){
            // both ratings are same
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            // increasing slope -> Peak
            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                candy += peak; // adding peak value in candy
                i++;

                // check for i == n
                if(i == n){
                    return candy;
                }
            }

            // decreasing slope -> dip
            int dip = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                dip++;
                candy += dip;
                i++;
                
            }
            // subtracting extra dip added in it
            candy -= min(peak,dip);
        }
        return candy;
    }
};