// Insert Intervals
// Leetcode : https://leetcode.com/problems/insert-interval/

#include<bits/stdc++.h>
using namespace std;
// Approach -> Greedy
// TC - O(N)
// SC - O(N)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;

        vector<vector<int>> result;

        int n = intervals.size();

        while(i < n){
            if(intervals[i][1] < newInterval[0]){
                result.push_back(intervals[i]);
            }
            else if(intervals[i][0] > newInterval[1]){
                break;
            }
            else{
                //merge karo
                newInterval[0] = min(newInterval[0] , intervals[i][0]);
                newInterval[1] = max(newInterval[1] , intervals[i][1]);
            }
            i++;
        }
        result.push_back(newInterval); 
        while(i < n){
            // pushing the rest which are left in intervals
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};